/***********************************************************************//** 
 * \file  tkey.c
 * \brief TKEY description and static inline functions at register level 
 * \copyright Copyright (C) 2015-2022 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2021-1-4 <td>V0.0  <td>ASM AE Team   <td>initial
 * </table>
 * *********************************************************************
*/  

#ifndef _CSP_TKEY_H
#define _CSP_TKEY_H

#include <stdint.h>
#include <sys_clk.h>


#define TKEY_RESET_VALUE  	(0x00000000)


/**
@brief TKEY  bits Structure
*/
typedef volatile struct
{
   __IOM uint32_t   TCH_IDR;               /* Control Register */
   __IOM uint32_t   TCH_CCR;               /* Control Register */
   __IOM uint32_t   TCH_CON0;               /* Control Register */
   __IOM uint32_t   TCH_CON1;               /* Control Register */
   __IOM uint32_t   TCH_RSSR;               /* Hardmacro control    */
   __IOM uint32_t   TCH_THR;            /* Sensing target value */
   __IOM uint32_t   TCH_SCVAL;            /* Sensing counter value*/
   __IOM uint32_t   TCH_TKST;            /* Reference counter value*/
   __IOM uint32_t   TCH_CHINF;                /* Match Status           */
   __IOM uint32_t   TCH_RISR;				
   __IOM uint32_t   TCH_MISR;               /* Interrupt Enable       */
   __IOM uint32_t   TCH_IMCR;               /* Interrupt Clear        */
   __IOM uint32_t   TCH_ICR;            /* Sensing target value */
   __IOM uint32_t   Reserved0[1011];
   __IOM uint32_t   TCH_DAT[32];          /* Reference value capture value */
   __IOM uint32_t   Reserved1[992];
   __IOM uint32_t   TCH_SEQxCON[32];         /* SEQ Hardmacro control  */
}csp_tkey_t; 

/***********************************************************
  * @brief  tkey clock control register
  *********************************************************/
typedef enum
{
    TK_CLK_EN = 1<<0,
	TK_CLK_DIS = 0<<0,
}TK_CLK_TypeDef;

typedef enum
{
    TK_DCHCKSEL_REFCLK  = 0<<3,
	TK_DCHCKSEL_PCLK = 1<<3,
}TK_DCHCKSEL_TypeDef;

#define TK_PCKDIV(n) ((n&0xf)<<4)

typedef enum
{
    TK_DCHCKDIV_2 = 0<<8,
	TK_DCHCKDIV_4 = 1<<8,
	TK_DCHCKDIV_6 = 2<<8,
	TK_DCHCKDIV_8 = 3<<8,
}TK_DCHCKDIV_TypeDef;

typedef enum
{
    TK_ALDTRIM_EN  = 1<<15,
	TK_ALDTRIM_DIS = 0<<15,
}TK_ALDTRIM_TypeDef;

typedef enum
{
    TK_TRMTARSEL_TRIM  = 0<<16,
	TK_TRMTARSEL_FSEL = 1<<16,
}TK_TRMTARSEL_TypeDef;
#define TK_TRIMCONFIG0(n) ((n&0x1f)<<17)
#define TK_TRIMCONFIG1(n) ((n&0x1f)<<22)
#define TK_TRIMCONFIG2(n) ((n&0x1f)<<27)

/***********************************************************************
  * @brief  tkey General Control Register 0
  **********************************************************************/
typedef enum
{
    TK_HM_EN = 1<<0,
	TK_HM_DIS = 0<<0,
}TK_HMEN_TypeDef;

typedef enum
{
    TK_MODE_SINGLE  = 0<<1,
	TK_MODE_SEQ = 1<<1,
}TK_MODE_TypeDef;

#define TK_SEQLEN(n) (((n-1)&0x1f)<<2)

typedef enum
{
    TK_ECLVL_1V = 0<<7,
	TK_ECLVL_2V = 1<<7,
	TK_ECLVL_3V = 2<<7,
	TK_ECLVL_3V6 = 3<<7,
}TK_ECLVL_TypeDef;

typedef enum
{
    TK_SCTIMLMT_5ms = 0<<9,
	TK_SCTIMLMT_10ms = 1<<9,
	TK_SCTIMLMT_50ms = 2<<9,
	TK_SCTIMLMT_100ms = 3<<9,
}TK_SCTIMLMT_TypeDef;

typedef enum
{
    TK_SCTLIM_EN = 0<<11,
	TK_SCTLIM_DIS = 1<<11,
}TK_SCTLIM_TypeDef;

typedef enum
{
    TK_INTVTIM_None = 0<<12,
	TK_INTVTIM_16ms = 1<<12,
	TK_INTVTIM_32ms = 2<<12,
	TK_INTVTIM_64ms = 3<<12,
	TK_INTVTIM_128ms = 4<<12,
	TK_INTVTIM_186ms = 5<<12,
}TK_INTVTIM_TypeDef;

typedef enum
{
    TK_PWRSRC_FVR = 0<<15,
	TK_PWRSRC_AVDD = 1<<15,
}TK_PWRSRC_TypeDef;

typedef enum
{
    TK_INTREN_EN = 1<<16,
	TK_INTREN_DIS = 0<<16,
}TK_INTREN_TypeDef;

typedef enum
{
    TK_STBLCNT_4 = 0<<17,
	TK_STBLCNT_8 = 1<<17,
	TK_STBLCNT_12 = 2<<17,
	TK_STBLCNT_16 = 3<<17,
}TK_STBLCNT_TypeDef;

typedef enum
{
    TK_CYCSCNT_EN = 1<<19,
	TK_CYCSCNT_DIS = 0<<19,
}TK_CYCSCNT_TypeDef;

typedef enum
{
    TK_STPATDSL_EN = 0<<20,
	TK_STPATDSL_DIS = 1<<20,
}TK_STPATDSL_TypeDef;




/**********************************************************************
  * @brief  tkey General Control Register 1
  **********************************************************************/
  
typedef enum
{
    TK_DST_Z = 0<<0,
	TK_DST_HIGH = 1<<0,
	TK_DST_LOW = 2<<0,
}TK_DST_TypeDef;


typedef enum
{
    TK_DBGSDO_EN = 1<<4,
	TK_DBGSDO_DIS = 0<<4,
}TK_DBGSDO_TypeDef;


typedef enum
{
    TK_DBGDLEN_16bit = 0<<5,
	TK_DBGDLEN_24bit = 1<<5,
}TK_DBGDLEN_TypeDef;


typedef enum
{
    TK_DBGDOCKDIV_2 = 0<<6,
	TK_DBGDOCKDIV_4 = 1<<6,
	TK_DBGDOCKDIV_8 = 2<<6,
	TK_DBGDOCKDIV_16 = 3<<6,
}TK_DBGDOCKDIV_TypeDef;

typedef enum
{
    TK_PHS_SHFT_SEQ_0 = 0<<20,
	TK_PHS_SHFT_SEQ_2 = 1<<20,
	TK_PHS_SHFT_SEQ_3 = 2<<20,
	TK_PHS_SHFT_SEQ_4 = 3<<20,
	TK_PHS_SHFT_SEQ_5 = 4<<20,
	TK_PHS_SHFT_SEQ_6 = 5<<20,
	TK_PHS_SHFT_SEQ_7 = 6<<20,
	TK_PHS_SHFT_SEQ_8 = 7<<20,
}TK_PHS_SHFT_SEQ_TypeDef;

#define TK_SHFT_STEP(n) ((n&0xff)<<24)

/**********************************************************************
  * @brief  tkey Restart Start Control Register
  **********************************************************************/

#define TK_START 0X1
#define TK_STOP 0X0
#define TK_SRR (0X5<<12)

/**********************************************************************
  * @brief  tkey Threshold Register Register
  **********************************************************************/

typedef enum
{
    TK_THRSEL_CMP_BIT_23_4 = 0<<0,	//阈值 16
	TK_THRSEL_CMP_BIT_23_5 = 1<<0,	//阈值 32
	TK_THRSEL_CMP_BIT_23_6 = 2<<0,	//阈值 64
	TK_THRSEL_CMP_BIT_23_7 = 3<<0,  //阈值 128
	TK_THRSEL_CMP_BIT_23_8 = 4<<0,  //阈值 256
	TK_THRSEL_CMP_BIT_23_9 = 5<<0,  //阈值 512
	TK_THRSEL_CMP_BIT_23_10 = 6<<0, //阈值 1024
	TK_THRSEL_CMP_BIT_23_11 = 7<<0, //阈值 2048
}TK_THRSEL_TypeDef;

typedef enum
{
    TK_THRSET_16   = 0<<0,	//阈值 16
	TK_THRSET_32   = 1<<0,	//阈值 32
	TK_THRSET_64   = 2<<0,	//阈值 64
	TK_THRSET_128  = 3<<0,  //阈值 128
	TK_THRSET_256  = 4<<0,  //阈值 256
	TK_THRSET_512  = 5<<0,  //阈值 512
	TK_THRSET_1024 = 6<<0, //阈值 1024
	TK_THRSET_2048 = 7<<0, //阈值 2048
}TK_THRSET_TypeDef;

typedef enum
{
	TK_THR_EN = 1<<8,
	TK_THR_DIS = 0<<8,
}TK_THREN_TypeDef;

/**********************************************************************
  * @brief   tkey State Register
  **********************************************************************/

#define TK_BUSY (0X1<<12)

/**********************************************************************
  * @brief   tkey Interrupt Register
  **********************************************************************/

#define TK_SEQ_DNE	(0x01ul << 0)
#define TK_CH_DNE	(0x01ul << 1)
#define TK_CH_ERR	(0x01ul << 2)
#define TK_TIMOVF	(0x01ul << 3)
#define TK_REFOVF	(0x01ul << 4)
#define TK_THROVR	(0x01ul << 5)



#endif		
