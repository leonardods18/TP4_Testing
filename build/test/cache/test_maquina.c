#include "build/temp/_test_maquina.c"
#include "src/FSM.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"






enum Test {

 TEST_CONEXION = 1,

 TEST_LECTURA = 1,

 TEST_ENVIO = 1,

 TEST_RECIBO = 1,

 TEST_ESCRIBO = 1,

 TEST_ENCIENDO = 1,

 TEST_APAGO = 0,



} valores;







static int resultado;

static int statusCheck;





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









void test_protocol_Command(void){



    int buf[3] = {0xF0,CONEXION, 0xF0};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((FAIL)), (UNITY_INT)((statusCheck)), (

   ((void *)0)

   ), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

}







void test_conexion_server(void){



    int buf[3] = {0xF0,CONEXION, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_CONEXION)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(106), UNITY_DISPLAY_STYLE_INT);

}





void test_lecturaSD(void){



    int buf[3] = {0xF0,LECTURA_SD, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_LECTURA)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_INT);

}





void test_lecturaSPI(void){



    int buf[3] = {0xF0,LECTURA_SPI, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_LECTURA)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(124), UNITY_DISPLAY_STYLE_INT);

}





void test_lecturaADC(void){



    int buf[3] = {0xF0,LECTURA_ADC, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_LECTURA)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(133), UNITY_DISPLAY_STYLE_INT);

}







void test_lecturaGPS(void){



    int buf[3] = {0xF0,LECTURA_GPS, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_LECTURA)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(143), UNITY_DISPLAY_STYLE_INT);

}







void test_envioTrama(void){



    int buf[3] = {0xF0,ENVIO_TRAMA, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_LECTURA)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(153), UNITY_DISPLAY_STYLE_INT);

}





void test_reciboACK(void){



    int buf[3] = {0xF0,RECIBO_ACK, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_RECIBO)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(162), UNITY_DISPLAY_STYLE_INT);

}





void test_escriboSD(void){



    int buf[3] = {0xF0,ESCRIBO_SD, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_ESCRIBO)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(171), UNITY_DISPLAY_STYLE_INT);

}



void test_apago_indicador(void){



    int buf[3] = {0xF0,INDICACION_OFF, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_APAGO)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(179), UNITY_DISPLAY_STYLE_INT);

}

void test_enciendo_indicador(void){



    int buf[3] = {0xF0,INDICACION_ON, 0xFF};



    sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_ENCIENDO)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(186), UNITY_DISPLAY_STYLE_INT);

}
