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

| Parámetro | valor declarado              | Descripción                                                  |
| :-------- | :--------------------------- | :----------------------------------------------------------- |
| PIN       | digitalPinToInterrupt(boton) | Esta es la manera  correcta de declarar el pin               |
| ISR       | funcion_a_ejecutar           | Servicio o rutina a llamar. No son necesarios los paréntesis |
| Mode      | RISING                       | Existen diferentes modos,  lea a continuación                |

### Modos

| Modo    | Se ejecuta la interrupción si...                  |
| :------ | :------------------------------------------------ |
| LOW     | **Siempre** que el pin esté en nivel bajo (LOW)   |
| HIGH    | **Siempre** que el pin esté en nivel alto (HIGH)  |
| RISING  | Cuando el nivel va de **bajo a alto** (LOW->HIGH) |
| FALLING | Cuando el nivel va de **alto a bajo** (HIGH->LOW) |
| CHANGE  | Cuando exista un cambio de estado                 |

---

## Cómo evitar que hayan falsos positivos en el botón?

Para eso te invito a leer el siguiente [artículo](https://github.com/geeksium).

---

### Yo soy Rich y espero que este contenido te haya sido de utilidad

Te comparto nuestras redes para poder ver más contenido de Geeksium.

Hasta pronto!

Sigue nuestras redes para este y para próximos proyectos:

- [Canal de Telegram](https://t.me/geeksium)
- [Instagram](https://instagram.com/geeksium)
- [GitHub](https://github.com/geeksium)
- [Facebook](https://facebook.com/geeksium)
- [Patreon](https://patreon.com/geeksium)
- [Invitar ☕ vía PayPal](https://paypal.me/richglz?country.x=MX&locale.x=es_XC)
