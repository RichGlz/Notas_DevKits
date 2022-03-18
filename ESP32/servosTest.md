``` cpp
/**
 * @file main.cpp
 * @name Código probador de servos
 * @author Rich González (contacto@geeksium.com)
 * @brief Con este código aún ando haciendo pruebas.
 * @version 0.1
 * @date 2022-03-17
 * 
 * @copyright Copyright (c) 2021
 * 
 * 
*/

#include <Arduino.h>
#include <Servo.h>

uint8_t retraso = 15;
Servo servo;

const unit8_t servoPin = 4;
const unit8_t potenciomeretroPin = 5;


void setup(){
  Serial.begin();
  Servo.attach(servoPin);

  uint32_t msAnterior = 0;
  int valor = 0;
}

void  loop(){

  uint32_t ms = millis();
  if (ms - msAnterior > retraso)
  {
    valor = analogRead(potenciometroPin);
    valor = map(valor, 0, 1023, 0, 180);
    servo.write(valor);

    tiempo 
  }
}
```
