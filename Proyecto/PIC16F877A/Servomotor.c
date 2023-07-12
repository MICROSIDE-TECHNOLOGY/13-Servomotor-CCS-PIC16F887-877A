/*
AUTOR: MICROSIDE TECHNOLOGY S.A. DE C.V.
FECHA: JUNIO 2019
*/

/*
---------------------------------------------------------------------------
Controlar la posicíon de un servo por medio del módulo PWM interno
---------------------------------------------------------------------------
*/

#include <16F877A.h>                            //Incluye el microcontrolador con el que se va a trabajar 
#use delay(clock=20Mhz, crystal)                //Tipo de oscilador y frecuencia dependiendo del microcontrolador 

int16 DUTY;                                     //variable para ajustar el valor del PWM
int1 SUBE;
int i;

void SisInit()
{
  set_tris_c(0xFB);                                 // C2 salida
  setup_timer_0(T0_INTERNAL|T0_DIV_4);
  enable_interrupts(INT_TIMER0);
  enable_interrupts(GLOBAL);

}

#int_TIMER0

 
void TIMER0_isr(){
output_high(PIN_C2);                              //Salida Pin_C2
SUBE=1;
set_timer0(5780);                                

}

void main()
{
        SisInit();
        while(1)
              {

                    for(i=0;i<255;i++)
                         {
                             if(SUBE==1)
                             {
                                delay_us(500);     //0°
                                 output_low( PIN_C2);
                                 SUBE=0;
                              }
                                while(SUBE==0);
                            }

                      for(i=0;i<255;i++)
                           {
                              if(SUBE==1)
                               {
                                  delay_us(1500);  //90°
                                   output_low( PIN_C2);
                                   SUBE=0;
                                }
                                while(SUBE==0);
                          } 

                        for(i=0;i<255;i++)
                               {
                                  if(SUBE==1)
                                  {
                                      delay_us(2500); //180°
                                      output_low( PIN_C2);
                                       SUBE=0;
                                   }
                                  while(SUBE==0);
                                    }

                 }
}
