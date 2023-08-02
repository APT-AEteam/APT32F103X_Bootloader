/***********************************************************************//** 
 * \file  iic_demo.c
 * \brief IIC_DEMO description and static inline functions at register level 
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2021-6-7 <td>V0.0  <td>XB     <td>initial
 * </table>
 * *********************************************************************
*/
/* Includes ---------------------------------------------------------------*/
#include "csp.h"
#include "iic.h"
#include "irq.h"
#include "pin.h"
#include "demo.h"


csi_iic_master_config_t  tIicMasterCfg;	//主机初始化结构体变量
csi_iic_slave_config_t  tIicSlaveCfg;	//从机初始化结构体变量

volatile uint8_t bySendBuffer[32]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
volatile uint8_t byWriteBuffer[32];

/** \brief 	该例程为主机读写AT24C04的EEPROM的示例，因AT24C04每次写入的数据不能超过16byte
	        请使用时注意写的长度。不同的EEPROM会有不同的写入长度限制，请参考相应的数据手册
 *  \param[in] none
 *  \return none
 */
void iic_master_demo(void)
{
	volatile uint8_t data[9] = {1,2,3,4,5,6,7,8,9};
	volatile uint8_t data1[9] = {0};
	
	csi_pin_output_mode(PA03,GPIO_OPEN_DRAIN); 
	csi_pin_output_mode(PA04,GPIO_OPEN_DRAIN);
	csi_pin_pull_mode(PA03, GPIO_PULLUP);
	csi_pin_pull_mode(PA04, GPIO_PULLUP);
	
	csi_pin_set_mux(PA03,PA03_I2C_SDA);//PIN4 ->	I2C_SDA
	csi_pin_set_mux(PA04,PA04_I2C_SCL);//PIN5 -> 	I2C_SCL
	
	tIicMasterCfg.byAddrMode = IIC_ADDRESS_7BIT;			//设置主机地址模式 7/10 bit
	tIicMasterCfg.byReStart = ENABLE;						//使能重复起始位
	tIicMasterCfg.bySpeedMode = IIC_BUS_SPEED_FAST;	//设置主机速度模式	IIC_BUS_SPEED_STANDARD <=100kHz   IIC_BUS_SPEED_FAST <=400kHz    IIC_BUS_SPEED_FAST_PLUS <=  1MHz
	tIicMasterCfg.hwInt = IIC_INTSRC_NONE;					//使能需要的中断
	tIicMasterCfg.wSdaTimeout = 0XFFFF;						//SDA 超时时间设置，  1/主频 * tIicMasterCfg.wSdaTimeout  ms
	tIicMasterCfg.wSclTimeout = 0XFFFF;						//SCL 超时时间设置，  1/主频 * tIicMasterCfg.wSdaTimeout  ms
	csi_iic_master_init(I2C0,&tIicMasterCfg);				//主机初始化
	
//	csp_i2c_set_fs_sclh(I2C0,10);
//	csp_i2c_set_fs_scll(I2C0,10);
	
//	csp_i2c_set_ss_sclh(I2C0,50);  
//	csp_i2c_set_ss_scll(I2C0,50);

//	csp_i2c_sda_setup(I2C0,0x2);
//	csp_i2c_sda_hold(I2C0,0xf,0xf);

	//该例程为主机读写AT24C04的EEPROM的示例，因AT24C04每次写入的数据不能超过16byte
	//请使用时注意写的长度。不同的EEPROM会有不同的写入长度限制，请参考相应的数据手册
	while(1)
	{
		csi_iic_write_nbyte(I2C0,0xa0,0x01,2,&data[0],9);
		mdelay(100);
		csi_iic_read_nbyte(I2C0,0xa0,0x01,2,&data1[0],9);
		mdelay(100);
	}
}

/** \brief I2C主机示例代码
 *   		- iic master write 9 byte data
 *     		- iic master read 9 byte data
 *  \param[in] none
 *  \return none
 */

void iic_master_slave_demo(void)
{
	volatile uint8_t data[13] = {4,6,3,4,5,6,7,8,9,10,11,12,13};
	volatile uint8_t data1[19] = {4,4,4,4,4,4,4,4,4};
	
	csi_pin_output_mode(PA03,GPIO_OPEN_DRAIN); 
	csi_pin_output_mode(PA04,GPIO_OPEN_DRAIN);
	csi_pin_pull_mode(PA03, GPIO_PULLUP);
	csi_pin_pull_mode(PA04, GPIO_PULLUP);
	
	csi_pin_set_mux(PA03,PA03_I2C_SDA);//PIN4 ->	I2C_SDA
	csi_pin_set_mux(PA04,PA04_I2C_SCL);//PIN5 -> 	I2C_SCL

	tIicMasterCfg.byAddrMode = IIC_ADDRESS_7BIT;			//设置主机地址模式 7/10 bit
	tIicMasterCfg.byReStart =ENABLE;						//使能重复起始位
	tIicMasterCfg.bySpeedMode = IIC_BUS_SPEED_STANDARD;	//设置主机速度模式	IIC_BUS_SPEED_STANDARD <=100kHz   IIC_BUS_SPEED_FAST <=400kHz    IIC_BUS_SPEED_FAST_PLUS <=  1MHz
	tIicMasterCfg.hwInt = IIC_INTSRC_RX_DONE;					//使能需要的中断IIC_INTSRC_RX_UNDER|IIC_INTSRC_RX_DONE
	tIicMasterCfg.wSdaTimeout = 0XFFFF;						//SDA 超时时间设置，  1/主频 * tIicMasterCfg.wSdaTimeout  ms
	tIicMasterCfg.wSclTimeout = 0XFFFF;						//SCL 超时时间设置，  1/主频 * tIicMasterCfg.wSdaTimeout  ms
	csi_iic_master_init(I2C0,&tIicMasterCfg);				//主机初始化

	while(1)
	{
		
		for(int i = 0;i!=19;i++)
		{
			data1[i] = 0;
		}
		
		csi_iic_write_nbyte(I2C0,0xa0,0x02,1,&data[0],9);   
		mdelay(100);
		csi_iic_read_nbyte(I2C0,0xa0,0x02,1,&data1[0],9);
	}
		
}

/** \brief I2C从机示例代码
 *  作为从机时需要在IIC中断里调用 i2c_irqhandler(I2C0) 函数；
 * 	如下：
 *	void i2c_int_handler(void) 
 *	{
 *		// ISR content ...
 *		i2c_irqhandler(I2C0);
 *	}
 *  \param[in] none
 *  \return none
 */
void iic_slave_demo(void)
{
	csi_pin_output_mode(PA03,GPIO_OPEN_DRAIN); 
	csi_pin_output_mode(PA04,GPIO_OPEN_DRAIN);
	csi_pin_pull_mode(PA03, GPIO_PULLUP);
	csi_pin_pull_mode(PA04, GPIO_PULLUP);
	
	csi_pin_set_mux(PA03,PA03_I2C_SDA);//PIN4 ->	I2C_SDA
	csi_pin_set_mux(PA04,PA04_I2C_SCL);//PIN5 -> 	I2C_SCL
	
	tIicSlaveCfg.byAddrMode = IIC_ADDRESS_7BIT;		//设置从机地址模式 
	tIicSlaveCfg.bySpeedMode = IIC_BUS_SPEED_STANDARD;	//设置从机速度	IIC_BUS_SPEED_STANDARD <=100kHz   IIC_BUS_SPEED_FAST <=400kHz    IIC_BUS_SPEED_FAST_PLUS <=  1MHz
	tIicSlaveCfg.hwSlaveAddr = 0xa0;				//设置从机地址
	tIicSlaveCfg.hwInt = IIC_INTSRC_SCL_SLOW | IIC_INTSRC_STOP_DET | 
					IIC_INTSRC_RD_REQ | IIC_INTSRC_RX_FULL | IIC_INTSRC_TX_ABRT; //使能相应中断
	csi_iic_set_slave_buffer(byWriteBuffer,32,bySendBuffer,32); //从机就是数组和发送数组设置
	tIicMasterCfg.wSdaTimeout = 0XFFFF;						//SDA 超时时间设置，  1/主频 * tIicMasterCfg.wSdaTimeout  ms
	tIicMasterCfg.wSclTimeout = 0XFFFF;						//SCL 超时时间设置，  1/主频 * tIicMasterCfg.wSdaTimeout  ms
	csi_iic_slave_init(I2C0,&tIicSlaveCfg);		//初始化从机


	while(1);
	
}

