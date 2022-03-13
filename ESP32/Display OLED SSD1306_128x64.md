# Display SSD1306 128x64 (Estructura Base)

Este es el código base para poder inicializar el Display OLED SSD1306.

---

## Bibliotecas requeridas

| Biblioteca (library) | Autor           | Descripción                                                       |
| :------------------- | :-------------- | :---------------------------------------------------------------- |
| Arduino              | Arduino         | Se encarga de los comandos principales de control de arduino.     |
| SPI (Adafruit BusIO) | Adafruit        | Biblioteca de interface para UART, I2C y SPI.                     |
| Wire (OneWire)       | Paul Stoffregen | Protocolo de control 1-wire.                                      |
| Adafruit_GFX         | Adafruit        | Biblioteca del núcleo gráfico de hardware de displays.            |
| Adafruit_SSD1306     | Adafruit        | Controlador OLED  monocrómico para el SSD1306 de 128x64 y 128x32. |

---

## Definiciones

| Nombre              | Descripción              | Comentarios                                                    |
| :------------------ | :----------------------- | :------------------------------------------------------------- |
| _displayAncho 128   | Ancho del display (128)  | Esta variable no es estrictamente necesario definirla.         |
| _displayAlto 64     | Alto del display (64)    | Esta variable no es estrictamente necesario definirla.         |
| OLED_RESET -1       | Botón de RESET asociado  | Si no se define botón o está compartido, se escribe -1.        |
| SCREEN_ADDRESS 0x3C | Dirección de la pantalla | Dirección de la pantalla, generalmente 0x3C pero también 0x3C. |

---

### Configuración dentro de la función _setup()_

| Nombre                   | Argumentos                                     | Descripción                       | Comentarios |
| :----------------------- | :--------------------------------------------- | :-------------------------------- | :---------- |
| Serial.begin             | 115200                                         | Inicialización del Monitor Serial |             |
| Adafruit_SSD1306 display | _displayAncho, _displayAlto, &Wire, OLED_RESET | Ancho del display (128)           |             |
| display.begin            | SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS           | Alto del display (64)             |             |

---

### **Configuración básica del display _SSD1306 128x64_**

| Nombre                                        | Descripción                                                 | Comentarios |
| :-------------------------------------------- | :---------------------------------------------------------- | :---------- |
| display.display()                             | Si se escribe al inicio, se muestra el logotipo de Adafruit |             |
| display.clearDisplay()                        | Limpia el buffer del display. Pone los pixeles en 0.        |             |
| display.drawLine(16,0,16,128, SSD1306_WHITE); | Agrega al buffer una línea color blanca                     |             |
| display.display();                            | Muestra el buffer en el display.                            |             |

## Código

``` cpp

/**
 * @file main.cpp
 * @name Estructura base para Display SSD1306 128x64px
 * @author Rich González (contacto@geeksium.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-03
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
 */

#include <Arduino.h>          // Biblioteca de Arduino 

#include <SPI.h>              // Biblioteca de SPI (by )
#include <Wire.h>             // Biblioteca de OneWire (by )
#include <Adafruit_GFX.h>     // Biblioteca de GFX (by )
#include <Adafruit_SSD1306.h> // Biblioteca de SSD1306 (by )

/*************************************************************/

#define _displayAncho 128   // ANCHO del display OLED en pixeles
#define _displayAlto 64     // ALTO del display OLED en pixeles
#define OLED_RESET -1       // # Pin de Reset (o -1 si se comparte el pin de reset del Arduino)
#define SCREEN_ADDRESS 0x3C // mira el datasheet Para la dirección; puede ser 0x3C o 0x3D.

uint8_t _ancho = 128-1;
uint8_t _alto = 64-1;

void setup() {
  Serial.begin(115200);

  Adafruit_SSD1306 display(_displayAncho, _displayAlto, &Wire, OLED_RESET);

  // SSD1306_SWITCHCAPVCC = configura el voltaje del display a 3.3V de manera interna.
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("No se encontró al SSD1306"));
    for(;;); // Bucle infinito. No avanzará si esto pasa.
  }

  // Limpia el buffer.
  display.clearDisplay();

  // Se agrega al buffer líneas horizontales en color blanco.
  display.drawLine(0, 0,128, 0, WHITE); // Línea horizontal, con Y =  0
  display.drawLine(0,15,128,15, WHITE); // Línea horizontal, con Y = 15
  display.drawLine(0,16,128,16, WHITE); // Línea horizontal, con Y = 16
  display.drawLine(0,63,128,63, WHITE); // Línea horizontal, con Y = 63

  // Se agrega al buffer las letras "Geeksium".
  display.setTextColor(WHITE);          // Se configura el color comoblanco
  display.setTextSize(1);               // Tamaño del texto (del 1 al 6).
  display.setCursor(42, 4);             // Se pone el cursor en la posición x=42, y=4.
  display.println("Geeksium");          // Se imprime la cadena "Geeksium".

  // Muestra el buffer de la pantalla. Tienes que invocar la función "display()"
  // después para hacer los elementos visibles en la pantalla.
  display.display();
  delay(2000);
  // display.display() NO es necesario que se ponga en en cada línea
  // a menos que sea lo que quieras, de otra manera haz al configuración
  // y ejecuta la función "display.display()" al final.
}

void loop() {}

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