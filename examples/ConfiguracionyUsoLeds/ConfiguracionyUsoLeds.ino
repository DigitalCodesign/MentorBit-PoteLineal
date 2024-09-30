/*


          ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗
          ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║
          ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║
          ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║
          ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗
          ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝

   ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
  ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
  ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
  ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
  ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
   ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝


  Autor: Digital Codesign
  Version: 1.0.0
  Fecha de creación: Septiembre de 2024
  Fecha de version: Septiembre de 2024
  Repositorio: https://github.com/DigitalCodesign/MentorBit-PoteLineal
  Descripcion:
    Este sketch muestra un ejemplo de como configurar el estado de los leds del modulo.
    Este cambio de configuracion se hace en bucle para poder observar las diferencias
    entre los tres modos.
*/

// Se incluye la libreria del potenciometro lineal de MentorBit
#include <MentorBitPoteLineal.h>

// Se crea el objeto potenciometro
MentorBitPoteLineal potenciometro;

void setup() {

  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  
  /*
    Se recomienda mover potenciometro para poder observar el cambio 
    de funcionamiento de los leds en una posicion intermedia
  */
  // Tambien se pueden encender los leds de forma individual 
  for(int i=0;i<17;i++){
    potenciometro.encenderLed(i);
    delay(50);
  }
  for(int i=16;i>0;i--){
    potenciometro.encenderLed(i);
    delay(50);
  }
  /*
    Solo se puede encender un led, por lo que si se enciende otro
    el primero se apagara
  */
}

void loop() {
  // Se configuran los leds en modo individual
  potenciometro.configurarLeds(potenciometro.LED_INDIVIDUAL);
  delay(2000);
  // Se configuran los leds en modo multiplexado
  potenciometro.configurarLeds(potenciometro.LEDS_ENCENDIDOS);
  delay(2000);
  // Se configuran los leds en modo apagado
  potenciometro.configurarLeds(potenciometro.LEDS_APAGADOS);
  delay(2000);
}
