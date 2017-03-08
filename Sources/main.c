/* ###################################################################
**     Filename    : main.c
**     Project     : motorTest
**     Processor   : MK64FN1M0VLQ12
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2017-03-07, 11:33, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "Pins1.h"
#include "Bit1.h"
#include "BitIoLdd1.h"
#include "Bit2.h"
#include "BitIoLdd2.h"
#include "Bit3.h"
#include "BitIoLdd3.h"
#include "AS1.h"
#include "ASerialLdd1.h"
#include "MCUC1.h"
#include "TMOUT1.h"
#include "CS1.h"
#include "WAIT1.h"
#include "TU1.h"
#include "TI1.h"
#include "TimerIntLdd1.h"
/* Including shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PDD_Includes.h"
#include "Init_Config.h"
/* User includes (#include below this line is not maintained by Processor Expert) */
#include "dxl_hal.h"
#include "dynamixel.h"

static uint16_t i=0;
/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */
	int PP=0;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */
  TMOUT1_Init();
  /* Set PTC17 to enable the board */
  Bit1_SetVal();
  WAIT1_Waitms(100);

  dxl_initialize( 1, 57600 );

  /* Get present position */
  PP = dxl_read_byte( 1, 36 );

  /* Locates at the position 180бу with the sppeed of 57RPM */
  /* Compose the message */
  dxl_set_txpacket_id( 1 );
  dxl_set_txpacket_length( 0x07 );
  dxl_set_txpacket_instruction( INST_WRITE );
  dxl_set_txpacket_parameter( 0, 0x1E );
  dxl_set_txpacket_parameter( 1, 0x00 );
  dxl_set_txpacket_parameter( 2, PP+5 );
  dxl_set_txpacket_parameter( 3, 0x00 );
  dxl_set_txpacket_parameter( 4, 0x01 );
  dxl_txrx_packet();

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
