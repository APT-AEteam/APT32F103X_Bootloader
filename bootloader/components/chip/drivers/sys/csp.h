/***********************************************************************//** 
 * \file  csp.h
 * \copyright Copyright (C) 2015-2021 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2020-11-24 <td>V0.0  <td>WNN   <td>initial
 * <tr><td> 20201-5-13 <td>V0.0  <td>ZJY   <td>add *IWDT
 * </table>
 * *********************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/ 
#ifndef _CSP_H
#define _CSP_H

/* Includes ------------------------------------------------------------------*/
#include "csp_adc.h"
#include "csp_bt.h"
#include "csp_cnta.h"
#include "csp_crc.h"
#include "csp_ept.h"
#include "csp_etb.h"
#include "csp_gpio.h"
#include "csp_gpta.h"
#include "csp_i2c.h"
#include "csp_ifc.h"
#include "csp_lpt.h"
#include "csp_rtc.h"
#include "csp_sio.h"
#include "csp_spi.h"
#include "csp_dma.h"
#include "csp_syscon.h"
#include "csp_uart.h"
#include "csp_usart.h"
#include "csp_wwdt.h"
#include "csi_core.h"
#include "csp_tkey.h"


typedef csp_syscon_t 	csp_iwdt_t;
typedef csp_usart_t 	csp_lin_t;


extern CLIC_Type  		*COREINT;
extern CORET_Type 		*CORETIMER;
extern csp_ifc_t 		*IFC;
extern csp_syscon_t 	*SYSCON;
extern csp_etb_t        *ETCB;
extern csp_dma_t   		*DMA;
extern csp_adc_t 		*ADC0;
extern csp_gpio_t 		*GPIOA0, *GPIOB0;
extern csp_igrp_t 		*GPIOGRP;
extern csp_usart_t 		*USART0;
extern csp_uart_t 		*UART0, *UART1, *UART2;
extern csp_spi_t  		*SPI0;
extern csp_sio_t  		*SIO0;
extern csp_i2c_t  		*I2C0; 
extern csp_cnta_t  		*CNTA;
extern csp_gpta_t 		*GPTA0;
extern csp_ept_t 		*EPT0;
extern csp_lpt_t 		*LPT;
extern csp_wwdt_t 		*WWDT;
extern csp_bt_t  		*BT0, *BT1,*BT2, *BT3;
extern csp_crc_t 		*CRC;
extern csp_rtc_t 		*RTC;
extern csp_iwdt_t		*IWDT;
extern csp_tkey_t		*TKEY;

extern csp_lin_t		*LIN0;

#endif

/******************* (C) COPYRIGHT 2020 APT Chip *****END OF FILE****/