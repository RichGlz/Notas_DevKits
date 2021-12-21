# Utilizando el núcleo 0

Es una pregunta que muchos nos hemos hecho una vez que sabemos que el ESP32 cuenta con dos núcleos en us interior según [la documentación oficial](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf) deSpressif (página 12). y aquí les mostramos cómo:

---

## Cómo saber qué núcleo estoy usando para alguna tarea en concreto?

Copia y pega la siguiente línea de código en tu función `void loop(){...}`:

``` cpp
    Serial.prinln("Utilizando el núcleo: " + String(xPortGetID()));
    delay(500);
```

> No olvides inicializar el Serial con la línea de código: `Serial.begin(115200);`.

---

Es común que el ESP32 utilice el núcleo 1 para la ejecución normal de su programa. Así que nos concentraremos en utilizar el **núcleo 0** del ESP32.

### Código

``` cpp
#include <Arduino.h>

// Función para Simular multitareas en CI con un sólo núcleo (RTOS).
// En este caso se asignará a un núcleo físico secundario existente.
TaskHandle_t Task2;

// Función "loop2", que asignaremos al núcleo secundario.
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
     * @param pcName        Tarea_1   Nombre de esta función, puede cambiarse.
     * @param usStackDepth  1000      Tamaño de la pila.
     * @param pvParameters  NULL      Parámetros para esta tarea, en este caso nada.
     * @param uxPriority    1         Prioridad.
     * @param pvCreatedTask &Tarea2   Nombre de la tarea que le dimos a la "TaskHandler_t".
     * @param xCoreID       0         Núcleo en el que se ejecutará esta tarea.
     */
    xTaskCreatePinnedToCore(loop2, "Tarea_1", 1000, NULL, 1, &Tarea2, 0);
    
    // Inicialización normal para el Monitor Serial.
    Serial.begin(115200);
}

void loop(){}
```

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
