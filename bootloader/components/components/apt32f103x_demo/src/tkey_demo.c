/***********************************************************************//** 
 * \file  tkey_demo.c
 * \brief TKEY_DEMO description and static inline functions at register level 
 * \copyright Copyright (C) 2020-2025 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2023-8-1 <td>V0.9  <td>XB     <td>initial
 * </table>
 * *********************************************************************
*/
/* Includes ---------------------------------------------------------------*/
#include <string.h>
#include <drv/tkey.h>
#include <drv/pin.h>
#include <drv/uart.h>
#include <drv/gpio.h>
#include <drv/bt.h>
#include <iostring.h>
#include "demo.h"

/* externs function--------------------------------------------------------*/
	
/* externs variablesr------------------------------------------------------*/
/* Private macro-----------------------------------------------------------*/
/* Private variablesr------------------------------------------------------*/
void uart_init(void)
{
	csi_uart_config_t tUartConfig;				//UART1 参数配置结构体	
	csi_pin_set_mux(PA014, PA014_UART1_TX);		//UART1 TX管脚配置
	tUartConfig.byParity = UART_PARITY_NONE;		//校验位，奇校验
	tUartConfig.wBaudRate = 115200;				//波特率，115200
	tUartConfig.wInt = UART_INTSRC_NONE;		//无中断
	tUartConfig.byTxMode = UART_TX_MODE_POLL;	//发送 轮询模式
	tUartConfig.byRxMode = UART_RX_MODE_POLL;	//接收 轮询模式
	
	csi_uart_init(UART1, &tUartConfig);			//初始化串口
	csi_uart_start(UART1,UART_FUNC_TX);			//打开串口
}

void tkey_uart_serialplot(void)
{
	csi_uart_putc(UART1, 0X0D);
	csi_uart_putc(UART1, 0X0A);
	for(int i =0;i<16;i++)
	{
		csi_uart_putc(UART1, (hwSampling_data0[i]>>8));
		csi_uart_putc(UART1, (hwSampling_data0[i]&0xff));
		
		csi_uart_putc(UART1, (hwBaseline_data0[i]>>8));
		csi_uart_putc(UART1, (hwBaseline_data0[i]&0xff));
	}

}

void csi_tkey_config(void)
{
	tkey_init();
	csi_bt_timer_init(BT2, 10000);		//初始化BT2, 定时10ms; BT2定时用作Tkey基准时钟
	csi_bt_start(BT2);					//启动定时器
}

/*
 * 操作步骤
 * ① 右键chip组件，选择ptions for "XXX"选项
 * ② linker选项卡界面，Library Name输入对应的库名称，如:_103tkey_f_0_90.a，版本说明请参考csi使用文档的相关章节
 * ③ Library Path后面输入路径：drivers
 * 然后在sdk_110x->apt32f110x_chip->drivers->tkey_parameter.c里配置相关的参数，配置说明请参考csi使用文档的相关章节
 */
 
 
/*
 * 库版本说明  注意！！！目前只有默认版本，其他版本后续补上！！！！！！！！！
 * 
 * 
 * lib_103tkey_f_X_XX：跳频版本，Touch使用中断处理，占用更多的SRAM及程序空间，抗干扰能力最强
 * lib_103tkey_c_X_XX：默认版本，Touch使用中断处理，SRAM及程序占用空间更小，速度更快，抗干扰性能稍低
 * lib_103tkey_mc_X_XX：主循环版本，使用Touch需要调用tkey_main_prog();函数，扫描时间更长，完全不占用中断，按键越多扫描时间越长，按键速度也会越慢
 * lib_103tkey_dma_X_XX：TOUCH->DMA版本，使用DMA模块传递touch采样数据，不使用touch中断，速度最快，占用最多的SRAM，使用此版本后不再允许配置DMA3
*/


/* *******************    库的使用说明      ****************************
①f_X_XX 和 c_X_XX版本：

	需要在bt2_int_handler中断里调用tkey_basecnt_process()函数，在tkey_int_handler中断里调用tkey_int_process()函数
	（调用tkey_basecnt_process()函数，占用时间时间如果影响到bt2_int_handler的运行的话，也可以配置别的定时器中断去调用该函数，
	建议进中断的时间控制在10ms左右，调用见隔越小，TKEY反应越灵敏），在bt2_int_handler的示例如下：
	void bt2_int_handler(void) 
	{
	#if	BT2_INT_HANDLE_EN
		// ISR content ...
		tkey_basecnt_process();
		bt_irqhandler(BT2);
		
	#endif
	}
	
	void tkey_int_handler(void) 
	{
	#if	TKEY_INT_HANDLE_EN
		// ISR content ...
		tkey_int_process();
	#endif
	}
②dma_X_XX版本：
    只需要在bt2_int_handler中断里调用tkey_basecnt_process()函数，tkey_int_handler中断里不需要调用相关函数。
 
③mc_X_XX版本：

   只需要在主循环调用csi_tkey_main_prog();定时器中断和TKEY中断函数里不需要调用任何函数

 
所有版本的使用除了调用函数的地方不一样和需要调用的函数不一样，其他处理机制都是一样的。


*/

void tkey_demo(void)
{
	
	csi_tkey_config();
	uart_init();
	csi_pin_set_mux(PA015,PA015_OUTPUT);//LED
	csi_pin_set_low(PA015);
	while(1)
	{
		//tkey_uart_serialplot();//串口打样采样值函数
		if(dwKey_Map!=0)		//处理按键结果，如果有按键按下，点亮LED灯
		{
			csi_pin_set_low(PA015);
		}
		else csi_pin_set_high(PA015);
	}
	
}