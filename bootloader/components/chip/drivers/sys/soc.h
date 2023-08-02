
 
/***********************************************************************//** 
 * \file  soc.h
 * \brief  CSI Core Peripheral Access Layer Header File for
 *           CSKYSOC Device Series
 * \copyright Copyright (C) 2015-2021 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2021-5-13 <td>V0.0 <td>ZJY     <td>initial
 * </table>
 * *********************************************************************
*/  

#ifndef _SOC_H_
#define _SOC_H_

#include <stdint.h>
#include <csi_core.h>
#include <drv/clk.h>
#include <drv/porting.h>

#ifdef __cplusplus
extern "C" {
#endif


#ifndef ISOSC_VALUE
#define ISOSC_VALUE			27000U
#endif

#ifndef EMOSC_VALUE
#define EMOSC_VALUE         24000000U
#endif

#ifndef EMOSC_32K_VALUE
#define EMOSC_32K_VALUE		32768U
#endif

#ifndef IMOSC_5M_VALUE
#define IMOSC_5M_VALUE		5556000U
#endif
#ifndef IMOSC_4M_VALUE
#define IMOSC_4M_VALUE      4194000U  

#endif
#ifndef IMOSC_2M_VALUE
#define IMOSC_2M_VALUE      2094000U
#endif
#ifndef IMOSC_131K_VALUE
#define IMOSC_131K_VALUE	131000U
#endif

#ifndef HFOSC_48M_VALUE
#define HFOSC_48M_VALUE     48000000U
#endif
#ifndef HFOSC_24M_VALUE
#define HFOSC_24M_VALUE     24000000U
#endif
#ifndef HFOSC_12M_VALUE
#define HFOSC_12M_VALUE     12000000U
#endif
#ifndef HFOSC_6M_VALUE
#define HFOSC_6M_VALUE      6000000U
#endif

//DMA
#define DMA_IDX_NUM			1
#define DMA_CH_MAX_NUM		6

//ETB dma start channel  number
//ETB max channel  number
#define ETB_CH_DMA_STAR		ETB_CH6
#define ETB_CH_MAX_NUM		12

//UARTx id number
#define UART_IDX_NUM   		3
#define UART_RECV_MAX_LEN	256

//USART id number
#define USART_IDX_NUM   		1
#define USART_RECV_MAX_LEN	128

//FLASH

#define PFLASHBASE			0x00000000  
#define PFLASHSIZE			0x00014000  //80K
#define PFLASHPAGE			320          
#define PFLASHLIMIT			(PFLASHBASE + PFLASHSIZE) 
#define USEROPTION_ADDR		0x000800C0
#define DFLASHBASE			0x10000000
#define DFLASHSIZE			0x00000C00 //3k
#define DFLASHPAGE			48  
#define DFLASHLIMIT 		(DFLASHBASE + DFLASHSIZE) 

#define IRQNUM				48
typedef enum {
	
	NMI_EXP_NUM                     = -2,      /* NMI Exception */
	SOFTWARE_IRQ_NUM                = 3U,
//	CORET_IRQn						= 7U,						 					
	SYSCON_IRQ_NUM					= 17U,
	IFC_IRQ_NUM						= 18U,
	ADC_IRQ_NUM						= 19U,	
	EPTA_IRQ_NUM					= 20U,	
	DMA_IRQ_NUM    	  				= 21U,	
	WWDT_IRQ_NUM					= 22U,
	EXI0_IRQ_NUM					= 23U,
	EXI1_IRQ_NUM					= 24U,	
	GPTA0_IRQ_NUM					= 25U,	
	//DUMMY1_IRQn    				= 26U,
	//DUMMY2_IRQn    				= 27U,
	RTC_IRQ_NUM						= 28U,
	UART0_IRQ_NUM      				= 29U,
	UART1_IRQ_NUM      				= 30U,
	UART2_IRQ_NUM      				= 31U,
	USART0_IRQ_NUM    				= 32U,
	I2C_IRQ_NUM    					= 33U,
	//DUMMY3_IRQn    				= 34U,
	SPI0_IRQ_NUM					= 35U,
	SIO0_IRQ_NUM					= 36U,
	EXI2_IRQ_NUM    				= 37U,
	EXI3_IRQ_NUM    				= 38U,
	EXI4_IRQ_NUM    				= 39U,
	CNTA_IRQ_NUM					= 40U,
	TKEY_IRQ_NUM					= 41U,
	LPT_IRQ_NUM						= 42U,
	//DUMMY4_IRQn    				= 43U,
	BT0_IRQ_NUM      				= 44U,
	BT1_IRQ_NUM      				= 45U,	
	BT2_IRQ_NUM    					= 46U,
	BT3_IRQ_NUM   					= 47U,
	
	
} irqn_type_e;

typedef enum {
	PA00			= 0U,
	PA01			= 1U,		
	PA02			= 2U,
    PA03			= 3U,
    PA04			= 4U,
    PA05			= 5U,
    PA06			= 6U,
    PA07			= 7U,
    PA08			= 8U,
    PA09			= 9U,
    PA010			= 10U,
    PA011			= 11U,
    PA012			= 12U,
    PA013			= 13U,
    PA014			= 14U,
    PA015			= 15U,
    PB00			= 16U,
    PB01			= 17U,
    PB02			= 18U,
    PB03			= 19U,
    PB04			= 20U,
    PB05			= 21U,
	PB06			= 22U,
	PB07			= 23U,
    PB08			= 24U,
    PB09			= 25U,
    PB010			= 26U,
    PB011			= 27U,
    PB012			= 28U,
	PB013			= 29U,
	
} pin_name_e;


typedef enum {
	
	PA00_GPD				=  0U,
	PA00_INPUT				=  1U,		//input
	PA00_OUTPUT				=  2U,		//output
	PA00_OUTPUT_MONI		=  3U,		//output with monitor
    PA00_UART0_TX			=  4U,
    PA00_I2C_SDA            =  5U,
    PA00_BT0_OUT            =  6U,
    PA00_UART2_RX           =  7U,
	PA00_DBUG_SWDIO			=  8U,
    PA00_TKEY_CH1           =  9U,
	PA00_GROUP0_I2C_SCL     =  10U,
    PA00_ADC_AIN1           =  11U,
	
	PA01_GPD				=  0U,
	PA01_INPUT				=  1U,		//input
	PA01_OUTPUT				=  2U,		//output
	PA01_OUTPUT_MONI		=  3U,		//output with monitor
	PA01_UART0_RX			=  4U,
    PA01_I2C_SCL            =  5U,
    PA01_BT1_OUT            =  6U,
    PA01_UART2_TX           =  7U,
	PA01_DBUG_SWCLK			=  8U,
    PA01_TKEY_CH2           =  9U,
	PA01_GROUP0_I2C_SDA     =  10U,
    PA01_ADC_AIN2           =  11U,
	
	PA02_GPD				=  0U,
	PA02_INPUT				=  1U,		//input
	PA02_OUTPUT				=  2U,		//output
	PA02_OUTPUT_MONI		=  3U,		//output with monitor
    PA02_SIO				=  4U,
    PA02_RTC_ALM            =  5U,
    PA02_BT0_OUT            =  6U,
    PA02_CLO           		=  7U,
	PA02_VREFP				=  8U,
	PA02_BUF				=  8U,
    PA02_TKEY_CH3           =  9U,
	PA02_GROUP0_GPT_CHA     =  10U,

	PA03_GPD				=  0U,
	PA03_INPUT				=  1U,		//input
	PA03_OUTPUT				=  2U,		//output
	PA03_OUTPUT_MONI		=  3U,		//output with monitor
	PA03_OSC_XI				=  4U,
    PA03_EPT_CHCX           =  5U,
    PA03_I2C_SDA            =  6U,
    PA03_UART1_TX           =  7U,
	PA03_SIO				=  8U,
    PA03_TKEY_CH4           =  9U,
	PA03_GROUP0_GPT_CHB     =  10U,
	PA03_ADC_AIN3           =  11U,
	PA03_VREFN          	=  11U,
	
	PA04_GPD				=  0U,
	PA04_INPUT				=  1U,		//input
	PA04_OUTPUT				=  2U,		//output
	PA04_OUTPUT_MONI		=  3U,		//output with monitor
	PA04_OSC_XO				=  4U,
    PA04_EPT_CHCY           =  5U,
    PA04_I2C_SCL            =  6U,
    PA04_UART1_RX           =  7U,
	PA04_LVDIN				=  8U,
    PA04_TKEY_CH5           =  9U,
	PA04_GROUP0_SPI_MOSI    =  10U,
	
	PA05_GPD				=  0U,
	PA05_INPUT				=  1U,		//input
	PA05_OUTPUT				=  2U,		//output
	PA05_OUTPUT_MONI		=  3U,		//output with monitor
	PA05_DBUG_SWCLK			=  4U,
    PA05_BT0_OUT            =  5U,
    PA05_CNTA_BUZ           =  6U,
    PA05_UART0_RX           =  7U,
	PA05_EPT_CHBY			=  8U,
    PA05_TKEY_C0            =  9U,
	PA05_GROUP0_SPI_MISO    =  10U,
	PA05_ADC_AIN4           =  11U,
	
	PA06_GPD				=  0U,
	PA06_INPUT				=  1U,		//input
	PA06_OUTPUT				=  2U,		//output
	PA06_OUTPUT_MONI		=  3U,		//output with monitor
	PA06_BT1_OUT			=  4U,
    PA06_SPI_NSS            =  5U,
    PA06_I2C_SCL            =  6U,
    PA06_UART2_TX           =  7U,
	PA06_DBUG_SWCLK			=  8U,
	PA06_GROUP0_SPI_SCK     =  10U,
	PA06_ADC_AIN5           =  11U,
	
	PA07_GPD				=  0U,
	PA07_INPUT				=  1U,		//input
	PA07_OUTPUT				=  2U,		//output
	PA07_OUTPUT_MONI		=  3U,		//output with monitor
	PA07_I2C_SDA			=  4U,
    PA07_EPI0            	=  5U,
    PA07_EPT_CHAX           =  6U,
    PA07_UART2_RX  	        =  7U,
	PA07_DBUG_SWDIO			=  8U,
	PA07_GROUP0_SPI_NSS     =  10U,
	PA07_ADC_AIN6           =  11U,
	
	PB02_GPD				=  0U,
	PB02_INPUT				=  1U,		//input
	PB02_OUTPUT				=  2U,		//output
	PB02_OUTPUT_MONI		=  3U,		//output with monitor
	PB02_I2C_SCL			=  4U,
    PB02_BT0_OUT           	=  5U,
    PB02_EPT_CHBX           =  6U,
    PB02_EPI3  	        	=  7U,
	PB02_SPI_SCK			=  8U,
	PB02_TKEY_CH6           =  9U,
	PB02_GROUP1_UART0_RX    =  10U,
	PB02_ADC_AIN7           =  11U,
	
	PB03_GPD				=  0U,
	PB03_INPUT				=  1U,		//input
	PB03_OUTPUT				=  2U,		//output
	PB03_OUTPUT_MONI		=  3U,		//output with monitor
	PB03_EPT_CHCX			=  4U,
    PB03_EPT_CHAY           =  5U,
    PB03_EPT_CHD            =  6U,
    PB03_EPI2  	        	=  7U,
	PB03_SPI_MOSI			=  8U,
	PB03_TKEY_CH7           =  9U,
	PB03_GROUP1_UART0_TX    =  10U,
	PB03_ADC_AIN8           =  11U,
	
	PA08_GPD				=  0U,
	PA08_INPUT				=  1U,		//input
	PA08_OUTPUT				=  2U,		//output
	PA08_OUTPUT_MONI		=  3U,		//output with monitor
	PA08_EPT_CHD			=  4U,
    PA08_EPT_CHBY           =  5U,
    PA08_BT1_OUT            =  6U,
    PA08_CLO	  	        =  7U,
	PA08_SPI_MISO			=  8U,
	PA08_TKEY_CH8           =  9U,
	PA08_GROUP1_EPT_CHAX    =  10U,
	PA08_ADC_AIN9           =  11U,
	
	PA09_GPD				=  0U,
	PA09_INPUT				=  1U,		//input
	PA09_OUTPUT				=  2U,		//output
	PA09_OUTPUT_MONI		=  3U,		//output with monitor
	PA09_SPI_SCK			=  4U,
    PA09_GPT_CHA            =  5U,
    PA09_CLO                =  6U,
    PA09_EPT_CHCY	  	    =  7U,
	PA09_LPT_OUT			=  8U,
	PA09_TKEY_CH9           =  9U,
	PA09_GROUP1_EPT_CHBX    =  10U,
	PA09_ADC_AIN10          =  11U,
	
	PA010_GPD				=  0U,
	PA010_INPUT				=  1U,		//input
	PA010_OUTPUT			=  2U,		//output
	PA010_OUTPUT_MONI		=  3U,		//output with monitor
	PA010_SPI_MOSI			=  4U,
    PA010_EPT_CHAX          =  5U,
    PA010_GPT_CHA           =  6U,
    PA010_GPT_CHB	  	    =  7U,
	PA010_LPT_IN			=  8U,
	PA010_TKEY_CH10         =  9U,
	PA010_GROUP1_EPT_CHCX   =  10U,
	PA010_ADC_AIN11         =  11U,

	PA011_GPD				=  0U,
	PA011_INPUT				=  1U,		//input
	PA011_OUTPUT			=  2U,		//output
	PA011_OUTPUT_MONI		=  3U,		//output with monitor
	PA011_SPI_MISO			=  4U,
    PA011_EPT_CHBX          =  5U,
    PA011_GPT_CHB           =  6U,
    PA011_CNTA_BUZ	  	    =  7U,
	PA011_BT0_OUT			=  8U,
	PA011_TKEY_CH11         =  9U,
	PA011_GROUP1_EPT_CHAY   =  10U,
	PA011_ADC_AIN12         =  11U,

	PA012_GPD				=  0U,
	PA012_INPUT				=  1U,		//input
	PA012_OUTPUT			=  2U,		//output
	PA012_OUTPUT_MONI		=  3U,		//output with monitor
	PA012_DBUG_SWDIO		=  4U,
    PA012_EPT_CHAY          =  5U,
    PA012_BT1_OUT           =  6U,
    PA012_UART0_TX	  	    =  7U,
	PA012_SIO				=  8U,
	PA012_TKEY_CH12         =  9U,
	PA012_GROUP1_EPT_CHBY   =  10U,
	PA012_ADC_AIN13         =  11U,
	
	PA013_GPD				=  0U,
	PA013_INPUT				=  1U,		//input
	PA013_OUTPUT			=  2U,		//output
	PA013_OUTPUT_MONI		=  3U,		//output with monitor
	PA013_EPI1				=  4U,
    PA013_EPT_CHCY          =  5U,
    PA013_I2C_SDA           =  6U,
    PA013_UART1_RX	  	    =  7U,
	PA013_BT0_OUT			=  8U,
	PA013_TKEY_CH13         =  9U,
	PA013_GROUP1_EPT_CHCY   =  10U,
	PA013_ADC_AIN14         =  11U,
	
	PB00_GPD				=  0U,
	PB00_INPUT				=  1U,		//input
	PB00_OUTPUT				=  2U,		//output
	PB00_OUTPUT_MONI		=  3U,		//output with monitor
	PB00_GPT_CHB			=  4U,
    PB00_EPT_CHCX          	=  5U,
    PB00_I2C_SCL            =  6U,
    PB00_UART1_TX	  	    =  7U,
	PB00_BT1_OUT			=  8U,
	PB00_TKEY_CH14          =  9U,
	PB00_ADC_AIN15          =  11U,
	
	PB01_GPD				=  0U,
	PB01_INPUT				=  1U,		//input
	PB01_OUTPUT				=  2U,		//output
	PB01_OUTPUT_MONI		=  3U,		//output with monitor
	PB01_CNTA_BUZ			=  4U,
    PB01_GPT_CHA          	=  5U,
    PB01_GPT_CHB            =  6U,
    PB01_SIO		  	    =  7U,
	PB01_LPT_OUT			=  8U,
	PB01_TKEY_CH0           =  9U,
	PB01_ADC_AIN0           =  11U,
	
	PB06_GPD				=  0U,
	PB06_INPUT				=  1U,		//input
	PB06_OUTPUT				=  2U,		//output
	PB06_OUTPUT_MONI		=  3U,		//output with monitor
    PB06_USART_RX          	=  4U,
    PB06_UART1_RX           =  5U,
    PB06_SPI_SCK		  	=  6U,
	PB06_EPT_CHAX			=  7U,
	PB06_TKEY_CH17          =  9U,
	PB06_ADC_AIN16          =  11U,
	
	PB07_GPD				=  0U,
	PB07_INPUT				=  1U,		//input
	PB07_OUTPUT				=  2U,		//output
	PB07_OUTPUT_MONI		=  3U,		//output with monitor
    PB07_USART_TX          	=  4U,
    PB07_UART1_TX           =  5U,
    PB07_SPI_NSS		  	=  6U,
	PB07_EPT_CHAY			=  7U,
	PB07_TKEY_CH18          =  9U,
	PB07_ADC_AIN17          =  11U,	

	PB08_GPD				=  0U,
	PB08_INPUT				=  1U,		//input
	PB08_OUTPUT				=  2U,		//output
	PB08_OUTPUT_MONI		=  3U,		//output with monitor
    PB08_USART_CK          	=  4U,
    PB08_UART0_TX           =  5U,
    PB08_SPI_MOSI		  	=  6U,
	PB08_EPT_CHBX			=  7U,
	PB08_TKEY_CH19          =  9U,
	PB08_ADC_AIN18          =  11U,	

	PB09_GPD				=  0U,
	PB09_INPUT				=  1U,		//input
	PB09_OUTPUT				=  2U,		//output
	PB09_OUTPUT_MONI		=  3U,		//output with monitor
    PB09_BT0_OUT          	=  4U,
    PB09_UART0_RX           =  5U,
    PB09_SPI_MISO		  	=  6U,
	PB09_EPT_CHBY			=  7U,
	PB09_TKEY_CH20          =  9U,
	PB09_ADC_AIN19          =  11U,			
	
	PB010_GPD				=  0U,
	PB010_INPUT				=  1U,		//input
	PB010_OUTPUT			=  2U,		//output
	PB010_OUTPUT_MONI		=  3U,		//output with monitor
    PB010_I2C_SDA          	=  4U,
    PB010_USART_TX          =  5U,
    PB010_SIO		    	=  6U,
	PB010_EPT_CHCX			=  7U,
	PB010_TKEY_CH21         =  9U,
	PB010_ADC_AIN20         =  11U,	

	
	PB011_GPD				=  0U,
	PB011_INPUT				=  1U,		//input
	PB011_OUTPUT			=  2U,		//output
	PB011_OUTPUT_MONI		=  3U,		//output with monitor
    PB011_I2C_SCL          	=  4U,
    PB011_USART_RX          =  5U,
    PB011_CNTA_BUZ		    =  6U,
	PB011_EPT_CHCY			=  7U,
	PB011_TKEY_CH22         =  9U,
	PB011_ADC_AIN21         =  11U,	
	
	PB012_GPD				=  0U,
	PB012_INPUT				=  1U,		//input
	PB012_OUTPUT			=  2U,		//output
	PB012_OUTPUT_MONI		=  3U,		//output with monitor
    PB012_UART2_TX          =  4U,
    PB012_EPI0              =  5U,
    PB012_CNTA_BUZ		    =  6U,
	PB012_GPT_CHA			=  7U,
	PB012_TKEY_CH23         =  9U,
	PB012_ADC_AIN22         =  11U,	

	PB013_GPD				=  0U,
	PB013_INPUT				=  1U,		//input
	PB013_OUTPUT			=  2U,		//output
	PB013_OUTPUT_MONI		=  3U,		//output with monitor
    PB013_UART2_RX          =  4U,
    PB013_EPI1              =  5U,
	PB013_GPT_CHB			=  7U,
	PB013_TKEY_CH24         =  9U,
	PB013_ADC_AIN23         =  11U,		
	
	PB04_GPD				=  0U,
	PB04_INPUT				=  1U,		//input
	PB04_OUTPUT				=  2U,		//output
	PB04_OUTPUT_MONI		=  3U,		//output with monitor
	PB04_EPT_CHCY			=  4U,
    PB04_EPT_CHBY          	=  5U,
    PB04_UART2_TX           =  6U,
    PB04_BT1_OUT		  	=  7U,
	PB04_SPI_SCK			=  8U,
	PB04_TKEY_CH15          =  9U,
	
	PB05_GPD				=  0U,
	PB05_INPUT				=  1U,		//input
	PB05_OUTPUT				=  2U,		//output
	PB05_OUTPUT_MONI		=  3U,		//output with monitor
	PB05_EPT_CHCX			=  4U,
    PB05_EPT_CHAY          	=  5U,
    PB05_UART2_RX           =  6U,
    PB05_BT0_OUT		  	=  7U,
	PB05_SPI_NSS			=  8U,
	PB05_TKEY_CH16          =  9U,
	
	PA014_GPD				=  0U,
	PA014_INPUT				=  1U,		
	PA014_OUTPUT			=  2U,		
	PA014_OUTPUT_MONI		=  3U,		
	PA014_EPT_CHBX			=  4U,
    PA014_BT1_OUT          	=  5U,
    PA014_I2C_SDA           =  6U,
    PA014_UART1_TX		  	=  7U,
	PA014_SPI_MOSI			=  8U,
	
	PA015_GPD				=  0U,
	PA015_INPUT				=  1U,		
	PA015_OUTPUT			=  2U,		
	PA015_OUTPUT_MONI		=  3U,		
	PA015_EPT_CHAX			=  4U,
    PA015_BT0_OUT          	=  5U,
    PA015_I2C_SCL           =  6U,
    PA015_UART1_RX		  	=  7U,
	PA015_SPI_MISO			=  8U,
	
	IOMAP					=  10U
} pin_func_e;

typedef enum{
	SWD_GRP0 = 0,
	SWD_GRP1,
	SWD_GRP2
}swd_grp_e;



//APB for APT32F103
//--Peripheral Address Setting
#define APB_PERI_BASE		0x40000000UL 
#define APB_DEVID_BASE      (APB_PERI_BASE + 0x0) //Device ID
#define APB_IFC_BASE    	(APB_PERI_BASE + 0x10000)
#define APB_SYS_BASE  	    (APB_PERI_BASE + 0x11000)
#define APB_ETCB_BASE    	(APB_PERI_BASE + 0x12000)
#define APB_TKEY_BASE    	(APB_PERI_BASE + 0x20000)
#define APB_ADC_BASE    	(APB_PERI_BASE + 0x30000)
#define APB_CNTA_BASE     	(APB_PERI_BASE + 0x50000)
#define APB_BT0_BASE       	(APB_PERI_BASE + 0x51000)
#define APB_BT1_BASE      	(APB_PERI_BASE + 0x52000)
#define APB_BT2_BASE       	(APB_PERI_BASE + 0x53000)
#define APB_BT3_BASE      	(APB_PERI_BASE + 0x54000)
#define APB_GPTA_BASE    	(APB_PERI_BASE + 0x55000)
#define APB_EPT_BASE    	(APB_PERI_BASE + 0x59000)
#define APB_RTC_BASE		(APB_PERI_BASE + 0x60000)
#define APB_LPT_BASE     	(APB_PERI_BASE + 0x61000)
#define APB_WWDT_BASE		(APB_PERI_BASE + 0x62000)
#define APB_UART0_BASE  	(APB_PERI_BASE + 0x80000)
#define APB_UART1_BASE  	(APB_PERI_BASE + 0x81000)
#define APB_UART2_BASE  	(APB_PERI_BASE + 0x82000)
#define APB_USART0_BASE      (APB_PERI_BASE + 0x83000) 
#define APB_SPI_BASE  		(APB_PERI_BASE + 0x90000)
#define APB_I2C_BASE   	    (APB_PERI_BASE + 0xA0000)
#define APB_SIO_BASE  		(APB_PERI_BASE + 0xB0000)

//
#define AHB_GPIO_BASE 		0x60000000
#define APB_GPIOA0_BASE  	(AHB_GPIO_BASE + 0x0000) 	//A0  
#define APB_GPIOB0_BASE  	(AHB_GPIO_BASE + 0x2000) 	//B0 
#define APB_IGRP_BASE		(AHB_GPIO_BASE + 0xF000)

//
#define AHB_CRC_BASE    	0x50000000
#define AHB_HWD_BASE		0x70000000	
#define AHB_DMA_BASE    	0x80000000
#define CORE_ADDR_BASE      0xE0004000
//#define CK801_ADDR_BASE  	0xE000E000	


#define CONFIG_IRQ_NUM				32U
#define CK_CPU_ENALLNORMALIRQ		__enable_irq()
#define CK_CPU_DISALLNORMALIRQ		__disable_irq()

#define nop							asm ("nop")
#define NOP							asm ("nop")



//ISR Define for generating special interrupt related ASM (E902), with compile option -mistack

#ifndef CONFIG_IRQ_LOOKUP

#define  ATTRIBUTE_ISR				__attribute__ ((interrupt ("machine")))

//
ATTRIBUTE_ISR 	void coret_int_handler(void);			//CPU Systick interrupt 
ATTRIBUTE_ISR 	void syscon_int_handler(void);			//System controller interrupt
ATTRIBUTE_ISR 	void ifc_int_handler(void);				//Internal flash controller interrupt
ATTRIBUTE_ISR 	void adc0_int_handler(void);			//ADC0 controller interrupt
ATTRIBUTE_ISR	void ept0_int_handler(void);          	//EPTA interrupt
ATTRIBUTE_ISR 	void dma_int_handler(void);				//DMA0 interrupt
ATTRIBUTE_ISR 	void wwdt_int_handler(void);			//Window watchdog timer interrupt
ATTRIBUTE_ISR 	void exi0_int_handler(void);			//External interrupt GROUP0, GROUP16 
ATTRIBUTE_ISR 	void exi1_int_handler(void);			//External interrupt GROUP1, GROUP17 
ATTRIBUTE_ISR 	void gpta0_int_handler(void);			//GPTA0 Interrupt
ATTRIBUTE_ISR 	void rtc_int_handler(void);				//Real timer clock interrupt
ATTRIBUTE_ISR 	void uart0_int_handler(void);			//UART0 interrupt
ATTRIBUTE_ISR 	void uart1_int_handler(void);			//UART1 interrupt
ATTRIBUTE_ISR 	void uart2_int_handler(void);			//UART2 interrupt
ATTRIBUTE_ISR 	void usart_int_handler(void);			//USART0 interrupt
ATTRIBUTE_ISR 	void i2c_int_handler(void);				//I2C  interrupt
ATTRIBUTE_ISR 	void spi0_int_handler(void);			//SPI0 interrupt
ATTRIBUTE_ISR 	void sio0_int_handler(void);		    	//SIO0 interrupt
ATTRIBUTE_ISR 	void exi2_3_int_handler(void);			//External Interrupt GROUP2 ~ 3, GROUP18~19
ATTRIBUTE_ISR 	void exi4_9_int_handler(void);			//External Interrupt GROUP4 ~ 9
ATTRIBUTE_ISR 	void exi10_15_int_handler(void);		//External Interrupt GROUP10 ~ 15
ATTRIBUTE_ISR 	void cnta_int_handler(void);			//COUNTER A interrupt
ATTRIBUTE_ISR 	void tkey_int_handler(void);          	//Touch Key interrupt
ATTRIBUTE_ISR 	void lpt_int_handler(void);				//Low power timer interrupt
ATTRIBUTE_ISR 	void bt0_int_handler(void); 			//BT0 interrupt
ATTRIBUTE_ISR 	void bt1_int_handler(void);				//BT1 interrupt
ATTRIBUTE_ISR 	void bt2_int_handler(void);				//BT2 interrupt
ATTRIBUTE_ISR 	void bt3_int_handler(void);				//BT3 interrupt
//
ATTRIBUTE_ISR	void tspend_handler(void);				//tspend interrupt
ATTRIBUTE_ISR 	void sw_int_handler( void);				//CPU software interrupt

#else
void sw_int_handler(void);				//CPU software interrupt

void coret_int_handler(void);			//CPU Systick interrupt 
void syscon_int_handler(void);			//System controller interrupt
void ifc_int_handler(void);				//Internal flash controller interrupt
void adc0_int_handler(void);			//ADC0 controller interrupt
void ept0_int_handler(void);            //EPTA interrupt
void dma_int_handler(void);			    //DMA0 interrupt
void wwdt_int_handler(void);			//Window watchdog timer interrupt
void exi0_int_handler(void);			//External interrupt GROUP0, GROUP16 
void exi1_int_handler(void);			//External interrupt GROUP1, GROUP17 
void gpta0_int_handler(void);			//GPTA0 Interrupt
void rtc_int_handler(void);				//Real timer clock interrupt
void uart0_int_handler(void);			//UART0 interrupt
void uart1_int_handler(void);			//UART1 interrupt
void uart2_int_handler(void);			//UART2 interrupt
void usart_int_handler(void);			//USART0 interrupt
void i2c_int_handler(void);				//I2C  interrupt
void spi0_int_handler(void);			//SPI0 interrupt
void sio0_int_handler(void);			//SIO0 interrupt
void exi2_3_int_handler(void);			//External Interrupt GROUP2 ~ 3, GROUP18~19
void exi4_9_int_handler(void);			//External Interrupt GROUP4 ~ 9
void exi10_15_int_handler(void);		//External Interrupt GROUP10 ~ 15
void cnta_int_handler(void);			//COUNTER A interrupt
void tkey_int_handler(void);            //Touch Key interrupt
void lpt_int_handler(void);				//Low power timer interrupt
void bt0_int_handler(void);				//BT0 interrupt
void bt1_int_handler(void);				//BT1interrupt
void bt2_int_handler(void);				//BT2 interrupt
void bt3_int_handler(void);				//BT3interrupt

#endif

void BreakPointHandler(void);
void FetchInstruAccessHandler(void);
void IllegalInstrHandler(void);
void UserModeCallHandler(void) ;
void MachineModeCallHandler(void);
void StoreInstruMisalignedHandler(void);
void LoadInstruMisalignedHandler(void);
void StoreInstruAccessHandler(void);
void LoadInstruAccessHandler(void);

#ifdef __cplusplus
}
#endif

#endif  /* _SOC_H_ */
