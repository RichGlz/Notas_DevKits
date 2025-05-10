# Utilizando el núcleo 0

Es una pregunta que muchos nos hemos hecho una vez que sabemos que el ESP32 cuenta con dos núcleos en us interior según [la documentación oficial](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf) deSpressif (página 12). y aquí les mostramos cómo:

---

## Cómo saber qué núcleo estoy usando para alguna tarea en concreto?

Copia y pega el siguiente código

``` cpp
/**
 * @file main.cpp
 * @name Código para utilizar el segundo núcleo físico del ESP32.
 * @author Rich González (contacto@geeksium.com)
 * @brief Con este código se puede conocer al núcleo desde el cual se  ejecuta el programa principal.
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 */

#include <Arduino.h>

void setup() {
    Serial.begin(115200);
}

void loop(){
    Serial.prinln("Utilizando el núcleo: " + String(xPortGetID()));
    delay(500);
}
```

---

Es común que el ESP32 utilice el núcleo 1 para la ejecución normal de su programa. Así que nos concentraremos en utilizar el **núcleo 0** del ESP32.

### Código

``` cpp
/**
 * @file main.cpp
 * @name Código para utilizar el segundo núcleo físico del ESP32.
 * @author Rich González (contacto@geeksium.com)
 * @brief En este código se describe la forma correcta para ejecutar funciones en el segundo núcleo del ESP32, mediante el uso de RTOS (Real-time Operative System).
 * @version 0.1
 * @date 2021-12-21
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 */

#include <Arduino.h>

// Función para Simular multitareas en Circuitos Intergrados (CI) con un sólo núcleo (RTOS).
// En este caso se asignará a un núcleo físico secundario físico (no sólo simulado).
TaskHandle_t Task2;

// Función "loop2". función que se le asignará al núcleo secundario.
void loop2 (void *parameter){
    for(;;){
        // [Opcional] Se imprimirá el Núcleo desde el cual se ejecuta esta tarea.
        Serial.println(" Utilizando el núcleo " + String(xPortGetCoreID()));
        // Aquí va el código a ejecutar en el Núcleo secundario.
        // ...
        
    }
    // Evitar alerta del "WatchDog en el Monitor Serial"
    vTaskDelay(10);
}

void setup() {
    /**
     * Definición de parámetros
     * 
     * @param pvTaskCode    loop2     Nombre de la función recursiva.
     * @param pcName        Tarea_1   Nombre de esta función que se està definiendo, puede cambiarse.
     * @param usStackDepth  1000      Tamaño de la pila.
     * @param pvParameters  NULL      Parámetros para esta tarea, en este caso son NULOS.
     * @param uxPriority    1         Prioridad.
     * @param pvCreatedTask &Tarea2   Nombre de la tarea que le dimos a la "TaskHandler_t" (se definió después del #include <Arduino.h>).
     * @param xCoreID       0         Núcleo en el que se ejecutará esta tarea, en este caso el núcleo 0.
     */
    xTaskCreatePinnedToCore(loop2, "Tarea_1", 1000, NULL, 1, &Task2, 0);
    
    // Inicialización normal para el Monitor Serial.
    Serial.begin(115200);
}

void loop(){}
```

---

---

<div align="center">
    <span
    style="font-family:'bebas neue extrabold';
    font-size:4em;">
        GEEKSIUM
    </span>
</div>

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
