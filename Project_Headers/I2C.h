/*
 * I2C.h
 *
 *  Created on: Dec 4, 2017
 *      Author: cocasticox
 */


#ifndef I2C_H_
#define I2C_H_

#include "Cpu.h"
#include "Events.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#define SDA PTAD_PTAD2
#define SCL PTAD_PTAD3
#define SDAIO PTADD_PTADD2

#define OUT 1
#define IN 0

#define HIGH 1
#define LOW 0

#define ACK 0
#define NACK 1


void init_i2c(void);
void start_master_i2c(void);
void stop_master_i2c(void);
void ack_from_master_i2c(void);
void nack_from_master_i2c(void);
void ack_from_slave_i2c(void);
void read_byte_i2c(unsigned char *octet);
void send_byte_i2c(unsigned char *octet);

#endif /* I2C_H_ */
