# Creación de Bibliotecas (libraries) en C++

La creación de bibliotecas es una páctica muy utilizada especialmente a la hora de separar o 'modulizar' nuestro código. De esta manera el código se ve más limpio y puede ser más comprensible para los demás programadores involucrados.

**Trabajo en equipo:** Es muy común también que si varias personas hacen un mismo programa, cada quien se encargue de realizar una parte de ese programa, si fuera el caso, se podría encargar cada quien de realizar bibliotecas para luego hacer llamadas a esas funciones y que el programa/aplicación funcione correctamente.

> **Nota:** El término correcto es **Biblioteca**, ya que "librería"  en inglés sería _bookstore_ (tienda de libros).

---

## Qué se necesita para crear una biblioteca en Platformio?

### Archivos externos

- Archivo de encabezados
- Código de la biblioteca (funciones)

### Código dentro del archivo _.cpp_ principal

- Incluir Biblioteca
- Llamadas de funciones.

---

## Cómo organizar los archivos de la **Bibliotecas** en Platformio?

> Nótese que este es el acomodo para Platformio. El IDE de Arduino utiliza un método similar, pero varía en algunos puntos.

``` sql
Proyecto
│
└─ lib
│  └─ ManejoDeLeds           <-- Carpeta de la biblioteca
│       ManejoDeLeds.h       <-- Archivo de encabezados
│       ManejoDeLeds.cpp     <-- Código de la biblioteca
└─ src
     main.cpp
```

## Ejemplo de Biblioteca en donde se realizan operaciones con LEDs

### Crear archivo de encabezados **bibliotecaNueva.h**

``` cpp
#ifndef MANEJODELEDS_H
#define MANEJODELEDS_H

#include <Arduino.h>

void declaraLed( const uint8_t pin );     // Declaración de LED
void enciendeLed( const uint8_t pin );    // Encender LED
void apagaLed( const uint8_t pin ) ;      // Apaga LED
  
#endif // MANEJODELEDS_H
```

### Crear archivo de código de la biblioteca **bibliotecaNueva.cpp**

> Se recomienda ampliamente documentar el código de las bibliotecas creadas, ya que de hacerse de la manera correcta, será más fácil el poder saber a qué corresponde cada valor al momentos de llamar a las funciones.

``` cpp
#include <ManejoDeLeds.h>

// Declaración de LED
void declaraLed( const uint8_t pin ) {
    pinMode(pin, OUTPUT);
} 

// EnciendeLED
void enciendeLed( const uint8_t pin ) {
    digitalWrite(pin, HIGH);
} 

// ApagaLED
void apagaLed( const uint8_t pin ) {
    digitalWrite(pin, LOW);
} 
```

### Llamada a la biblioteca dentro del programa principal **main.cpp**

``` cpp
#include ″ManejoDeLeds.h″
```

## Invocación de funciones

``` cpp
// Incluir la Biblioteca
#include "ManejoDeLeds.h"

// Declarar la variable
const uint8_t pinDestino = 2;   //Para este ejemplo será el PIN 2.

void setup() {

    // Prueba de funciones
    declaraLed(pinDestino);
    enciendeLed(pinDestino);
    delay(2000);
    apagaLed(pinDestino);
}
```

---

## GEEKSIUM

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
