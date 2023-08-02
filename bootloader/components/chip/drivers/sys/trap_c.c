/*
 * Copyright (C) 2017-2019 Alibaba Group Holding Limited
 */

/******************************************************************************
 * @file     trap_c.c
 * @brief    source file for the trap process
 * @version  V1.0
 * @date     12. December 2017
 ******************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//#include <csi_config.h>
#include <csi_core.h>
#include <iostring.h>
#include "soc.h"
#include "pin.h"

void (*trap_c_callback)(void);

void trap_c(uint32_t *pwRegs)
{
    //int i;
    uint32_t vec = 0;

    vec = __get_MCAUSE() & 0x3FF;
	
	switch(vec)
	{
		case 3:  //breakpoint exception
		
			BreakPointHandler();
			
			break;
		case 1: //Fetch Instruction access error exception
		
			FetchInstruAccessHandler();

			break;
		case 2:  //Illegal Instruction exception
		
			IllegalInstrHandler();
			
			break;
		case 8: //User-mode environment call exception
			
			UserModeCallHandler();
			
			break;
			
		case 11: //Machine-mode environment call exception
			
			MachineModeCallHandler();
			
			break;
			
		case 6://Store Instruction Misaligned Access exception 
			
			StoreInstruMisalignedHandler();
			
			break;
			
		case 4: //Load Instruction Misaligned Access exception 
		
			LoadInstruMisalignedHandler();
			
			break;
		case 7: //Store Instruction access error exception
		
			StoreInstruAccessHandler();
			
			break;			
		case 5: //Load Instruction access error exception
			
			LoadInstruAccessHandler();
			
			break;
			
		default:
		
			while(1);
			
			break;		
	}
//
//    my_printf("CPU Exception: NO.%d", vec);
//    my_printf("\n");
//
//    for (i = 0; i < 15; i++) {
//       my_printf("x%d: %08x\t", i + 1, pwRegs[i]);
//
//        if ((i % 4) == 3) {
//            my_printf("\n");
//        }
//    }
//
//    my_printf("\n");
//    my_printf("mepc   : %08x\n", pwRegs[15]);
//    my_printf("mstatus: %08x\n", pwRegs[16]);
//
//    if (trap_c_callback) {
//        trap_c_callback();
//    }
//
//    while (1)
//		{
//
//		};
}

