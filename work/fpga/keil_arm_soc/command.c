#include <string.h>
#include "command.h"
#include "uart.h"

void CmdSetChipID()//FFAA0A01000000000102030405
{
	UINT8 i=0;
	UINT8 Len=0;
	UINT8 MAC = 0;
	MAC = GetXOR(Uart0CommandData+3,9);
	Len=Uart0CommandData[2];
	if(Len != 0x0A)//Command Len Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x08;
		Uart0SendBuffer[3]=Uart0CommandData[4];
		Uart0SendBuffer[4]=Uart0CommandData[5];
		Uart0SendBuffer[5]=Uart0CommandData[6];
		Uart0SendBuffer[6]=Uart0CommandData[7];
		Uart0SendBuffer[7]=0x01;
		Uart0SendBuffer[8]=0x67;
		Uart0SendBuffer[9]=0x00;
		Uart0SendBuffer[10]=GetXOR(Uart0SendBuffer+3,7);
		for(i=0;i<11;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	if(Uart0CommandData[12]!=MAC)//MAC Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x08;
		Uart0SendBuffer[3]=Uart0CommandData[4];
		Uart0SendBuffer[4]=Uart0CommandData[5];
		Uart0SendBuffer[5]=Uart0CommandData[6];
		Uart0SendBuffer[6]=Uart0CommandData[7];
		Uart0SendBuffer[7]=0x01;
		Uart0SendBuffer[8]=0x6A;
		Uart0SendBuffer[9]=0x86;
		Uart0SendBuffer[10]=GetXOR(Uart0SendBuffer+3,7);
		for(i=0;i<11;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	if((ChipID[1]==Uart0CommandData[5])&&(ChipID[2]==Uart0CommandData[6])&&(ChipID[3]==Uart0CommandData[7]))
	{
		ChipID[0]=0;
		ChipID[1]=Uart0CommandData[9];
		ChipID[2]=Uart0CommandData[10];
		ChipID[3]=Uart0CommandData[11];
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x08;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x01;
		Uart0SendBuffer[8]=0x90;
		Uart0SendBuffer[9]=0x00;
		Uart0SendBuffer[10]=GetXOR(Uart0SendBuffer+3,7);
		for(i=0;i<11;i++)
			Uart0SendData(&Uart0SendBuffer[i]);
	}
	else
	{
		for(i=0;i<(Len+2+1);i++)
			Uart1SendData(&Uart0CommandData[i]);
	}
}

void CmdTestChip()
{
	UINT8 i=0;
	UINT8 Len=0;
	UINT32 tmpdata = 0x00;
	UINT8 MAC = 0;
	UINT8 BlakeIndex=0;
	
	MAC = GetXOR(Uart0CommandData+3,0x65);
	Len=Uart0CommandData[2];
	
	if(Len != 0x66)//Command Len Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x28;
		Uart0SendBuffer[3]=Uart0CommandData[4];
		Uart0SendBuffer[4]=Uart0CommandData[5];
		Uart0SendBuffer[5]=Uart0CommandData[6];
		Uart0SendBuffer[6]=Uart0CommandData[7];
		Uart0SendBuffer[7]=0x02;
		for( i = 0; i < 32; i++){
			Uart0SendBuffer[i+8] = Uart0CommandData[i+8];
		}
		Uart0SendBuffer[40]=0x67;
		Uart0SendBuffer[41]=0x00;
		Uart0SendBuffer[42]=GetXOR(Uart0SendBuffer+3,0x27);
		for(i=0;i<43;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	if(Uart0CommandData[104]!=MAC)//MAC Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x28;
		Uart0SendBuffer[3]=Uart0CommandData[4];
		Uart0SendBuffer[4]=Uart0CommandData[5];
		Uart0SendBuffer[5]=Uart0CommandData[6];
		Uart0SendBuffer[6]=Uart0CommandData[7];
		Uart0SendBuffer[7]=0x02;
		for( i = 0; i < 32; i++){
			Uart0SendBuffer[i+8] = Uart0CommandData[i+8];
		}
		Uart0SendBuffer[40]=0x6A;
		Uart0SendBuffer[41]=0x86;
		Uart0SendBuffer[42]=GetXOR(Uart0SendBuffer+3,0x27);
		for(i=0;i<43;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	else if((ChipID[1]==Uart0CommandData[5])&&(ChipID[2]==Uart0CommandData[6])&&(ChipID[3]==Uart0CommandData[7]))
	{
		//...packthe response
		BlakeIndex=	Uart0CommandData[4];
    if(BlakeIndex>=BLAKE_MAX_NUM)
		{
			Uart0SendBuffer[0]=0xEE;
			Uart0SendBuffer[1]=0xBB;
			Uart0SendBuffer[2]=0x28;
			Uart0SendBuffer[3]=Uart0CommandData[4];
			Uart0SendBuffer[4]=Uart0CommandData[5];
			Uart0SendBuffer[5]=Uart0CommandData[6];
			Uart0SendBuffer[6]=Uart0CommandData[7];
			Uart0SendBuffer[7]=0x02;
			for( i = 0; i < 32; i++){
				Uart0SendBuffer[i+8] = Uart0CommandData[i+8];
			}
			Uart0SendBuffer[40]=0x68;
			Uart0SendBuffer[41]=0x01;
			Uart0SendBuffer[42]=GetXOR(Uart0SendBuffer+3,0x27);
			for(i=0;i<43;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
			return ;
		}

		
		u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_RST,0x1);

		for(i=0;i<0x20;i++);
		
		for(i=0;i<32;i+=4)//IV
		{
			tmpdata = UINT8TOUINT32(Uart0CommandData+i+8);
			u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_IV+i, tmpdata);
		}	
		for(i=0;i<64;i+=4)//data
		{
			tmpdata = UINT8TOUINT32(Uart0CommandData+i+40);
			u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_DI+i, tmpdata);
		}	
		
		u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_CT,ChipCT);
		
		u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_OPER,0);
		
		u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_START,0x1);
		
		tmpdata=u32READ(BlakeAddressStart[BlakeIndex]+BLAKE_DONE);
		while((tmpdata&0x1)!=0x1)  tmpdata=u32READ(BlakeAddressStart[BlakeIndex]+BLAKE_DONE);
	
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x28;
		Uart0SendBuffer[3]=BlakeIndex;
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x02;
		for(i=0;i<32;i+=4)
		{
			tmpdata = u32READ(BlakeAddressStart[BlakeIndex]+BLAKE_DO+i);
		  UINT32toUINT8(&Uart0SendBuffer[i+8],tmpdata);
		}
		Uart0SendBuffer[40]=0x90;
		Uart0SendBuffer[41]=0x00;
		Uart0SendBuffer[42]=GetXOR(Uart0SendBuffer+3,0x27);
		
		u32WRITE(GPIODATA,0x0);  //GPIO0  0  
		for(i=0;i<0x20;i++);
		
		for(i=0;i<43;i++)//43=3+4+1+32+2+1
					Uart0SendData(&Uart0SendBuffer[i]);
	}
	else//do not deal with the apdu just move to next chip
	{
		for(i=0;i<(Len+2+1);i++)
					Uart1SendData(&Uart0CommandData[i]);
	}
	
}

void CmdMiner()
{
	UINT32 i=0;
	UINT32 Len=0;
	UINT32 tmpdata = 0x00;
	UINT32 ExtraData=0;
  UINT8  MAC = 0;
	UINT8  index=0;
	
	MAC= GetXOR(Uart0CommandData+3,0x69);
	Len=Uart0CommandData[2];
	if(Len != 0x6A)//command Len Error
	{	
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x10;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x03;
		for( i = 0; i < 8; i++){
			Uart0SendBuffer[i+8] = 0x00;
		}
		Uart0SendBuffer[16]=0x67;
		Uart0SendBuffer[17]=0x00;
		Uart0SendBuffer[18]=GetXOR(Uart0SendBuffer+3,0x0F);
		for(i=0;i<19;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	if(Uart0CommandData[108]!=MAC)//MAC Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x10;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x03;
		for( i = 0; i < 8; i++){
			Uart0SendBuffer[i+8] = 0x00;
		}
		Uart0SendBuffer[16]=0x6A;
		Uart0SendBuffer[17]=0x86;
		Uart0SendBuffer[18]=GetXOR(Uart0SendBuffer+3,0x0F);
		for(i=0;i<19;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	
		//make the next chip to start miner at the same time
		for(i=0;i<(Len+2+1);i++)
					Uart1SendData(&Uart0CommandData[i]);
		//move data to IP regester then start the IP
		//extranonce = extranonce + 0x10000*chipID
		ExtraData = UINT8TOUINT32LittleEndin(Uart0CommandData+60);
		ExtraData += 0x10000*UINT8TOUINT32(ChipID);

		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x10;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x03;
		Uart0SendBuffer[16]=0x90;
		Uart0SendBuffer[17]=0x00;
	
	  //miner led off
		u32WRITE(GPIODATA,0x1);  //GPIO0  1
	
	
	  for(index=0;index<BLAKE_MAX_NUM;index++)
		{
			if(BlakeEnable[index]==1)
			{
				u32WRITE(BlakeAddressStart[index]+BLAKE_RST,0x1);
				
				//rst delay
				for(i=0;i<0x20;i++);
		
				//difficult
				for(i=0;i<8;i+=4)
				{
					tmpdata = UINT8TOUINT32(Uart0CommandData+i+4);
					u32WRITE(BlakeAddressStart[index]+BLAKE_DIF+i, tmpdata);
				}	
				//IV
				for(i=0;i<32;i+=4)
				{
					tmpdata = UINT8TOUINT32(Uart0CommandData+i+12);
					u32WRITE(BlakeAddressStart[index]+BLAKE_IV+i, tmpdata);
				}	
	      //set ExtraData for each IP
				UINT32ToUINT8LittleEndin(&Uart0CommandData[60],ExtraData+index*3000);
	
				//set Data for IP
				for(i=0;i<64;i+=4)
				{
					tmpdata = UINT8TOUINT32(Uart0CommandData+i+44);
					u32WRITE(BlakeAddressStart[index]+BLAKE_DI+i, tmpdata);
				}	
		
				u32WRITE(BlakeAddressStart[index]+BLAKE_CT,ChipCT);
		
				u32WRITE(BlakeAddressStart[index]+BLAKE_OPER,1);
		
				u32WRITE(BlakeAddressStart[index]+BLAKE_START,0x1);
			}//endif
		}//end for
		
   
}

void CmdMinerReset()
{
	UINT8 i=0;
	UINT8 Len=0;
	UINT8 MAC = 0;
	
	MAC = GetXOR(Uart0CommandData+3,0x1);
	Len=Uart0CommandData[2];
	if(Len != 0x02)//Command Len Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x08;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x04;
		Uart0SendBuffer[8]=0x67;
		Uart0SendBuffer[9]=0x00;
		Uart0SendBuffer[10]=GetXOR(Uart0SendBuffer+3,0x07);
		for(i=0;i<11;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	if(Uart0CommandData[4]!=MAC)//MAC Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x08;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x04;
		Uart0SendBuffer[8]=0x6A;
		Uart0SendBuffer[9]=0x86;
		Uart0SendBuffer[10]=GetXOR(Uart0SendBuffer+3,0x07);
		for(i=0;i<11;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
		//make the next chip rst at the same time
		for(i=0;i<(Len+2+1);i++)
					Uart1SendData(&Uart0CommandData[i]);
		//IP soft reset
	  for(i=0;i<BLAKE_MAX_NUM;i++)
			{
					u32WRITE(BlakeAddressStart[i]+BLAKE_RST,0x1);
			 }//end for
		
		//rst delay
		for(i=0;i<0x20;i++);
		
		//off led
		u32WRITE(GPIODATA,0x1);

}

void CmdParaSet()
{
	UINT8 i=0;
	UINT8 Len=0;
	UINT8 MAC = 0;
	MAC = GetXOR(Uart0CommandData+3,0x5);
	Len=Uart0CommandData[2];
	if(Len != 0x06)//Command Len Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x08;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x05;
		Uart0SendBuffer[8]=0x67;
		Uart0SendBuffer[9]=0x00;
		Uart0SendBuffer[10]=GetXOR(Uart0SendBuffer+3,0x07);
		for(i=0;i<11;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	if(Uart0CommandData[8]!=MAC)//MAC Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x08;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x05;
		Uart0SendBuffer[8]=0x6A;
		Uart0SendBuffer[9]=0x86;
		Uart0SendBuffer[10]=GetXOR(Uart0SendBuffer+3,0x07);
		for(i=0;i<11;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
		//make the next chip same CT
		for(i=0;i<(Len+2+1);i++)
					Uart1SendData(&Uart0CommandData[i]);
	  
		ChipCT=UINT8TOUINT32(Uart0CommandData+4);
}

void CmdIPEnableSet()
{
	UINT8 i=0;
	UINT8 Len=0;
	UINT8 MAC = 0;
	
	MAC = GetXOR(Uart0CommandData+3,0x15);
	Len=Uart0CommandData[2];
	
	if(Len != 0x16)//Command Len Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x18;
		Uart0SendBuffer[3]=Uart0CommandData[4];
		Uart0SendBuffer[4]=Uart0CommandData[5];
		Uart0SendBuffer[5]=Uart0CommandData[6];
		Uart0SendBuffer[6]=Uart0CommandData[7];
		Uart0SendBuffer[7]=0x06;
		for( i = 0; i < 16; i++){
			Uart0SendBuffer[i+8] = Uart0CommandData[i+8];
		}
		Uart0SendBuffer[24]=0x67;
		Uart0SendBuffer[25]=0x00;
		Uart0SendBuffer[26]=GetXOR(Uart0SendBuffer+3,23);
		for(i=0;i<27;i++)//27=3+0x18
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	if(Uart0CommandData[24]!=MAC)//MAC Error
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x18;
		Uart0SendBuffer[3]=Uart0CommandData[4];
		Uart0SendBuffer[4]=Uart0CommandData[5];
		Uart0SendBuffer[5]=Uart0CommandData[6];
		Uart0SendBuffer[6]=Uart0CommandData[7];
		Uart0SendBuffer[7]=0x06;
		for( i = 0; i < 16; i++){
			Uart0SendBuffer[i+8] = Uart0CommandData[i+8];
		}
		Uart0SendBuffer[24]=0x6A;
		Uart0SendBuffer[25]=0x86;
		Uart0SendBuffer[26]=GetXOR(Uart0SendBuffer+3,23);
		for(i=0;i<27;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	else if((ChipID[1]==Uart0CommandData[5])&&(ChipID[2]==Uart0CommandData[6])&&(ChipID[3]==Uart0CommandData[7]))
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x18;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x06;
		for( i = 0; i < 16; i++){
			BlakeEnable[i] = Uart0CommandData[i+8];
		}
		for( i = 0; i < 16; i++){
			Uart0SendBuffer[i+8] = BlakeEnable[i];
		}
		Uart0SendBuffer[24]=0x90;
		Uart0SendBuffer[25]=0x00;
		Uart0SendBuffer[26]=GetXOR(Uart0SendBuffer+3,23);
		
		for(i=0;i<27;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
	}
	else//do not deal with the apdu just move to next chip
	{
		for(i=0;i<(Len+2+1);i++)
					Uart1SendData(&Uart0CommandData[i]);
	}
	
}

void CmdRegWrite()
{
	UINT8 i=0;
	UINT8 Len=0;
	UINT8 RegLen=0;
	UINT32 RegAddress=0;
	UINT32 RegData=0;
	Len=Uart0CommandData[2];
	RegLen=Uart0CommandData[8];
	if((ChipID[1]==Uart0CommandData[5])&&(ChipID[2]==Uart0CommandData[6])&&(ChipID[3]==Uart0CommandData[7]))
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x07;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x07;
		for( i = 0; i < RegLen; i++){
			RegAddress=UINT8TOUINT32(&Uart0CommandData[9+8*i]);
			RegData=UINT8TOUINT32(&Uart0CommandData[9+8*i+4]);
			u32WRITE(RegAddress,RegData);
		}
		Uart0SendBuffer[8]=0x90;
		Uart0SendBuffer[9]=0x00;
		for(i=0;i<10;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
	}
	else//do not deal with the apdu just move to next chip
	{
		for(i=0;i<(Len+2+1);i++)
					Uart1SendData(&Uart0CommandData[i]);
	}
}

void CmdRegRead()
{
	UINT8 i=0;
	UINT8 Len=0;
	UINT8 RegLen=0;
	UINT32 RegAddress=0;
	UINT32 RegData=0;
	Len=Uart0CommandData[2];
	RegLen=Uart0CommandData[8];
	if((ChipID[1]==Uart0CommandData[5])&&(ChipID[2]==Uart0CommandData[6])&&(ChipID[3]==Uart0CommandData[7]))
	{
		Uart0SendBuffer[0]=0xEE;
		Uart0SendBuffer[1]=0xBB;
		Uart0SendBuffer[2]=0x7+RegLen*4;
		Uart0SendBuffer[3]=ChipID[0];
		Uart0SendBuffer[4]=ChipID[1];
		Uart0SendBuffer[5]=ChipID[2];
		Uart0SendBuffer[6]=ChipID[3];
		Uart0SendBuffer[7]=0x08;
		for( i = 0; i < RegLen; i++)
		{
			RegAddress=UINT8TOUINT32(&Uart0CommandData[9+4*i]);
			if(RegAddress == 0xFFFFFFFF)
			{
				RegData = 0x30;
			}else
      {
				RegData=u32READ(RegAddress);
			}
			UINT32toUINT8(&Uart0SendBuffer[4*i+8],RegData);
		}
		Uart0SendBuffer[8+RegLen*4]=0x90;
		Uart0SendBuffer[9+RegLen*4]=0x00;
		for(i=0;i<10+RegLen*4;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
	}
	else//do not deal with the apdu just move to next chip
	{
		for(i=0;i<(Len+2+1);i++)
					Uart1SendData(&Uart0CommandData[i]);
	}
}

void CmdCheckChip()
{
	UINT8 i=0;
	UINT8 Len=0;
	UINT32 tmpdata = 0x00;
	UINT8 BlakeIndex=0;
	
	//IV
	UINT32 IV[8]={0xed04da39,0x2af73656,0x90bb2f8d,0xe7ff0a1e,0xc3dfc15c,0x858a3980,0x85e31807,0x2649889b};
	//data
	UINT32 data[16]={0xaa430200,0xca420000,0x71285e59,0x04af912c,0x00040000,0x0a000000,0xe300151d,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x04000000,0x80000001,0x00000000,0x000005A0};
	//hash
	UINT32 hash[8]={0xc29dcfaf,0x38d64688,0x26e28776,0xb2bf54d3,0x7c79bf02,0xb6dc94bf,0x893287cc,0x00000000};
	
	Len=Uart0CommandData[2];
	
	u32WRITE(GPIODATA,0x0);  //GPIO0  0  
	for(i=0;i<0x20;i++);
	
	if(Len != 0x02)//Command Len Error
	{
		Uart0SendBuffer[0]=0x00;
		Uart0SendBuffer[1]=0x80;
		Uart0SendBuffer[2]=0x00;
		
		u32WRITE(GPIODATA,0x1);  //GPIO0  1  
		for(i=0;i<0x20;i++);
		
		for(i=0;i<3;i++)
					Uart0SendData(&Uart0SendBuffer[i]);
		return ;
	}
	
	Uart0SendBuffer[0]=0x00;
	Uart0SendBuffer[1]=0x00;
	Uart0SendBuffer[2]=0x00;
	
	for(BlakeIndex = 0; BlakeIndex < BLAKE_MAX_NUM;BlakeIndex++)
	{
		u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_RST,0x1);

		for(i=0;i<0x20;i++);
		
		for(i=0;i<8;i++)//IV
		{
			u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_IV+4*i, IV[i]);
		}	
		for(i=0;i<16;i++)//data
		{
			u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_DI+4*i, data[i]);
		}	
		
		u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_CT,ChipCT);
		
		u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_OPER,0);
		
		u32WRITE(BlakeAddressStart[BlakeIndex]+BLAKE_START,0x1);
		
		tmpdata=u32READ(BlakeAddressStart[BlakeIndex]+BLAKE_DONE);
		while((tmpdata&0x1)!=0x1)  tmpdata=u32READ(BlakeAddressStart[BlakeIndex]+BLAKE_DONE);
		
		for(i=0;i<8;i++)
		{
			tmpdata = u32READ(BlakeAddressStart[BlakeIndex]+BLAKE_DO+4*i);
		  if(tmpdata != hash[i])
			{
				if(BlakeIndex <= 7){
					Uart0SendBuffer[2] ^= (0x1 << BlakeIndex);
				}else if(BlakeIndex >7){
					Uart0SendBuffer[1] ^= (0x1 << (BlakeIndex-8));
				}
				break;
			}
		}
	}
	if((Uart0SendBuffer[1] == 0x00) && (Uart0SendBuffer[2] == 0x00))
	{
		Uart0SendBuffer[0] = 0x55;
	}
		u32WRITE(GPIODATA,0x1);  //GPIO0  1  
		for(i=0;i<0x20;i++);
		
		for(i=0;i<3;i++)//3=1+2
					Uart0SendData(&Uart0SendBuffer[i]);	
}


UINT8 GetXOR(UINT8 *pbuff,UINT8 len)
{
	UINT8 xr=0x0;
	while(len)
	{
		xr ^= *pbuff++;
		len--;
	}

	return xr;
}

UINT32 UINT8TOUINT32(UINT8 *buff){
	UINT32 tmp = 0x00;
	tmp = (buff[0] << 24) | (buff[1] << 16) | (buff[2] << 8) | (buff[3] << 0);
	return tmp;
}

UINT32 UINT8TOUINT32LittleEndin(UINT8 *buff){
	UINT32 tmp = 0x00;
	tmp = (buff[3] << 24) | (buff[2] << 16) | (buff[1] << 8) | (buff[0] << 0);
	return tmp;
}

void UINT32toUINT8(UINT8 *dst,UINT32 src)
{
	
	dst[0] = (UINT8)((src&0xFF000000) >> 24);
	dst[1] = (UINT8)((src&0x00FF0000) >> 16);
	dst[2] = (UINT8)((src&0x0000FF00) >> 8);
	dst[3] = (UINT8)((src&0x000000FF) >>0 );

}

void UINT32ToUINT8LittleEndin(UINT8 *dst,UINT32 src)
{
	dst[3] = (UINT8)((src&0xFF000000) >> 24);
	dst[2] = (UINT8)((src&0x00FF0000) >> 16);
	dst[1] = (UINT8)((src&0x0000FF00) >> 8);
	dst[0] = (UINT8)((src&0x000000FF) >>0 );
	
}

UINT32 UINT32AddOne(UINT32 src)
{
	UINT8 bsrc[4]={0};
	UINT32 dst=0;
	bsrc[3] = (UINT8)((src&0xFF000000) >> 24);
	bsrc[2] = (UINT8)((src&0x00FF0000) >> 16);
	bsrc[1] = (UINT8)((src&0x0000FF00) >> 8);
	bsrc[0] = (UINT8)((src&0x000000FF) >>0 );
	dst=UINT8TOUINT32(bsrc);
	dst++;
	bsrc[3] = (UINT8)((dst&0xFF000000) >> 24);
	bsrc[2] = (UINT8)((dst&0x00FF0000) >> 16);
	bsrc[1] = (UINT8)((dst&0x0000FF00) >> 8);
	bsrc[0] = (UINT8)((dst&0x000000FF) >>0 );
	dst=UINT8TOUINT32(bsrc);
	return dst;
}

