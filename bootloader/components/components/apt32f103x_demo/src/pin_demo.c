/***********************************************************************//** 
 * \file  pin_demo.c
 * \brief  PIN_DEMO description and static inline functions at register level 
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2020-4-25 <td>V0.0 <td>ZJY     <td>initial
 * </table>
 * *********************************************************************
*/
/* Includes ---------------------------------------------------------------*/
#include <string.h>
#include "sys_clk.h"
#include <drv/gpio.h>
#include <drv/pin.h>
#include "demo.h"
/* externs function--------------------------------------------------------*/
/* externs variablesr------------------------------------------------------*/
/* Private macro-----------------------------------------------------------*/
/* Private variablesr------------------------------------------------------*/


/** \brief gpio pin output demo 
 * 
 *  \param[in] none
 *  \return error code
 */
int pin_output_demo(void)
{
	int iRet = 0;
	
	csi_pin_set_mux(PB00,PB00_OUTPUT);			//PB00 配置为输出
	csi_pin_set_high(PB00);						//PB00 输出高
	mdelay(100);								//延时100ms
	csi_pin_set_low(PB00);						//PB00 输出低
	mdelay(100);
	csi_pin_set_high(PB00);						//PB00 输出低
	mdelay(100);
	
	csi_pin_output_mode(PB00, GPIO_OPEN_DRAIN);	//PB00 配置为开漏输出
	csi_pin_set_high(PB00);						
	mdelay(100);
	csi_pin_set_low(PB00);						
	mdelay(100);
	csi_pin_set_high(PB00);						
	mdelay(100);
	
	csi_pin_output_mode(PB00, GPIO_PUSH_PULL);	//PB00 配置为推挽输出
	csi_pin_set_high(PB00);						
	mdelay(100);
	csi_pin_set_low(PB00);						
	mdelay(100);
	csi_pin_set_high(PB00);						
	mdelay(100);
	
	return iRet;
}

/** \brief gpio 管脚输入模式
 * 		 - 输入分别配置为：无上下拉，上拉和下拉
 *  \param[in] none
 *  \return error code
 */
int pin_input_demo(void)
{
	int iRet = 0;
	
	uint32_t wStatus;
	
	csi_pin_set_mux(PA08,PA08_INPUT);			//PA08 配置为输入
	csi_pin_pull_mode(PA08,GPIO_PULLNONE);		//无上下拉
	mdelay(100);
	wStatus = csi_pin_read(PA08);				//PA08 输入状态读取(0/1 = 高/低)
	while(wStatus != 0);
	
	csi_pin_pull_mode(PA08,GPIO_PULLUP);		//上拉
	mdelay(100);
	wStatus = csi_pin_read(PA08);
	while(wStatus != (0x01 << 0x08));
	
	csi_pin_pull_mode(PA08,GPIO_PULLDOWN);		//下拉
	mdelay(100);
	wStatus = csi_pin_read(PA08);
	while(wStatus != 0);
	
	return iRet;
}

/** \brief gpio 管脚中断配置 
 * 		 - 管脚配置为下降沿产生中断
 *  \param[in] none
 *  \return error code
 */
int pin_irq_demo(void)
{
	int iRet = 0;
//	csi_imosc_enable(2);
//	csi_exi_flt_enable(EXI_FLT_CKDIV4, ENABLE);					//EXI 去抖滤波
	csi_pin_set_mux(PB01, PB01_INPUT);							//PB01 配置为输入
	csi_pin_pull_mode(PB01, GPIO_PULLUP);						//PB01 上拉
	csi_pin_irq_enable(PB01, ENABLE);							//PB01 中断使能
	csi_pin_irq_mode(PB01, EXI_GRP1, GPIO_IRQ_FALLING_EDGE);	//PB01 下降沿产生中断, 选择中断组1	
	csi_pin_vic_irq_enable(EXI_GRP1, ENABLE);					//VIC中断使能，选择中断组1
	
	return iRet;
}
/** \brief gpio 管脚remap配置
 * 		 - 将相应的IO配置为group0/group1的功能
 *  \param[in] none
 *  \return error code
 */
int pin_ioremap_demo(void)
{
	int iRet = 0;

	
//	csi_pin_set_mux(PA07, PA07_OUTPUT);                     //PA07 as output
//	csi_pin_output_mode(PA07, GPIO_PUSH_PULL);              //PA07 push pull mode
//	csi_spi_nss_high(PA07);								    //PA07 NSS init high
	
//	csi_pin_output_mode(PA00,GPIO_OPEN_DRAIN);
//	csi_pin_output_mode(PA01,GPIO_OPEN_DRAIN);
//	csi_swd_unlock();
	
	//IOMAP GROUP0
//	csi_pin_set_iomap(PA00, IOMAP0_I2C_SCL);
//	csi_pin_set_iomap(PA01, IOMAP0_I2C_SDA);
	csi_pin_set_iomap(PA02, IOMAP0_GPT_CHA);
	csi_pin_set_iomap(PA03, IOMAP0_GPT_CHB);
//	csi_pin_set_iomap(PA04, IOMAP0_SPI_MOSI);
//	csi_pin_set_iomap(PA05, IOMAP0_SPI_MISO);
//	csi_pin_set_iomap(PA06, IOMAP0_SPI_SCK);
//	csi_pin_set_iomap(PA07, IOMAP0_SPI_NSS);
	
	//IOMAP GROUP1
//	csi_pin_set_iomap(PB02, IOMAP1_UART0_TX);
//	csi_pin_set_iomap(PB03, IOMAP1_UART0_RX);
//	csi_pin_set_iomap(PA08, IOMAP1_EPT_CHAX);
//	csi_pin_set_iomap(PA09, IOMAP1_EPT_CHBX);
//	csi_pin_set_iomap(PA010, IOMAP1_EPT_CHCX);
//	csi_pin_set_iomap(PA011, IOMAP1_EPT_CHAY);
//	csi_pin_set_iomap(PA012, IOMAP1_EPT_CHBY);
//	csi_pin_set_iomap(PA013, IOMAP1_EPT_CHCY);



	
	return iRet;
}