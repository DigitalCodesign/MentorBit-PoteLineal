# MentorBitPotenciometroLineal

Librería para el uso de potenciómetros lineales con LEDs integrados en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitPotenciometroLineal` facilita la lectura de potenciómetros lineales con LEDs integrados, comunicándose a través del protocolo I2C, en módulos compatibles con MentorBit. Permite leer la posición del potenciómetro, configurar el comportamiento de los LEDs (encendido/apagado automático o control individual), y cambiar la dirección I2C del módulo.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitPotenciometroLineal" e instálala.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitPotenciometroLineal.h>

    MentorBitPoteLineal pote; // Crea un objeto para el potenciómetro lineal

    void setup() {
      Serial.begin(9600);
      pote.configurarLeds(pote.LEDS_ENCENDIDOS); // Enciende los LEDs automáticamente
    }

    void loop() {
      uint16_t valor = pote.obtenerLectura(); // Obtiene la lectura del potenciómetro
      Serial.print("Valor del potenciómetro: ");
      Serial.println(valor);
      delay(100);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitPoteLineal(uint8_t i2c_addr = 0x18)`: Crea un objeto `MentorBitPoteLineal`.
    * `i2c_addr`: Dirección I2C del módulo. El valor predeterminado es `0x18`.

### Métodos

* `uint16_t obtenerLectura()`: Devuelve la lectura del potenciómetro (un valor de 16 bits).
* `void configurarLeds(uint8_t modo_leds)`: Configura el modo de funcionamiento de los LEDs.
    * `modo_leds`: Puede ser `LEDS_APAGADOS` (apaga los LEDs), `LEDS_ENCENDIDOS` (enciende los LEDs automáticamente según la posición del potenciómetro) o `LED_INDIVIDUAL` (permite controlar LEDs individuales).
* `void encenderLed(uint8_t numero_led)`: Enciende un LED individual.
    * `numero_led`: Número del LED a encender (0-7).
* `void cambiarDireccionI2c(uint8_t i2c_addr)`: Cambia la dirección I2C del módulo.
    * `i2c_addr`: Nueva dirección I2C.

## Constantes Públicas

* `LEDS_APAGADOS`, `LEDS_ENCENDIDOS`, `LED_INDIVIDUAL`: Constantes para configurar el modo de los LEDs.
