# EScaner de puertos i2c.

Los puertos i2c sirven para conectar múltiples dispositivos con sólo 4 cables, es decir, VCC, GND, SDA y SCL.

### En las placas más conocidas, los puertos son los siguientes:

|      Placa       |  Puerto SDA  |  Puerto SCL  |
| :--------------- | :----------- | :----------- |
| Arduino uno      |    GPIO18    |    GPIO19    |
| ESP32 (30 pines) |    GPIO21    |    GPIO22    |
| ESP32 (38 pines) |    GPIO21    |    GPIO22    |
| DigiSpark        |    GPIO00    |    GPIO02    |


El *ESP01* No tiene unos puertos definidos, sin embargo, hay algunos entuciastas que han podido realizar estas conexiónes, les dejo un ejemplo en este [enlace](https://www.youtube.com/watch?v=9LeRmFg8vRc).

## OJO! Dependiendo del módulo, éste trabajará con 3.3V o con 5V. Se recomienda leer las especificaciones de cada módulo evitar dañarlo/quemarlo.

---

## Código de ejemplo de las tres funciones

``` cpp
#include <Arduino.h>
#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("\nEscaner de puertos I2C");
}
 
void loop() {
  byte error, address;
  int nDevices;
  Serial.println("Escaneando...");
  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Dispositivo I2C en la dirección: 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
      nDevices++;
    }
    else if (error==4) {
      Serial.print("Error desconocido en la dirección: 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("No se encontraron dispositivos I2C.\n");
  }
  else {
    Serial.println("done\n");
  }
  delay(5000);          
}
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
