/********************************************************************************************************
 * @file	default_config.h
 *
 * @brief	This is the header file for BLE SDK
 *
 * @author	BLE GROUP
 * @date	2020.06
 *
 * @par     Copyright (c) 2020, Telink Semiconductor (Shanghai) Co., Ltd. ("TELINK")
 *          All rights reserved.
 *
 *          Redistribution and use in source and binary forms, with or without
 *          modification, are permitted provided that the following conditions are met:
 *
 *              1. Redistributions of source code must retain the above copyright
 *              notice, this list of conditions and the following disclaimer.
 *
 *              2. Unless for usage inside a TELINK integrated circuit, redistributions
 *              in binary form must reproduce the above copyright notice, this list of
 *              conditions and the following disclaimer in the documentation and/or other
 *              materials provided with the distribution.
 *
 *              3. Neither the name of TELINK, nor the names of its contributors may be
 *              used to endorse or promote products derived from this software without
 *              specific prior written permission.
 *
 *              4. This software, with or without modification, must only be used with a
 *              TELINK integrated circuit. All other usages are subject to written permission
 *              from TELINK and different commercial license may apply.
 *
 *              5. Licensee shall be solely responsible for any claim to the extent arising out of or
 *              relating to such deletion(s), modification(s) or alteration(s).
 *
 *          THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 *          ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 *          WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *          DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDER BE LIABLE FOR ANY
 *          DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *          (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *          LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 *          ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *          (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *          SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************************************/
#pragma once


#include "config.h"
#include "app_config.h"

//////////// product  Infomation  //////////////////////////////
#ifndef ID_VENDOR
#define ID_VENDOR			0x248a			// for report 
#endif
#ifndef ID_PRODUCT_BASE
#define ID_PRODUCT_BASE		0x8800
#endif
#ifndef STRING_VENDOR
#define STRING_VENDOR		L"Telink"
#endif
#ifndef STRING_PRODUCT
#define STRING_PRODUCT		L"BLE 5.0"
#endif

#ifndef STRING_SERIAL
#define STRING_SERIAL		L"TLSR82x8"
#endif


#ifndef PM_DEEPSLEEP_RETENTION_ENABLE
#define PM_DEEPSLEEP_RETENTION_ENABLE				0
#endif


#if (PM_DEEPSLEEP_RETENTION_ENABLE)
	#define	BLC_PM_EN								1
	#define	BLC_PM_DEEP_RETENTION_MODE_EN			1
#endif


#ifndef	BLC_PM_EN
#define	BLC_PM_EN									0
#endif


#ifndef	BLC_PM_DEEP_RETENTION_MODE_EN
#define	BLC_PM_DEEP_RETENTION_MODE_EN				0
#endif






#if(APPLICATION_DONGLE)
	#ifndef MODULE_MOUSE_ENABLE
	#define MODULE_MOUSE_ENABLE		0
	#endif
	#ifndef MODULE_KEYBOARD_ENABLE
	#define MODULE_KEYBOARD_ENABLE	0
	#endif
	#ifndef MODULE_MIC_ENABLE
	#define MODULE_MIC_ENABLE		0
	#endif
	#ifndef MODULE_SPEAKER_ENABLE
	#define MODULE_SPEAKER_ENABLE	0			// device , not dongle
	#endif
	#ifndef MODULE_USB_ENABLE
	#define MODULE_USB_ENABLE		1
	#endif
#else
	#ifndef MODULE_MOUSE_ENABLE
	#define MODULE_MOUSE_ENABLE		1
	#endif
	#ifndef MODULE_KEYBOARD_ENABLE
	#define MODULE_KEYBOARD_ENABLE	1
	#endif

	#ifndef MODULE_MIC_ENABLE
	#define MODULE_MIC_ENABLE		0
	#endif
	#ifndef MODULE_SPEAKER_ENABLE
	#define MODULE_SPEAKER_ENABLE	0			// device , not dongle
	#endif

	#ifndef MODULE_USB_ENABLE
	#define MODULE_USB_ENABLE		0
	#endif
#endif








///////////////////  USB   /////////////////////////////////
#ifndef IRQ_USB_PWDN_ENABLE
#define	IRQ_USB_PWDN_ENABLE  	0
#endif


#ifndef USB_PRINTER_ENABLE
#define	USB_PRINTER_ENABLE 		0
#endif
#ifndef USB_SPEAKER_ENABLE
#define	USB_SPEAKER_ENABLE 		0
#endif
#ifndef USB_MIC_ENABLE
#define	USB_MIC_ENABLE 			0
#endif
#ifndef USB_MOUSE_ENABLE
#define	USB_MOUSE_ENABLE 			0
#endif
#ifndef USB_KEYBOARD_ENABLE
#define	USB_KEYBOARD_ENABLE 		0
#endif
#ifndef USB_SOMATIC_ENABLE
#define	USB_SOMATIC_ENABLE 		0
#endif
#ifndef USB_CUSTOM_HID_REPORT
#define	USB_CUSTOM_HID_REPORT 		0
#endif
#ifndef USB_AUDIO_441K_ENABLE
#define USB_AUDIO_441K_ENABLE  	0
#endif
#ifndef USB_MASS_STORAGE_ENABLE
#define USB_MASS_STORAGE_ENABLE  	0
#endif
#ifndef MIC_CHANNEL_COUNT
#define MIC_CHANNEL_COUNT  			2
#endif

#ifndef USB_DESCRIPTER_CONFIGURATION_FOR_KM_DONGLE
#define USB_DESCRIPTER_CONFIGURATION_FOR_KM_DONGLE  			0
#endif

#ifndef USB_ID_AND_STRING_CUSTOM
#define USB_ID_AND_STRING_CUSTOM  								0
#endif

/*
 * Default Link Layer Module Configuration
 */

#ifndef LL_MODULE_LEGACY_ADVERTISING_ENABLE
#define LL_MODULE_LEGACY_ADVERTISING_ENABLE							0
#endif

#ifndef LL_MODULE_LEGACY_SCANNING_ENABLE
#define LL_MODULE_LEGACY_SCANNING_ENABLE							0
#endif

#ifndef LL_MODULE_LEGACY_INITIATING_ENABLE
#define LL_MODULE_LEGACY_ADVERTISING_ENABLE							0
#endif


#ifndef LL_MODULE_EXTENDED_ADVERTISING_ENABLE
#define LL_MODULE_EXTENDED_ADVERTISING_ENABLE						0
#endif

#ifndef LL_MODULE_EXTENDED_SCANNING_ENABLE
#define LL_MODULE_EXTENDED_SCANNING_ENABLE							0
#endif

#ifndef LL_MODULE_EXTENDED_INITIATING_ENABLE
#define LL_MODULE_EXTENDED_INITIATING_ENABLE						0
#endif


#ifndef LL_MODULE_PERIODIC_ADVERTISING_ENABLE
#define LL_MODULE_PERIODIC_ADVERTISING_ENABLE						0
#endif



#ifndef LL_MODULE_ACL_CONNECTION_ENABLE
#define LL_MODULE_ACL_CONNECTION_ENABLE								0
#endif

#ifndef LL_MODULE_ACL_MASTER_ROLE_ENABLE
#define LL_MODULE_ACL_MASTER_ROLE_ENABLE							0
#endif

#ifndef LL_MODULE_ACL_SLAVE_ROLE_ENABLE
#define LL_MODULE_ACL_SLAVE_ROLE_ENABLE								0
#endif



#ifndef LL_MODULE_CIS_MASTER_ROLE_ENABLE
#define LL_MODULE_CIS_MASTER_ROLE_ENABLE							0
#endif

#ifndef LL_MODULE_CIS_SLAVE_ROLE_ENABLE
#define LL_MODULE_CIS_SLAVE_ROLE_ENABLE								0
#endif







#ifndef DEBUG_GPIO_ENABLE
#define DEBUG_GPIO_ENABLE  								0
#endif



#if (DEBUG_GPIO_ENABLE)
	#ifdef GPIO_CHN0
		#define DBG_CHN0_LOW		gpio_write(GPIO_CHN0, 0)
		#define DBG_CHN0_HIGH		gpio_write(GPIO_CHN0, 1)
		#define DBG_CHN0_TOGGLE		gpio_toggle(GPIO_CHN0)
	#else
		#define DBG_CHN0_LOW
		#define DBG_CHN0_HIGH
		#define DBG_CHN0_TOGGLE
	#endif

	#ifdef  GPIO_CHN1
		#define DBG_CHN1_LOW		gpio_write(GPIO_CHN1, 0)
		#define DBG_CHN1_HIGH		gpio_write(GPIO_CHN1, 1)
		#define DBG_CHN1_TOGGLE		gpio_toggle(GPIO_CHN1)
	#else
		#define DBG_CHN1_LOW
		#define DBG_CHN1_HIGH
		#define DBG_CHN1_TOGGLE
	#endif

	#ifdef  GPIO_CHN2
		#define DBG_CHN2_LOW		gpio_write(GPIO_CHN2, 0)
		#define DBG_CHN2_HIGH		gpio_write(GPIO_CHN2, 1)
		#define DBG_CHN2_TOGGLE		gpio_toggle(GPIO_CHN2)
	#else
		#define DBG_CHN2_LOW
		#define DBG_CHN2_HIGH
		#define DBG_CHN2_TOGGLE
	#endif

	#ifdef  GPIO_CHN3
		#define DBG_CHN3_LOW		gpio_write(GPIO_CHN3, 0)
		#define DBG_CHN3_HIGH		gpio_write(GPIO_CHN3, 1)
		#define DBG_CHN3_TOGGLE		gpio_toggle(GPIO_CHN3)
	#else
		#define DBG_CHN3_LOW
		#define DBG_CHN3_HIGH
		#define DBG_CHN3_TOGGLE
	#endif

	#ifdef GPIO_CHN4
		#define DBG_CHN4_LOW		gpio_write(GPIO_CHN4, 0)
		#define DBG_CHN4_HIGH		gpio_write(GPIO_CHN4, 1)
		#define DBG_CHN4_TOGGLE		gpio_toggle(GPIO_CHN4)
	#else
		#define DBG_CHN4_LOW
		#define DBG_CHN4_HIGH
		#define DBG_CHN4_TOGGLE
	#endif

	#ifdef  GPIO_CHN5
		#define DBG_CHN5_LOW		gpio_write(GPIO_CHN5, 0)
		#define DBG_CHN5_HIGH		gpio_write(GPIO_CHN5, 1)
		#define DBG_CHN5_TOGGLE		gpio_toggle(GPIO_CHN5)
	#else
		#define DBG_CHN5_LOW
		#define DBG_CHN5_HIGH
		#define DBG_CHN5_TOGGLE
	#endif

	#ifdef  GPIO_CHN6
		#define DBG_CHN6_LOW		gpio_write(GPIO_CHN6, 0)
		#define DBG_CHN6_HIGH		gpio_write(GPIO_CHN6, 1)
		#define DBG_CHN6_TOGGLE		gpio_toggle(GPIO_CHN6)
	#else
		#define DBG_CHN6_LOW
		#define DBG_CHN6_HIGH
		#define DBG_CHN6_TOGGLE
	#endif

	#ifdef  GPIO_CHN7
		#define DBG_CHN7_LOW		gpio_write(GPIO_CHN7, 0)
		#define DBG_CHN7_HIGH		gpio_write(GPIO_CHN7, 1)
		#define DBG_CHN7_TOGGLE		gpio_toggle(GPIO_CHN7)
	#else
		#define DBG_CHN7_LOW
		#define DBG_CHN7_HIGH
		#define DBG_CHN7_TOGGLE
	#endif

	#ifdef GPIO_CHN8
		#define DBG_CHN8_LOW		gpio_write(GPIO_CHN8, 0)
		#define DBG_CHN8_HIGH		gpio_write(GPIO_CHN8, 1)
		#define DBG_CHN8_TOGGLE		gpio_toggle(GPIO_CHN8)
	#else
		#define DBG_CHN8_LOW
		#define DBG_CHN8_HIGH
		#define DBG_CHN8_TOGGLE
	#endif

	#ifdef  GPIO_CHN9
		#define DBG_CHN9_LOW		gpio_write(GPIO_CHN9, 0)
		#define DBG_CHN9_HIGH		gpio_write(GPIO_CHN9, 1)
		#define DBG_CHN9_TOGGLE		gpio_toggle(GPIO_CHN9)
	#else
		#define DBG_CHN9_LOW
		#define DBG_CHN9_HIGH
		#define DBG_CHN9_TOGGLE
	#endif

	#ifdef  GPIO_CHN10
		#define DBG_CHN10_LOW		gpio_write(GPIO_CHN10, 0)
		#define DBG_CHN10_HIGH		gpio_write(GPIO_CHN10, 1)
		#define DBG_CHN10_TOGGLE	gpio_toggle(GPIO_CHN10)
	#else
		#define DBG_CHN10_LOW
		#define DBG_CHN10_HIGH
		#define DBG_CHN10_TOGGLE
	#endif

	#ifdef  GPIO_CHN11
		#define DBG_CHN11_LOW		gpio_write(GPIO_CHN11, 0)
		#define DBG_CHN11_HIGH		gpio_write(GPIO_CHN11, 1)
		#define DBG_CHN11_TOGGLE	gpio_toggle(GPIO_CHN11)
	#else
		#define DBG_CHN11_LOW
		#define DBG_CHN11_HIGH
		#define DBG_CHN11_TOGGLE
	#endif

	#ifdef GPIO_CHN12
		#define DBG_CHN12_LOW		gpio_write(GPIO_CHN12, 0)
		#define DBG_CHN12_HIGH		gpio_write(GPIO_CHN12, 1)
		#define DBG_CHN12_TOGGLE	gpio_toggle(GPIO_CHN12)
	#else
		#define DBG_CHN12_LOW
		#define DBG_CHN12_HIGH
		#define DBG_CHN12_TOGGLE
	#endif

	#ifdef  GPIO_CHN13
		#define DBG_CHN13_LOW		gpio_write(GPIO_CHN13, 0)
		#define DBG_CHN13_HIGH		gpio_write(GPIO_CHN13, 1)
		#define DBG_CHN13_TOGGLE	gpio_toggle(GPIO_CHN13)
	#else
		#define DBG_CHN13_LOW
		#define DBG_CHN13_HIGH
		#define DBG_CHN13_TOGGLE
	#endif

	#ifdef  GPIO_CHN14
		#define DBG_CHN14_LOW		gpio_write(GPIO_CHN14, 0)
		#define DBG_CHN14_HIGH		gpio_write(GPIO_CHN14, 1)
		#define DBG_CHN14_TOGGLE	gpio_toggle(GPIO_CHN14)
	#else
		#define DBG_CHN14_LOW
		#define DBG_CHN14_HIGH
		#define DBG_CHN14_TOGGLE
	#endif

	#ifdef  GPIO_CHN15
		#define DBG_CHN15_LOW		gpio_write(GPIO_CHN15, 0)
		#define DBG_CHN15_HIGH		gpio_write(GPIO_CHN15, 1)
		#define DBG_CHN15_TOGGLE	gpio_toggle(GPIO_CHN15)
	#else
		#define DBG_CHN15_LOW
		#define DBG_CHN15_HIGH
		#define DBG_CHN15_TOGGLE
	#endif
#else
	#define DBG_CHN0_LOW
	#define DBG_CHN0_HIGH
	#define DBG_CHN0_TOGGLE
	#define DBG_CHN1_LOW
	#define DBG_CHN1_HIGH
	#define DBG_CHN1_TOGGLE
	#define DBG_CHN2_LOW
	#define DBG_CHN2_HIGH
	#define DBG_CHN2_TOGGLE
	#define DBG_CHN3_LOW
	#define DBG_CHN3_HIGH
	#define DBG_CHN3_TOGGLE
	#define DBG_CHN4_LOW
	#define DBG_CHN4_HIGH
	#define DBG_CHN4_TOGGLE
	#define DBG_CHN5_LOW
	#define DBG_CHN5_HIGH
	#define DBG_CHN5_TOGGLE
	#define DBG_CHN6_LOW
	#define DBG_CHN6_HIGH
	#define DBG_CHN6_TOGGLE
	#define DBG_CHN7_LOW
	#define DBG_CHN7_HIGH
	#define DBG_CHN7_TOGGLE
	#define DBG_CHN8_LOW
	#define DBG_CHN8_HIGH
	#define DBG_CHN8_TOGGLE
	#define DBG_CHN9_LOW
	#define DBG_CHN9_HIGH
	#define DBG_CHN9_TOGGLE
	#define DBG_CHN10_LOW
	#define DBG_CHN10_HIGH
	#define DBG_CHN10_TOGGLE
	#define DBG_CHN11_LOW
	#define DBG_CHN11_HIGH
	#define DBG_CHN11_TOGGLE
	#define DBG_CHN12_LOW
	#define DBG_CHN12_HIGH
	#define DBG_CHN12_TOGGLE
	#define DBG_CHN13_LOW
	#define DBG_CHN13_HIGH
	#define DBG_CHN13_TOGGLE
	#define DBG_CHN14_LOW
	#define DBG_CHN14_HIGH
	#define DBG_CHN14_TOGGLE
	#define DBG_CHN15_LOW
	#define DBG_CHN15_HIGH
	#define DBG_CHN15_TOGGLE
#endif
