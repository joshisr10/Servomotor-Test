// Dynamixel SDK platform dependent source
#include "dxl_hal.h"
#include "TMOUT1.h"
#include "WAIT1.h"
#include "AS1.h"
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "Bit2.h"
#include "BitIoLdd2.h"
#include "Bit3.h"
#include "BitIoLdd3.h"

static int timeout = 0;
static TMOUT1_CounterHandle tmch;

extern uint8_t TXComplete;

int dxl_hal_open( int devIndex, float baudrate )
{
	// Opening device
	// devIndex: Device index
	// baudrate: Real baudrate (ex> 115200, 57600, 38400...)
	// Return: 0(Failed), 1(Succeed)
	  AS1_Init();

	return 1;
}

void dxl_hal_close()
{
	// Closing device

}

void dxl_hal_clear(void)
{
	// Clear communication buffer
	AS1_ClearRxBuf();
	AS1_ClearTxBuf();
}

int dxl_hal_tx( unsigned char *pPacket, int numPacket )
{
	// Transmiting date
	// *pPacket: data array pointer
	// numPacket: number of data array
	// Return: number of data transmitted. -1 is error.
	unsigned short snd;

	TXComplete=0;

	/* Enable driver */
	Bit2_SetVal();
	Bit3_SetVal();

	AS1_SendBlock(pPacket,numPacket,&snd);
	return snd;
}

int dxl_hal_rx( unsigned char *pPacket, int numPacket )
{
	// Recieving date
	// *pPacket: data array pointer
	// numPacket: number of data array
	// Return: number of data recieved. -1 is error.
	unsigned short rcv;
	unsigned int nbofus = 0;

	/* Attendre la fin de la transmission */
	while(!TXComplete);

	/* Enable reception*/
	Bit2_ClrVal();
	Bit3_ClrVal();

	AS1_RecvBlock(pPacket,numPacket,&rcv);
	return rcv;
}

void dxl_hal_set_timeout( int NumRcvByte )
{
	// Start stop watch
	// NumRcvByte: number of recieving data(to calculate maximum waiting time)
	TMOUT1_Init();
	tmch = TMOUT1_GetCounter(NumRcvByte);
}

int dxl_hal_timeout(void)
{
	// Check timeout
	// Return: 0 is false, 1 is true(timeout occurred)
	if(TMOUT1_CounterExpired(tmch))
	{
		TMOUT1_LeaveCounter(tmch);
		return 1;
	}
	else
	{
		return 0;
	}
}
