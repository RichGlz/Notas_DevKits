# Un mismo código, varias placas

No has requerido utilizar el mismo código con varias placas?
Arduino, ESP8266, ESP32, etc?

Pues la realidad es que es posible, sólo hay que darle unas cuantas condiciones al compilador para que, al momento de hacer su trabajo, decida por sí mismo qué lineas de código incluir y cuales no con base en la placa que con la que estemos trabajando.

## Desglose de parámetros de la función _attachinterrupt()_

| Función                        | Descripción                                        | Se lee como                                                          |
| :----------------------------- | :------------------------------------------------- | :------------------------------------------------------------------- |
| ```#if defined(condicion)```   | Se define una primera condición                    | Si (la placa) está definida como `_condicion_`, ejecuta lo siguiente |
| ```#elif defined(condicion)``` | Se evalúa otra condición                           | De otra manera, si está definida como  `_condicion_`                 |
| ```#else```                    | Se ejecuta si ninguna condición anterior se cumple | Si ninguna anterior se cumple, entonces                              |
| ```#endif```                   | Cierre del `if`                                    |                                                                      |
| ```#pragma message "texto" ``` | Mensaje para mostrar en la terminal                | Muestra por terminal el siguiente mensaje `texto`                    |

## Código de ejemplo

``` Arduino
#if defined(ESP32)
  #pragma message "Código para ESP32"
  // Escriba código a ejecutar para ESP32

#elif defined(ESP8266)
  #pragma message "Código para ESP8266"
  // Escriba código a ejecutar para ESP8266

#elif defined(ARDUINO)
  #pragma message "Código para Arduino"
  // Escriba código a ejecutar para Arduino

#else
  #pragma message "Código para todas las demás"
  // Escriba código a ejecutar para otras placas

#endif

void setup() {
  // Aquí va el código del setup.
}

void loop() {
  // Aquí va el código del loop.
}
```

---

## Ventajas

* Se utiliza una menor cantidad de memoria ya que, aunque sea un código largo sólo se compilará (y meterá a la memoria) lo necesario, según lo hayamos programado.


## Usos comunes

* Ejecutar **diferentes bibliotecas** según el Hardware que estemos utilizando.
* Utilizar **la misma biblioteca, pero diferente configuración**, según el Hardware.
* entre otras..

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
