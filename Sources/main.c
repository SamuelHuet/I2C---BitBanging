/* ###################################################################
 **     Filename    : main.c
 **     Project     : I2Cbis
 **     Processor   : MC9S08QE8CLC
 **     Version     : Driver 01.12
 **     Compiler    : CodeWarrior HCS08 C Compiler
 **     Date/Time   : 2017-12-04, 17:27, # CodeGen: 0
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
 ** @version 01.12
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
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "I2C.h"

/* User includes (#include below this line is not maintained by Processor Expert) */

void main(void) {
	/* Write your local variable definition here */

	unsigned char address = 0x90;
	unsigned char add = 0x90;
	unsigned char data = 0x40;
	unsigned char atad = 0x55;
	unsigned int i;
	unsigned char read1 = 0x94;
	unsigned char read2 = 0x94;
	unsigned char read3 = 0x94;
	unsigned char read4 = 0x94;

	unsigned char temp = 0;
	/*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
	PE_low_level_init();
	/*** End of Processor Expert internal initialization.                    ***/
	for (;;) {
		init_i2c();
		start_master_i2c();

		/*
		 send_byte_i2c(&add);
		 ack_from_slave_i2c();
		 send_byte_i2c(&data);
		 ack_from_slave_i2c();
		 stop_master_i2c();
		 init_i2c(); */

		send_byte_i2c(&address);
		ack_from_slave_i2c();
		send_byte_i2c(&data);
		ack_from_slave_i2c();
		send_byte_i2c(&atad);
		ack_from_slave_i2c();
		//read_byte_i2c(&read1);
		//ack_from_slave_i2c();

		/*
		 read_byte_i2c(&read1);
		 ack_from_master_i2c();
		 read_byte_i2c(&read2);
		 ack_from_master_i2c();
		 read_byte_i2c(&read3);
		 ack_from_master_i2c();
		 read_byte_i2c(&read4);
		 */
		asm {
			NOP
		}

		stop_master_i2c();
	}
	/*	
	 for(;;){

	 if (atad == 0xFF){
	 temp = 1;
	 }else if (atad == 0x00) {
	 temp = 0;
	 }
	 
	 if (temp == 0){
	 atad++;
	 
	 }else{
	 atad--;
	 }
	 
	 send_byte_i2c(&atad);
	 ack_from_slave_i2c();
	 }
	 
	 
	 
	 
	 
	 

	 /*
	 send_byte_i2c(&address);
	 ack_from_slave_i2c();
	 send_byte_i2c(&atad);
	 ack_from_slave_i2c();
	 */

	/*
	 for (;;) {

	 start_master_i2c(); 
	 send_byte_i2c(&address);
	 ack_from_slave_i2c();
	 send_byte_i2c(&data);
	 ack_from_slave_i2c();
	 stop_master_i2c();

	 for (i = 0; i < 60000; i++) {
	 //do nothing
	 }
	 start_master_i2c();
	 send_byte_i2c(&address);
	 ack_from_slave_i2c();
	 send_byte_i2c(&atad);
	 ack_from_slave_i2c();
	 stop_master_i2c();

	 for (i = 0; i < 60000; i++) {
	 //do nothing
	 }
	 }
	 */

	stop_master_i2c();

	/* Write your code here */
	/* For example: for(;;) { } */

	/*** Don't write any code pass this line, or it will be deleted during code generation. ***/
	/*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
#ifdef PEX_RTOS_START
	PEX_RTOS_START(); /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
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
 **     This file was created by Processor Expert 10.3 [05.09]
 **     for the Freescale HCS08 series of microcontrollers.
 **
 ** ###################################################################
 */
