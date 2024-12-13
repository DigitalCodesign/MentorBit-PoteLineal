

# MentorBit-PoteLineal
Esta librería está construida por Digital Codesign para utilizar el módulo de Potenciómetro Lineal de MentorBit, principalmente diseñado para el kit educacional "MentorBit".

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de empleo

Una vez tengamos la librería instalada desde el Arduino IDE, debemos incluir la librería con la siguiente línea:

```
#include <MentorBitPoteLineal.h>
```

### Constructor

Una vez incluida la librería, usamos el constructor para crear el objeto del módulo de potenciómetro lineal y definimos la dirección I2C del módulo (por defecto es `0x18`):

```
MentorBitPoteLineal poteLineal(DIRECCION_I2C);
```

Si no se pasa una dirección, la dirección por defecto será `0x18`.

### Uso

Con el objeto `poteLineal` definido, podemos obtener la lectura del potenciómetro utilizando la función `obtenerLectura()`, que devuelve el valor analógico leído desde el potenciómetro:

```
uint16_t lectura = poteLineal.obtenerLectura();
```

El valor devuelto es un número entre 0 y 1023, correspondiente al valor de la lectura analógica del potenciómetro.

### Configuración de LEDs

Puedes controlar los LEDs del módulo utilizando la función `configurarLeds()`. Hay tres modos disponibles para configurar los LEDs:

- `LEDS_APAGADOS`: Apaga todos los LEDs del módulo.
- `LEDS_ENCENDIDOS`: Enciende todos los LEDs del módulo en función de la posición del potenciómetro.
- `LED_INDIVIDUAL`: Enciende un único LED individual que se aproximará a la posición del potenciómetro.

```
poteLineal.configurarLeds(poteLineal.LEDS_ENCENDIDOS);
```

### Encender un LED individual

Si deseas encender un solo LED, puedes usar la función `encenderLed()`, pasando como parámetro el número de LED que quieres encender:

```
poteLineal.encenderLed(NUMERO_LED);
```

Recuerda que al encender un LED individual, se deshabilita el encendido automático de los LEDs.

### Cambiar dirección I2C

Si necesitas cambiar la dirección I2C del módulo, puedes utilizar la función `cambiarDireccionI2c()`:

```
poteLineal.cambiarDireccionI2c(NUEVA_DIRECCION_I2C);
```

Este cambio de dirección se mantiene incluso si se desconecta la alimentación del módulo.

### Atributos

- `LEDS_APAGADOS`: Apaga todos los LEDs del módulo.
- `LEDS_ENCENDIDOS`: Enciende todos los LEDs del módulo en función de la posición del potenciómetro.
- `LED_INDIVIDUAL`: Enciende un único LED individual que se aproximará a la posición del potenciómetro.

### Configuración de puertos

Si deseas configurar puertos personalizados, puedes usar la función `configPort()` para asignar los pines y configuraciones de puertos que necesitas. Esta función no se encuentra disponible en el código proporcionado, pero puedes adaptarla si es necesario para tu caso.

