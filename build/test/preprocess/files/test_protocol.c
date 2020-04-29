#include "build/temp/_test_protocol.c"
#include "src/FSM.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"
enum Test {

 TEST_ON = 1,

 TEST_OFF = 0,

 TEST_TEMP = 25,

 TEST_HUM = 30,

} valores;







static int resultado;

static int statusCheck;





void procesar(int cmd){

 switch (cmd)

 {

 case ILUMINACION_OFF:

  resultado = TEST_OFF;

  break;

 case ILUMINACION_ON:

  resultado = TEST_ON;

  break;

 case RIEGO_OFF:

  resultado = TEST_OFF;

  break;

 case RIEGO_ON:

  resultado = TEST_ON;

  break;

 case GET_TEMP:

  resultado = TEST_TEMP;

  break;

 case GET_HUM:

  resultado = TEST_HUM;

  break;

 }

}







void status(int cmd){

    statusCheck = cmd;

}





void setUp(void)

{

    init();



    procesar_callback(&procesar);

    responder_callback(&status);

}



void tearDown(void)

{

}





void test_iluminacionON(void){



    int buf[3] = {0xF0,ILUMINACION_ON, 0xFF};



 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_ON)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

}





void test_riegoON(void){



    int buf[3] = {0xF0,RIEGO_ON, 0xFF};



 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_ON)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(86), UNITY_DISPLAY_STYLE_INT);

}















void test_Command(void){



    int buf[3] = {0xF0,RIEGO_ON, 0xF0};



 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((FAIL)), (UNITY_INT)((statusCheck)), (

   ((void *)0)

   ), (UNITY_UINT)(100), UNITY_DISPLAY_STYLE_INT);

}









void test_getTemperatura(void){



    int buf[3] = {0xF0,GET_TEMP, 0xFF};



 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_TEMP)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(111), UNITY_DISPLAY_STYLE_INT);

}









void test_getHumedad(void){



    int buf[3] = {0xF0,GET_HUM, 0xFF};



 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_HUM)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(122), UNITY_DISPLAY_STYLE_INT);

}







void test_iluminacionOFF(void){



    int buf[3] = {0xF0,ILUMINACION_OFF, 0xFF};



 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_OFF)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(132), UNITY_DISPLAY_STYLE_INT);

}





void test_riegoOFF(void){



    int buf[3] = {0xF0,RIEGO_OFF, 0xFF};



 sendCommand(buf);

    UnityAssertEqualNumber((UNITY_INT)((TEST_OFF)), (UNITY_INT)((resultado)), (

   ((void *)0)

   ), (UNITY_UINT)(141), UNITY_DISPLAY_STYLE_INT);

}
