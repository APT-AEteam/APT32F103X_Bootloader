/***********************************************************************//** 
 * \file  gpta.c
 * \brief  Enhanced purpose timer driver
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2022-1-17 <td>V0.0  <td>ljy   <td>initial
 * </table>
 * *********************************************************************
*/
#include "sys_clk.h"
#include "drv/common.h"
#include "drv/gpta.h"
#include "csp_gpta.h"
#include "drv/pin.h"
#include <drv/irq.h>
extern void load1(void);
uint32_t gTick;
uint32_t gGpta0Prd;
uint32_t gGpta1Prd;
uint32_t wGpta_Cmp_Buff[4] = {0};

/** \brief gpta interrupt handle weak function
 *   		- 
 *     		- 
 * 			- 
 *  \param[in] none
 *  \return    none
 */
__attribute__((weak)) void gpta0_initen_irqhandler(csp_gpta_t *ptGptaBase)
{

	if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_PEND))==GPTA_INT_PEND)
	{	
		csi_gpio_port_set_high(GPIOA0, (0x01ul << 0));			
            nop;
		csi_gpio_port_set_low (GPIOA0, (0x01ul << 0));
	    csp_gpta_clr_isr(ptGptaBase, GPTA_INT_PEND);
	}
	if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_TRGEV0))==GPTA_INT_TRGEV0)
	{	
		//csi_gpio_port_set_high(GPIOA0, (0x01ul << 0));				//输出高
//		csi_gpta_change_ch_duty(GPTA0,GPTA_CH_A, 25);
//	    csi_gpta_change_ch_duty(GPTA0,GPTA_CH_B, 25);	
	    csp_gpta_clr_isr(ptGptaBase, GPTA_INT_TRGEV0);
	   	//csi_gpio_port_set_low (GPIOA0, (0x01ul << 0));
	}
	if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_TRGEV1))==GPTA_INT_TRGEV1)
	{	
//		csi_gpta_change_ch_duty(GPTA0,GPTA_CH_A, 50);
//	    csi_gpta_change_ch_duty(GPTA0,GPTA_CH_B, 50);		
	    csp_gpta_clr_isr(ptGptaBase, GPTA_INT_TRGEV1);
	   	
	}
    if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_CAPLD0))==GPTA_INT_CAPLD0)
	{		
	 wGpta_Cmp_Buff[0]=csp_gpta_get_cmpa(ptGptaBase);
	 csp_gpta_clr_isr(ptGptaBase, GPTA_INT_CAPLD0);			
	}
	if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_CAPLD1))==GPTA_INT_CAPLD1)
	{		
     	wGpta_Cmp_Buff[0]=csp_gpta_get_cmpa(ptGptaBase);
		wGpta_Cmp_Buff[1]=csp_gpta_get_cmpb(ptGptaBase);
		csp_gpta_clr_isr(ptGptaBase, GPTA_INT_CAPLD1);			
	}
    if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_CAPLD2))==GPTA_INT_CAPLD2)
	{		
     	wGpta_Cmp_Buff[0]=csp_gpta_get_cmpa(ptGptaBase);
		wGpta_Cmp_Buff[1]=csp_gpta_get_cmpb(ptGptaBase);
		wGpta_Cmp_Buff[2]=csp_gpta_get_cmpaa(ptGptaBase);
		csp_gpta_clr_isr(ptGptaBase, GPTA_INT_CAPLD2);			
	}
	if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_CAPLD3))==GPTA_INT_CAPLD3)
	{		
     	wGpta_Cmp_Buff[0]=csp_gpta_get_cmpa(ptGptaBase);
		wGpta_Cmp_Buff[1]=csp_gpta_get_cmpb(ptGptaBase);
		wGpta_Cmp_Buff[2]=csp_gpta_get_cmpaa(ptGptaBase);
		wGpta_Cmp_Buff[3]=csp_gpta_get_cmpba(ptGptaBase);
		csp_gpta_clr_isr(ptGptaBase, GPTA_INT_CAPLD3);			
	}	
	
    if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_CBU))==GPTA_INT_CBU)
	{	
#if 0		
		gTick++;if(gTick>=5){	
								   //load1();	
	                               gTick=0;
								   csi_gpio_port_set_high(GPIOA0, (0x01ul << 0));
								   csi_gpta_channel_cmpload_config(GPTA0, GPTA_CMPLD_IMM, GPTA_LDCMP_ZRO ,GPTA_CAMPA);
	                               csi_gpta_channel_cmpload_config(GPTA0, GPTA_CMPLD_IMM, GPTA_LDCMP_ZRO ,GPTA_CAMPB);
								   csi_gpta_change_ch_duty(GPTA0,GPTA_CAMPA, 25);
	                               csi_gpta_change_ch_duty(GPTA0,GPTA_CAMPB, 25);
								   csi_gpio_port_set_low (GPIOA0, (0x01ul << 0));
		                         }
#endif
	    csp_gpta_clr_isr(ptGptaBase, GPTA_INT_CBU);
	   	
	}

}
__attribute__((weak)) void gpta1_initen_irqhandler(csp_gpta_t *ptGptaBase)
{

	if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_PEND))==GPTA_INT_PEND)
	{	
	  
	    csp_gpta_clr_isr(ptGptaBase, GPTA_INT_PEND);
	}
	if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_TRGEV0))==GPTA_INT_TRGEV0)
	{	
			
	    csp_gpta_clr_isr(ptGptaBase, GPTA_INT_TRGEV0);
	   	
	}
	
    if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_CAPLD0))==GPTA_INT_CAPLD0)
	{		
	 wGpta_Cmp_Buff[0]=csp_gpta_get_cmpa(ptGptaBase);
	 csp_gpta_clr_isr(ptGptaBase, GPTA_INT_CAPLD0);			
	}
	if(((csp_gpta_get_isr(ptGptaBase) & GPTA_INT_CAPLD1))==GPTA_INT_CAPLD1)
	{		
     	wGpta_Cmp_Buff[0]=csp_gpta_get_cmpa(ptGptaBase);
		wGpta_Cmp_Buff[1]=csp_gpta_get_cmpb(ptGptaBase);
	 csp_gpta_clr_isr(ptGptaBase, GPTA_INT_CAPLD1);			
	}

}
/** \brief capture configuration
 * 
 *  \param[in] ptGptaBase: pointer of gptb register structure
 *  \param[in] ptGptaPwmCfg: refer to csi_ept_captureconfig_t
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_capture_init(csp_gpta_t *ptGptaBase, csi_gpta_captureconfig_t *ptGptaPwmCfg)
{
	uint32_t wClkDiv=0;
	uint32_t wCrVal;
	uint32_t wPrdrLoad; 
			
	csi_clk_enable((uint32_t *)ptGptaBase);								 // clk enable	
	csp_gpta_clken(ptGptaBase);
	csp_gpta_wr_key(ptGptaBase);                                           //Unlocking
	csp_gpta_reset(ptGptaBase);											 // reset 
	
	if(wClkDiv == 0){wClkDiv = 1;}		                                  // clk div value

					
	wCrVal =ptGptaPwmCfg->byCountingMode | (ptGptaPwmCfg->byStartSrc<<GPTA_STARTSRC_POS) | (ptGptaPwmCfg->byWorkmod<<GPTA_MODE_POS);

	wCrVal=(wCrVal & ~(GPTA_PSCLD_MSK))   |((ptGptaPwmCfg->byPscld&0x03)   <<GPTA_PSCLD_POS);
	
	wCrVal=(wCrVal & ~(GPTA_CAPMD_MSK))   |((ptGptaPwmCfg->byCaptureCapmd&0x01)   <<GPTA_CAPMD_POS);
	wCrVal=(wCrVal & ~(GPTA_STOPWRAP_MSK))|((ptGptaPwmCfg->byCaptureStopWrap&0x03)<<GPTA_STOPWRAP_POS);
	wCrVal=(wCrVal & ~(GPTA_CMPA_RST_MSK))|((ptGptaPwmCfg->byCaptureLdaret&0x01)  <<GPTA_CMPA_RST_POS);
	wCrVal=(wCrVal & ~(GPTA_CMPB_RST_MSK))|((ptGptaPwmCfg->byCaptureLdbret&0x01)  <<GPTA_CMPB_RST_POS);
	wCrVal=(wCrVal & ~(GPTA_CMPAA_RST_MSK))|((ptGptaPwmCfg->byCaptureLdaaret&0x01)  <<GPTA_CMPAA_RST_POS);
	wCrVal=(wCrVal & ~(GPTA_CMPBA_RST_MSK))|((ptGptaPwmCfg->byCaptureLdbaret&0x01)  <<GPTA_CMPBA_RST_POS);
	
	wCrVal|=GPTA_CAPLD_EN;
	wCrVal|=GPTA_CAPREARM;
	wPrdrLoad=0xFFFF;

    csp_gpta_clken(ptGptaBase);                                     // clkEN
	csp_gpta_set_cr(ptGptaBase, wCrVal);							// set bt work mode
	csp_gpta_set_pscr(ptGptaBase, (uint16_t)wClkDiv-1);				// clk div
	csp_gpta_set_prdr(ptGptaBase, (uint16_t)wPrdrLoad);				// prdr load value
	
	csi_irq_enable(ptGptaBase);										//enable gpta vic interrupt
	if(ptGptaPwmCfg->wInt)
		csp_gpta_int_enable(ptGptaBase, ptGptaPwmCfg->wInt);		//enable gpta interrupt
	else 
		csp_gpta_int_disable(ptGptaBase, 0x10ff3);					//disable gpta all interrupt
	
//	gGpta0Prd=wPrdrLoad;
	
	return CSI_OK;
}

/** \brief wave configuration
 * 
 *  \param[in] ptGptaBase: pointer of gptb register structure
 *  \param[in] ptGptaPwmCfg: refer to csi_ept_pwmconfig_t
 *  \return error code \ref csi_error_t
 */
csi_error_t  csi_gpta_wave_init(csp_gpta_t *ptGptaBase, csi_gpta_pwmconfig_t *ptGptaPwmCfg)
{
    uint32_t wClkDiv;
	uint32_t wCrVal;
	uint32_t wCmpLoad; 
	uint32_t wPrdrLoad; 
	
	if(ptGptaPwmCfg->wFreq == 0 ){return CSI_ERROR;}
		
	csi_clk_enable((uint32_t *)ptGptaBase);								// clk enable
	
	csp_gpta_clken(ptGptaBase);
	csp_gpta_wr_key(ptGptaBase);                                           //Unlocking
	csp_gpta_reset(ptGptaBase);											// reset 
	

	if(ptGptaPwmCfg->byCountingMode==GPTA_UPDNCNT){
		    wClkDiv = (csi_get_pclk_freq()  / ptGptaPwmCfg->wFreq /2 / 30000);		// clk div value
			if(wClkDiv == 0)wClkDiv = 1;	
			wPrdrLoad  = (csi_get_pclk_freq()/ptGptaPwmCfg->wFreq /2 /wClkDiv);	    //prdr load value
		
	}else{
			wClkDiv = (csi_get_pclk_freq() / ptGptaPwmCfg->wFreq / 30000);		// clk div value
			if(wClkDiv == 0)wClkDiv = 1;	
			wPrdrLoad  = (csi_get_pclk_freq()/ptGptaPwmCfg->wFreq/wClkDiv);	    //prdr load value
	}
		
	wCrVal =ptGptaPwmCfg->byCountingMode | (ptGptaPwmCfg->byStartSrc<<GPTA_STARTSRC_POS) |
	        ptGptaPwmCfg->byOneshotMode<<GPTA_OPMD_POS | (ptGptaPwmCfg->byWorkmod<<GPTA_MODE_POS);
    
	wCrVal=(wCrVal & ~(GPTA_PSCLD_MSK))   |((ptGptaPwmCfg->byPscld&0x03)   <<GPTA_PSCLD_POS);
	
    csp_gpta_clken(ptGptaBase);                                         // clkEN
	csp_gpta_set_cr(ptGptaBase, wCrVal);								// set bt work mode
	csp_gpta_set_pscr(ptGptaBase, (uint16_t)wClkDiv - 1);				// clk div
	csp_gpta_set_prdr(ptGptaBase, (uint16_t)wPrdrLoad);				    // prdr load value
		
	if(ptGptaPwmCfg->byDutyCycle>=100){wCmpLoad=0;}
	else if(ptGptaPwmCfg->byDutyCycle==0){wCmpLoad=wPrdrLoad+1;}
	else{wCmpLoad =wPrdrLoad-(wPrdrLoad * ptGptaPwmCfg->byDutyCycle /100);}		
	csp_gpta_set_cmpa(ptGptaBase, (uint16_t)wCmpLoad);					// cmp load value
	csp_gpta_set_cmpb(ptGptaBase, (uint16_t)wCmpLoad);
		
	csi_irq_enable(ptGptaBase);											//enable vic interrupt
	if(ptGptaPwmCfg->wInt)
		csp_gpta_int_enable(ptGptaBase, ptGptaPwmCfg->wInt);			//enable interrupt
	else 
		csp_gpta_int_disable(ptGptaBase, 0x10ff3);						//disable gpta all interrupt
	
	gGpta0Prd=wPrdrLoad;
	
	return CSI_OK;	
}

/** \brief initialize gpta data structure
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] wTimeOut: the timeout for gpta, unit: us, 20us < wTimeOut < 3S
 *  \return error code \ref csi_error_t
 */ 
csi_error_t csi_gpta_timer_init(csp_gpta_t *ptGptaBase, uint32_t wTimeOut)
{
    uint32_t wClkDiv;
	uint32_t wCrVal;
	uint32_t wPrdrLoad; 
	
	if(wTimeOut == 0 ){return CSI_ERROR;}
		
	csi_clk_enable((uint32_t *)ptGptaBase);								// clk enable
	
	csp_gpta_clken(ptGptaBase);
	csp_gpta_wr_key(ptGptaBase);                                           //Unlocking
	csp_gpta_reset(ptGptaBase);											   // reset 
	
	apt_timer_set_load_value(wTimeOut);
	wPrdrLoad = apt_timer_get_prdrload_value();
	wClkDiv = apt_timer_get_clkdiv_value();

	wCrVal =GPTA_UPCNT | (GPTA_SYNC_START<<GPTA_STARTSRC_POS) | (GPTA_WAVE<<GPTA_MODE_POS);
	wCrVal=(wCrVal & ~(GPTA_PSCLD_MSK))   |((GPTA_LDPSCR_ZRO&0x03)   <<GPTA_PSCLD_POS);	

    csp_gpta_clken(ptGptaBase);                                         // clkEN
	csp_gpta_set_cr(ptGptaBase, wCrVal);								// set gpta work mode
	csi_gpta_count_mode(ptGptaBase, GPTA_OP_CONT);                      // gpta count mode
	csp_gpta_set_pscr(ptGptaBase, (uint16_t)wClkDiv - 1);				// clk div
	csp_gpta_set_prdr(ptGptaBase, (uint16_t)wPrdrLoad);				    // prdr load value

	csp_gpta_int_enable(ptGptaBase, GPTA_INT_PEND);		        		//enable gpta interrupt
	csi_irq_enable(ptGptaBase);							   				//enable vic interrupt
	
	return CSI_OK;					
}

/** \brief set gpta count mode
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] eCntMode: gpta count mode, one pulse/continuous
 *  \return none
 */ 
void csi_gpta_count_mode(csp_gpta_t *ptGptaBase, csi_gpta_opmd_e eCntMode)
{
	csp_gpta_set_opmd(ptGptaBase, eCntMode);
}

/** \brief enable/disable gpta burst 
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] byCgsrc:cgr src 
 *  \param[in] byCgflt:cfg flt
 *  \param[in] bEnable: ENABLE/DISABLE
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_burst_enable(csp_gpta_t *ptGptaBase,uint8_t byCgsrc,uint8_t byCgflt, bool bEnable)
{
	csp_gpta_set_burst(ptGptaBase,byCgsrc,bEnable);	
	csp_gpta_flt_init(ptGptaBase,byCgflt,bEnable);
	return CSI_OK;
}
/** \brief Channel CMPLDR configuration
 * 
 *  \param[in] ptGptaBase: pointer of ept register structure
 *  \param[in] tld: refer to csp_gpta_cmpdata_ldmd_e
 *  \param[in] tldamd: refer to csp_gpta_ldamd_e
 *  \param[in] eChannel: refer to csi_gpta_comp_e
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_channel_cmpload_config(csp_gpta_t *ptGptaBase, csp_gpta_cmpdata_ldmd_e tld, csp_gpta_ldamd_e tldamd ,csi_gpta_comp_e channel)
{			  
	switch (channel)
	{	
		case (GPTA_COMPA):   ptGptaBase -> CMPLDR = (ptGptaBase -> CMPLDR &~(GPTA_CMPA_LD_MSK) )    |  (tld    << GPTA_CMPA_LD_POS);
		                     ptGptaBase -> CMPLDR = (ptGptaBase -> CMPLDR &~(GPTA_CMPA_LDTIME_MSK) )|  (tldamd <<GPTA_CMPA_LDTIME_POS);
			break;
		case (GPTA_COMPB):   ptGptaBase -> CMPLDR = (ptGptaBase -> CMPLDR &~(GPTA_CMPB_LD_MSK) )    |  (tld    << GPTA_CMPB_LD_POS);
		                     ptGptaBase -> CMPLDR = (ptGptaBase -> CMPLDR &~(GPTA_CMPB_LDTIME_MSK) )|  (tldamd << GPTA_CMPB_LDTIME_POS);
			break;
//		case (GPTA_COMPC):   ptGptaBase -> CMPLDR = (ptGptaBase -> CMPLDR &~(GPTA_CMPC_LD_MSK) )    |  (tld    << GPTA_CMPC_LD_POS);
//		                     ptGptaBase -> CMPLDR = (ptGptaBase -> CMPLDR &~(GPTA_CMPC_LDTIME_MSK) )|  (tldamd << GPTA_CMPC_LDTIME_POS);
//            break;
//		case (GPTA_COMPD):   ptGptaBase -> CMPLDR = (ptGptaBase -> CMPLDR &~(GPTA_CMPD_LD_MSK) )    |  (tld    << GPTA_CMPD_LD_POS);
//		                     ptGptaBase -> CMPLDR = (ptGptaBase -> CMPLDR &~(GPTA_CMPD_LDTIME_MSK) )|  (tldamd << GPTA_CMPD_LDTIME_POS);
//		    break;
		default:return CSI_ERROR;
			break;
	}
	return CSI_OK;
}

/** \brief Channel configuration
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] tPwmCfg: refer to csi_gpta_pwmchannel_config_t
 *  \param[in] eChannel:  refer to csi_gpta_channel_e
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_channel_config(csp_gpta_t *ptGptaBase, csi_gpta_pwmchannel_config_t *tPwmCfg, csi_gpta_channel_e eChannel)
{
    uint32_t w_AQCRx_Val;
	
	w_AQCRx_Val=  tPwmCfg -> byActionZro 
	              | ( tPwmCfg -> byActionPrd  << GPTA_ACT_PRD_POS  )
				  | ( tPwmCfg -> byActionC1u  << GPTA_ACT_C1U_POS  )
				  | ( tPwmCfg -> byActionC1d  << GPTA_ACT_C1D_POS  )
				  | ( tPwmCfg -> byActionC2u  << GPTA_ACT_C2U_POS  )
				  | ( tPwmCfg -> byActionC2d  << GPTA_ACT_C2D_POS  )
				  | ( tPwmCfg -> byActionT1u  << GPTA_ACT_T1U_POS  )
				  | ( tPwmCfg -> byActionT1d  << GPTA_ACT_T1D_POS  )
				  | ( tPwmCfg -> byActionT2u  << GPTA_ACT_T2U_POS  )
				  | ( tPwmCfg -> byActionT2d  << GPTA_ACT_T2D_POS  )
				  | ( tPwmCfg -> byChoiceC1sel  << GPTA_C1SEL_POS  )
				  | ( tPwmCfg -> byChoiceC2sel  << GPTA_C2SEL_POS  );
				  
	switch (eChannel)
	{	
		case (GPTA_CHANNEL_1):csp_gpta_set_aqcr1(ptGptaBase,w_AQCRx_Val);
			break;
		case (GPTA_CHANNEL_2):csp_gpta_set_aqcr2(ptGptaBase,w_AQCRx_Val);
			break;
		default:return CSI_ERROR;
			break;
	}
	return CSI_OK;
}

/** \brief Channel AQLDR configuration
 * 
 *  \param[in] ptGptaBase: pointer of ept register structure
 *  \param[in] tld: refer to csp_gpta_ld_e
 *  \param[in] tldamd: refer to csp_gpta_ldamd_e
 *  \param[in] eChannel: refer to csi_gpta_channel_e
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_channel_aqload_config(csp_gpta_t *ptGptaBase, csp_gpta_ld_e tld, csp_gpta_ldamd_e tldamd ,csi_gpta_channel_e eChannel)
{			  
	switch (eChannel)
	{	
		case (GPTA_CHANNEL_1):ptGptaBase -> AQLDR = (ptGptaBase -> AQLDR &~(GPTA_AQCR1_SHDWEN_MSK) )|  (tld << GPTA_AQCR1_SHDWEN_POS);
		                      ptGptaBase -> AQLDR = (ptGptaBase -> AQLDR &~(GPTA_LDAMD_MSK) )|  (tldamd << GPTA_LDAMD_POS);
			break;
		case (GPTA_CHANNEL_2):ptGptaBase -> AQLDR = (ptGptaBase -> AQLDR &~(GPTA_AQCR2_SHDWEN_MSK) )|  (tld << GPTA_AQCR2_SHDWEN_POS);
		                      ptGptaBase -> AQLDR = (ptGptaBase -> AQLDR &~(GPTA_LDBMD_MSK) )|  (tldamd << GPTA_LDBMD_POS);
			break;

		default:return CSI_ERROR;
			break;
	}
	return CSI_OK;
}
/**
 \brief  gpta configuration Loading
 \param  ptGptaBase    	pointer of gpta register structure
 \param  tCfg           refer to csi_gpta_Global_load_control_config_t
 \return CSI_OK /CSI_ERROR
*/
csi_error_t csi_gpta_global_config(csp_gpta_t *ptGptaBase,csi_gpta_Global_load_control_config_t *Global)
{   uint32_t w_GLDCR;	
	w_GLDCR =0;
    w_GLDCR = (w_GLDCR &~GPTA_GLDEN_MSK)       | ((Global->bGlden & 0x01)<<GPTA_GLDEN_POS);
	w_GLDCR = (w_GLDCR &~GPTA_GLDMD_MSK)       | ((Global->byGldmd & 0x0f)<<GPTA_GLDMD_POS);
	w_GLDCR = (w_GLDCR &~GPTA_GLDCR_OSTMD_MSK) | ((Global->bOstmd & 0x01)<<GPTA_GLDCR_OSTMD_POS);
	w_GLDCR = (w_GLDCR &~GPTA_GLDPRD_MSK)      | ((Global->bGldprd & 0x07)<<GPTA_GLDPRD_POS);
	w_GLDCR = (w_GLDCR &~GPTA_GLDCNT_MSK)      | ((Global->byGldcnt & 0x07)<<GPTA_GLDCNT_POS);
	csp_gpta_set_gldcr(ptGptaBase,w_GLDCR);	
	return CSI_OK;
}

/** \brief CLDCFG loading
 * 
 *  \param[in] ptGptaBase of gpta register structure
 *  \param[in] Glo:  csi_gpta_Global_load_gldcfg  
 *  \param[in] bENABLE：ENABLE or DISABLE
 *  \return CSI_OK
 */
csi_error_t csi_gpta_gldcfg(csp_gpta_t *ptGptaBase ,csi_gpta_Global_load_gldcfg Glo,bool bENABLE)
{
   	switch (Glo)
	{	
		case (byprdr_A): ptGptaBase -> GLDCFG  = (ptGptaBase -> GLDCFG & ~(GPTA_LD_PRDR_MSK)) |(bENABLE << GPTA_LD_PRDR_POS) ;
			break;
		case (bycmpa_A): ptGptaBase -> GLDCFG  = (ptGptaBase -> GLDCFG & ~(GPTA_LD_CMPA_MSK)) |(bENABLE << GPTA_LD_CMPA_POS) ;
			break;
		case (bycmpb_A): ptGptaBase -> GLDCFG  = (ptGptaBase -> GLDCFG & ~(GPTA_LD_CMPB_MSK)) |(bENABLE << GPTA_LD_CMPB_POS) ;
		    break;
		
		case (byaqcra_A):ptGptaBase -> GLDCFG  = (ptGptaBase -> GLDCFG & ~(GPTA_LD_AQCRA_MSK)) |(bENABLE << GPTA_LD_AQCRA_POS );
		    break;
		case (byaqcrb_A):ptGptaBase -> GLDCFG  = (ptGptaBase -> GLDCFG & ~(GPTA_LD_AQCRB_MSK)) |(bENABLE << GPTA_LD_AQCRB_POS );
		    break;
		
	    case (byaqcsf_A):ptGptaBase -> GLDCFG  = (ptGptaBase -> GLDCFG & ~(GPTA_LD_AQCSF_MSK)) |(bENABLE << GPTA_LD_AQCSF_POS );
			 break;
	 
		default: return CSI_ERROR;
			break;
	}   
	return CSI_OK;
}


/** \brief Software trigger loading
 * 
 *  \param[in] ptGptaBase pointer of gpta register structure
 *  \return none
*/
void csi_gpta_global_sw(csp_gpta_t *ptGptaBase)
{
	csp_gpta_set_gldcr2(ptGptaBase,0x02);
}
/** \brief rearm  loading
 * 
 *  \param[in] ptGptaBase pointer of gpta register structure
 *  \return none
*/
void csi_gpta_global_rearm(csp_gpta_t *ptGptaBase)
{
	csp_gpta_set_gldcr2(ptGptaBase,0x01);
}
/** \brief start gpta
 * 
 *  \param[in] ptGptaBase pointer of gpta register structure
 *  \return none
*/
void csi_gpta_start(csp_gpta_t *ptGptaBase)
{   csp_gpta_wr_key(ptGptaBase); 
	csp_gpta_start(ptGptaBase);
}
/** \brief SW stop gpta counter
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \return none
*/
void csi_gpta_stop(csp_gpta_t *ptGptaBase)
{
	csp_gpta_wr_key(ptGptaBase);
	csp_gpta_stop(ptGptaBase);
}
/** \brief set gpta start mode. 
 * 
 *  \param[in] ptGptaBase ：pointer of gpta register structure
 *  \param[in] eMode GPTA_SW/GPTA_SYNC
 *  \return none
 */
void csi_gpta_set_start_mode(csp_gpta_t *ptGptaBase, csi_gpta_stmd_e eMode)
{
	csp_gpta_set_start_src(ptGptaBase, eMode);
}
/** \brief set gpta operation mode
 * 
 *  \param[in] ptGptaBase ：pointer of gpta register structure
 *  \param[in] eMode ： GPTA_OP_CONT/GPTA_OP_OT
 *  \return none
 */
void csi_gpta_set_os_mode(csp_gpta_t *ptGptaBase, csi_gpta_opmd_e eMode)
{
	csp_gpta_set_opmd(ptGptaBase, eMode);
}

/** \brief set gpta stop status
 * 
 *  \param[in] ptGptaBase :   pointer of gpta register structure
 *  \param[in] eSt 	 GPTA_STPST_HZ/GPTA_STPST_LOW
 *  \return none
 */
void csi_gpta_set_stop_st(csp_gpta_t *ptGptaBase, csp_gpta_stpst_e eSt)
{	
  csp_gpta_set_stop_st(ptGptaBase,eSt);
}

/** \brief get counter period to calculate the duty cycle. 
 * 
 *  \param[in] ptGptaBase  :  pointer of gpta register structure
 *  \return counter period (reg data)
 */
uint16_t csi_gpta_get_prdr(csp_gpta_t *ptGptaBase)
{
	return csp_gpta_get_prdr(ptGptaBase);
}

/** \brief  update gpta PRDR and CMPx reg value
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] eComp: select which COMP to set(COMPA or COMPB)
 *  \param[in] hwPrdr: gpta PRDR reg  value
 *  \param[in] hwCmp: gpta COMP reg value
 *  \return none
 */
csi_error_t csi_gpta_prdr_cmp_update(csp_gpta_t *ptGptaBase,csi_gpta_comp_e eComp, uint16_t hwPrdr, uint16_t hwCmp) 
{
	csp_gpta_set_prdr(ptGptaBase, (uint16_t)hwPrdr);		//set GPTA PRDR Value
	switch (eComp)
	{	
		case (GPTA_COMPA):
			csp_gpta_set_cmpa(ptGptaBase, (uint16_t)hwCmp);	//set GPTA COMPA Value
			break;
			
		case (GPTA_COMPB):
			csp_gpta_set_cmpb(ptGptaBase, (uint16_t)hwCmp);	//set GPTA COMPB Value
			break;

		default: 
			return CSI_ERROR;
			break;
	}
    return (CSI_OK);
}

/** \brief change gpta output dutycycle. 
 * 
 *  \param[in] ptGptaBase :    pointer of gpta register structure
 *  \param[in] eCh  :          refer to csi_gpta_comp_e
 *	\param[in] wDuty :   	   duty of PWM:0%-100%
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_change_ch_duty(csp_gpta_t *ptGptaBase, csi_gpta_comp_e eCh, uint32_t wDuty)
{ uint16_t  wCmpLoad;
  uint16_t  wPrd;
    wPrd=csp_gpta_get_prd(ptGptaBase);
	if(wDuty>=100){wCmpLoad=0;}
	else if(wDuty==0){wCmpLoad=wPrd+1;}
	else{wCmpLoad =wPrd-(wPrd * wDuty /100);}

	switch (eCh)
	{	
		case (GPTA_COMPA):csp_gpta_set_cmpa(ptGptaBase, (uint16_t)wCmpLoad);
			break;
		case (GPTA_COMPB):csp_gpta_set_cmpb(ptGptaBase, (uint16_t)wCmpLoad);
			break;

		default: return CSI_ERROR;
			break;
	}
    return (CSI_OK);
}

/** \brief enable/disable gpta in debug mode
 * 
 *  \param[in]  ptGptaBase      pointer of gpta register structure
 *  \param[in]   bEnable		ENABLE/DISABLE
 *  \return none
 */
void csi_gpta_debug_enable(csp_gpta_t *ptGptaBase, bool bEnable)
{
	csp_gpta_dbg_enable(ptGptaBase, bEnable);
}

/** \brief enable/disable gpta out trigger 
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] eCh: 0/1
 *  \param[in] bEnable: ENABLE/DISABLE
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_evtrg_enable(csp_gpta_t *ptGptaBase, csi_gpta_trgout_e byCh, bool bEnable)
{	
	if (byCh > 1)return CSI_ERROR;
    csp_gpta_trg_xoe_enable(ptGptaBase, byCh, bEnable);
	return CSI_OK;
}


/** \brief   One time software output 
 * 
 *  \param[in]   ptGptaBase: pointer of gptb register structure 
 *  \param[in]   byCh:  GPTA_OSTSFA/GPTA_OSTSFB
 *  \param[in]   bEnable : GPTA_LDAQCR_ZRO/GPTA_LDAQCR_PRD/GPTA_LDAQCR_ZROPRD
 *  \return error code \ref csi_error_t
*/
csi_error_t csi_gpta_onetimesoftware_output(csp_gpta_t *ptGptaBase, uint16_t byCh, csp_gpta_action_e bEnable)
{	
	switch (byCh){
	case GPTA_OSTSF1: ptGptaBase ->AQOSF |= GPTA_OSTSF1;
	                  ptGptaBase ->AQOSF = (ptGptaBase ->AQOSF &~(GPTA_ACT1_MSK))|((bEnable&0x03)<<GPTA_ACT1_POS);
	     break;
	case GPTA_OSTSF2: ptGptaBase ->AQOSF |= GPTA_OSTSF2;
	                  ptGptaBase ->AQOSF = (ptGptaBase ->AQOSF &~(GPTA_ACT2_MSK))|((bEnable&0x03)<<GPTA_ACT2_POS);
	     break;	
	default: return CSI_ERROR;
	     break;
    }
	return CSI_OK;
}
/** \brief  Continuous software waveform loading control
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] bEnable:    refer to csp_gpta_aqosf_e
 *  \return  none
 */
void csi_gpta_aqcsfload_config(csp_gpta_t *ptGptaBase, csp_gpta_aqosf_e bEnable)
{
	ptGptaBase ->AQOSF  = (ptGptaBase ->AQOSF &~(GPTA_AQCSF_LDTIME_MSK))|((bEnable&0x03)<<GPTA_AQCSF_LDTIME_POS);
}
/** \brief Continuous software waveform control
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] byCh        refer to csi_gpta_channel_e
 *  \param[in] bEnable:    refer to  csp_gpta_aqcsf_e
 *  \return  none
 */
csi_error_t csi_gpta_continuous_software_waveform(csp_gpta_t *ptGptaBase, csi_gpta_channel_e byCh, csp_gpta_aqcsf_e bEnable)
{
	
	switch (byCh){
	case GPTA_CHANNEL_1:  ptGptaBase ->AQCSF = (ptGptaBase ->AQCSF &~(0x03))|(bEnable&0x03);            
	     break;
	case GPTA_CHANNEL_2:  ptGptaBase ->AQCSF = (ptGptaBase ->AQCSF &~(0x0c))|(bEnable&0x03)<<2;
	     break;	

	default: return CSI_ERROR;
	     break;
    }		
	return CSI_OK;
}

/** \brief gpta soft trg
 *  \param[in] ptGptaBase:pointer of gpta register structure
 *  \param[in] eCh: 0/1
 *  \return none
 */
void csi_gpta_swf_trg(csp_gpta_t *ptGptaBase, csi_gpta_trgout_e byCh)
{
	csp_gpta_swf_trg(ptGptaBase, byCh);
}

/** \brief gpta  input  config  
 *  \param[in] ptGptaBase:pointer of gpta register structure
 *  \param[in] eInt:     refer to to csi_gpta_intsrc_e
 *  \param[in] bEnable:  ENABLE/DISABLE
 *  \return CSI_OK;
 */
void csi_gpta_int_enable(csp_gpta_t *ptGptaBase, csi_gpta_intsrc_e eInt)
{   
	csp_gpta_clr_isr(ptGptaBase,(csp_gpta_int_e)eInt);
	csp_gpta_int_enable(ptGptaBase,(csp_gpta_int_e)eInt);
}

/** \brief gpta interrupt disable
 *  \param[in] ptGptaBase:pointer of gpta register structure
 *  \param[in] eInt:     refer to to csi_gpta_intsrc_e
 *  \return none;
 */
void csi_gpta_int_disable(csp_gpta_t *ptGptaBase, csi_gpta_intsrc_e eInt)
{   
	csp_gpta_int_disable(ptGptaBase,(csp_gpta_int_e)eInt);
}

/** \brief gpta sync input evtrg config  
 * 
 *  \param[in] ptGptaBase:pointer of gpta register structure
 *  \param[in] eTrgin: gpta sync evtrg input channel(0~5)
 *  \param[in] eTrgMode: gpta sync evtrg mode, continuous/once
 *  \param[in] eAutoRearm: refer to csi_gpta_arearm_e 
 *  \return none
 */
void csi_gpta_set_sync(csp_gpta_t *ptGptaBase, csi_gpta_trgin_e eTrgIn, csi_gpta_trgmode_e eTrgMode, csi_gpta_arearm_e eAutoRearm)
{
	csp_gpta_set_sync_mode(ptGptaBase, eTrgIn, (csp_gpta_syncmd_e)eTrgMode);
	csp_gpta_set_auto_rearm(ptGptaBase, (csp_gpta_arearm_e)eAutoRearm);
	csp_gpta_sync_enable(ptGptaBase, eTrgIn, ENABLE);
}

/** \brief gpta extsync input select
 * 
 *  \param[in] ptGptaBase:pointer of gpta register structure
 *  \param[in] eTrgin: gpta sync evtrg input channel(0~5)
 *  \param[in] byTrgChx: trgxsel channel(0~1)
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_set_extsync_chnl(csp_gpta_t *ptGptaBase, csi_gpta_trgin_e eTrgIn, uint8_t byTrgChx)
{
	switch(byTrgChx)
	{
		case 0:
			csp_gpta_sync_trg0sel(ptGptaBase, eTrgIn);
			break;
		case 1:
			csp_gpta_sync_trg1sel(ptGptaBase, eTrgIn);
			break;
		default:
			return CSI_ERROR;
		
	}
	return CSI_OK;
}

/** \brief gpta sync input filter config  
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] ptFilter: pointer of sync input filter parameter config structure
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_set_sync_filter(csp_gpta_t *ptGptaBase, csi_gpta_filter_config_t *ptFilter)
{
	uint32_t wFiltCr;
	uint32_t wWindow;
	
	if(ptFilter->byFiltSrc > GPTA_FILT_SYNCIN5)
		return CSI_ERROR;
	wFiltCr = ptFilter->byFiltSrc | (ptFilter->byWinInv << GPTA_FLTBLKINV_POS) | 
			(ptFilter->byWinAlign << GPTA_ALIGNMD_POS) | (ptFilter->byWinCross << GPTA_CROSSMD_POS);
	wWindow = ptFilter->byWinOffset | (ptFilter->byWinWidth << GPTA_FLT_WDW_POS);
	
	csp_gpta_set_trgftcr(ptGptaBase, wFiltCr);
	csp_gpta_set_trgftwr(ptGptaBase, wWindow);
	
	return CSI_OK;
}
/** \brief rearm gpta sync evtrg  
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] eTrgin: gpta sync evtrg input channel(0~5)
 *  \return none
 */
void csi_gpta_rearm_sync(csp_gpta_t *ptGptaBase,csi_gpta_trgin_e eTrgin)
{
	csp_gpta_rearm_sync(ptGptaBase, eTrgin);
}
/** \brief gpta evtrg output config
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] byTrgOut: evtrg out port(0~1)
 *  \param[in] eTrgSrc: evtrg source(1~15) 
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_set_evtrg(csp_gpta_t *ptGptaBase, csi_gpta_trgout_e byTrgOut, csp_gpta_trgsrc_e eTrgSrc)
{
	switch (byTrgOut)
	{
		case GPTA_TRGOUT0:
		        if(eTrgSrc == GPTA_TRG01_DIS)								
				{
					csp_gpta_trg_xoe_enable(ptGptaBase, byTrgOut, DISABLE);	//disable evtrg source out
					return CSI_OK;
				}
				csp_gpta_set_trgsrc01(ptGptaBase, byTrgOut, eTrgSrc);
			break;
		
		case GPTA_TRGOUT1: 
				if(eTrgSrc == GPTA_TRG01_DIS)								
				{
					csp_gpta_trg_xoe_enable(ptGptaBase, byTrgOut, DISABLE);	//disable evtrg source out
					return CSI_OK;
				}
				csp_gpta_set_trgsrc01(ptGptaBase, byTrgOut, eTrgSrc);
			break;
		default: 
			return CSI_ERROR;
	}
	
	csp_gpta_trg_xoe_enable(ptGptaBase, byTrgOut, ENABLE);				//evtrg out enable
	
	return CSI_OK;
}


/** \brief gpta evtrg cntxinit control
 * 
 *  \param[in] ptGptaBase: pointer of gpta register structure
 *  \param[in] byCntChx: evtrg countinit channel(0~3)
 *  \param[in] byCntVal: evtrg cnt value
 *  \param[in] byCntInitVal: evtrg cntxinit value
 *  \return error code \ref csi_error_t
 */
csi_error_t csi_gpta_set_evcntinit(csp_gpta_t *ptGptaBase, uint8_t byCntChx, uint8_t byCntVal, uint8_t byCntInitVal)
{

 if(byCntChx > GPTA_CNT1INIT)
  return CSI_ERROR;
 
 csp_gpta_set_trgprd(ptGptaBase, byCntChx, byCntVal - 1);    //evtrg count
 csp_gpta_trg_cntxinit(ptGptaBase, byCntChx, byCntInitVal);
 csp_gpta_trg_cntxiniten_enable(ptGptaBase, byCntChx, ENABLE);
 
 return CSI_OK;
}

/**
 \brief  gpta configuration Loading
 \param  ptGptaBase    	pointer of gptb register structure
 \param  tCfg           refer to csi_gpta_feglk_config_t
 \return CSI_OK /CSI_ERROR
*/
csi_error_t csi_gpta_reglk_config(csp_gpta_t *ptGptaBase,csi_gpta_feglk_config_t *Global)
{   uint32_t w_GLK;	
	w_GLK =0;
    w_GLK = (w_GLK & ~GPTA_PRDR_MSK )| ((Global-> byPrdr & 0xF)<< GPTA_PRDR_POS);
	w_GLK = (w_GLK & ~GPTA_CMPA_MSK )| ((Global-> byCmpa & 0xF)<< GPTA_CMPA_POS);
	w_GLK = (w_GLK & ~GPTA_CMPB_MSK )| ((Global-> byCmpb & 0xF)<< GPTA_CMPB_POS);
	w_GLK = (w_GLK & ~GPTA_GLD2_MSK )| ((Global-> byGld2 & 0xF)<< GPTA_GLD2_POS);
	w_GLK = (w_GLK & ~GPTA_RSSR_MSK )| ((Global-> byRssr & 0xF)<< GPTA_RSSR_POS);
	csp_gpta_set_feglk(ptGptaBase,w_GLK);
	w_GLK =0;
	w_GLK = (w_GLK & ~GPTA_EMSLCLR_MSK )| ((Global-> byEmslclr & 0xF)<< GPTA_EMSLCLR_POS);
	w_GLK = (w_GLK & ~GPTA_EMHLCLR_MSK )| ((Global-> byEmhlclr & 0xF)<< GPTA_EMHLCLR_POS);
	w_GLK = (w_GLK & ~GPTA_EMICR_MSK )  | ((Global-> byEmicr   & 0xF)<< GPTA_EMICR_POS);
	w_GLK = (w_GLK & ~GPTA_EMFRCR_MSK ) | ((Global-> byEmfrcr  & 0xF)<< GPTA_EMFRCR_POS);
	w_GLK = (w_GLK & ~GPTA_AQOSF_MSK )  | ((Global-> byAqosf   & 0xF)<< GPTA_AQOSF_POS);
	w_GLK = (w_GLK & ~GPTA_AQCSF_MSK )  | ((Global-> byAqcsf   & 0xF)<< GPTA_AQCSF_POS);
	csp_gpta_set_feglk2(ptGptaBase,w_GLK);	
	return CSI_OK;
}


