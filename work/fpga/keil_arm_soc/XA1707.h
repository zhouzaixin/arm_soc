									         /*(c) Copyright 2008-2018，XA
                                                  All rights reserved */
//**************************************************************************
//*\文件名称：XA1704.h
//*\摘要：    定义XA1707各模块寄存器的地址
//*\当前版本：Ver1.0
//*\作者：    hanym
//*\完成日期：2017-08-07
//*\取代版本：--
//*\原作者：  --
//*\完成日期：--
//***************************************************************************


//存储器地址
#define ROM_ADDR		0x00000000
#define DMEM_ADDR		0x000D0000

#define AHB_ADDR		0x40008000
#define APB_ADDR		0x40000000

// sysctrl
#define SYS_ADDR		0x40000000
#define PCON        0x4000F400
#define CFCR        0x4000F404
#define PLLCFG      0x4000F408
#define TEST        0x4000F40C
#define GPCON       0x4000F410

// timer
#define TMRLOAD           0x40000800
#define TMRVAL            0x40000804
#define TMRCON            0x40000808
#define TMRIS             0x4000080C

// SPI1
#define SPICON            0x40001800

// GPIO
#define GPIODATA		      0x40003000
#define	GPIODIR			      0x40003004
#define	GPIOIS			      0x40003008
#define GPIOIBE			      0x4000300C
#define	GPIOIEV 		      0x40003010
#define	GPIOIE			      0x40003014
#define GPIORIS			      0x40003018
#define	GPIOMIS			      0x4000301C
#define	GPIOIC			      0x40003020


// UART0	0x51000000
#define	UART0_CON		    	0x51005800
#define UART0_BAUDFREQ  	0x51005804
#define UART0_BAUDLIMIT 	0x51005808
#define UART0_RXDATA    	0x5100580C
#define UART0_TXDATA    	0x51005810

// UART1	0x40007000?
#define	UART1_CON		    	0x40007000
#define UART1_BAUDFREQ  	0x40007004
#define UART1_BAUDLIMIT 	0x40007008
#define UART1_RXDATA    	0x4000700C
#define UART1_TXDATA    	0x40007010


#define BLAKE_BASE       0x40008000
// BLAKE 0x4000B000
#define BLAKE_START     	0x00000004
#define BLAKE_OPER      	0x00000008
#define BLAKE_DI        	0x0000000C //16 word
#define BLAKE_IV        	0x0000004C //8 word
#define BLAKE_DIF       	0x00000070 //2 word
#define BLAKE_CT        	0x00000078 //1 word
#define BLAKE_RST         0x000000F0  
#define BLAKE_DO          0x00000080 //8 word
#define BLAKE_GOLD_NONCE  0x000000C0 
#define BLAKE_EXTRA_DATA  0x000000C4 
#define BLAKE_DONE      	0x000000F4 
#define BLAKE_FIND_NONCE  0x000000F8 

#define BLAKE_MAX_NUM     12      //can be set from 0 to 16 do not large 16 !

  // NVIC
#define NVIC_ISER		0xE000E100	 // Interrupt Set-Enable Register
#define NVIC_ICER		0xE000E180	 // Interrupt Clear Enable Register
#define NVIC_ISPR		0xE000E200	 // Interrupt Set-Pending Register
#define NVIC_ICPR		0xE000E280	 // Interrupt Clear-Pending Register
#define NVIC_IPR0		0xE000E400	 // Interrupt Priority Registers
#define NVIC_IPR1		0xE000E404
#define NVIC_IPR2		0xE000E408
#define NVIC_IPR3		0xE000E40c
#define NVIC_IPR4		0xE000E410
#define NVIC_IPR5		0xE000E414
#define NVIC_IPR6		0xE000E418
#define NVIC_IPR7		0xE000E41c

#define   inp_w(addr)      		*(volatile UINT32*)(addr)
#define   inp_h(addr)      		*(volatile UINT16*)(addr)
#define   inp_b(addr)			*(volatile UINT8*)(addr)

#define   outp_w(addr, dat)     *(volatile UINT32*)(addr)=dat;
#define   outp_h(addr, dat)     *(volatile UINT16*)(addr)=dat;
#define   outp_b(addr, dat)		*(volatile UINT8*)(addr)=dat;

#define u32READ(REG)			(*((volatile unsigned long *)(REG)))
#define u32WRITE(REG,DATA)		((*((volatile unsigned long *)(REG)))=(unsigned long)DATA)
	
#define RX_BUSY_MASK			0x80000
#define TX_BUSY_MASK			0x100000

typedef unsigned char  	BOOLEAN;
typedef unsigned char  	UINT8;
typedef signed   char   SINT8;
typedef unsigned short 	UINT16;
typedef signed   short 	SINT16;
typedef unsigned long  	UINT32;
typedef signed long    	SINT32;
typedef unsigned char  	BYTE;


