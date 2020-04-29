// TESTING DE SOFTWARE 2020   PROFESOR: ESTEBAN, VOLENTINI  - ALUMNO: DEL SANCIO, LEONARDO 


#include "unity.h"
#include "FSM.h"

// se puede conectar a la red
// puede lee la memoria SD
// puede leer los datos por spi
// puede leer los datos del ADC
// puede leer los datos del GPS
// puede enviar una trama
// puede recibir el ACK confirmando la trama
// puede escribir la memoria SD
// puede indicar que termino el proceso con exito

enum Test {	
	TEST_CONEXION 			= 1,
	TEST_LECTURA 			= 1,
	TEST_ENVIO 			= 1,
	TEST_RECIBO 			= 1,	
	TEST_ESCRIBO			= 1,
	TEST_ENCIENDO			= 1,
	TEST_APAGO			= 0,
		
} valores;

//Contienen el resultado
//de la accion de llama al protocolo
static int resultado;
static int statusCheck;

//Funciones ejecuta una operacion
void procesar(int cmd){
	switch (cmd)
	{
	case CONEXION:
		resultado = TEST_CONEXION;
		break;
	case LECTURA_SD:
		resultado = TEST_LECTURA;
		break;
	case LECTURA_SPI:
		resultado = TEST_LECTURA;
		break;
	case LECTURA_ADC:
		resultado = TEST_LECTURA;
		break;
	case LECTURA_GPS:
		resultado = TEST_LECTURA;
		break;
	case ENVIO_TRAMA:
		resultado = TEST_ENVIO;
		break;
	case RECIBO_ACK:
		resultado = TEST_RECIBO;
		break;
	case ESCRIBO_SD:
		resultado = TEST_ESCRIBO;
		break;
	case INDICACION_ON:
		resultado = TEST_ENCIENDO;
		break;
	case INDICACION_OFF:
		resultado = TEST_APAGO;
		break;
	}
}

//Funciones obtiene el resultado
//de un operación
void status(int cmd){
    statusCheck = cmd;
}


void setUp(void)
{
    inicio();  
    proceso(&procesar);
    respondo(&status);  
}

void tearDown(void)
{
}

//  verifico el comando enviado
//  se valida antes de ejecutar la instruccion

void test_protocol_Command(void){
    //comando a validar
    int buf[BUFFER_LENGHT] = {START_CMD,CONEXION, START_CMD};
    //enviamos el comando
    sendCommand(buf);   
    TEST_ASSERT_EQUAL(FAIL, statusCheck);
}


//  testeo la conexion al servidor
void test_conexion_server(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,CONEXION, END_CMD};
    //enviamos el comando
    sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_CONEXION, resultado);
}

//  Testeo la lectura de la memoria SD
void test_lecturaSD(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,LECTURA_SD, END_CMD};
    //enviamos el comando
    sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_LECTURA, resultado);
}

// testeo lectura SPI
void test_lecturaSPI(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,LECTURA_SPI, END_CMD};
    //enviamos el comando
    sendCommand(buf);   
    TEST_ASSERT_EQUAL(TEST_LECTURA, resultado);
}

//  testeo la lectura del modulo ADC 
void test_lecturaADC(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,LECTURA_ADC, END_CMD};
    //enviamos el comando
    sendCommand(buf);   
    TEST_ASSERT_EQUAL(TEST_LECTURA, resultado);
}


//  para poder realizar el testing
void test_lecturaGPS(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,LECTURA_GPS, END_CMD};
    //enviamos el comando
    sendCommand(buf);   
    TEST_ASSERT_EQUAL(TEST_LECTURA, resultado);
}


//  Se puede apagar la iluminacion del invernadero
void test_envioTrama(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,ENVIO_TRAMA, END_CMD};
    //enviamos el comando
    sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_LECTURA, resultado);
}

//  se recibe verificacion de trama 
void test_reciboACK(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,RECIBO_ACK, END_CMD};
    //enviamos el comando
    sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_RECIBO, resultado);
}

// escribo memoria SD
void test_escriboSD(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,ESCRIBO_SD, END_CMD};
    //enviamos el comando
    sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_ESCRIBO, resultado);
}

void test_apago_indicador(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,INDICACION_OFF, END_CMD};
    //enviamos el comando
    sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_APAGO, resultado);
}
void test_enciendo_indicador(void){
    //comando a ejecutar
    int buf[BUFFER_LENGHT] = {START_CMD,INDICACION_ON, END_CMD};
    //enviamos el comando
    sendCommand(buf);    
    TEST_ASSERT_EQUAL(TEST_ENCIENDO, resultado);
}



