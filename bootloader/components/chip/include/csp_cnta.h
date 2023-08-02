/***********************************************************************//** 
 * \file  csp_cnta.h
 * \brief CNTA description and static inline functions at register level 
 * \copyright Copyright (C) 2015-2021 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version   <th>Author  <th>Description
 * <tr><td> 2020-9-10 <td>V0.0  <td>ZJY     <td>initial
 * <tr><td> 2021-1-9 <td>V0.1   <td>ZJY     <td>modify
 * <tr><td> 2021-11-23 <td>V0.2  <td>LQ      <td>modify
 * </table>
 * *********************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _CSP_CNTA_H
#define _CSP_CNTA_H

/* Includes ------------------------------------------------------------------*/
#include <soc.h>

/// \struct csp_adc_t
/// \brief SPI reg description   
typedef struct
{
	__IOM uint32_t      CADATAH;        /**< DATA High Register        */
    __IOM uint32_t      CADATAL;        /**< DATA Low Register         */
    __IOM uint32_t      CACON;          /**< Control Register          */
    __IOM uint32_t      INTMASK;        /**< Interrupt Mask CR         */
} csp_cnta_t ;  

/*****************************************************************************
************************** ssp Function defined *****************************
******************************************************************************/
#define	CNTA_RESET_VALUE	(0x00000000)

/******************************************************************************
* CADATAH : Cnta Output High Level Length Register 
******************************************************************************/
#define	ICNTA_CADATAH_POS	(0)
#define	ICNTA_CADATAH_MSK	(0xFFFFul << ICNTA_CADATAH_POS)

/******************************************************************************
* CADATAL : Cnta Output Low Level Length Register 
******************************************************************************/
#define	ICNTA_CADATAL_POS	(0)
#define	ICNTA_CADATAL_MSK	(0xFFFFul << ICNTA_CADATAL_POS)

/******************************************************************************
* CACON : Cnta Control Register 
******************************************************************************/
#define	CNTA_OSP_POS		(0)		
#define	CNTA_OSP_MSK		(0x01ul << CNTA_OSP_POS)
typedef enum
{
	CNTA_OSP_LOW		= 0,
	CNTA_OSP_HIGH        
}cnta_osp_e;

#define	CNTA_MODE_POS		(1)		
#define	CNTA_MODE_MSK		(0x01ul << CNTA_MODE_POS)
typedef enum
{
	CNTA_ONCE_MODE		= 0,
	CNTA_REPEAT_MODE          
}cnta_mode_e;

#define	CNTA_START_POS		(2)
#define	CNTA_START_MSK		(0x01ul << CNTA_START_POS)
#define	CNTA_START			(0x01ul)

#define	CNTA_STOP_POS		(3)
#define	CNTA_STOP_MSK		(0x01ul << CNTA_STOP_POS)
#define	CNTA_STOP			(0x01ul)

#define	CNTA_CKDIV_POS		(4)		
#define	CNTA_CKDIV_MSK		(0x03ul << CNTA_CKDIV_POS)
typedef enum
{
	CNTA_CK_DIV1		= 0,
	CNTA_CK_DIV2, 
	CNTA_CK_DIV4,  
	CNTA_CK_DIV8  
}cnta_ckdiv_e;

#define	CNTA_SW_STROBE_POS	(16)		
#define	CNTA_SW_STROBE_MSK	(0x01ul << CNTA_SW_STROBE_POS)
#define	CNTA_SW_STROBE		(0x01ul)

#define	CNTA_HW_STROBE_POS	(17)		
#define	CNTA_HW_STROBE_MSK	(0x03ul << CNTA_HW_STROBE_POS)
typedef enum
{
	CNTA_HW_STROBE_DIS = 0,
	CNTA_HW_STROBE_MATCH , 
	CNTA_HW_STROBE_PEND ,
	CNTA_HW_STROBE_MATCH_PEND	
}cnta_hwstrobe_e;

#define	CNTA_MATCH_REM_POS	(19)		
#define	CNTA_MATCH_REM_MSK	(0x03ul << CNTA_MATCH_REM_POS)
typedef enum
{
	CNTA_MATCHREM_OFF	= 0,
	CNTA_MATCHREM_CLR, 
	CNTA_MATCHREM_SET       
}cnta_matchrem_e;

#define	CNTA_PEND_REM_POS	(21)		
#define CNTA_PEND_REM_MSK	(0x03ul << CNTA_PEND_REM_POS)
typedef enum
{
	CNTA_PENDREM_OFF	= 0,
	CNTA_PENDREM_CLR, 
	CNTA_PENDREM_SET      
}cnta_pendrem_e;

#define	CNTA_REMSTAT_POS	(23)		
#define	CNTA_REMSTAT_MSK	(0x01ul << CNTA_REMSTAT_POS)
typedef enum
{
	CNTA_REMSTAT_LOW	= 0,
	CNTA_REMSTAT_HIGH,     
}cnta_remstat_e;

#define	CNTA_ENVELOPE_POS	(24)		
#define	CNTA_ENVELOPE_MSK	(0x01ul << CNTA_ENVELOPE_POS)
typedef enum
{
	CNTA_CARRIER_OUT	= 0,
	CNTA_ENVELOPE_OUT,     
}cnta_envelope_e;


#define	CNTA_CARRIER_POS	(25)		
#define	CNTA_CARRIER_MSK	(0x01ul << CNTA_CARRIER_POS)
typedef enum
{
	CNTA_CARRIER_DIS	= 0,
	CNTA_CARRIER_EN 
}cnta_carrier_e;

/******************************************************************************
* INTMASK : Interrupt Mask 
******************************************************************************/
typedef enum
{
	CNTA_NONE_INT		= (0x00ul << 0),
	CNTA_PENDL_INT		= (0x01ul << 0),
	CNTA_PENDH_INT		= (0x01ul << 1),     
	CNTA_PENDHL_INT		= (0x03ul << 0),
}cnta_int_e;

#define CLIC_INTATTR_TRIG_LEVE                  (0x0UL << CLIC_INTATTR_TRIG_Pos)  
#define CLIC_INTATTR_TRIG_UP                    (0x1UL << CLIC_INTATTR_TRIG_Pos)  
#define CLIC_INTATTR_TRIG_DOWN                  (0x3UL << CLIC_INTATTR_TRIG_Pos)  

#define apt_cnta_int_arrt_set(x)                 CLIC->CLICINT[40].ATTR |= x

/******************************************************************************
********************* CNTA inline Functions Declaration ***********************
******************************************************************************/
static inline void csp_cnta_set_datah(csp_cnta_t *ptCntaBase,uint16_t hwData)
{
	ptCntaBase->CADATAH = hwData;
}
static inline void csp_cnta_set_datal(csp_cnta_t *ptCntaBase,uint16_t hwData)
{
	ptCntaBase->CADATAL = hwData;
}
static inline uint16_t csp_cnta_get_datah(csp_cnta_t *ptCntaBase)
{
	return (uint16_t)(ptCntaBase->CADATAH & ICNTA_CADATAH_MSK);
}
static inline uint16_t csp_cnta_get_datal(csp_cnta_t *ptCntaBase)
{
	return (uint16_t)(ptCntaBase->CADATAL & ICNTA_CADATAL_MSK);
}
static inline uint8_t csp_cnta_get_ckdiv(csp_cnta_t *ptCntaBase)
{
	return (uint8_t)((ptCntaBase->CACON & CNTA_CKDIV_MSK) >> CNTA_CKDIV_POS);
}

static inline void csp_cnta_start(csp_cnta_t *ptCntaBase)
{
	ptCntaBase->CACON = (ptCntaBase->CACON & 0xfffffff3) | (CNTA_START << CNTA_START_POS);
}
static inline void csp_cnta_stop(csp_cnta_t *ptCntaBase)
{
	ptCntaBase->CACON = (ptCntaBase->CACON & 0xfffffff7) | (CNTA_STOP << CNTA_STOP_POS);
}

//lin add
static inline void csp_cnta_set_ckdiv(csp_cnta_t *ptCntaBase,cnta_ckdiv_e eClkDiv)
{
	ptCntaBase->CACON &=  ~(CNTA_CKDIV_MSK);
	ptCntaBase->CACON |= (eClkDiv << CNTA_CKDIV_POS) ;
}

static inline void csp_cnta_soft_rst(csp_cnta_t *ptCntaBase)
{
	ptCntaBase->CADATAH = CNTA_RESET_VALUE;
    ptCntaBase->CADATAL = CNTA_RESET_VALUE;
    ptCntaBase->CACON   = CNTA_RESET_VALUE;
    ptCntaBase->INTMASK = CNTA_RESET_VALUE;
}

static inline void csp_cnta_int_enable(csp_cnta_t *ptCntaBase, cnta_int_e eBtInt)
{
	ptCntaBase->INTMASK |= eBtInt; 
}

static inline void csp_cnta_int_disable(csp_cnta_t *ptCntaBase, cnta_int_e eBtInt)
{
	ptCntaBase->INTMASK  &= ~eBtInt; 
}

static inline void csp_cnta_set_carrier(csp_cnta_t *ptCntaBase, cnta_carrier_e eCarCtrl)
{
	ptCntaBase->CACON &= ~(CNTA_CARRIER_MSK );
	ptCntaBase->CACON |= (eCarCtrl << CNTA_CARRIER_POS);
}

static inline void csp_cnta_set_envelope(csp_cnta_t *ptCntaBase,cnta_envelope_e eEnvelope)
{
	ptCntaBase->CACON &= ~(CNTA_ENVELOPE_MSK);
	ptCntaBase->CACON |= (eEnvelope << CNTA_ENVELOPE_POS);
}

static inline void csp_cnta_set_carrier_start_level(csp_cnta_t *ptCntaBase,cnta_osp_e eOsp)
{
	ptCntaBase->CACON &= ~(CNTA_OSP_MSK);
	ptCntaBase->CACON |= (eOsp << CNTA_OSP_POS);
}

static inline void csp_cnta_set_carrier_stop_level(csp_cnta_t *ptCntaBase, cnta_remstat_e eRemsta)
{
	ptCntaBase->CACON &= ~(CNTA_REMSTAT_MSK);
	ptCntaBase->CACON |= (eRemsta << CNTA_REMSTAT_POS);
}

static inline void csp_cnta_soft_updata(csp_cnta_t *ptCntaBase)
{
	ptCntaBase->CACON |= (CNTA_SW_STROBE << CNTA_SW_STROBE_POS);	
}

static inline void csp_cnta_set_btpend_rem_con(csp_cnta_t *ptCntaBase, cnta_pendrem_e eTcPend)
{
	ptCntaBase->CACON &= ~(CNTA_PEND_REM_MSK);
	ptCntaBase->CACON |= (eTcPend << CNTA_PEND_REM_POS);
}

static inline void csp_cnta_set_btmatch_rem_con(csp_cnta_t *ptCntaBase,cnta_matchrem_e eTcMatch)
{
	ptCntaBase->CACON &= ~(CNTA_MATCH_REM_MSK);
	ptCntaBase->CACON |= (eTcMatch << CNTA_MATCH_REM_POS);
}

static inline void csp_cnta_set_hw_strobe_data(csp_cnta_t *ptCntaBase,cnta_hwstrobe_e eHwstrobe)
{
	ptCntaBase->CACON &= ~(CNTA_HW_STROBE_MSK);
	ptCntaBase->CACON |= (eHwstrobe << CNTA_HW_STROBE_POS);
}

static inline void csp_cnta_count_mode(csp_cnta_t *ptCntaBase, cnta_mode_e eMode)
{
	ptCntaBase->CACON &= ~(CNTA_MODE_MSK);
	ptCntaBase->CACON |= (eMode << CNTA_MODE_POS);
}
#endif
