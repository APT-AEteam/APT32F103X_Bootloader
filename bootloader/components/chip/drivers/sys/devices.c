/***********************************************************************//** 
 * \file  devices.c
 * \brief  source file for the devices
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2020-5-13 <td>V0.0  <td>ZJY    <td>initial
 * </table>
 * *********************************************************************
*/
//#include <csi_config.h>
#include <stdio.h>
#include <soc.h>
#include <sys_clk.h>
#include <drv/uart.h>
#include <drv/bt.h>
#include <drv/dma.h>
#include <drv/iic.h>
#include <drv/rtc.h>
#include <drv/spi.h>
#include <drv/adc.h>
#include <drv/gpio.h>
#include <drv/irq.h>
#include <drv/pin.h>




const csi_irqmap_t irq_map[] = {
	
	//{CORE_ADDR_BASE,			CORET_IRQ_NUM		},
    {APB_SYS_BASE,				SYSCON_IRQ_NUM		},
	{APB_IFC_BASE,				IFC_IRQ_NUM		    },
    {APB_ADC_BASE,              ADC_IRQ_NUM	    	},
	{APB_EPT_BASE,				EPTA_IRQ_NUM		},
	{AHB_DMA_BASE,              DMA_IRQ_NUM		    },
	{APB_WWDT_BASE,           	WWDT_IRQ_NUM		},
    {APB_GPTA_BASE,           	GPTA0_IRQ_NUM		},
	{APB_RTC_BASE,           	RTC_IRQ_NUM		    },
	{APB_USART0_BASE,           USART0_IRQ_NUM		},
	{APB_UART0_BASE,           	UART0_IRQ_NUM		},
	{APB_UART1_BASE,           	UART1_IRQ_NUM		},
	{APB_UART2_BASE,           	UART2_IRQ_NUM		},
	{APB_I2C_BASE,            	I2C_IRQ_NUM		    },
	{APB_SPI_BASE,              SPI0_IRQ_NUM		},
	{APB_SIO_BASE,              SIO0_IRQ_NUM		},	
	{APB_CNTA_BASE,            	CNTA_IRQ_NUM		},
	{APB_TKEY_BASE,            	TKEY_IRQ_NUM		},
	{APB_LPT_BASE,            	LPT_IRQ_NUM	     	},
    {APB_BT0_BASE,              BT0_IRQ_NUM		    },
    {APB_BT1_BASE,              BT1_IRQ_NUM		    },
	{APB_BT2_BASE,              BT2_IRQ_NUM		    },
    {APB_BT3_BASE,              BT3_IRQ_NUM		    },
    {0,  						0			    	}
};

const csi_clkmap_t clk_map[] = {
    {APB_IFC_BASE,				IFC_SYS_CLK		},
    {APB_ADC_BASE,				ADC_SYS_CLK		},
    {APB_TKEY_BASE,				TKEY_SYS_CLK	},
    {APB_ETCB_BASE,				ETCB_SYS_CLK	},
    {APB_UART0_BASE,			UART0_SYS_CLK	},
    {APB_UART1_BASE,			UART1_SYS_CLK	},
    {APB_UART2_BASE,			UART2_SYS_CLK	},
	{APB_USART0_BASE,			USART0_SYS_CLK	},
    {APB_SPI_BASE,				SPI_SYS_CLK		},
    {APB_SIO_BASE,				SIO_SYS_CLK		},
    {APB_I2C_BASE,				I2C_SYS_CLK		},
    {APB_WWDT_BASE,				WWDT_SYS_CLK	},
    {APB_RTC_BASE,				RTC_SYS_CLK		},
    {APB_LPT_BASE,				LPT_SYS_CLK		},
    {APB_CNTA_BASE,				CNTA_SYS_CLK	},
    {APB_BT0_BASE,				BT0_SYS_CLK		},
    {APB_BT1_BASE,				BT1_SYS_CLK		},
	{APB_BT2_BASE,				BT2_SYS_CLK		},
    {APB_BT3_BASE,				BT3_SYS_CLK		},
    {APB_GPTA_BASE,			    GPT_SYS_CLK		},
    {APB_EPT_BASE,				EPT_SYS_CLK		},
    {0x00U, 					0xFFFFFFFFU		}
};

