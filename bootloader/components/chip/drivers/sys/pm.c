/***********************************************************************//** 
 * \file  pm_102.c
 * \brief  power management
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2020-8-10 <td>V0.0  <td>WNN   <td>initial for csi
 * </table>
 * *********************************************************************
*/

#include <drv/common.h>
#include <csp_syscon.h>
#include <soc.h>
#include "pm.h"





#ifdef CONFIG_USER_PM
/// to make user defined prepaare_to_stop() and wkup_frm_stop() possible
pm_core_t g_tPmCore;

/**
  \brief       to attach user defined functions, 
   * to use in case user wants to preserve the scene in lp mode 
  \param	eMd: low power mode
  \param   pfBeforeSlp: funtion to be called before lp
  \param   pfBeforeSlp: funtion to be called after wakeup 
  \return      None.
*/
void csi_pm_attach_callback(csi_pm_mode_e eMd, void *pfBeforeSlp, void *pfWkup)
{
	switch(eMd)
	{
		case (PM_MODE_SLEEP):g_tPmCore.prepare_to_sleep = pfBeforeSlp;
				g_tPmCore.wkup_frm_sleep = pfWkup;
			break;
		case (PM_MODE_DEEPSLEEP):g_tPmCore.prepare_to_deepsleep = pfBeforeSlp;
				g_tPmCore.wkup_frm_deepsleep = pfWkup;
			break;
		default:
			break;
	}
	
}
#endif

static csi_error_t apt_sleep(csi_pm_mode_e eMode)
{
	csi_error_t ret = CSI_OK;
	switch (eMode)
	{
		case (PM_MODE_SLEEP):
			//__WFI();
			__DOZE();
			break;
		case (PM_MODE_DEEPSLEEP):
			__STOP();
			break;
		default:
			ret = CSI_ERROR;
			break;
	}
	return ret;
}
/**
  \brief       choose the pmu mode to enter
  \param[in]   handle  pmu handle to operate.
  \param[in]   mode    \ref pmu_mode_e
  \return      error code
*/
csi_error_t csi_pm_enter_sleep(csi_pm_mode_e eMode)
{
	
	switch (eMode)
	{
		case PM_MODE_SLEEP:		
			#ifdef CONFIG_USER_PM
			g_tPmCore.prepare_to_sleep();
			#endif
			apt_sleep(PM_MODE_SLEEP);	
			#ifdef CONFIG_USER_PM
			g_tPmCore.wkup_frm_sleep();		
			#endif
			break;
		case PM_MODE_DEEPSLEEP:
			#ifdef CONFIG_USER_PM
			g_tPmCore.prepare_to_deepsleep();
			#endif
			apt_sleep(PM_MODE_DEEPSLEEP);	
			#ifdef CONFIG_USER_PM
			g_tPmCore.wkup_frm_deepsleep();
			#endif
			break;
		default:
            return CSI_ERROR;
	}
	return CSI_OK;
}

/**
  \brief       Config the wakeup source.
  \param[in]   wakeup_num wakeup source num
  \param[in]   enable  flag control the wakeup source is enable or not
  \return      error code
*/
csi_error_t csi_pm_config_wakeup_source(csi_wakeup_src_e eWkupSrc, bool bEnable)
{

	csi_error_t ret = CSI_OK;
	csp_syscon_t *ptSysconBase  = (csp_syscon_t*)APB_SYS_BASE;

	
	if (bEnable){
		ptSysconBase->WKCR |= 0x1 << (eWkupSrc);

	}
	else{
		ptSysconBase->WKCR &= ~(0x1 << (eWkupSrc));

	}
	return ret;
}


