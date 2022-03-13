# Sensores internos del ESP32

La placa **ESP32** cuenta con sensores internos tales como los mencionados a continuación:

## Sensor de efecto Hall

> También "Sensor de campo electromagnético".

---

El sensor de efecto hall se puede combinar con una detección de umbral para actuar como un interruptor, por ejemplo. Además, los sensores de efecto Hall se utilizan principalmente para:

- Detectar la proximidad a un objeto
- Calcular la posiciónde la placa
- Contar el número de revoluciones de una rueda
- Detecta el cierre de una puerta
- y más...

### Código de Sensor de efecto Hall

``` cpp
#include <Arduino.h>

int val = 0;

void setup(){
    Serial.begin(115200);
}

void  loop(){
    val = hallRead();

    Serial.println("Efecto Hall: " + val);
    delay(1000);
}
```

## Sensor de Temperatura

Utilizado para saber la temperatura de la placa del ESP32 DEV-KIT.

### Código de Sensor de temperatura

``` cpp
/**
 * @file main.cpp
 * @name Código de Sensor de temperatura
 * @author Rich González (contacto@geeksium.com)
 * @brief En este código se muestran la forma para acceder al sensor de temperatura interno del ESP32.
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 */

#include <Arduino.h>
#ifdef __cplusplus
extern "C"  {
    #endif
    uint8_t temprature_sens_read();
    #ifdef __cplusplus
} #endif

unit8_t temprature_sens_read();

void setup(){
    Serial.begin(115200);
}

void  loop(){
    // Convertir la Temp en ºF a ºC.
    float temp = (temprature_sens_read() - 32) / 1.8;

    Serial.println("La temperatura es: " + String(temp) + "ºC");
}
```

## Sensor de Pines touch

El ESP32 cuenta con 10 pines touch, sin embargo, al menos el _ESP32 DEVKIT V1 de 30 pines_ sólo cuenta con 9, ya que el GPIO0 (TOUCH_1) no tiene un PIN al cual conectarse de manera física. Por otro lado hay much que hacer con los 9 pines touch disponibles.

### Código de pines touch

``` cpp
  // Pendiente
```

---

---

<div align="center"> <span style="font-family:'bebas neue extrabold'; font-size:4em;">GEEKSIUM</span> </div>

---

---

## Yo soy Rich!

Espero que este contenido te haya sido de utilidad.
Hasta pronto!

---

Sigue nuestras redes para este y para próximos proyectos:

- [Canal de Telegram](https://t.me/geeksium)
- [Instagram](https://instagram.com/geeksium)
- [GitHub](https://github.com/geeksium)
- [Facebook](https://facebook.com/geeksium)
- [Patreon](https://patreon.com/geeksium)
- [Invitar ☕ vía PayPal](https://paypal.me/richglz?country.x=MX&locale.x=es_XC)