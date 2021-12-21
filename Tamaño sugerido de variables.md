# Tamaño de variables en C++

Lenguaje que usa Arduino

## Tipo de variables *para pines*

| Tipo   | Nombre                     | Tamaño (bits) | Posibles valores |
| :----- | :------------------------- | :------------ | :--------------- |
| uint_8 | Entero sin signo de 8 bits | 8             | 0 - 255          |

---

## Tipo de variable para la función _millis()_

Al igualar a millis(), es conveniente usar una 'variable entera sin signo de 32 bits'; ya que "millis()", al desbordarse ese valor se reinicia, tal como se muestra en [la documentación oficial](https://www.arduino.cc/reference/en/language/functions/time/millis/) de Arduino.

| Tipo          | Nombre                      | Tamaño | Posibles valores  |
| :------------ | :-------------------------- | :----- | :---------------- |
| uint_32       | Entero sin signo de 32 bits | 32     | 0 - 4,294,967,295 |
| unsigned long | Variable long sin signo     | 32     | 0 - 4,294,967,295 |

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
