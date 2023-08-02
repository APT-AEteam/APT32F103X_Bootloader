/***********************************************************************//** 
 * \file  rtc_demo.c
 * \brief  rtc demo code
 * \copyright Copyright (C) 2015-2021 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2022-8-11 <td>V1.0 <td>CWL    <td>initial
 * </table>
 * *********************************************************************
*/

/* include ----------------------------------------------------------------*/
#include "rtc.h"
#include "irq.h"
#include "bt.h"
#include "etb.h"
#include "pin.h"
#include "iostring.h"
#include "board_config.h"

/* externs function--------------------------------------------------------*/

/* private function--------------------------------------------------------*/
/* externs variablesr------------------------------------------------------*/
/* Private variablesr------------------------------------------------------*/

//extern uint8_t AlarmA_Flag;
//extern uint8_t AlarmB_Flag;

/** \brief 设置rtc时间的示例代码：包括时钟源、时间模式、时间设置，当前时间回读函数
 * 
 *  \param[in] none
 *  \return    none
 */
void rtc_set_time_demo(void)
{	
	csi_rtc_config_t tRtcConfig;
	csi_rtc_time_t tRtcTime,tRtcTimeRdbk;
	uint32_t wSec = 0;
	
	csi_pin_set_mux(PA03, PA03_OSC_XI);			//设置PA0.3为SXIN，如果使用外部主晶振作为RTC时钟源，必须先对管脚进行配置
	csi_pin_set_mux(PA04, PA04_OSC_XO);         //设置PA0.4为SXOUT，如果使用外部主晶振作为RTC时钟源，必须先对管脚进行配置
	
	tRtcConfig.byClkSrc = RTC_CLKSRC_EMOSC_DIV4;//外部副晶振作为RTC时钟源
	tRtcConfig.byFmt = RTC_12FMT;				//选择时间模式,12H制或者24H制
	csi_rtc_init(RTC, &tRtcConfig);				//初始化设置
	
	
	tRtcTime.iYear = 22;
	tRtcTime.iMon  = 2;
	tRtcTime.iMday = 14;
//	tRtcTime.iWday = 1;                         //星期：1-7，不用设置，由get_week_by_date函数自动计算
	tRtcTime.iPm   = RTC_AM;					//AM 或 PM,24H制下AM/PM位无效
	tRtcTime.iHour = 11;						//如果是12H制，回读到的hour范围为1->12；如果是24H制，回读到的hour范围是0->23
	tRtcTime.iMin  = 59;                        //分，0-59
	tRtcTime.iSec  = 55;	                    //秒，0-59
	csi_rtc_set_time(RTC, &tRtcTime);			//设置时间
	csi_rtc_start(RTC);							//RTC开始计时
	
//	csi_rtc_change_fmt(RTC, RTC_12FMT);			//修改时间模式为12小时制
//	tRtcTime.iYear = 22;
//	tRtcTime.iMon  = 2;
//	tRtcTime.iMday = 14;
////	tRtcTime.iWday = 1;                     //星期1-7
//	tRtcTime.iPm   = RTC_AM;					// AM or PM
//	tRtcTime.iHour = 11;
//	tRtcTime.iHour = 9;
//	tRtcTime.iMin  = 59;
//	tRtcTime.iSec  = 56;	
//	csi_rtc_set_time(RTC, &tRtcTime);			//修改时间以后需要重新start rtc
//	csi_rtc_start(RTC);
//	
//	csi_rtc_get_time(RTC,  &tRtcTimeRdbk);		//回读当前时间
//	my_printf("12FMT: %d:%d:%d\n", tRtcTimeRdbk.iHour, tRtcTimeRdbk.iMin, tRtcTimeRdbk.iSec);
//	
//	csi_rtc_change_fmt(RTC, RTC_24FMT);			//修改时间模式为24小时制
//	csi_rtc_get_time(RTC,  &tRtcTimeRdbk);		//回读当前时间
//	my_printf("24FMT: %d:%d:%d\n", tRtcTimeRdbk.iHour, tRtcTimeRdbk.iMin, tRtcTimeRdbk.iSec);
//	
//	csi_rtc_change_fmt(RTC, RTC_12FMT);			//修改时间模式为12小时制
	
	while(1)
	{
		csi_rtc_get_time(RTC,  &tRtcTimeRdbk);  //读RTC时间
		
		if(wSec != tRtcTimeRdbk.iSec )          //1s打印一次
		{
			wSec = tRtcTimeRdbk.iSec;
			my_printf("20%d.%d.%d  %d  %d:%d:%d pm= %d\n",tRtcTimeRdbk.iYear,tRtcTimeRdbk.iMon,tRtcTimeRdbk.iMday, tRtcTimeRdbk.iWday,tRtcTimeRdbk.iHour, tRtcTimeRdbk.iMin, tRtcTimeRdbk.iSec, tRtcTimeRdbk.iPm);
			
		}
	}
}

/** \brief 设置rtc 闹钟的示例代码：包括闹表模式、闹钟时间设置
 * 
 *  \param[in] none
 *  \return    none
 */

void rtc_alarm_demo(void)	
{	
	uint32_t wSec = 0;
	
	csi_rtc_time_t tRtcTime, tRtcTimeRdbk;
	csi_rtc_time_t tAlmTime;
	csi_rtc_time_t tBlmTime;
	csi_rtc_config_t tRtcConfig;
	
//	csi_pin_set_mux(PA03, PA03_OSC_XI);			//设置PA0.3为SXIN，如果使用外部主晶振作为RTC时钟源，必须先对管脚进行配置
//	csi_pin_set_mux(PA04, PA04_OSC_XO);         //设置PA0.4为SXOUT，如果使用外部主晶振作为RTC时钟源，必须先对管脚进行配置
	
	tRtcConfig.byClkSrc = RTC_CLKSRC_ISOSC;		//选择ISOSC做RTC时钟源，如果选择外部晶振做RTC时钟源必须先配置晶振引脚
	tRtcConfig.byFmt    = RTC_24FMT;			//选择时间模式，12H 或 24H制
	csi_rtc_init(RTC, &tRtcConfig);				//初始化RTC
	
	tRtcTime.iYear = 22;                      //年
	tRtcTime.iMon  = 8;                       //月
	tRtcTime.iMday = 11;                      //日
//	tRtcTime.iWday = 1;                       //星期：1-7，不用设置，由get_week_by_date函数自动计算
	tRtcTime.iHour = 23;                      //时
	tRtcTime.iMin  = 59;                      //分
	tRtcTime.iSec  = 55;                      //秒
	tRtcTime.iPm   = RTC_AM;	              //AM 或 PM,24H制下AM/PM位无效
	csi_rtc_set_time(RTC, &tRtcTime);		  //设置时间
	csi_rtc_start(RTC);						  //RTC开始工作
	
	/*** 闹铃A设置 ***/
//	tAlmTime.iWday = THURSDAYS | TUESDAYS;      //星期二、四闹铃
	tAlmTime.iWday = EVERYDAY;                  //每天闹铃，也可以SUNDAYS~MONDAYS任意组合
	tAlmTime.iHour = 0;			                //闹铃A时设置，如果不考虑小时则填0xFF
	tAlmTime.iMin  = 0;                         //闹铃A分设置，如果不考虑分时则填0xFF
	tAlmTime.iSec  = 3;			                //闹铃A秒设置，如果不考虑秒则填0xFF			
	tAlmTime.iPm   = RTC_AM;                    //闹铃A AM/PM位位设置，12H制有效，24H该位无效	
	csi_rtc_set_alarm(RTC, RTC_ALMA,&tAlmTime);	//设置闹钟A	
	
	
	/*** 闹铃B设置 ***/
//	tBlmTime.iWday =  SATURDAYS | SUNDAYS;     //星期六、日闹铃
	tBlmTime.iWday = EVERYDAY;                 //每天闹铃，也可以SUNDAYS~MONDAYS任意组合
	tBlmTime.iHour = 0;                        //闹铃B时设置，如果不考虑小时则填0xFF
	tBlmTime.iMin  = 0;                        //闹铃B分设置，如果不考虑分则填0xFF
	tBlmTime.iSec  = 5;			               //闹铃B秒设置，如果不考虑秒则填0xFF			    
	tBlmTime.iPm   = RTC_AM;                   //闹铃B AM/PM位设置，12H制有效，24H该位无效	
	csi_rtc_set_alarm(RTC,RTC_ALMB,&tBlmTime); //设置闹钟B	
	
	
	/*** 闹铃输出设置 ***/
//	csi_pin_set_mux(PA02,PA02_RTC_ALM);  	   //设置PA02脚为RTC_ALM引脚输出脉冲
//	csi_rtc_set_alarm_out(RTC,RTC_ALMB_P);
	
	while(1)
	{
		csi_rtc_get_time(RTC,  &tRtcTimeRdbk); //读RTC时间
		
		if(wSec != tRtcTimeRdbk.iSec )         //1s打印一次
		{
			wSec = tRtcTimeRdbk.iSec;
			my_printf("20%d.%d.%d  %d  %d:%d:%d pm= %d\n",tRtcTimeRdbk.iYear,tRtcTimeRdbk.iMon,tRtcTimeRdbk.iMday, tRtcTimeRdbk.iWday,tRtcTimeRdbk.iHour, tRtcTimeRdbk.iMin, tRtcTimeRdbk.iSec, tRtcTimeRdbk.iPm);
		}
		if(csi_rtc_get_int_msg(RTC_INTSRC_ALMA,1)) //判断闹铃B中断信息是否产生，并且清除中断信息标志位
		{
			my_printf("RTC AlarmA has triggered!!\n");
		}
		if(csi_rtc_get_int_msg(RTC_INTSRC_ALMB,1)) //判断闹铃B中断信息是否产生，并且清除中断信息标志位
		{
			my_printf("RTC AlarmB has triggered!!\n");
		}
	}
}

/** \brief 示例如何将RTC当做一个简单timer来使用
 * 
 *  \param[in] none
 *  \return    none
 */
void rtc_timer_demo(void)
{
//	uint32_t wSec = 0;
//	csi_rtc_time_t tRtcTimeRdbk;
	csi_rtc_time_t tRtcTime;
	csi_rtc_config_t tRtcConfig;
	
//	csi_pin_set_mux(PA03, PA03_OSC_XI);			//设置PA0.3为SXIN，如果使用外部主晶振作为RTC时钟源，必须先对管脚进行配置
//	csi_pin_set_mux(PA04, PA04_OSC_XO);         //设置PA0.4为SXOUT，如果使用外部主晶振作为RTC时钟源，必须先对管脚进行配置
	
	tRtcConfig.byClkSrc = RTC_CLKSRC_ISOSC;  	//选择RTC时钟源，如果选择外部晶振做RTC时钟源必须先配置晶振引脚
	tRtcConfig.byFmt = RTC_24FMT;				//选择时间模式，12H 或 24H制
	csi_rtc_init(RTC, &tRtcConfig);				//初始化RTC
	
	tRtcTime.iYear = 22;                        //年
	tRtcTime.iMon  = 8;                         //月
	tRtcTime.iMday = 11;                        //日
//	tRtcTime.iWday = 1;                         //星期：1-7，不用设置，由get_week_by_date函数自动计算
	tRtcTime.iHour = 9;                         //时
	tRtcTime.iMin  = 59;                        //分
	tRtcTime.iSec  = 55;                        //秒
	tRtcTime.iPm   = RTC_AM;                    //AM 或 PM,24H制下AM/PM位无效	
	csi_rtc_set_time(RTC, &tRtcTime);			//设置时间
	
	
	csi_rtc_start_as_timer(RTC, RTC_TIMER_1MIN);//每1分钟进一次中断
	csi_rtc_start(RTC);							//RTC开始工作
	
	/*** 闹铃输出设置 ***/
	csi_pin_set_mux(PA02,PA02_RTC_ALM);  	   //设置PA02脚为RTC_ALM引脚输出脉冲
	csi_rtc_set_alarm_out(RTC,RTC_CPRD_P);     //设置RTC_ALM脚输出为CPRD周期事件

	while(1)
	{
//		csi_rtc_get_time(RTC,  &tRtcTimeRdbk); //读RTC时间
//		
//		if(wSec != tRtcTimeRdbk.iSec )         //1s打印一次
//		{
//			wSec = tRtcTimeRdbk.iSec;
//			my_printf("20%d.%d.%d  %d  %d:%d:%d pm= %d\n",tRtcTimeRdbk.iYear,tRtcTimeRdbk.iMon,tRtcTimeRdbk.iMday, tRtcTimeRdbk.iWday,tRtcTimeRdbk.iHour, tRtcTimeRdbk.iMin, tRtcTimeRdbk.iSec, tRtcTimeRdbk.iPm);
//		}
		if(csi_rtc_get_int_msg(RTC_INTSRC_CPRD,1)) //判断周期事件CPRD中断信息是否产生，并且清除中断信息标志位
		{
			my_printf("RTC CPRD has triggered!!\n");
		}
	}
}


/** \brief 示例RTC通过ETCB触发BT工作
 * 		 - AlarmA触发BT0 PWM输出
 * 		 - AlarmB触发BT1 PWM输出
 * 
 *  \param[in] none
 *  \return    none
 */
 void rtc_trgev_demo(void)	
 {
	csi_bt_pwm_config_t tPwmCfg;
	
	csi_etb_config_t tEtbConfig1,tEtbConfig2;
	csi_rtc_config_t tRtcConfig;
	csi_rtc_time_t tRtcTime,tRtcTimeRdbk;
	csi_rtc_time_t tAlmTime;
	csi_rtc_time_t tBlmTime;
	volatile uint8_t ch;
	uint32_t wSec = 0;
	
	
	csi_pin_set_mux(PA03, PA03_OSC_XI);			//设置PA0.3为SXIN，如果使用外部主晶振作为RTC时钟源，必须先对管脚进行配置
	csi_pin_set_mux(PA04, PA04_OSC_XO);         //设置PA0.4为SXOUT，如果使用外部主晶振作为RTC时钟源，必须先对管脚进行配置
	
	tRtcConfig.byClkSrc = RTC_CLKSRC_EMOSC_DIV4;//选择时钟源，如果选择外部晶振做RTC时钟源必须先配置晶振引脚
	tRtcConfig.byFmt = RTC_24FMT;				//选择时间模式
	csi_rtc_init(RTC, &tRtcConfig);				//初始化设置
	
	tRtcTime.iYear = 22;                        //年
	tRtcTime.iMon  = 2;                         //月
	tRtcTime.iMday = 14;                        //日
//	tRtcTime.iWday = 1;                         //星期：1-7，不用设置，由get_week_by_date函数自动计算
	tRtcTime.iHour = 9;						    //如果是12小时制，回读到的hour范围为1->12；如果是24小时制，回读到的hour范围是0->23
	tRtcTime.iMin = 59;                         //分
	tRtcTime.iSec = 55;                         //秒
	tRtcTime.iPm  = RTC_AM;						//AM 或 PM,24H制下AM/PM位无效
	csi_rtc_set_time(RTC, &tRtcTime);			//设置时间
	csi_rtc_start(RTC);							//RTC开始计时
	
	
	/*** 闹铃A设置 ***/
	tAlmTime.iWday = EVERYDAY;                  //每天准时闹铃
	tAlmTime.iHour = 10;			            //闹铃A时设置，如果不考虑小时则填0xFF
	tAlmTime.iMin  = 0;                         //闹铃A分设置，如果不考虑分时则填0xFF
	tAlmTime.iSec  = 5;			                //闹铃A秒设置，如果不考虑秒则填0xFF			
	tAlmTime.iPm   = RTC_AM;                    //闹铃A上午、下午位设置，12H制有效，24H该位无效	
	csi_rtc_set_alarm(RTC, RTC_ALMA,&tAlmTime);	//设置闹钟A	
	
	
	/*** 闹铃B设置 ***/
	tBlmTime.iWday = EVERYDAY;                  //每天准时闹铃
	tBlmTime.iHour = 10;                        //闹铃B时设置，如果不考虑小时则填0xFF
	tBlmTime.iMin  = 0;                         //闹铃B分设置，如果不考虑分则填0xFF
	tBlmTime.iSec  = 6;			                //闹铃B秒设置，如果不考虑秒则填0xFF			    
	tBlmTime.iPm   = RTC_AM;                    //闹铃B上午、下午位设置，12H制有效，24H该位无效	
	csi_rtc_set_alarm(RTC,RTC_ALMB,&tBlmTime);	//设置闹钟B	
	
	/*** RTC触发输出配置 ***/	
	csi_rtc_set_evtrg(RTC, RTC_TRGOUT0, RTC_TRGOUT_ALRMA, 0);  	//RTC TRGEV0 闹铃A到时产生trigger event
	csi_rtc_int_enable(RTC, RTC_INTSRC_TRGEV0);       			//使能TRGEV0中断
	csi_rtc_set_evtrg(RTC, RTC_TRGOUT1, RTC_TRGOUT_ALRMB, 0);  	//RTC TRGEV1 闹铃B到时产生trigger event
	csi_rtc_int_enable(RTC, RTC_INTSRC_TRGEV1);       			//使能TRGEV1中断
	
	/*** 触发目标事件BT0配置 ***/
	csi_pin_set_mux(PA015, PA015_BT0_OUT);					//PA015 作为BT0 PWM输出引脚
	tPwmCfg.byIdleLevel = BT_PWM_IDLE_HIGH;					//PWM 输出空闲电平
	tPwmCfg.byStartLevel= BT_PWM_START_HIGH;				//PWM 输出起始电平
	tPwmCfg.byDutyCycle = 50;								//PWM 输出占空比(0 < DutyCycle < 100)		
	tPwmCfg.wFreq 		= 1000;								//PWM 输出频率
	tPwmCfg.byInt		= BT_INTSRC_NONE;
	csi_bt_pwm_init(BT0, &tPwmCfg);							//初始化BT0 PWM输出
	csi_bt_set_sync(BT0, BT_TRG_SYNCIN0, BT_TRG_CONTINU, ENABLE);	//外部触发bt启动(SYNCIN0)
	
	/*** 触发目标事件BT1配置 ***/ 	
	csi_pin_set_mux(PA014, PA014_BT1_OUT);					//PA014 作为BT1 PWM输出引脚
	tPwmCfg.byIdleLevel = BT_PWM_IDLE_HIGH;					//PWM 输出空闲电平
	tPwmCfg.byStartLevel= BT_PWM_START_HIGH;				//PWM 输出起始电平
	tPwmCfg.byDutyCycle = 50;								//PWM 输出占空比(0 < DutyCycle < 100)		
	tPwmCfg.wFreq 		= 1000;								//PWM 输出频率
	tPwmCfg.byInt		= BT_INTSRC_NONE;
	csi_bt_pwm_init(BT1, &tPwmCfg);							//初始化BT0 PWM输出
	csi_bt_set_sync(BT1, BT_TRG_SYNCIN0, BT_TRG_CONTINU, ENABLE);	//外部触发bt启动(SYNCIN0)
	
	csi_etb_init();								    //ETCB 初始化
	
	/*** ETCB0配置 ***/
	tEtbConfig1.byChType = ETB_ONE_TRG_ONE;  		//单个源触发单个目标
	tEtbConfig1.bySrcIp  = ETB_RTC_TRGOUT0 ;  	    //RTC_SYNC0 触发输出0作为触发源
	tEtbConfig1.bySrcIp1 = 0xff;      
	tEtbConfig1.bySrcIp2 = 0xff;
	tEtbConfig1.byDstIp  = ETB_BT0_SYNCIN0;   	    //BT0 同步输入作为目标事件
	tEtbConfig1.byDstIp1 = 0xff;
	tEtbConfig1.byDstIp2 = 0xff;
	tEtbConfig1.byTrgMode = ETB_HARDWARE_TRG;       //硬件触发
	ch = csi_etb_ch_alloc(tEtbConfig1.byChType);	//自动获取空闲通道号,ch >= 0 获取成功
	csi_etb_ch_config(ch,&tEtbConfig1);
	
	/*** ETCB1配置 ***/
	tEtbConfig2.byChType = ETB_ONE_TRG_ONE;  		//单个源触发单个目标
	tEtbConfig2.bySrcIp  = ETB_RTC_TRGOUT1 ;  	    //RTC_SYNC0 触发输出0作为触发源
	tEtbConfig2.bySrcIp1 = 0xff;      
	tEtbConfig2.bySrcIp2 = 0xff;
	tEtbConfig2.byDstIp  = ETB_BT1_SYNCIN0;   	    //BT1 同步输入作为目标事件
	tEtbConfig2.byDstIp1 = 0xff;
	tEtbConfig2.byDstIp2 = 0xff;
	tEtbConfig2.byTrgMode = ETB_HARDWARE_TRG;       //硬件触发
	ch = csi_etb_ch_alloc(tEtbConfig2.byChType);	//自动获取空闲通道号,ch >= 0 获取成功
	csi_etb_ch_config(ch,&tEtbConfig2);
	
	
	while(1)
	{
		csi_rtc_get_time(RTC,  &tRtcTimeRdbk);      //读RTC时间
		if(wSec != tRtcTimeRdbk.iSec )              //1s打印一次
		{
			wSec = tRtcTimeRdbk.iSec;
			my_printf("20%d.%d.%d  %d:%d:%d pm= %d\n",tRtcTimeRdbk.iYear,tRtcTimeRdbk.iMon,tRtcTimeRdbk.iMday, tRtcTimeRdbk.iHour, tRtcTimeRdbk.iMin, tRtcTimeRdbk.iSec, tRtcTimeRdbk.iPm);
		}
		
		if(csi_rtc_get_int_msg(RTC_INTSRC_TRGEV0,1)) //判断闹铃B中断信息是否产生，并且清除中断信息标志位
		{
			my_printf("RTC TRGEV0 has triggered!!\n");
		}
		if(csi_rtc_get_int_msg(RTC_INTSRC_TRGEV1,1)) //判断闹铃B中断信息是否产生，并且清除中断信息标志位
		{
			my_printf("RTC TRGEV1 has triggered!!\n");
		}
	}
 }