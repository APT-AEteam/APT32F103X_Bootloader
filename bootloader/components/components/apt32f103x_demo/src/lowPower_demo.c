/***********************************************************************//** 
 * \file  lowPower_demo.c
 * \brief  low power demo code
 * \copyright Copyright (C) 2015-2021 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2021-6-2 <td>V2.0 <td>WNN    <td>initial
 * </table>
 * *********************************************************************
*/

/* include ----------------------------------------------------------------*/
#include <drv/pm.h>
#include <drv/pin.h>
#include <drv/rtc.h>
#include <drv/lpt.h>
#include <drv/irq.h>
#include <drv/iwdt.h>
#include <drv/tick.h>
#include <drv/common.h> 
#include <drv/reliability.h>

#include "demo.h"
#include "iostring.h"
#include "csp_syscon.h"
#include "board_config.h"

/* Private macro------------------------------------------------------*/
#define	SRAM1_LEN		256

/* externs function---------------------------------------------------*/
/* externs variablesr-------------------------------------------------*/
/* Private variablesr-------------------------------------------------*/
uint8_t *bypSramAddr = (uint8_t *)0x20002000;	


volatile uint8_t byExiFlg = 0x00;


/** \brief 进入低功耗模式前的准备动作
 *  \param[in] none
 *  \return error code
 */
void prepare_lp(void)				  
{
	//USER CODE，如记忆管脚状态
}

/** \brief 退出低功耗模式后恢复动作
 *  \param[in] none
 *  \return error code
 */
void wkup_lp(void)					   
{
	//USER CODE，如恢复管脚状态
	csi_pin_set_low(PB02);
}


/** \brief 通过LPT唤醒DEEPSLEEP模式
 * 
 *  \param  none
 *  \return none
 */
void lp_lpt_wakeup_deepsleep_demo(void)
{
	csi_pm_mode_e ePmMode = PM_MODE_SLEEP;		
	
	csi_pin_set_mux(PB05,PB05_OUTPUT);				//PA05 OUTPUT
	
	csi_pin_toggle(PB05);
	mdelay(250);
	csi_pin_toggle(PB05);
	mdelay(250);
	csi_pin_toggle(PB05);
	mdelay(250);
	csi_pin_toggle(PB05);
	mdelay(250);
	csi_pin_toggle(PB05);
	mdelay(250);
	csi_pin_toggle(PB05);
	mdelay(250);
	csi_pin_toggle(PB05);
	mdelay(250);
	csi_pin_toggle(PB05);
	mdelay(250);

#ifdef CONFIG_USER_PM	
	csi_pm_attach_callback(ePmMode, prepare_lp, wkup_lp);	//需要在工程设置compiler tab下加入define CONFIG_USER_PM=1;
#endif

	csi_pm_config_wakeup_source(WKUP_LPT, ENABLE);			//配置唤醒源
					
//	csi_clk_pm_enable(ISOSC_STP, ENABLE);  //DEEPSLEEP 模式下时钟开启/关闭
//	csi_clk_pm_enable(IMOSC_STP, ENABLE);
//	csi_clk_pm_enable(EMOSC_STP, ENABLE);
//  csi_clk_pm_enable(PCLK_IDLE, DISABLE);
	csi_clk_pm_enable(HCLK_IDLE, DISABLE);
	
	//lpt初始化配置
	csi_lpt_timer_init(LPT,LPT_CLK_ISCLK, 1000);       		//初始化lpt,选用内部超低功耗时钟,定时500ms,默认采用PEND中断
	csi_lpt_start(LPT);	  
	mdelay(10);
	
	switch(ePmMode)
	{
		case PM_MODE_SLEEP:
			my_printf("Enter Sleep Mode\n");
			break;
		case PM_MODE_DEEPSLEEP:
			my_printf("Enter Deep-Sleep mode\n");
			break;
		default:
			break;
	}
	
	while(1) 
	{
//		csi_pin_set_high(PB05);
		csi_pm_enter_sleep(ePmMode);
		my_printf("Wakeup From Deep-Sleep Mode...\n");
		csi_pin_toggle(PB05);
		
	}
}

/** \brief 各种源唤醒低功耗的示例代码
 * 		 - 唤醒源分别可配置为：外部中断/LVD/LPT/RTC/iwdt
 * 		 - 低功耗的模式为：sleep/deepsleep
 *  \param  none
 *  \return none
 */
void lp_wakeup_demo(void)
{
	csi_pm_mode_e ePmMode = PM_MODE_DEEPSLEEP;		//PM_MODE_SLEEP/PM_MODE_DEEPSLEEP


	
	csi_pin_set_mux(PB01,PB01_OUTPUT);				//PB01 OUTPUT
	
//	csi_pin_toggle(PB01);
//	mdelay(250);
//	csi_pin_toggle(PB01);
//	mdelay(250);
//	csi_pin_toggle(PB01);
//	mdelay(250);
//	csi_pin_toggle(PB01);
//	mdelay(250);
//	csi_pin_toggle(PB01);
//	mdelay(250);
//	csi_pin_toggle(PB01);
//	mdelay(250);
//	csi_pin_toggle(PB01);
//	mdelay(250);
//	csi_pin_toggle(PB01);
//	mdelay(250);

	
#ifdef CONFIG_USER_PM	
	csi_pm_attach_callback(ePmMode, prepare_lp, wkup_lp);	//需要在工程设置compiler tab下加入define CONFIG_USER_PM=1;
#endif
	
//	csi_pin_set_mux(PB01,PB01_INPUT);							//PB01 输入							
//	csi_pin_pull_mode(PB01, GPIO_PULLUP);						//PB01 上拉
//	csi_pin_irq_mode(PB01,EXI_GRP1, GPIO_IRQ_FALLING_EDGE);		//PB01 下降沿产生中断
//	csi_pin_irq_enable(PB01, EXI_GRP1, ENABLE);					//PB01 中断使能，选择中断组0	
//	csi_vic_set_wakeup_irq(EXI1_IRQn);
	
	
//	csi_pm_clk_enable(SP_IDLE_PCLK, DISABLE);
//	csi_pm_clk_enable(SP_IDLE_HCLK, DISABLE);
//	csi_pm_clk_enable(DP_ISOSC, ENABLE);
//	csi_pm_clk_enable(DP_IMOSC, ENABLE);
//	csi_pm_clk_enable(DP_ESOSC, ENABLE);
//	csi_pm_clk_enable(DP_EMOSC, ENABLE);
	
	csi_pm_config_wakeup_source(WKUP_LVD, ENABLE);

	
	//LPT WAKEUP DeepSleep
//	csi_lpt_timer_init(LPT,LPT_CLK_ISCLK, 500);       		//初始化lpt,选用内部超低功耗时钟,定时200ms,默认采用PEND中断
//	csi_lpt_start(LPT);	  
	
	//LVD WAKEUP	DeepSleep
	csi_lvd_int_enable(LVD_INTF,LVD_33);  						//VDD掉电到3.6V即触发LVD中断
	

//	csi_pin_set_mux(PA03, PA03_OSC_XI);
//	csi_pin_set_mux(PA04, PA04_OSC_XO);

//	//RTC WAKEUP DeepSleep
//	{
//		csi_rtc_config_t tRtcConfig;
//		
//		tRtcConfig.byClkSrc = RTC_CLKSRC_ISOSC;  		//选择时钟源
//		tRtcConfig.byFmt = RTC_24FMT;				  	//选择时间模式
//		csi_rtc_init(RTC, &tRtcConfig);				  	//初始化RTC
//		csi_rtc_start_as_timer(RTC, RTC_TIMER_0_5S);	//每1s进一次中断
//		csi_rtc_start(RTC);	
//	}

//	//IWDT WAKEUP DeepSleep
//	csi_iwdt_init(IWDT_TO_1024);						//初始化看门狗，溢出时间为1000ms(系统复位时间)
//	csi_iwdt_irq_enable(IWDT_ALARMTO_4_8, ENABLE);		//使能看门狗报警中断，报警时间为4/8溢出时间(500ms)
//	csi_iwdt_open();	
//	csi_iwdt_feed();
	
//	mdelay(10);
	
//	switch(ePmMode)
//	{
//		case PM_MODE_SLEEP:
//			my_printf("Enter Sleep Mode\n");
//			break;
//		case PM_MODE_DEEPSLEEP:
//			my_printf("Enter Deep-Sleep mode\n");
//			break;
//		default:
//			break;
//	}
	
	while(1) 
	{
		//csi_pin_set_high(PB01);
		
		csi_pm_enter_sleep(ePmMode);
	//	csi_iwdt_feed();
		//mdelay(100);
		csi_pin_toggle(PB01);
		mdelay(100);
		my_printf("Wakeup From Sleep Mode...\n");
	}
}

/** \brief write sram1
 *  \param[in] byWrData 待写入数据
 *  \return none
 */
static void write_sram1(uint8_t byWrData)
{
	uint16_t i;
	uint8_t byVal;
	
	for(i = 0; i < SRAM1_LEN; i++)		
	{
		*(bypSramAddr+i) = byWrData; 
	}
	
	for(i = 0; i < SRAM1_LEN; i++)			
	{
		byVal = *(bypSramAddr+i);
		if(byVal != byWrData)
			break;
	}
	
	if(i < SRAM1_LEN)
		my_printf("Write Sram1 Data = 0x%x Fail!\n", byWrData);
	else
		my_printf("Write Sram1 Data = 0x%x Success!\n", byWrData);
}


/** \brief read sram1
 *  \param[in] byData sram中写入的数据
 *  \return none
 */

static void read_sram1(uint8_t byData)
{
	uint16_t i;
	uint8_t byVal;
	for(i = 0; i < SRAM1_LEN; i++)
	{
		byVal = *(bypSramAddr+i);
		if(byVal != byData)
			break;
	}
	
	if(i < SRAM1_LEN)
		my_printf("Read Sram1 Data = 0x%x Fail!\n", byData);
	else
		my_printf("Read Sram1 Data = 0x%x Success!\n", byData);
}

