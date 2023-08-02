/*
 * Copyright (C) 2017-2019 Alibaba Group Holding Limited
 */
 /******************************************************************************
 * @file     vectors.S
 * @brief    define default vector handlers. Should use with
 *           GCC for CSKY Embedded Processors
 * @version  V1.0
 * @date     28. Nove 2017
 ******************************************************************************/

//#include <csi_config.h>

/* Enable interrupts when returning from the handler */
#define MSTATUS_PRV1 0x1880
	
	//stack size
	.equ 	STACK_SIZE, CONFIG_ARCH_INTERRUPTSTACK			
	.globl 	STACK_SIZE
	
.section .bss
    .align  2
    .globl  g_trapstackalloc
    .global g_trapstackbase
    .global g_top_trapstack
g_trapstackalloc:
g_trapstackbase:
    .space 512
g_top_trapstack:

    .align 2
    .globl g_trap_sp
    .type  g_trap_sp, object
g_trap_sp:
    .long 0
    .size g_trap_sp, .-g_trap_sp

irq_nested_level:
.long 0
//irq_mstatus_fs_flag:
//.long 0


.text
#ifdef CONFIG_IRQ_LOOKUP
/******************************************************************************
 * Functions:
 *     Default_IRQHandler(void);
 * ALL IRQ handler, Lookup table processing interrupt 
 ******************************************************************************/	
    .align  2
    .global Default_IRQHandler
    .weak   Default_IRQHandler
    .type   Default_IRQHandler, %function
Default_IRQHandler:
//	ipush
	
//.F_RegNotSave:
//
//    csrr    t1, mcause
    addi    sp, sp, -48
    sw      t0, 4(sp)
    sw      t1, 8(sp)
    csrr    t0, mepc
    csrr    t1, mcause
    sw      t1, 40(sp)
    sw      t0, 44(sp)
    csrs    mstatus, 8  // mstatus <-- mstatus | 8   bit3 =  MIE / global int EN

    sw      ra, 0(sp)
    sw      t2, 12(sp)
    sw      a0, 16(sp)
    sw      a1, 20(sp)
    sw      a2, 24(sp)
    sw      a3, 28(sp)
    sw      a4, 32(sp)
    sw      a5, 36(sp)
	
    andi    t1, t1, 0x3FF  //Get int ID
    slli    t1, t1, 2     // t1 <-- ID*4
    la      t0, g_irqvector
    add     t0, t0, t1
    lw      t2, (t0)
    jalr    t2
	
//	li      t0, MSTATUS_PRV1
//    csrs    mstatus, t0
//    
//.F_RegNotLoad:
//    ipop

    csrc    mstatus, 8   // Clear MIE bit of mstatus

    lw      a1, 40(sp)
    andi    a0, a1, 0x3FF

    /* clear pending */
    li      a2, 0xE000E100
    add     a2, a2, a0   //  a2 = ID+ 0xE000E100
    lb      a3, 0(a2)   //a3 = first byte of a2 when msb of the byte is 0, = 0xffffffxx,when msb of xx is 1
    li      a4, 1
    not     a4, a4      //a4 = 0xfffffffe
    and     a5, a4, a3  
    sb      a5, 0(a2)
	
	
    li      t0, MSTATUS_PRV1
    csrs    mstatus, t0
    csrw    mcause, a1
    lw      t0, 44(sp)
    csrw    mepc, t0
    lw      ra, 0(sp)
    lw      t0, 4(sp)
    lw      t1, 8(sp)
    lw      t2, 12(sp)
    lw      a0, 16(sp)
    lw      a1, 20(sp)
    lw      a2, 24(sp)
    lw      a3, 28(sp)
    lw      a4, 32(sp)
    lw      a5, 36(sp)

    addi    sp, sp, 48
    mret


/******************************************************************************
 * Functions:
 *     void trap(void);
 * default exception handler
 ******************************************************************************/
    .align  2
    .global trap
    .type   trap, %function
trap:
    /* Check for interrupt */
    addi    sp, sp, -4
    sw      t0, 0x0(sp)
    csrr    t0, mcause

    blt     t0, x0, .Lirq   //t0<0 , jump .Lirq  interupt --- 31bit =1 
							//t0>=0  next step  traps
    addi    sp, sp, 4    

    la      t0, g_trap_sp
    addi    t0, t0, -68
    sw      x1, 0(t0)
    sw      x2, 4(t0)
    sw      x3, 8(t0)
    sw      x4, 12(t0)
    sw      x6, 20(t0)
    sw      x7, 24(t0)
    sw      x8, 28(t0)
    sw      x9, 32(t0)
    sw      x10, 36(t0)
    sw      x11, 40(t0)
    sw      x12, 44(t0)
    sw      x13, 48(t0)
    sw      x14, 52(t0)
    sw      x15, 56(t0)
    csrr    a0, mepc
    sw      a0, 60(t0)
    csrr    a0, mstatus
    sw      a0, 64(t0)

    mv      a0, t0
    lw      t0, -4(sp)
    mv      sp, a0
    sw      t0, 16(sp)

    jal     trap_c

.Lirq:
    lw      t0, 0x0(sp)
    addi    sp, sp, 4
    j       Default_IRQHandler

#else
    .align  2
    .global trap
    .type   trap, %function
trap:
    la      t0, g_trap_sp
    addi    t0, t0, -68
    sw      x1, 0(t0)
    sw      x2, 4(t0)
    sw      x3, 8(t0)
    sw      x4, 12(t0)
    sw      x6, 20(t0)
    sw      x7, 24(t0)
    sw      x8, 28(t0)
    sw      x9, 32(t0)
    sw      x10, 36(t0)
    sw      x11, 40(t0)
    sw      x12, 44(t0)
    sw      x13, 48(t0)
    sw      x14, 52(t0)
    sw      x15, 56(t0)
    csrr    a0, mepc
    sw      a0, 60(t0)
    csrr    a0, mstatus
    sw      a0, 64(t0)

    mv      a0, t0
    lw      t0, -4(sp)
    mv      sp, a0
    sw      t0, 16(sp)

    jal     trap_c

#endif




    .align  6
    .weak   Default_Handler
    .global Default_Handler
    .type   Default_Handler, %function
Default_Handler:
    /* Check for nmi */
    addi    sp, sp, -8
    sw      t0, 0x0(sp)
    sw      t1, 0x4(sp)       
    csrr    t0, mcause
    andi    t0, t0, 0x3FF
    li      t1, 24
    beq     t0, t1, .NMI_Handler    //mcause&0x3ff == 24? .NMI_Handler: next step
    lw      t0, 0x0(sp)
    lw      t1, 0x4(sp)
    addi    sp, sp, 8
    j      trap

.NMI_Handler:
    lw      t0, 0x0(sp)
    lw      t1, 0x4(sp)
    addi    sp, sp, 8

    addi    sp, sp, -40
    sw      ra, 0(sp)
    sw      t0, 4(sp)
    sw      t1, 8(sp)
    sw      t2, 12(sp)
    sw      a0, 16(sp)    
    sw      a1, 20(sp)    
    sw      a2, 24(sp)
    sw      a3, 28(sp)
    sw      a4, 32(sp)
    sw      a5, 36(sp)

    la      t0, g_nmivector
    lw      t0, (t0)
    jalr    t0

    lw      ra, 0(sp)
    lw      t0, 4(sp)
    lw      t1, 8(sp)
    lw      t2, 12(sp)
    lw      a0, 16(sp)
    lw      a1, 20(sp)
    lw      a2, 24(sp)
    lw      a3, 28(sp)
    lw      a4, 32(sp)
    lw      a5, 36(sp)
    addi    sp, sp, 40
    mret


    .size   Default_Handler, . - Default_Handler

/*    Macro to define default handlers. Default handler
 *    will be weak symbol and just dead loops. They can be
 *    overwritten by other handlers */
    .macro  def_irq_handler handler_name
    .weak   \handler_name
    .globl  \handler_name
    .set    \handler_name, Default_Handler
    .endm

    def_irq_handler tspend_handler
    def_irq_handler coret_int_handler
//    def_irq_handler syscon_int_handler
//	def_irq_handler ifc_int_handler
//    def_irq_handler adc0_int_handler
//    def_irq_handler ept0_int_handler
//	def_irq_handler dma_int_handler
//	def_irq_handler wwdt_int_handler
//	def_irq_handler exi0_int_handler
//    def_irq_handler exi1_int_handler
//    def_irq_handler gpta0_int_handler
//	def_irq_handler rtc_int_handler
//    def_irq_handler usart_int_handler
//	def_irq_handler uart0_int_handler
//    def_irq_handler uart1_int_handler
//    def_irq_handler uart2_int_handler
//	def_irq_handler i2c_int_handler
//    def_irq_handler spi0_int_handler
//    def_irq_handler sio0_int_handler
//	def_irq_handler exi2_3_int_handler
//    def_irq_handler exi4_9_int_handler
//    def_irq_handler exi10_15_int_handler
//	def_irq_handler cnta_int_handler
//	def_irq_handler tkey_int_handler
//	def_irq_handler lpt_int_handler
//	def_irq_handler bt0_int_handler
//	def_irq_handler bt1_int_handler	
	

