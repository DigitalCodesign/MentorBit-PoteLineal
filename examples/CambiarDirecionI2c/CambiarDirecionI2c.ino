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
    Este sketch muestra un ejemplo de como cambair la direccion I2C del modulo. Este cambio 
    se almacena en el modulo. El cambio se efectua de inmediato, de forma que el modulo cambia
    su direccion I2C y se queda funcionando con la nueva direccion dada. En este ejemplo el
    modulo emite constantemente el valor analogico del potenciometro despues del cambio de direccion

*/

// Se incluye la libreria del potenciometro de MentorBit
#include <MentorBitPoteLineal.h>

// Se definen las direcciones I2c
#define DireccionI2C 0x18
#define NuevaDireccionI2C 0x18

// Se crea el objeto potenciometro
MentorBitPoteLineal potenciometro(DireccionI2C);

void setup() {
  // Cambiamos la direccion I2C del modulo
  potenciometro.cambiarDireccionI2c(NuevaDireccionI2C);
  
  // Inicializamos el bus serial a una velocidad de 9600 baudios
  Serial.begin(9600);
  Serial.println("Se ha cambiado la direccon I2C a:" + String(NuevaDireccionI2C));
}

void loop() {
  // Mostramos el valor de la posicion para asegurarnos que funciona bien
  Serial.println("Valor del Potenciometro: " + String(potenciometro.obtenerLectura()));
  delay(1000);
}
