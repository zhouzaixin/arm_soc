/***************************************************\
*			Copy Right(C)北京华大信安科技有限公司
*			 All Right Reserved
*
*文件名称：IS32U320A_uart.h
*作    者：李宪法
*版    本：V1.0.0
*日    期：2012.08.28
*功能描述：
*	      完成IS32U320A开发板uart通信的底层驱动所需
*		  的头文件定义
*历史记录：
*	1、 日期：
*		版本：
*		作者：
*	修改内容：
*	2、.....
\***************************************************/

#ifndef ___IS32U320A_UART_H__
#define ___IS32U320A_UART_H__

#include "typesmacro.h"
#include "XA1707.h"

//#define IS32U320AUARTENABLE 

typedef struct
{			   	
	UINT32 UART_RXStopBit;
	UINT32 UART_RXBitLen;
	UINT32 UART_RXParity;

	UINT32 UART_TXStopBit;
	UINT32 UART_TXBitLen;
	UINT32 UART_TXParity;

	UINT32 UART_IE;

}UARTCTRL_InitType;

#define UART_RXStopBit_1		0x0000
#define UART_RXStopBit_15		0x1000
#define UART_RXStopBit_2		0x2000

#define UART_RXBitLen_8			0x0000
#define UART_RXBitLen_7			0x0400
#define UART_RXBitLen_6			0x0800
#define UART_RXBitLen_5			0x0C00

#define UART_RXParity_NULL		0x0000
#define UART_RXParity_EVEN		0x0200
#define UART_RXParity_ODD		0x0100


#define UART_TXStopBit_1		0x0000
#define UART_TXStopBit_15		0x0020
#define UART_TXStopBit_2		0x0040

#define UART_TXBitLen_8			0x0000
#define UART_TXBitLen_7			0x0008
#define UART_TXBitLen_6			0x0010
#define UART_TXBitLen_5			0x0018

#define UART_TXParity_NULL		0x0000
#define UART_TXParity_EVEN		0x0004
#define UART_TXParity_ODD		0x0002

#define UART_IE_EN				0x0001
#define UART_IE_DIS				0x0000

#define UART1					0x0001
#define UART2					0x0002

typedef struct
{
	UINT32 UARTClk_Sel;
	UINT32 AHB_Div;
	UINT32 SYS_Div;
}UARTCLK_InitType;

#define UARTClk_Sel_APB			0x00
#define UARTClk_Sel_PLL			0x01

#define AHB_Div_0				0x00
#define AHB_Div_2				0x02

#define SYS_Div_0				0x00
#define SYS_Div_2				0x02
#define SYS_Div_4				0x04
#define SYS_Div_8				0x08

#define UART_RX_Mask			0xC0FF
#define UART_TX_Mask			0xFF81
#define UART_IE_Mask			0xFFFE
#define RX_BUSY_MASK			0x80000
#define TX_BUSY_MASK			0x100000

#ifndef UART_GLOBAL
#define UART_EXT	extern
#else
#define UART_EXT
#endif

UART_EXT UINT8 Uart0ReceiveBuffer[256];
UART_EXT UINT8 Uart0CommandData[256];
UART_EXT UINT8 Uart0SendBuffer[256];
UART_EXT UINT8 *pUart0;
UART_EXT UINT8 Uart1ReceiveBuffer[256];
UART_EXT UINT8 Uart1ResponseData[256];
UART_EXT UINT8 Uart1SendBuffer[256];
UART_EXT UINT8 *pUart1;
UART_EXT UINT8 Uart0ReceiveCounter;
UART_EXT UINT8 Uart1ReceiveCounter;
UART_EXT UINT8 CommandCome;
UART_EXT UINT8 ResponseCome;
UART_EXT UINT8 CommandLen;
UART_EXT UINT8 RepsonseLen;
UART_EXT UINT8 ChipID[4];

UART_EXT UINT32 BlakeAddressStart[16];
UART_EXT UINT32 ChipGoldNonce[16];
UART_EXT UINT32 ChipExtraData[16];
UART_EXT UINT8  BlakeEnable[16];
UART_EXT UINT32 ChipCT;

UART_EXT UINT32 UartClkInit(UARTCLK_InitType *UARTClk_Struct,unsigned char uartnumber);
UART_EXT void UartBaudRateInit(UARTCLK_InitType *UARTCLK_Struct,UINT32 UART_BaudRate,unsigned char uartnumber);
UART_EXT void Uart0SendData(UINT8 *pData);
UART_EXT void Uart0ReceiveData(UINT8 *pData);
UART_EXT void Uart1SendData(UINT8 *pData);
UART_EXT void Uart1ReceiveData(UINT8 *pData);
UART_EXT void UARTCONInit(UARTCTRL_InitType *UARTCTRL_InitStruct,unsigned char uartnumber);
UART_EXT void IS32U320AUartProcess(unsigned char uartnumber);
#endif
