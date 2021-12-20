# Sensores internos del ESP32

La placa **ESP32** cuenta con sensores internos tales como los mencionados a continuación:

# Sensor de efecto Hall

> También "Sensor de campo electromagnético".

---

El sensor de efecto hall se puede combinar con una detección de umbral para actuar como un interruptor, por ejemplo. Además, los sensores de efecto Hall se utilizan principalmente para:

- Detectar la proximidad a un objeto
- Calcular la posiciónde la placa
- Contar el número de revoluciones de una rueda
- Detecta el cierre de una puerta
- y más...

### Código:

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

# **Sensor de Temperatura**
### Código:

``` cpp
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

# **Sensor de pines Touch**

### Código:

``` cpp
  // Pendiente
```
