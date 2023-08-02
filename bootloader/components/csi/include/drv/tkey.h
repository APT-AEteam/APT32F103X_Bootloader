/***********************************************************************//** 
 * \file  tkey.h
 * \brief  csi tkey headfile
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2020-9-03 <td>V0.0  <td>XB   <td>initial
 * <tr><td> 2021-1-03 <td>V0.0  <td>ZJY   <td>modify
 * </table>
 * *********************************************************************
*/

#ifndef _DRV_TKEY_H_
#define _DRV_TKEY_H_

#include <stdint.h>
#include <stdbool.h>
#include <drv/common.h>
#include "csp.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TK_START 0X1
#define TK_STOP 0X0
#define TK_SRR (0X5<<12)
#define TK_PCKDIV(n) ((n&0xf)<<4)
#define TK_TRIMCONFIG0(n) ((n&0x1f)<<17)
#define TK_TRIMCONFIG1(n) ((n&0x1f)<<22)
#define TK_TRIMCONFIG2(n) ((n&0x1f)<<27)
#define TK_SHFT_STEP(n) ((n&0xff)<<24)
#define TCH_EN(val)   (0x01<<val)
#define TK_SEQLEN(n) (((n-1)&0x1f)<<2)
/***********************************************************************
 @brief  tkey status and int define
***********************************************************************/
#define TK_BUSY 	(0X1<<12)
#define TK_SEQ_DNE	(0x01ul << 0)
#define TK_CH_DNE	(0x01ul << 1)
#define TK_CH_ERR	(0x01ul << 2)
#define TK_TIMOVF	(0x01ul << 3)
#define TK_REFOVF	(0x01ul << 4)
#define TK_THROVR	(0x01ul << 5)
#define TK_FVR_2048V 0
#define	TK_FVR_4096V 1
#define TK_FVR_NONE  2

/***********************************************************************
 @brief  tkey Variable Definition extern
***********************************************************************/
extern volatile unsigned char  	byTkeyGlobalSens;
extern volatile unsigned char	byTkeyGlobalTrigger;
extern volatile unsigned char 	byTkeyGlobalIcon;	
extern volatile unsigned char 	byPressDebounce;		
extern volatile unsigned char 	byReleaseDebounce;	
extern volatile unsigned char 	byMultiTimesFilter;			
extern volatile unsigned char 	byValidKeyNum;				
extern volatile unsigned char 	byKeyMode;					
extern volatile unsigned char 	byBaseUpdateSpeed;
extern volatile unsigned char 	byTkeyRebuildTime;
extern volatile unsigned char 	byTkeyFineTurn;
extern volatile unsigned char 	byTkeyIcon[32];
extern volatile unsigned char 	byTkeyChxSens[32];		
extern volatile unsigned char	byTkeyChxTrigger[32];							
extern volatile unsigned char	byTkeyChxIcon[32];
extern volatile unsigned char   byTkeyWakeupLevel;
extern volatile unsigned char 	byTkeyLowPowerMode;
extern volatile unsigned char 	byTkeyLowPowerLevel;

extern volatile unsigned short  hwTkeyGlobalTrigger;
extern volatile unsigned short 	hwTkeyBaseCnt;	
extern volatile unsigned short 	hwTkeyEcLevel;
extern volatile unsigned short 	hwTkeyPselMode;		
extern volatile unsigned short 	hwTkeyFvrLevel;
extern volatile unsigned short 	hwTkeySenprd[32];
extern volatile unsigned short 	hwTkeyTriggerLevel[32];	

extern volatile unsigned long  	dwTkeyScanFreq;
extern volatile unsigned long  	dwTkeyIoEnable;	
extern volatile unsigned long  	dwTkeyWakeupIoEnable;

/***********************************************************************
 @brief  Tkey Hidden Variable Definition extern
***********************************************************************/
extern volatile unsigned char 	byTkeyDstStatus;		
//Used to modify the default state when TCHx is not enabled;0/3=Z,1=high,2=low(Default)
extern volatile unsigned char 	byTkeyIntrStatus;		
//Used to enable the default internal resistor of TCHx;0=disable(Default),1=enable
extern volatile unsigned char   byTkeyImtvtimTime;		
//Used to modify the scan interval;0=none(Default),1=16ms,2=32ms,3=64ms,4=128ms,>4=186ms
extern volatile unsigned char 	byAutoAdjustDis;		
//Used to enable or disable automatic TriggerLevel adjustment on the first pressd of each TCHx;1=disable,0=enable(Default)
extern volatile unsigned char 	byTkeyNegBuildBounce;	
//Used to modify the Bounce of the forced negative Rebuild;>=1 (Default=3)
//The higher the number, the longer it takes to trigger the update mechanism
extern volatile unsigned char 	byTkeyPosBuildBounce;
//Used to modify the Bounce of the forced postive Rebuild;>=1 (Default=3)
//The higher the number, the longer it takes to trigger the update mechanism
extern volatile unsigned char 	byTkeyTrim0;
extern volatile unsigned char 	byTkeyTrim1;
extern volatile unsigned char 	byTkeyTrim2;	
/*********************************************************************** 
 @brief  Tkey extern variable                  
***********************************************************************/
extern volatile unsigned long dwKey_Map;
extern volatile unsigned char byForceReBuild;
extern volatile unsigned short hwSampling_data0[32];
extern volatile unsigned short hwBaseline_data0[32];
extern volatile unsigned short hwSampling_data1[32];
extern volatile unsigned short hwBaseline_data1[32];
extern volatile unsigned short hwSampling_data2[32];
extern volatile unsigned short hwBaseline_data2[32];
extern volatile unsigned short hwOffset_data0_abs[32];
extern volatile unsigned short hwOffset_data1_abs[32];
extern volatile unsigned short hwOffset_data2_abs[32];
/*********************************************************************** 
 @brief  Tkey extern functions                  
***********************************************************************/ 
extern void tkey_sampling_prog(void);
extern void	tkey_keymap_prog(void);
extern void	tkey_baseline_tracking(void);
extern void	tkey_result_prog(void);
extern void	tkey_trigger_auto_adjust(void);
extern void tkey_error_detect(void);
extern void tkey_baseline_prog(void);
extern void tkey_init(void);
extern void tkey_main_prog(void);
extern void tkey_basecnt_process(void); 
extern void tkey_basecnt_process(void); 
extern void tkey_parameter_init(void);
extern void tkey_int_process(void);
#ifdef __cplusplus
}
#endif

#endif /* _DRV_tkey_H_ */