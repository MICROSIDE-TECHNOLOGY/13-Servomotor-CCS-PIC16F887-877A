/************************************************************************************************
Company:
Microside Technology Inc.
File Name:
Servomotor.c
Product Revision  :  1
Device            :  X-TRAINER
Driver Version    :  1.0
************************************************************************************************/

/*
--------------------------------------------------------------------------------------
Controlar la posicíon de un servo utilizando Timer1 para generar una señal PWM de 50Hz
--------------------------------------------------------------------------------------
*/

#include <16F877A.h>                        // Incluye el microcontrolador con el que se va a trabajar
#include "Servo.h"                          // Librería para controlar 1 servo (Utiliza Timer1)
#use delay( clock = 20Mhz, crystal )        // Tipo de oscilador y frecuencia dependiendo del microcontrolador

void main( void ) {
   set_tris_c( 0xFB );                      // Configura C2 como salida
   setup_servo( PIN_C2 );                   // Configura el PIN C2 como el servo

   while ( 1 ) {
      delay_ms( 1000 );
      set_servo_angle (0);                  // Configura la posición del servo
      delay_ms( 1000 );
      set_servo_angle (45);
      delay_ms( 1000 );
      set_servo_angle (90);
      delay_ms( 1000 );
      set_servo_angle (135);
      delay_ms( 1000 );
      set_servo_angle (180);
   }
}
