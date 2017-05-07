#ifndef _KB_H_
#define _KB_H_

	/* Includes: */
		#include <avr/io.h>
		#include <avr/wdt.h>
		#include <avr/power.h>
		#include <avr/interrupt.h>
		#include <stdbool.h>
		#include <string.h>

		#include "descriptors.h"

		#include <LUFA/Drivers/USB/USB.h>
		#include <LUFA/Drivers/Board/Joystick.h>
		#include <LUFA/Drivers/Board/Buttons.h>
		#include <LUFA/Drivers/Board/LEDs.h>
		#include <LUFA/Platform/Platform.h>

	/* Macros: */
		/** LED mask for the library LED driver, to indicate that the USB interface is not ready. */
		#define LEDMASK_USB_NOTREADY        LEDS_LED1

		/** LED mask for the library LED driver, to indicate that the USB interface is enumerating. */
		#define LEDMASK_USB_ENUMERATING     (LEDS_LED2 | LEDS_LED3)

		/** LED mask for the library LED driver, to indicate that the USB interface is ready. */
		#define LEDMASK_USB_READY           (LEDS_LED2 | LEDS_LED4)

		/** LED mask for the library LED driver, to indicate that an error has occurred in the USB interface. */
		#define LEDMASK_USB_ERROR           (LEDS_LED1 | LEDS_LED3)

	/* Function Prototypes: */
		void SetupHardware(void);
		void HID_Task(void);

		void EVENT_USB_Device_Connect(void);
		void EVENT_USB_Device_Disconnect(void);
		void EVENT_USB_Device_ConfigurationChanged(void);
		void EVENT_USB_Device_ControlRequest(void);
		void EVENT_USB_Device_StartOfFrame(void);

		void CreateKeyboardReport(USB_KeyboardReport_Data_t* const ReportData);
		void ProcessLEDReport(const uint8_t LEDReport);
		void SendNextReport(void);
		void ReceiveNextReport(void);

#endif

