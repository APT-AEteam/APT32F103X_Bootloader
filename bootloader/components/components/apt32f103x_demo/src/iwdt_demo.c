/***********************************************************************//** 
 * \file  iwdt_demo.c
 * \brief  IWDT_DEMO description and static inline functions at register level 
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2021-5-13 <td>V0.0 <td>ZJY    <td>initial
 * </table>
 * *********************************************************************
*/
/* Includes ---------------------------------------------------------------*/
#include <string.h>
#include <drv/iwdt.h>
#include <drv/pin.h>

#include "demo.h"
/* externs function--------------------------------------------------------*/
/* externs variablesr------------------------------------------------------*/
/* Private macro-----------------------------------------------------------*/
/* Private variablesr------------------------------------------------------*/

/** \brief 配置IWDT溢出时间为1024ms
 * 	     - 520ms之后喂狗，防止系统复位
 *  \param[in] none
 *  \return error code
 */
int iwdt_normal_demo(void)
{
	int iRet = 0;

	csi_iwdt_init(IWDT_TO_1024);			//初始化看门狗，溢出时间为1000ms(系统复位时间)
	csi_iwdt_open();						//打开看门狗
	//mdelay(500);							//延时500ms
	mdelay(520);
	csi_iwdt_feed();						//喂狗
	mdelay(500);
			
	return iRet;
}

/** \brief 配置iwdt溢出时间为1024ms
 * 			- 使能看门口报警中断
 * 			- 报警时间为：1024*2/8 =256ms
 *  \param[in] none
 *  \return error code
 */
int iwdt_irq_demo(void)
{
	int iRet = 0;

	csi_iwdt_init(IWDT_TO_1024);					//初始化看门狗，溢出时间为1000ms(系统复位时间)
	csi_iwdt_irq_enable(IWDT_ALARMTO_2_8, ENABLE);	//使能看门狗报警中断，报警时间为2/8溢出时间
	csi_iwdt_open();								//打开看门狗
	//mdelay(700);

	return iRet;
}