# Display SSD1306 128x64 (Estructura Base)

Este es el código base para poder inicializar el Display OLED SSD1306.

---

### **Bibliotecas requeridas**

| Biblioteca (library) | Autor           | Descripción                                                       |
| :------------------- | :-------------- | :---------------------------------------------------------------- |
| Arduino              | Arduino         | Se encarga de los comandos principales de control de arduino.     |
| SPI (Adafruit BusIO) | Adafruit        | Biblioteca de interface para UART, I2C y SPI.                     |
| Wire (OneWire)       | Paul Stoffregen | Protocolo de control 1-wire.                                      |
| Adafruit_GFX         | Adafruit        | Biblioteca del núcleo gráfico de hardware de displays.            |
| Adafruit_SSD1306     | Adafruit        | Controlador OLED  monocrómico para el SSD1306 de 128x64 y 128x32. |

---

### **Definiciones**

| Nombre              | Descripción              | Comentarios                                                    |
| :------------------ | :----------------------- | :------------------------------------------------------------- |
| _displayAncho 128   | Ancho del display (128)  | Esta variable no es estrictamente necesario definirla.         |
| _displayAlto 64     | Alto del display (64)    | Esta variable no es estrictamente necesario definirla.         |
| OLED_RESET -1       | Botón de RESET asociado  | Si no se define botón o está compartido, se escribe -1.        |
| SCREEN_ADDRESS 0x3C | Dirección de la pantalla | Dirección de la pantalla, generalmente 0x3C pero también 0x3C. |

---

### **Configuración dentro de la función _setup()_**

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