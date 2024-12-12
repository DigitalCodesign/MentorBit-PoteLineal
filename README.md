# MentorBit-PoteLineal
Esta librería está construida por Digital Codesign para utilizar el módulo de Potenciómetro Lineal, principalmente diseñado para el kit educacional "MentorBit".

Puedes encontrar nuestro MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial:  [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

# Modo de empleo

Una vez tengamos la librería instalada desde el Arduino IDE, tenemos que incluir la librería con la siguiente línea:

```
#include <MentorBitPoteLineal.h>
```

### Constructor

Una vez incluida la librería, usamos el constructor para crear el objeto del módulo de potenciómetro lineal, y definir la dirección I2C a la que está conectado el dispositivo. Si no se especifica, se tomará la dirección por defecto `0x18`.

```
MentorBitPoteLineal poteLineal(DIRECCION_I2C);
```

Donde `DIRECCION_I2C` es la dirección I2C a la que está conectado el potenciómetro. Si no se especifica, se usará la dirección predeterminada `0x18`.

### Uso

Con el objeto `poteLineal` definido, podemos obtener la lectura del potenciómetro utilizando la función `obtenerLectura()`, que devuelve el valor analógico leído en el pin del potenciómetro:

```
uint16_t lectura = poteLineal.obtenerLectura();
```

El valor devuelto es un número entre 0 y 1023, correspondiente al valor de la lectura analógica del potenciómetro.

### Configuración de LEDs

El módulo tiene LEDs que pueden ser configurados de varias maneras. Utiliza la función `configurarLeds()` para configurar el modo de los LEDs:

```
poteLineal.configurarLeds(LEDS_APAGADOS);     // Apaga todos los LEDs
poteLineal.configurarLeds(LEDS_ENCENDIDOS);   // Enciende todos los LEDs en función de la posición del potenciómetro
poteLineal.configurarLeds(LED_INDIVIDUAL);    // Enciende un LED individual según la posición del potenciómetro
```

- `LEDS_APAGADOS`: Apaga todos los LEDs.
- `LEDS_ENCENDIDOS`: Enciende todos los LEDs en función de la posición del potenciómetro.
- `LED_INDIVIDUAL`: Enciende un solo LED que se aproxima a la posición del potenciómetro.

### Encender un LED Individual

Si deseas encender un único LED en particular, puedes usar la función `encenderLed()`, pasando el número del LED a encender:

```
poteLineal.encenderLed(NUMERO_LED);  // Enciende un LED específico
```

### Cambio de Dirección I2C

Si necesitas cambiar la dirección I2C del módulo, puedes usar la función `cambiarDireccionI2c()`:

```
poteLineal.cambiarDireccionI2c(NUEVA_DIRECCION_I2C);
```

Este cambio de dirección I2C se mantiene incluso si el módulo se desconecta de la alimentación.

### Atributos

- `LEDS_APAGADOS`: Apaga todos los LEDs del módulo.
- `LEDS_ENCENDIDOS`: Enciende todos los LEDs en función de la posición del potenciómetro.
- `LED_INDIVIDUAL`: Enciende un único LED individual que se aproxima a la posición del potenciómetro.
