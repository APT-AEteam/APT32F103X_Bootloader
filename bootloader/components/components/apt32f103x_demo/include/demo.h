/***********************************************************************//** 
 * \file  demo.h
 * \brief  demo description and static inline functions at register level 
 * \copyright Copyright (C) 2015-2020 @ APTCHIP
 * <table>
 * <tr><th> Date  <th>Version  <th>Author  <th>Description
 * <tr><td> 2020-12-11 <td>V0.0  <td>ZJY   <td>initial
 * </table>
 * *********************************************************************
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DEMO_H
#define _DEMO_H

/* Includes ------------------------------------------------------------------*/
#include "common.h"

//gpio port demo
extern int gpio_port_ouput_demo(void);
extern int gpio_port_input_demo(void);
extern int gpio_port_irq_demo(void);

//pin demo
extern int pin_output_demo(void);
extern int pin_input_demo(void);
extern int pin_irq_demo(void);
int pin_ioremap_demo(void);

//bt demo
extern int bt_timer_demo(void);
extern int bt_pwm_demo(void);
int bt_sync_trg_start_demo(void);
int bt_sync_trg_count_demo(void);
int bt_sync_trg_stop_demo(void);
int bt_trg_out_demo(void);
int bt_soft_trg_out_demo(void);


//iwdt demo
extern int iwdt_normal_demo(void);
extern int iwdt_irq_demo(void);

//etcb demo

int etcb_one_trg_one_demo0(void);
int etcb_one_trg_one_demo1(void);
int etcb_one_trg_more_demo(void);
int etcb_more_trg_one_demo(void);
int etcb_mix_demo(void);


//uart demo
//uart send
int uart_char_demo(void);
int uart_send_demo(void);
int uart_send_int_demo(void);
int uart_send_dma_demo(void);
//uart receive
int uart_recv_dma_demo(void);
int uart_receive_demo(void);
int uart_recv_rx_int_demo(void);
int uart_recv_rxfifo_int_demo(void);


//adc demo
//normal mode(no interrupt)
int adc_samp_oneshot_demo(void);
int adc_samp_continuous_demo(void);
//interrupt mode
int adc_samp_oneshot_int_demo(void);
int adc_samp_continuous_int_demo(void);
//DMA传输
int adc_samp_continuous_dma_transfer_demo(void);

//sio demo
//sio led
int sio_led_rgb_demo(void);
int sio_led_rgb_recv_rxfull_demo(void);
int sio_led_rgb_recv_rxdone_demo(void);
//hdq
int sio_hdq_send_demo(void);
int sio_hdq_recv_wrcmd_demo(void);
int sio_hdq_send_recv_demo(void);
int sio_hdq_recv_rdcmd_demo(void);

//lpt demo
extern int lpt_timer_demo(void);
extern int lpt_pwm_demo(void);

//reliability demo
extern void lvd_demo(void);
extern void lvr_demo(void);
extern void memorycheck_demo(void);
extern void emcm_demo(void);

//wwdt demo
extern csi_error_t wwdt_demo(void);

//ifc demo
void ifc_read(void);
void ifc_program(void);

//rtc_demo
void rtc_set_time_demo(void);
void rtc_alarm_demo(void);
void rtc_timer_demo(void);
void rtc_trgev_demo(void);

//low power demo
void lp_wakeup_demo(void);
void lp_lpt_wakeup_deepsleep_demo(void);

//iic demo
extern void iic_master_demo(void);
extern void iic_master_slave_demo(void);
extern void iic_slave_demo(void);

//cnta demo
extern int cnta_timer_demo(void);
extern int cnta_pwm_demo(void);

//spi demo
void spi_master_send_demo(void);
void spi_master_send_int_demo(void);
void spi_slave_receive_int_demo(void);
void spi_master_send_receive_demo(void);
void spi_slave_send_receive_int_demo(void);
void spi_etcb_dma_send(void);
void spi_etcb_dma_send_receive(void);




//touch demo
//extern void touch_lowpower_demo(void);
//extern void touch_timer_demo(void);
//extern void touch_main_demo(void);
extern void tkey_demo(void);

//ept demo
extern csi_error_t ept_capture_demo();
extern int ept_pwm_demo();
extern int ept_pwm_dz_demo();
extern int ept_pwm_dz_em_demo();

//gpta demo
extern int gpta_capture_demo();
extern int gpta_pwm_demo();

//crc demo
extern csi_error_t crc_demo();


//usart demo
int usart_char_demo(void);
int usart_send_demo(void);
int usart_send_int_demo(void);
int usart_recv_demo(void);
int usart_recv_rx_int_demo(void);
int usart_recv_rxfifo_int_demo(void);
int usart_send_dma_demo(void);
int usart_recv_dma_demo(void);

int lin_send_test(void);
int lin_send_recv_test(void);



#endif