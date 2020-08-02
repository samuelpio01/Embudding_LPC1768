/*****************************************************************************
 *   readme.txt:  Description of the LPC17xx Example Software Package
 *
 *   Copyright(C) 2009, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2009.06.23  ver 1.00    Preliminary version, first Release 
 *   2009.08.24  ver 1.01    (1) Added ADC burst mode support, 
 *                           (2) UART and ADC
 *                           use PCLKSELx to identify PCLK to the peripheral
 *                           instead of hard coding. 
 *                           (3) Added USBBHostLite as part of code bundle. 
 *                           (4) Added workaround for MDC and MDIO bit-banging 
 *                           due to the lack of MDC/MDIO support in LPC175x 80-pin 
 *                           package. 
 *                           (5) Added USBCDC class driver, Audio class driver,
 *                           and Mass Storage Class driver using both DMA and non-DMA.
 *                           (6) Fixed CAN issue.
 *                           (7) Used the latest Keil CMSIS header definition to be 
 *                           released.
 *                           (8) Added RS485 mode.
 *                           (9) Fixed CTCR misalighment in timer data structure in the header.
 *   2010.01.07  ver 1.02    (1) Header file and startup file update for CANActivity and 
 *                           USBActivity.
 *                           (2) Added USBActivity and CANActivity interrupt examples for 
 *                           power down and wakeup.
 *                           (3) Fixed a cut/paste error in PWM example.
 *                           (4) Added uVision 4 projects for examples.
 *                           (5) Change the order of PCLKSELx setting before PLL configuration
 *                           to address the issue mentioned in the errata.
 *                             
 *                                                        
 *		                             
******************************************************************************/

/*****************************************************************************/
Software that is described herein is for illustrative purposes only which 
provides customers with programming information regarding the products.
This software is supplied "AS IS" without any warranties. NXP Semiconductors 
assumes no responsibility or liability for the use of the software, conveys no 
license or title under any patent, copyright, or mask work right to the 
product. NXP Semiconductors reserves the right to make changes in the 
software without notification. NXP Semiconductors also make no representation 
or warranty that such application will be suitable for the specified use without 
further testing or modification.
/*****************************************************************************/


The Description of the Example software
===================

This example demonstrates the use of build-in peripherals on the NXP
LPC17xx family microcontrollers.

The Example software includes, common library, peripheral APIs, and test modules
for the APIs. The common library include startup file, standard definition and
header files, processor specific setup module, generic interrupt related APIs, 
timer routine. The peripheral directories include, ADC, DAC, DMA, GPIO, PWM, 
Real-time clock, timer, SPI, I2C, Watchdog timer, UART, external 
interrupt, CAN, Ethernet, USB HID,etc.
  
The development environment is Keil's, an ARM company now, uVision MDK 3.85 
or later, and ULINK2 ICE. The target boards are Keil's MCB1700 with a NXP's 
LPC17xx MCU on it.

Please note that, the latest Keil MDK includes the startup file, the header
files, and Cortex related API files for NVIC and Systick driver. These files
are also included in our common library. They may be slight change between the
revisions. If the users wish to use Keil MDK default setting, the compiler can 
also be set: 
Change "#include "lpc17xx.h" to "#include <lpc17xx.h> where should be 
located under C:\Keil\ARM\INC\NXP directory. This is also necessary if Keil 
releases the update of the header file. 

Many of the peripherals are similar to those in LPC23xx/LPC24xx, except NVIC
handling, not all the software modules have been ported from LPC23xx/24xx to
LPC17xx yet. e.g. once you are familiar with LPC23xx/24xx family MCU, you can
use LPC23xx/24xx as the reference and port simple driver from LPC23xx to LPC17xx.
Go to below website and check out the sample code bundle under "Support Doc." 
for more details.
http://www.standardics.nxp.com/products/lpc2000/all/~LPC2364/#LPC2364

The project is created for both target option "FLASH" and "RAM". 
For "FLASH", the image code can be programmed into the flash and executed;
for "RAM", the image code can be loaded into internal SRAM(IRAM)
for easy debugging. The "RAM.ini" in each directory is a Keil uVision debugger
script file, once the debugger starts, the code will be loaded to the IRAM
first, then, "RAM.ini" will be executed and reset program counter(PC) to 
0x10000000(IRAM starting address) that code will be executed from.

Some external components, such as I2C temperature, SPI serial EEPROM, will be 
required to add on the board in order to complete the test below.

By default, the test program is for Keil MCB1700 board.

The directory tree and content of the sample software
===================

core
    -- inc
	-- lpc17xx.h		CMSIS Cortex-M3 Core Peripheral Access Layer Header 
				File for NXP LPC17xx Device Series 
	-- core_cm3.h		CMSIS Cortex-M3 Core Peripheral Access Layer Header File
	-- system_LPC17xx.h	CMSIS Cortex-M3 Device Peripheral Access Layer Header 
				File for the NXP LPC17xx Device Series
	-- type.h		Type definition Header file for NXP LPC17xx Family 
    -- src
	-- core_cm3.c		CMSIS Cortex-M3 Core Peripheral Access Layer Source File
	-- startup_LPC17xx.s	CMSIS Cortex-M3 Core Device Startup File 
           			for the NXP LPC17xx Device Series
	-- system_LPC17xx.c	CMSIS Cortex-M3 Device Peripheral Access Layer Source
    				File for the NXP LPC17xx Device Series

ADC
    -- adc.h			ADC header
    -- adc.c			ADC APIs
    -- adctest.c		ADC controller test module
    -- adc.uv2			uVision 3 project file
    -- adc.uvproj		uVision 4 project file

CAN
    -- can.h			CAN header
    -- can.c			CAN APIs
    -- cantest.c		CAN test module
    -- can.uv2			uVision 3 project file
    -- can.uvproj		uVision 4 project file

DAC
    -- dac.h			DAC header
    -- dac.c			DAC APIs
    -- dactest.c		DAC test module
    -- dac.uv2			uVision 3 project file
    -- dac.uvproj		uVision 4 project file
    
DMA
    -- dma.h			DMA header
    -- dma.c			GPDMA APIs, memory to memory only.
				Note: memory to peripheral or peripheral
				to memory are in SSP, MCI, and I2S directories.
    -- dmatest.c		DMA test module
    -- dma.uv2			uVision 3 project file
    -- dma.uvproj		uVision 4 project file
    
EMAC
    -- easyweb.h		easyweb header
    -- easyweb.c		easyweb (EMAC test module)
    -- emac.h			EMAC header
    -- emac.c			EMAC APIs
    -- tcpip.h			header-file for tcpip.c
    -- tcpip.c			implements the TCP/IP-stack and provides a simple API
    -- webpage.h		web content
    -- easyweb.uv2		uVision 3 project file
    -- easyweb.uvproj		uVision 4 project file 
    
EXTINT
    -- extint.h			External interrupt header
    -- extint.c			External interrupt APIs
    -- einttest.c		External interrupt test module
    -- extint.uv2		uVision 3 project file
    -- extint.uvproj		uVision 4 project file
                
GPIO
    -- fio.h			GPIO and fast I/O header
    -- fio.c			GPIO and fast I/O APIs
    -- fiotest.c		GPIO and Fast I/O test module
    -- fio.uv2			uVision 3 project file
    -- fio.uvproj		uVision 4 project file

I2C
    -- i2c.h			I2C header
    -- i2c.c			I2C APIs
    -- i2cmst.c			I2C test module
    -- i2cmst.uv2		uVision 3 project file
    -- i2cmst.uvproj		uVision 4 project file
    
I2S
    -- i2s.h			I2S header
    -- i2s.c			I2S APIs
    -- dma.c			I2S DMA APIs
    -- dma.h			I2S DMA header
    -- i2stest.c		I2S test module
    -- i2s.uv2			uVision 3 project file
    -- i2s.uvproj		uVision 4 project file
        
PWM
    -- pwmc.h			PWM header
    -- pwm.c			PWM APIs
    -- pwmtest.c		PWM test module
    -- pwm.uv2			uVision 3 project file
    -- pwm.uvproj		uVision 4 project file
    
RTC
    -- rtc.h			Real-time clock(RTC) header
    -- rtc.c			Real-time clock(RTC) APIs
    -- rtctest.c		Real-time clock(RTC) test module
    -- rtc.uv2			uVision 3 project file
    -- rtc.uvproj		uVision 4 project file
    
Timer
    -- tmrtest.c		Timer test module, note: API modules
				are in the COMMON directory and 
				shared and used by some other peripheral testing.
    -- timer.uv2		uVision 3 project file
    -- timer.uvproj		uVision 4 project file

UART
    -- uart.h			UART header
    -- uart.c			UART APIs
    -- uarttest.c		UART test module
    -- uart.uv2			uVision 3 project file
    -- uart.uvproj		uVision 4 project file

USBHID
    -- hid.h			USB HID related header
    -- hiduser.h		USB HID user specific header
    -- hiduser.c		USB HID user APIs
    -- usb.h			USB header
    -- usbcfg.h			USB configuration header
    -- usbcore.h		USB Core header
    -- usbcore.c		USB Core APIs
    -- usbdesc.h		USB descriptor header
    -- usbdesc.c		USB descriptor APIs
    -- usbhw.h			USB hardware header
    -- usbhw.c			USB hardware APIs
    -- usbreg.h			USB misc. register header
    -- usbuser.h		USB user header
    -- useuser.c		USB user APIs
    -- demo.c			USB HID test module main entry
    -- demo.h                   header file for main entry
    -- usbhid.uv2		uVision 3 project file
    -- usbhid.uvproj		uVision 4 project file
	
USBMEM
    -- msc.h			USB MSC related header
    -- mscuser.h		USB MSC user specific header
    -- mscuser.c		USB MSC user APIs
    -- usb.h			USB header
    -- usbcfg.h			USB configuration header
    -- usbcore.h		USB Core header
    -- usbcore.c		USB Core APIs
    -- usbdesc.h		USB descriptor header
    -- usbdesc.c		USB descriptor APIs
    -- usbhw.h			USB hardware header
    -- usbhw.c			USB hardware APIs
    -- usbreg.h			USB misc. register header
    -- usbuser.h		USB user header
    -- useuser.c		USB user APIs
    -- diskimg.c                USB Virtual file page
    -- memory.c			USB MSC test module main entry
    -- memory.h                 header file for main entry
    -- usbmem.uv2		uVision 3 project file
    -- usbmem.uvproj		uVision 4 project file
    -- dma.sct                  uVision scatter file for use of DMA.

USBCDC   
    -- cdc.h			USB CDC related header
    -- cdcuser.h		USB CDC Device Class user specific header
    -- cdcuser.c		USB CDC Device Class user APIs
    -- usb.h			USB header
    -- usbcfg.h			USB configuration header
    -- usbcore.h		USB Core header
    -- usbcore.c		USB Core APIs
    -- usbdesc.h		USB descriptor header
    -- usbdesc.c		USB descriptor APIs
    -- usbhw.h			USB hardware header
    -- usbhw.c			USB hardware APIs
    -- usbreg.h			USB misc. register header
    -- usbuser.h		USB user header
    -- usbuser.c		USB user APIs
    -- vcomdemo.h		header for VCOM demo
    -- vcomdemo.c		USB CDC(Virtual COM) test module, main entry
    -- virtualCom.uv2		uVision 3 project file
    -- virtualCom.uvproj	uVision 4 project file
    -- serial.h			Header for UART port
    -- serial.c			UART module APIs
    -- mcb1700-vcom.inf		The host side driver installation file

USBAudio
    -- audio.h			USB Audio related header
    -- adcuser.h		USB Audio Device Class user specific header
    -- adcuser.c		USB Audio Device Class user APIs
    -- usb.h			USB header
    -- usbaudio.h		USB Audio misc. definition header
    -- usbcfg.h			USB configuration header
    -- usbcore.h		USB Core header
    -- usbcore.c		USB Core APIs
    -- usbdesc.h		USB descriptor header
    -- usbdesc.c		USB descriptor APIs
    -- usbhw.h			USB hardware header
    -- usbhw.c			USB hardware APIs
    -- usbreg.h			USB misc. register header
    -- usbuser.h		USB user header
    -- useuser.c		USB user APIs
    -- usbmain.c		USB Audio test module
    -- usbaudio.uv2		uVision 3 project file
    -- usbaudio.uvproj		uVision 4 project file
    -- dma.sct                  uVision scatter file for use of DMA.	

WDT
    -- wdt.h			Watchdog timer header
    -- wdt.c			Watchdog timer APIs
    -- wdttest.c		Watchdog timer test module
    -- wdt.uv2			uVision 3 project file
    -- wdt.uvproj		uVision 4 project file


RS485
    -- rs485.h			UART1 RS485 header
    -- rs485.c			UART1 RS485 APIs
    -- rs485test.c		UART1 RS485 test module
    -- rs485.uv2		uVision 3 project file
    -- rs485.uvproj		uVision 4 project file
