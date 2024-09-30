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

#include "MentorBitPoteLineal.h"

/*
    Constructor, se debe indicar una dirección I2C a la que conectarse
    
    En caso de no darse, se tomara por defecto la dirección 0x18
*/
MentorBitPoteLineal::MentorBitPoteLineal(uint8_t i2c_addr = 0x18){
    Wire.begin();
    _i2c_addr = i2c_addr;
}

/*
    Función que obtiene el valor de la lectura analogico del potenciometro
*/
uint16_t MentorBitPoteLineal::obtenerLectura(){
    Wire.requestFrom(_i2c_addr, 2);
    uint16_t valor_pote = (uint16_t)Wire.read();
    valor_pote |= (uint16_t)(Wire.read() << 8);
    return valor_pote;
}

/*
    Función que permite habilitar o deshabilitar los leds del módulo
*/
void MentorBitPoteLineal::configurarLeds(uint8_t modo_leds){
    Wire.beginTransmission(_i2c_addr);
    if(modo_leds==LEDS_APAGADOS){
        Wire.write(0x60);
    }
    else if(modo_leds==LEDS_ENCENDIDOS){
        Wire.write(0x61);
    }
    else if(modo_leds==LED_INDIVIDUAL){
        Wire.write(0x62);
    }
    Wire.endTransmission();
}

/*
    Esta función permite encender un solo led de los disponibles en el módulo

    Al encender un led, se deshabilita el encendido automatico de los leds. No 
    se puede encender mas de un led a la vez, en caso de encender dos, se mantendrá
    ecendido el último led indicado
*/
void MentorBitPoteLineal::encenderLed(uint8_t numero_led){
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0X25);
    Wire.write(numero_led);
    Wire.endTransmission();
}
/*
    Esta función permite cambiar la dirección I2C del módulo. Este cambio se mantiene incluso 
    si se desconecta la alimentación del módulo. Se puede volver a cambiar en caso de ser necesario.
*/
void MentorBitPoteLineal::cambiarDireccionI2c(uint8_t i2c_addr){
    Wire.beginTransmission(_i2c_addr);
    Wire.write(0x61);
    Wire.write(0x58);
    Wire.write(0x49);
    Wire.write(i2c_addr);
    Wire.endTransmission();
    _i2c_addr = i2c_addr;
}