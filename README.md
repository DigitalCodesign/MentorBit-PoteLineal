# MentorBit-PoteLineal

Esta librería está diseñada para que puedas leer fácilmente la posición del módulo **potenciómetro lineal** conectado a tu placa MentorBit mediante el **protocolo I2C**.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del MentorBit módulo de potenciómetro lineal.](https://github.com/DigitalCodesign/MentorBit-PoteLineal/blob/main/assets/PoteLineal_Module.png)

Con esta librería, podrás obtener la posición lineal de un potenciómetro para usarlo como control de entrada en tus proyectos.

---

## Descripción

### ¿Qué es un potenciómetro lineal?

Un potenciómetro lineal es un sensor analógico que varía su resistencia según la posición de un deslizador a lo largo de un eje lineal. Es ampliamente utilizado para:

- Controlar velocidad, volumen o intensidad.
- Detectar desplazamientos lineales.
- Crear interfaces físicas para proyectos interactivos.

Al estar integrado en un **módulo I2C para MentorBit**, su lectura es directa y sin necesidad de usar pines analógicos dedicados.

---

### ¿Qué hace esta librería?

La librería **MentorBit-PoteLineal** permite:

- Inicializar el módulo y la comunicación I2C.
- Leer la posición actual del potenciómetro como un valor entero.
- Mapear fácilmente la lectura a rangos útiles para controlar tus proyectos.

---

### ¿Qué puedes construir con este módulo?

- Controles deslizantes para interfaces interactivas.
- Ajuste de velocidad o brillo en tiempo real.
- Entrada de posición para robots o mecanismos lineales.
- Instrumentos musicales o juegos interactivos.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el módulo de potenciómetro lineal a uno de los **puertos I2C** con conector JST de 4 pines en la sección "Comunicaciones" de la placa MentorBit.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-PoteLineal*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-PoteLineal/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Leer posición lineal

Este ejemplo lee la posición del potenciómetro y la imprime por el monitor serie.

```cpp
// Se incluye la libreria del potenciometro lineal de MentorBit
#include <MentorBitPoteLineal.h>

// Se crea el objeto Potenciometro
MentorBitPoteLineal potenciometro;

void setup() {
    // Inicializamos el bus serial a una velocidad de 9600 baudios
    Serial.begin(9600);
}

void loop() {
    // Se imprime por pantalla el valor del potenciometro
    Serial.println("Valor del potenciometro: " + String(potenciometro.obtenerLectura()));
    // Delay para no llenar el monitor serial de mensajes
    delay(1000);
}
```

---

## Funciones Principales

- `uint16_t obtenerLectura()`  
  Devuelve el valor analógico actual del potenciómetro.

- `void configurarLeds(uint8_t modo_leds)`  
  Configura el funcionamiento de los leds entre los tres tipos diferentes (apagados, encendidos o individual).

- `void encenderLed(uint8_t numero_led)`  
  Desactiva el funcionamiento normal de los leds y enciende el led indicado manualmente.

- `void cambiarDireccionI2c(uint8_t i2c_addr)`  
  Cambia la dirección I2C del módulo. Este inicializa el protocolo I2C inmediatamente con la nueva dirección.

---

## Atributos Principales (clase pote)

- `pote.LEDS_APAGADOS`  
  Atributo para configurar el funcionamiento de los LEDs del módulo. Apaga los LEDs.

- `pote.LEDS_ENCENDIDOS`  
  Atributo para configurar el funcionamiento de los LEDs del módulo. Enciende los LEDs en funcionamiento normal.

- `pote.LED_INDIVIDUAL`  
  Atributo para configurar el funcionamiento de los LEDs del módulo. Enciende los LEDs en funcionamiento individual.

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo Pote Lineal](https://canarias.digitalcodesign.com/shop/00038997-mentorbit-modulo-potenciometro-lineal-8131?category=226&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1zwP4gsq2a6HzFGNhUjc8im9lB7dJZ98g/view?usp=drive_link)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/file/d/1p9H8I0K-evh7kxRTC7hVOVMObrgpWRWd/view?usp=drive_link)
