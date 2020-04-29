// TESTING DE SOFTWARE 2020   PROFESOR: ESTEBAN, VOLENTINI  - ALUMNO: DEL SANCIO, LEONARDO 

#include "FSM.h"

enum estado
{
	IDDLE,
	DATA,
	FIN
} estado;

unsigned char input_byte;
unsigned char inputs_byte;



void recibo_comando(int input);
bool ejecuto_comando(int cmd);
void envio_fallido();
void envio_ok();
void envio_datos(int input);
void (*Enviar)(int);
void (*Respuesta)(int);


void inicio()
{
	estado = IDDLE;	// seteo el estado inicial
}

void sendCommand(int *buf)
{
	int dato = 0;
	while (dato < 3)
	{
		recibo_comando(buf[dato]);
		dato++;
	}
}

void proceso(void (*funcionEjecutar)(int))
{
	Enviar = funcionEjecutar;
}

void respondo(void (*funcionReturn)(int))
{
	Respuesta = funcionReturn;
}

void recibo_comando(int input)
{
	switch (estado)
	{
	case IDDLE:
		if (input == START_CMD)
		{
			input_byte = input; // store valid command
			estado = DATA;
		}
		break;
	case DATA:
		if (input > -1)
		{
			inputs_byte = input; // store valid command
			estado = FIN;
		}
		else
		{
			estado = IDDLE;
			envio_fallido();
		}
		break;
	case FIN:
		if (input == END_CMD)
		{
			if (ejecuto_comando(inputs_byte))
			{
				envio_ok();
			}
			else
			{
				envio_fallido();
			}
			estado = IDDLE;
		}
		else
		{
			estado = IDDLE;
			envio_fallido();
		}
		break;
	}
}

bool ejecuto_comando(int cmd)
{
	bool check = true;
	switch (cmd)
	{
	case CONEXION:
		Enviar(cmd);
		break;
	case LECTURA_SD:
		Enviar(cmd);
		break;
	case LECTURA_SPI:
		Enviar(cmd);
		break;
	case LECTURA_ADC:
		Enviar(cmd);
		break;
	case LECTURA_GPS:
		Enviar(cmd);
		break;
	case ENVIO_TRAMA:
		Enviar(cmd);
		break;
	case RECIBO_ACK:
		Enviar(cmd);
		break;
	case ESCRIBO_SD:
		Enviar(cmd);
		break;
	case INDICACION_ON:
		Enviar(cmd);
		break;
	case INDICACION_OFF:
		Enviar(cmd);
		break;
	default:
		check = false;
		break;
	}
	return check;
}


void envio_ok()
{
	envio_datos(OK);
}

void envio_datos(int input)
{
	Respuesta(input);
}

void envio_fallido()
{
	envio_datos(FAIL);
}
