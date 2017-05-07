#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/wdt.h>
#include <util/delay.h>

int main(void) {
  MCUSR &= ~(1 << WDRF);
  wdt_disable();

  /* Disable clock division */
  // clock_prescale_set(clock_div_1);

  CLKPR = (1 << CLKPCE);
  CLKPR = (0 << CLKPS3) | (0 << CLKPS2) | (0 << CLKPS1) | (0 << CLKPS0);

  DDRB |= (1<<7);
  PORTB |= (1<<7);
  DDRE |= (1<<6);
  PORTE |= (1<<6);

  while(1){
    PORTB |= (1<<7);
    _delay_ms(1000);
    PORTB &= ~(1<<7);
    _delay_ms(1000);
  }
}
