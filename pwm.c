/*
 * pwm.c
 *
 *  Created on: 14 nov. 2019
 *      Author: David
 */
#include <MKL25Z4.H>
#include "pwm.h"
void PWM (int pin,int hz, int duty){
	int cicle;
	int hertz;
	hertz=((41980000/hz)/16);
	cicle=(hertz*duty)/100;
	if(pin==12){
	SIM->SCGC5 |= 0x200; /* enable clock to Port D */
	PORTA->PCR[12] = 0x0300; /* PTD1 used by TPM0 */
	SIM->SCGC6 |= 0x02000000; /* enable clock to TPM0 */
	SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
	TPM1->SC = 0; /* disable timer */
	TPM1->CONTROLS[0].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
	TPM1->MOD = hertz; /* Set up modulo register for 60 kHz */
	TPM1->CONTROLS[0].CnV = cicle; /* Set up channel value for 33% dutycycle */
	TPM1->SC = 0x0C; /* enable TPM0 with prescaler /16 */
} else if(pin ==13){

	SIM->SCGC5 |= 0x200; /* enable clock to Port D */
		PORTA->PCR[13] = 0x0300; /* PTD1 used by TPM0 */
		SIM->SCGC6 |= 0x02000000; /* enable clock to TPM0 */
		SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
		TPM1->SC = 0; /* disable timer */
		TPM1->CONTROLS[1].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
		TPM1->MOD = hertz; /* Set up modulo register for 60 kHz */
		TPM1->CONTROLS[1].CnV = cicle; /* Set up channel value for 33% dutycycle */
		TPM1->SC = 0x0C; /* enable TPM0 with prescaler /16 */
}else if(pin ==29){

	SIM->SCGC5 |= 0x2000; /* enable clock to Port D */
		PORTE->PCR[29] = 0x0300; /* PTD1 used by TPM0 */
		SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
		SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
		TPM0->SC = 0; /* disable timer */
		TPM0->CONTROLS[2].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
		TPM0->MOD = hertz; /* Set up modulo register for 60 kHz */
		TPM0->CONTROLS[2].CnV = cicle; /* Set up channel value for 33% dutycycle */
		TPM0->SC = 0x0C; /* enable TPM0 with prescaler /16 */
}else if(pin ==3){

	SIM->SCGC5 |= 0x1000; /* enable clock to Port D */
		PORTD->PCR[3] = 0x0400; /* PTD1 used by TPM0 */
		SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
		SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
		TPM0->SC = 0; /* disable timer */
		TPM0->CONTROLS[3].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
		TPM0->MOD = hertz; /* Set up modulo register for 60 kHz */
		TPM0->CONTROLS[3].CnV = cicle; /* Set up channel value for 33% dutycycle */
		TPM0->SC = 0x0C; /* enable TPM0 with prescaler /16 */
}else if(pin ==31){

	SIM->SCGC5 |= 0x2000; /* enable clock to Port D */
		PORTE->PCR[31] = 0x0300; /* PTD1 used by TPM0 */
		SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
		SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
		TPM0->SC = 0; /* disable timer */
		TPM0->CONTROLS[4].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
		TPM0->MOD = hertz; /* Set up modulo register for 60 kHz */
		TPM0->CONTROLS[4].CnV = cicle; /* Set up channel value for 33% dutycycle */
		TPM0->SC = 0x0C; /* enable TPM0 with prescaler /16 */
}else if(pin ==4){

	SIM->SCGC5 |= 0x200; /* enable clock to Port D */
		PORTA->PCR[4] = 0x0300; /* PTD1 used by TPM0 */
		SIM->SCGC6 |= 0x01000000; /* enable clock to TPM0 */
		SIM->SOPT2 |= 0x01000000; /* use MCGFLLCLK as timer counter clock */
		TPM0->SC = 0; /* disable timer */
		TPM0->CONTROLS[1].CnSC = 0x20 | 0x08; /* edge-aligned, pulse high */
		TPM0->MOD = hertz; /* Set up modulo register for 60 kHz */
		TPM0->CONTROLS[1].CnV = cicle; /* Set up channel value for 33% dutycycle */
		TPM0->SC = 0x0C; /* enable TPM0 with prescaler /16 */
}
}

void delayUs(int n)
{
	int i; int j;
	for(i = 0 ; i < n; i++) {
		for(j = 0; j < 3; j++);
	}
}
void delayMs(int n) {
	int i;
	int j;
	for(i = 0 ; i < n; i++)
		for(j = 0 ; j < 3500; j++) {
		}
}
