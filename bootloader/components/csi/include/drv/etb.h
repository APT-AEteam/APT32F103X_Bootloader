/***********************************************************************//** 
 * \file  lpt.c
 * \brief  csi lpt driver
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2017-10-27<td>V0.0 <td>Alibaba <td> initial
 * <tr><td> 2021-1-8  <td>V0.1 <td>WNN     <td> SWTRG
 * <tr><td> 2021-5-14 <td>V0.1 <td>ZJY     <td> initial
 * </table>
 * *********************************************************************
*/
#ifndef _DRV_ETB_H_
#define _DRV_ETB_H_

#include "csp.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \enum     csi_etb_trig_mode_e
 * \brief    ETB channel trigger mode
 */
typedef enum {
    ETB_HARDWARE_TRG  	= 0,	//etb channel inout is hardware trigger.
    ETB_SOFTWARE_TRG            //etb channel inout is software trigger.
} csi_etb_trg_mode_e;

/**
 * \enum     csi_etb_ch_type_e
 * \brief    ETB channel trigger type
 */
typedef enum {
    ETB_ONE_TRG_ONE	= 0,     	//one device trig one deivce, 3~31channel
    ETB_ONE_TRG_MORE,         	//one device trig two for more device, 1~2channel
    ETB_MORE_TRG_ONE,         	//two or more device trig one deivce, 0 channel
	ETB_ONE_TRG_ONE_DMA       	//one device trig one deivce of dma, 20->31channel
} csi_etb_ch_type_e;

/**
 * \enum     csi_etb_ch_e
 * \brief    ETB channel id(number 0~31)
 */
typedef enum {
    ETB_CH0			= 0,		//etb channel 0 id number
	ETB_CH1,					//etb channel 1 id number
	ETB_CH2,					//etb channel 2 id number
	ETB_CH3,					//etb channel 3 id number
	ETB_CH4,
	ETB_CH5,
	ETB_CH6,
	ETB_CH7,
	ETB_CH8,					//DMA channel 			
	ETB_CH9,					//DMA channel						
	ETB_CH10,					//DMA channel							
	ETB_CH11					//DMA channel						
} csi_etb_ch_e;

/**
 * \enum     csi_etb_src_e
 * \brief    ETB event source
 */
typedef enum{
	ETB_LPT_TRGOUT0 	= 0,
	ETB_EXI_TRGOUT0 	= 4,
	ETB_EXI_TRGOUT1,
	ETB_EXI_TRGOUT2,	
	ETB_EXI_TRGOUT3,
	ETB_EXI_TRGOUT4,	
	ETB_EXI_TRGOUT5,
	ETB_RTC_TRGOUT0,
	ETB_RTC_TRGOUT1,
	ETB_BT0_TRGOUT,
	ETB_BT1_TRGOUT,
	ETB_ETP0_TRGOUT0 	= 16,
	ETB_ETP0_TRGOUT1,
	ETB_ETP0_TRGOUT2,
	ETB_ETP0_TRGOUT3,
	ETB_SIO0_TXSRC 	    = 28,
	ETB_SIO0_RXSRC,	
	ETB_GPTA0_TRGOUT0 	= 32,
	ETB_GPTA0_TRGOUT1,	
	ETB_I2C0_TXSRC 		= 36,
	ETB_I2C0_RXSRC,
	ETB_SPI0_TXSRC 		= 40,
	ETB_SPI0_RXSRC,	
	ETB_ADC_TRGOUT0 	= 48,
	ETB_ADC_TRGOUT1,
	ETB_UART0_TXSRC 	= 52,
	ETB_UART0_RXSRC,
	ETB_UART1_TXSRC,
	ETB_UART1_RXSRC,
	ETB_UART2_TXSRC,
	ETB_UART2_RXSRC,
	ETB_USART0_TXSRC,
	ETB_USART0_RXSRC,	
	ETB_TOUCH_TRGOUT,

	ETB_SRC_NOT_USE 		= 0xff
}csi_etb_src_e;

/**
 * \enum     csi_etb_dst_e
 * \brief    ETB description event 
 */
typedef enum{
	ETB_LPT_SYNCIN0 	= 0,
	ETB_BT0_SYNCIN0 	= 2,
	ETB_BT0_SYNCIN1,
	ETB_BT0_SYNCIN2,
	ETB_ADC_SYNCIN0		= 6,
	ETB_ADC_SYNCIN1,
	ETB_ADC_SYNCIN2,
	ETB_ADC_SYNCIN3,
	ETB_ADC_SYNCIN4,
	ETB_ADC_SYNCIN5,
	ETB_BT1_SYNCIN0,
	ETB_BT1_SYNCIN1,
	ETB_BT1_SYNCIN2,
	ETB_EPT0_SYNCIN0    = 16,
	ETB_EPT0_SYNCIN1,
	ETB_EPT0_SYNCIN2,
	ETB_EPT0_SYNCIN3,
	ETB_EPT0_SYNCIN4,
	ETB_EPT0_SYNCIN5,
	ETB_BT2_SYNCIN0    = 24,
	ETB_BT2_SYNCIN1,
	ETB_BT2_SYNCIN2,
	ETB_BT3_SYNCIN0    = 32,
	ETB_BT3_SYNCIN1,
	ETB_BT3_SYNCIN2,	
	ETB_GPTA0_SYNCIN0  = 36,
	ETB_GPTA0_SYNCIN1,
	ETB_GPTA0_SYNCIN2,
	ETB_GPTA0_SYNCIN3,
	ETB_GPTA0_SYNCIN4,
	ETB_GPTA0_SYNCIN5,
	ETB_DMA_CH0 		= 48,
	ETB_DMA_CH1,
	ETB_DMA_CH2,
	ETB_DMA_CH3,	
	ETB_DMA_CH4,
	ETB_DMA_CH5,
	ETB_TOUCH_SYNCIN 	= 60,

	ETB_DST_NOT_USE 		= 0xff
}csi_etb_dst_e;

typedef struct {
    uint8_t			bySrcIp;			//a specific number represent a location in an source trigger location map to trigger other ip(s).
	uint8_t         bySrcIp1; 
	uint8_t         bySrcIp2; 
    uint8_t         byDstIp;     		//a specific number represent an location in an dest trigger map to wait signal(s) from source ip(s) or location(s).
	uint8_t         byDstIp1;
	uint8_t         byDstIp2;  
    uint8_t    		byTrgMode;			//the input source is hardware trigger or software trigger.
    uint8_t     	byChType;    		//channel type
} csi_etb_config_t;

/**
  \brief       Init the etb device
  \return      none
*/
void csi_etb_init(void);

/**
  \brief       alloc an etb channel
  \param[in]   eChType		etb channel work mode
  \return      channel id or CSI_ERROR
*/
int32_t csi_etb_ch_alloc(csi_etb_ch_type_e eChType);

/**
  \brief       free an etb channel
  \param[in]   eEtbCh		etb channel number 
  \return      none
*/
void csi_etb_ch_free(csi_etb_ch_e eEtbCh);

/**
  \brief       config etb channel
  \param[in]   eEtbCh		etb channel number
  \param[in]   ptConfig     the config structure for etb channel
  \return      csi error code
*/
csi_error_t csi_etb_ch_config(csi_etb_ch_e eEtbCh, csi_etb_config_t *ptConfig);

/** 
  \brief 	   etb channel sw force triger
  \param[in]   eEtbCh		etb channel number
  \return 	   none
*/
void csi_etb_ch_swtrg(csi_etb_ch_e eEtbCh);

/**
  \brief       open(start) an etb channel
  \param[in]   eEtbCh      	etb channel number
  \return      none
*/
void csi_etb_ch_start(csi_etb_ch_e eEtbCh);

/**
  \brief       close(stop) an etb channel
  \param[in]   eEtbCh        etb channel number
  \return      none
*/
void csi_etb_ch_stop(csi_etb_ch_e eEtbCh);

#endif /* _CSI_ETB_H_ */
