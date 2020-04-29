// TESTING DE SOFTWARE 2020   PROFESOR: ESTEBAN, VOLENTINI  - ALUMNO: DEL SANCIO, LEONARDO 

#ifndef FSM_H_
#define FSM_H_


#include <stdbool.h>
#include <stdio.h>

#define BUFFER_LENGHT 3
#define START_CMD       	0xF0
#define END_CMD 		0xFF
void inicio();
void sendCommand(int *buf);
void proceso(void (*funcionEjecutar)(int));
void respondo(void (*funcionReturn)(int));

enum Result {
	FAIL 				= 0xF7,
	OK   				= 0xF8,
	CONEXION			= 0x00,
	LECTURA_SD 	        	= 0x01,
	LECTURA_SPI 		        = 0x02,
	LECTURA_ADC 			= 0x03,
	LECTURA_GPS 			= 0x04,
	ENVIO_TRAMA 			= 0x05,
	RECIBO_ACK 			= 0x06,	
	ESCRIBO_SD			= 0x07,	
	INDICACION_ON			= 0x08,	
	INDICACION_OFF			= 0x09,	
};
#endif 
