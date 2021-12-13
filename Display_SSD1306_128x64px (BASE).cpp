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

#include <SPI.h>              // Biblioteca de SPI
#include <Wire.h>             // Biblioteca de OneWire
#include <Adafruit_GFX.h>     // Biblioteca de GFX
#include <Adafruit_SSD1306.h> // Biblioteca de SSD1306

/*************************************************************/

#define _displayAncho 128   // ANCHO del display OLED en pixeles
#define _displayAlto 64     // ALTO del display OLED en pixeles
#define OLED_RESET -1       // # Pin de Reset (o -1 si se comparte el pin de reset del Arduino)
#define SCREEN_ADDRESS 0x3C // mira el datasheet Para la dirección; puede ser 0x3C o 0x3D.

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

  // Dibuja una simple línea en color blanco.
  display.drawLine(16,0,16,128, SSD1306_WHITE);

  // Muestra el buffer de la pantalla. Tienes que invocar la función "display()"
  // después para hacer los elementos visibles en la pantalla.
  display.display();
  delay(2000);
  // display.display() NO es necesario que se ponga en en cada línea
  // a menos que sea lo que quieras, de otra manera haz al configuración
  // y ejecuta la función "display.display()" al final.

}

void loop() {}