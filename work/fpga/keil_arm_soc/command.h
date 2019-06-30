#include "XA1707.h"



typedef enum {XOR_SUCCESS,XOR_FAIL} XORStatus;

void CmdSetChipID(void);
void CmdMiner(void);
void CmdMinerReset(void);
void CmdTestChip(void);
void CmdParaSet(void);
void CmdIPEnableSet(void);
void CmdRegWrite(void);
void CmdRegRead(void);
void CmdCheckChip(void);

UINT8 GetXOR(UINT8 *pbuff,UINT8 len);
UINT32 UINT8TOUINT32(UINT8 *buff);
UINT32 UINT8TOUINT32LittleEndin(UINT8 *buff);
void UINT32toUINT8(UINT8 *dst,UINT32 src);
UINT32 UINT32AddOne(UINT32 src);
void UINT32ToUINT8LittleEndin(UINT8 *dst,UINT32 src);


