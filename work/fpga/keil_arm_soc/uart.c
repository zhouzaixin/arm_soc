/***************************************************\
*			Copy Right(C)北京华大信安科技有限公司
*			 All Right Reserved
*
*文件名称：IS32U320A_uart.c
*作    者：
*版    本：V1.0.0
*日    期：2015.02.05
*功能描述：完成IS32U320A开发板uart通信的底层驱动
*函数列表：
*			1、
*			2、
*			3、
*历史记录：
*	1、 日期：
*		版本：
*		作者：
*	修改内容：
*	2、.....
\***************************************************/
#define UART_GLOBAL
#include <string.h>
#include "uart.h"	
#include "XA1707.h"


/***************************************************\
*函数名称：Uart0SendData
*函数功能：完成uart1接口发送数据操作
*输入参数：无	       
*输出参数：无
*返 回 值：无
*其它说明：
\***************************************************/
void Uart0SendData(UINT8 *pData)
{
	UINT32 tmpreg=0x0;

	u32WRITE(UART0_TXDATA,(*pData));
	
	do
	{
		tmpreg = u32READ(UART0_CON);
		tmpreg &= TX_BUSY_MASK;	
	}while(tmpreg==TX_BUSY_MASK);
}
/***************************************************\
*函数名称：Uart1SendData
*函数功能：完成uart1接口发送数据操作
*输入参数：无	       
*输出参数：无
*返 回 值：无
*其它说明：
\***************************************************/
void Uart1SendData(UINT8 *pData)
{
	UINT32 tmpreg=0x0;
	
	u32WRITE(UART1_TXDATA,(*pData));

	do
	{
		tmpreg = u32READ(UART1_CON);
		tmpreg &= TX_BUSY_MASK;	
	}while(tmpreg==TX_BUSY_MASK);
}
/***************************************************\
*函数名称：UartReceiveData
*函数功能：完成uart1接口接收数据操作
*输入参数：无	       
*输出参数：无
*返 回 值：无
*其它说明：
\***************************************************/
void Uart0ReceiveData(UINT8 *pData)
{
	UINT32 tmpreg=0x0;
//	do
//	{
//		tmpreg = u32READ(UART0_CON);
//		tmpreg &= RX_BUSY_MASK;
//	}while(tmpreg==RX_BUSY_MASK);
	tmpreg = u32READ(UART0_RXDATA);
	*pData = (UINT8)(tmpreg);
}
/***************************************************\
*函数名称：Uart1ReceiveData
*函数功能：完成uart1接口接收数据操作
*输入参数：无	       
*输出参数：无
*返 回 值：无
*其它说明：
\***************************************************/
void Uart1ReceiveData(UINT8 *pData)
{
	UINT32 tmpreg=0x0;
	
	tmpreg = u32READ(UART1_RXDATA);
	*pData = (UINT8)(tmpreg);
}
/***************************************************\
*函数名称：UartProcess
*函数功能：完成uart1接口相应操作
*输入参数：无	       
*输出参数：无
*返 回 值：无
*其它说明：
\***************************************************/
void UartProcess(unsigned char uartnumber)
{
	
}
