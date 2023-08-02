/*
 * Copyright (C) 2016 YunOS Project. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//#include <csi_config.h>
#include <soc.h>

extern void Default_Handler(void);

void (*g_irqvector[64])(void);
void (*g_nmivector)(void);

void irq_vectors_init(void)
{
    int i;

    for (i = 0; i < 64; i++) {
        g_irqvector[i] = Default_Handler;
    }
	
//#ifdef	CONFIG_IRQ_LOOKUP		//Table lookup method for interrupt processing 
	//init all irq table
 //   g_irqvector[CORET_IRQn] 	= coret_int_handler;
	g_irqvector[SYSCON_IRQ_NUM] 	= syscon_int_handler;
	g_irqvector[IFC_IRQ_NUM] 		= ifc_int_handler;
	g_irqvector[ADC_IRQ_NUM] 		= adc0_int_handler;
	g_irqvector[EPTA_IRQ_NUM] 		= ept0_int_handler;
	g_irqvector[DMA_IRQ_NUM] 		= dma_int_handler;
	g_irqvector[WWDT_IRQ_NUM] 		= wwdt_int_handler;
	g_irqvector[EXI0_IRQ_NUM] 		= exi0_int_handler;
	g_irqvector[EXI1_IRQ_NUM] 		= exi1_int_handler;
	g_irqvector[GPTA0_IRQ_NUM]   	= gpta0_int_handler;
	g_irqvector[RTC_IRQ_NUM] 		= rtc_int_handler;
	g_irqvector[UART0_IRQ_NUM]  	= uart0_int_handler;
	g_irqvector[UART1_IRQ_NUM]  	= uart1_int_handler;
	g_irqvector[UART2_IRQ_NUM]  	= uart2_int_handler;
	g_irqvector[USART0_IRQ_NUM]  	= usart_int_handler;
	g_irqvector[I2C_IRQ_NUM] 		= i2c_int_handler;
	g_irqvector[SPI0_IRQ_NUM] 		= spi0_int_handler;
	g_irqvector[SIO0_IRQ_NUM] 		= sio0_int_handler;
	g_irqvector[EXI2_IRQ_NUM] 		= exi2_3_int_handler;
	g_irqvector[EXI3_IRQ_NUM] 		= exi4_9_int_handler;
	g_irqvector[EXI4_IRQ_NUM] 		= exi10_15_int_handler;
	g_irqvector[CNTA_IRQ_NUM] 		= cnta_int_handler;
	g_irqvector[TKEY_IRQ_NUM] 		= tkey_int_handler;
	g_irqvector[LPT_IRQ_NUM] 		= lpt_int_handler;
	g_irqvector[BT0_IRQ_NUM] 		= bt0_int_handler;
	g_irqvector[BT1_IRQ_NUM] 		= bt1_int_handler;
	g_irqvector[BT2_IRQ_NUM] 		= bt2_int_handler;
	g_irqvector[BT3_IRQ_NUM] 		= bt3_int_handler;


//#endif

}
