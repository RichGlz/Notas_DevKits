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