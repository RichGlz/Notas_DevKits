# Generación de números aleatorios

Los IC generalmente cuentan con funciones generadoras de números aleatorios por software, es decir que una función genera números con cierto nivel de aleatoriedad, sin embargo, aunque aparentan ser aleatorios, no lo son realmente.

El **ESP32** cuenta con una característica avanzada llamada _Aceleración de hardware criptográfico_, que dentro de sus funciones cuenta con un _Generador de números aleatorios (RNG - Random Numbers Generator)_ por sus siglas en inglés.

Los números pueden ser de tamaño de `unsigned long` o `UINT32_MAX`, que en ambos casos equivalen a 4 bytes (32 bits), es decir, van de 0 a 4,294,967,295.

---

## Función generadora de n números "semi-aleatorios"

Esta función genera _n_ números aleatorios que van de 0 hasta n-1, es decir, que si introducimos el número entero 10, la función generará números del 0 al 9 aleatoriamente.

``` cpp
random(n);
```

## Función generadora de números entre un rango dado "semi-aleatorios"

Se generarán números enteros aleatorios de _n a m-1_, es decir, si n=100 y m=200, obtendremos numeros del 100 al 199.

``` cpp
random(n, m);
```

## Función aleatorio del ESP32

``` cpp
esp_random();
```

> Los números de 32bits sin signo van de 0 a 4,294,967,295.

## Código de ejemplo de las tres funciones

``` cpp
#include <Arduino.h>

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println(random(10));
    Serial.println(random(20,30));
    Serial.println(esp_random());
    delay(1000);
}
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
