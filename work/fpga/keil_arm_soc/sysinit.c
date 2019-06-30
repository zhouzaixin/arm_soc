#include "sysinit.h"

void UART0Configuration(void){
	UINT8 i; 
	
	//tmpreg = u32READ(NVIC_ISER);
	//outp_w(NVIC_ISER, tmpreg | 0x4);
	
	//tmpreg = u32READ(PCON);
	//outp_w(PCON, tmpreg | 0x4);
	for(i=0;i<32;i++);
	
	outp_w(UART0_BAUDFREQ,0x240);	   
  outp_w(UART0_BAUDLIMIT,0x3d09); 	
  //wait_for_uart0_int = 1;
 //------data form config,8-bit data,no parity,1-bit stop----
	outp_w(UART0_CON,0x01); 
}


