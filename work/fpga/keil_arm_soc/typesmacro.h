/************************************************************/
/*				Copy Right (C) HED.Inc						*/
/*				All Right Reserved							*/
/*文件名称：IS32U320A_typesmacro.h							*/
/*作    者：												*/
/*当前版本：V1.0.0											*/
/*日    期：2012-08-26										*/
/*功能描述：	   											*/
/*		  本文件用于定义IS32U320A芯片所用到的类型定义和宏  */
/*修改内容：初版做成										*/
/************************************************************/
#ifndef __TYPEMARCO_H__
#define __TYPEMARCO_H__
//#define u8READ(REG)				(*((volatile unsigned char *)(REG)))
//#define u8WRITE(REG,DATA)		((*(( volatile unsigned char *)(REG)))=(unsigned char)DATA)
//#define u16READ(REG)			(*(( volatile unsigned short *)(REG)))
//#define u16WRITE(REG,DATA)		((*(( volatile unsigned short *)(REG)))=(unsigned short)DATA)
#define u32READ(REG)			(*((volatile unsigned long *)(REG)))
#define u32WRITE(REG,DATA)		((*((volatile unsigned long *)(REG)))=(unsigned long)DATA)
//#define inp_w(REG)			(*(( volatile unsigned long *)(REG)))
//#define outp_w(REG,DATA)		((*((volatile unsigned long *)(REG)))=(unsigned long)DATA)

// #define u8READ(REG)				(*((unsigned char *)(REG)))
// #define u8WRITE(REG,DATA)		((*((unsigned char *)(REG)))=DATA)
// #define u16READ(REG)			(*((unsigned short *)(REG)))
// #define u16WRITE(REG,DATA)		((*((unsigned short *)(REG)))=DATA)
// #define u32READ(REG)			(*((unsigned long *)(REG)))
// #define u32WRITE(REG,DATA)		((*((unsigned long *)(REG)))=DATA)
// #define inp_w(REG)			(*((unsigned long *)(REG)))
// #define outp_w(REG,DATA)		((*((unsigned long *)(REG)))=DATA)
//#define read(REG)				(*((unsigned char *)(REG)))
#ifndef UINT8
typedef unsigned char UINT8;
#endif

#ifndef pUINT8
typedef unsigned char *pUINT8;
#endif

#ifndef UINT16
typedef unsigned short UINT16;
#endif

#ifndef pUINT16
typedef unsigned short *pUINT16;
#endif

#ifndef UINT32
typedef unsigned long UINT32;
#endif

#ifndef pUINT32
typedef unsigned long *pUINT32;
#endif

#ifndef BYTE
typedef unsigned char BYTE;
#endif

#ifndef pBYTE
typedef unsigned char *pBYTE;
#endif

#ifndef WORD
typedef unsigned long WORD;
#endif

#ifndef pWORD
typedef unsigned char *pWORD;
#endif

typedef enum {DISABLE=0,ENABLE=!DISABLE} EnableCmd;
typedef enum {IRQ=0,FIQ=!IRQ} IntAttribute;

#ifndef SUCCESS
#define SUCCESS		0x00
#endif

#ifndef FAIL
#define FAIL		0x01
#endif

#ifndef TRUE
#define TRUE		0x00
#endif

#ifndef FALSE
#define FALSE		0x01
#endif

#endif
