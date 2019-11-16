#include <MKL25Z4.H>
#include "pwm.h"

/*
 * la funcion de PWM funciona pasandole tres parametros, el pin, la frecuencia y el dutycicle
 * el pin 4 genera pwm en el PTA4
 * el pin 12 genera pwm en el PTA12
 * el pin 13 genera pwm en el PTA13
 * el pin 3 genera pwm en el PTD3
 * el pin 29 genera pwm en el PTE29
 * el pin 31 genera pwm en el PTE31
 * */



int main (void) {

	while (1) {


		PWM (4,50,2);
				delayMs(2000);
				PWM (4,50,6);
				delayMs(2000);

		}

	}


