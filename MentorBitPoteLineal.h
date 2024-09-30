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
    Esta libreria esta especificamente diseñada para ser utilizada junto con
    el modulo potenciometro lineal de MentorBit
  Metodos principales:
    MentorBitPoteLineal -> constructor de la clase
    obtenerLectura -> esta funcion devuelve el valor analogico leido del potenciometro
    configurarLeds -> esta funcion permite configurar el modo de funcionamiento de los leds
    encenderLed -> esta funcion permite encender un led del modulo de forma individual
    cambiarDireccionI2c -> Esta funcion cambia la direccion I2C del modulo. Este cambio se almacena
  Atributos:
    LEDS_APAGADOS -> Apaga todos los leds del modulo
    LEDS_ENCENDIDOS -> Enciende todos los leds del modulo en funcion de la posicion del potenciometro
    LED_INDIVIDUAL -> Enciende un unico led individual que se aproximara a la posicion del potenciometro
*/

#ifndef MentorBitPotenciometroLineal_h
#define MentorBitPotenciometroLineal_h

#include <Wire.h>

class MentorBitPoteLineal
{
    public:
        
        MentorBitPoteLineal(uint8_t i2c_addr = 0x18);
        uint16_t obtenerLectura();
        void configurarLeds(uint8_t modo_leds);
        void encenderLed(uint8_t numero_led);
        void cambiarDireccionI2c(uint8_t i2c_addr);

        const uint8_t LEDS_APAGADOS = 0;
        const uint8_t LEDS_ENCENDIDOS = 1;
        const uint8_t LED_INDIVIDUAL = 2;

    private:
        uint8_t _i2c_addr;

};

#endif