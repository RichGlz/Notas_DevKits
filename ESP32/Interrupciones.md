# Creación de interrupciones

Las interrupciones sirven para realizar alguna tarea apenas se presione algún botón o un 'estado activo' según sea el caso.

A diferencia de un botón, una interrupción entra en una orden de prioridad superior. Ya que el flujo de código se modifica para ejecutar esta interrupción. Se puede ejecutar cualquier función creada por el programador, sin embargo, se pueden utilizar para funciones más concretas como:

- Reiniciar el CPU, el núcleo, el sistema
- Despertar el ESP32 del sueño profundo
- Encender un LED
- Sensar algún módulo
- Abrir el menú de configuración
- etc, etc..

**Qué pines se pueden configurar como interrupciones?**

Es importante notar que según sea el caso, los pines de interrupción van variando según la placa de DEVKIT, sin embargo, para nuestra suerte al ESP32 se le pueden configurar TODOS sus pines como interrupciones.

Con el **Arduino Uno**, sólo los pines 2 y 3 son configurables para interrupciones.

---

## Código de ejemplo de interrupciones

``` cpp
/**
 * @file main.cpp
 * @name Código de ejemplo de interrupciones
 * @author Rich González (contacto@geeksium.com)
 * @brief Este código contiene el ejemplo básico para interrupciones en el ESP32
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 * 
 */

#include <Arduino.h>

uint8_t boton = 4;  // Se define el pin 4 como botón.

void funcion_a_ejecutar(){
  // Aquí va el código a ejecutar.
}

void setup(){
    pinMode(boton, INPUT_PULLUP);

    attachInterrupt(

      digitalPinToInterrupt(boton), // Es recomendable hacerlo de esta manera.
      funcion_a_ejecutar,           // Servicio o rutina a ejecutar. Sin paréntesis.
      RISING                        // El modo, según sea necesario. Explico más adelante.
    );
}

void loop(){}

```

### Desglose de parámetros de la función _attachinterrupt()_

| Parámetro | valor declarado              | Descripción                                                                                                          |
| :-------- | :--------------------------- | :------------------------------------------------------------------------------------------------------------------- |
| PIN       | digitalPinToInterrupt(boton) | Se podría poner ser sólo _"boton"_, pero esta es la manera correcta de declarar el pin                               |
| ISR       | funcion_a_ejecutar           | Nombre de la funcion, servicio o rutina a llamar. *No son necesarios los paréntesis, como: ~~funcion_a_ejecutar()~~* |
| Mode      | RISING                       | Existen diferentes modos, se describen más adelante.                                                                 |

### Modos

| Modo    | Se ejecutará la interrupción cuando...            |
| :------ | :------------------------------------------------ |
| LOW     | **siempre** que el pin esté en nivel bajo (LOW)   |
| HIGH    | **siempre** que el pin esté en nivel alto (HIGH)  |
| RISING  | cuando el nivel va de **bajo a alto** (LOW->HIGH) |
| FALLING | cuando el nivel va de **alto a bajo** (HIGH->LOW) |
| CHANGE  | cuando exista un cambio de estado                 |

---

## Problemas con falsos positivos

Uno de los problemas más comunes al utilizar botones el circuitos es la presencia de campos magnéticos o influencias eléctricas cercanas al botón, lo que puede provoar (1) que el botón se presione solo o (2) que el botón, al ser presionado **una vez**, éste se active por dos o más veces.

En la parte de *setup()* de la función compartida, se incluyó la línea de código `pinMode(boton, INPUT_PULLUP);`, haciendo referencia a usar una **resistencia Pull-Up interna** con la que cuenta el *ESP32 DEV KIT* [], esto resuelve.

---

## Pines de interrupción para ESP32

| PLACA | PINES de interrupción                          | Motivo|
| :----: | :---------------------------------------------: | :----------------------: |
| ESP32 | Todos los GPIOs, excepto del GPIO34 al GPIO39. | 34, 35, 37, 39 son pines **INPUT ONLY** *(sólo entrada)*. |

## Pines de interrupción para otras placas

| PLACA                                          | Pines                             |
| :--------------------------------------------- | :-------------------------------- |
| ARDUINO UNO, NANO (y placas basadas en el 328) | 2, 3                              |
| ARDUINO MEGA, MEGA2500, MEGA ADK               | 2, 3, 18, 19, 20, 21              |
| ARDUINO Micro, Leonardo y basadas en el 32u4   | 0, 1, 2, 3, 7                     |
| ESP8266                                        | Todos los GPIOs, excepto GPIO16   |
| ESP01/ESP01s                                   | cuando exista un cambio de estado |

_De ser necesario se irán agragando placas._

---

## Puntos a tener en cuenta en interrupciones

1. Dentro de la función llamada desde la interrupción
   * La función `delay()` no funciona
   *  El valor devuelto por `millis()` no aumenta.

Motivo:  Las *interrupciones internas* no se disparan mientras hay una *interrupción externa*, y las funciones `delay()` y `millis()` hacen uso de interrupciones internas.

2. Los datos recibidos por el puerto serie se pueden perder mientras se está en la función llamada por la interrupción.

---

## Cómo evitar *falsos positivos* con el botón?

[Artículo pendiente](https://github.com/geeksium).

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