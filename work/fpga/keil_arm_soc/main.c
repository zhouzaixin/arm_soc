#include <string.h>
#include "XA1707.h"
#include "uart.h"
#include "sysinit.h"
#include "command.h"


int main()
{	
		unsigned char i=0;
		UART0Configuration(); 
		
		memset(Uart0ReceiveBuffer, 0x0, 256);
		memset(Uart0SendBuffer, 0x0, 256);
	 
		Uart0SendBuffer[0]=0xEE;
	  Uart0SendBuffer[1]=0xBB;
	  Uart0SendBuffer[2]=0x10;
	  Uart0SendBuffer[3]=0x90;
	  Uart0SendBuffer[4]=0x90;
	  Uart0SendBuffer[5]=0x90;
	  Uart0SendBuffer[6]=0x90;
	  Uart0SendBuffer[7]=0x03; 
	
	  while(1){
	  for(i=0;i<8;i++)
  	{
	  	Uart0SendData(&Uart0SendBuffer[i]);
	  }
	}
}
