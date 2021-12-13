# Tamaño de variables en C++

Lenguaje que usa Arduino

## Tipo de variables *para pines*

| Tipo   | Nombre                     | Tamaño (bits) | Posibles valores |
| :----- | :------------------------- | :------------ | :--------------- |
| uint_8 | Entero sin signo de 8 bits | 8             | 0 - 255          |

---

## Tipo de variable para la función *millis()*.
Al igualar a millis(), es conveniente usar una 'variable entera sin signo de 32 bits'; ya que "millis()", al desbordarse ese valor, el valor se reinicia, tal como se muestra en [la documentación oficial](https://www.arduino.cc/reference/en/language/functions/time/millis/).

| Tipo          | Nombre                      | Tamaño | Posibles valores  |
| :------------ | :-------------------------- | :----- | :---------------- |
| uint_32       | Entero sin signo de 32 bits | 32     | 0 - 4,294,967,295 |
| unsigned long | Variable long sin signo     | 32     | 0 - 4,294,967,295 |


