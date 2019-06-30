/*
 *-----------------------------------------------------------------------------
 * The confidential and proprietary information contained in this file may
 * only be used by a person authorised under and to the extent permitted
 * by a subsisting licensing agreement from ARM Limited or its affiliates.
 *
 *            (C) COPYRIGHT 2010-2013 ARM Limited or its affiliates.
 *                ALL RIGHTS RESERVED
 *
 * This entire notice must be reproduced on all copies of this file
 * and copies of this file may only be made by a person if such person is
 * permitted to do so under the terms of a subsisting license agreement
 * from ARM Limited or its affiliates.
 *
 *      SVN Information
 *
 *      Checked In          : $Date: 2017-07-25 15:10:13 +0100 (Tue, 25 Jul 2017) $
 *
 *      Revision            : $Revision: 368444 $
 *
 *      Release Information : Cortex-M0 DesignStart-r2p0-00rel0
 *-----------------------------------------------------------------------------
 */

#ifdef CORTEX_M0
#include "CMSDK_CM0.h"
#include "core_cm0.h"
#endif

#ifdef CORTEX_M0PLUS
#include "CMSDK_CM0plus.h"
#include "core_cm0plus.h"
#endif

#include <stdio.h>
#include "uart_stdout.h"

#define	REG0		    	0x40000000
#define	REG1		    	0x40000004
#define	REG2		    	0x40000008
#define	REG3		    	0x4000000c
#define	REG4		    	0x40000010

#define u32READ(REG)			(*((volatile unsigned long *)(REG)))
#define u32WRITE(REG,DATA)		((*((volatile unsigned long *)(REG)))=(unsigned long)DATA)
	
int main (void)
{

	  unsigned int a = 0;
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG0,0x11133333);
		u32WRITE(REG1,0xffffffff);
		u32WRITE(REG2,0x89abcdef);
		u32WRITE(REG3,0x12345678);

		
		
		    a = u32READ(REG0);
		a = u32READ(REG0);
		a = u32READ(REG0);
		a = u32READ(REG0);
		a = u32READ(REG0);
				a = u32READ(REG1);
				a = u32READ(REG2);
				a = u32READ(REG3);
		    a = u32READ(REG4);

  return 0;
}
