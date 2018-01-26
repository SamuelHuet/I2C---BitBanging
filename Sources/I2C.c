/*
 * I2C.c
 *
 *  Created on: Dec 4, 2017
 *      Author: cocasticox
 */
#include "I2C.h"

void init_i2c(void) {
	unsigned char i;

	//PTADD_PTADD2 = OUT;
	//PTADD_PTADD3 = OUT;

	PTCDD_PTCDD0 = OUT;
	PTCDD_PTCDD1 = OUT;

	SDA = HIGH;
	SCL = HIGH;

	for (i = 0; i < 100; i++) {		//Temps de repos
		//do nothing
	}
}

//---------------------------------------------------------------------

void start_master_i2c(void) {



	SDA = LOW;		//condition de start

	
}

//---------------------------------------------------------------------

void stop_master_i2c(void) {
	unsigned char i;

	SDA = HIGH;					//Etat de repos
	SCL = HIGH;

	for (i = 0; i < 5; i++) {		//Temps de repos
		//do nothing
	}

}

//---------------------------------------------------------------------

void send_byte_i2c(unsigned char *octet) {
	unsigned char i;
	volatile unsigned char a;
	unsigned char b = *octet;
	unsigned char k;

	SCL = LOW;

	for (i = 0; i < 10; i++) {		//Temps de repos
		//do nothing
	}

	for (i = 0; i < 16; i++) {		//pour chaque bits

		if ((i & 0x01) == 0x00) {
			a = b & 0x80;			//on récupère le MSB
			a = a >> 7; 				//on le passe en LSB
			SDA = a;
			b = b << 1;				//Envois du bit
		}
		SCL = ~(i & 0x01);		//Switch de la clock
		for (k = 0; k < 9; k++) {		//Temps de repos
			//do nothing
		}
		//Bit suivant
	}
	SDA = HIGH;					//Etat de repos
	SCL = HIGH;
}

//---------------------------------------------------------------------

void ack_from_slave_i2c(void) {

	unsigned int i;
	unsigned char ask_ack = 0;
	SDAIO = IN;

	while (ask_ack == 0) {

		for (i = 0; i < 4; i++) {		//Temps de repos
			if (SDA == ACK) {
				ask_ack = 1;		//do nothing
			}

		}
		SCL = LOW;
	}
	SDAIO = OUT;
	SDA = HIGH;
	//SCL = HIGH;
	for (i = 0; i < 3; i++) {		//Temps de repos
		//do nothing
	}

}

//---------------------------------------------------------------------

void read_byte_i2c(unsigned char *octet) {

	unsigned char i;
	unsigned char k;
	volatile unsigned char a;
	unsigned char b = *octet;

	SDAIO = IN;

	for (i = 0; i < 16; i++) {		//pour chaque bits

		if ((i & 0x01) == 0x01) {
			//Récupération du bit
			if (SDA == HIGH) {
				a += 1;
				a = a << 1;
			} else if (SDA == LOW) {
				a = a << 1;
			}

		}
		SCL = ~(i & 0x01);		//Switch de la clock
		for (k = 0; k < 9; k++) {		//Temps de repos
			//do nothing
		}

		//Bit suivant
	}
	*octet = a;

	SDAIO = OUT;
	SDA = HIGH;					//Etat de repos
	//SCL = HIGH;

}

//--------------------------------------------------------

void ack_from_master_i2c(void) {

	unsigned char i;
	unsigned char k;

	SDA = LOW;

	for (i = 0; i < 2; i++) {		//pour chaque bits

		for (k = 0; k < 1; k++) {
			//do nothing
		}

		SCL = ~(i & 0x01);		//Switch de la clock
	}

	SDA = HIGH;

}
