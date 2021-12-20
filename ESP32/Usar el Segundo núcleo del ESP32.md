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
    // Evitar alerta de "WatchDog timer en el Monitor Serial"
    vTaskDelay(10);
}


void setup() {
    /**
     * @params: loop2     Nombre de la función recursiva.
     *          "Tarea_1" Nombre de esta función, puede cambiarse.
     *          1000      Tamaño de la pila.
     *          NULL      Parámetros para esta tarea, en este caso nada.
     *          1         Prioridad.
     *          &Tarea2   Nombre de la tarea que le dimos a la "TaskHandler_t __".
     *          0         Núcleo en el que se ejecutará esta tarea.
     */
    xTaskCreatePinnedToCore(loop2, "Tarea_1", 1000, NULL, 1, &Tarea2, 0);
    
    // Inicialización normal para el Monitor Serial.
    Serial.begin(115200);
}

```