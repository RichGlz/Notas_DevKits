# Creación de Bibliotecas (libraries) en C/C++

La creación de bibliotecas es una páctica muy utilizada especialmente a la hora de separar o 'modulizar' nuestro código. De esta manera el código se ve más limpio y puede ser más comprensible para los demás programadores involucrados.

**Trabajo en equipo:** Es muy común también que si varias personas hacen un mismo programa, cada quien se encargue de realizar una parte de ese programa, si fuera el caso, se podría encargar cada quien de realizar bibliotecas para luego hacer llamadas a esas funciones y que el programa/aplicación funcione correctamente.

> **Nota:** El término correcto es **Biblioteca**, ya que "librería"  en inglés sería _bookstore_ (tienda de libros).

---

## Qué se necesita para crear una biblioteca?

### Archivos externos

- Archivo de encabezados
- Código de la biblioteca (funciones)

### Código dentro del archivo _.cpp_ principal

- Incluir Biblioteca
- Llamadas de funciones.

---

## Ejemplo de Biblioteca en donde se realizan operaciones básicas

### Crear archivo de encabezados **bibliotecaNueva.h**

``` cpp
#ifndef _BIBLIOTECANUEVA_H_     // Recomiendo que el nombre de la definición sea así: <<_NOMBRE_EXTENSION_>>
#define _BIBLIOTECANUEVA_H_     // Recomiendo que el nombre de la definición sea así: <<_NOMBRE_EXTENSION_>>
    float suma(float num1,float num2);
    float resta(float num1,float num2);
    float multi(float num1,float num2);
#include  "bibliotecaNueva.cpp″
#endif
```

### Crear archivo de código de la biblioteca **bibliotecaNueva.cpp**

> Se recomienda ampliamente documentar el código de las bibliotecas creadas, ya que de hacerse de la manera correcta, será más fácil el poder saber a qué corresponde cada valor al momentos de llamar a las funciones.

``` cpp
/**Código SIN comentarios**/

#include <bibliotecaNueva.h>

float suma( float num1, float num2 ){ return num1 + num2; }
float resta( float num1, float num2 ){ return num1 - num2; }
float multi( float num1, float num2 ){ return num1 * num2; }
```

``` cpp

/**Código CON comentarios**/

#include <bibliotecaNueva.h>

/**
 * @brief Función Suma.
 * Recibe dos número reales y los suma.
 * 
 * @param num1 Corresponde a un valor real. Puede ser entero o decimal.
 * @param num2 Corresponde a un valor real. Puede ser entero o decimal.
 * @return float | Resultado de la suma.
 * @details Recibe dos número reales y le resta el segundo al primero.
 * 
 */ 
float suma( float num1, float num2 ){
    return num1 + num2;
}

/**
 * @brief Función Resta.
 * Recibe dos número reales y le resta el segundo al primero.
 * 
 * @param num1 Corresponde a un valor real. Puede ser entero o decimal.
 * @param num2 Corresponde a un valor real. Puede ser entero o decimal.
 * @return float | Resultado de la resta.
 */ 
float resta( float num1, float num2 ){
    return num1 - num2;
}

/**
 * @brief Función Multiplicación.
 * Recibe dos número reales y los multiplica.
 * 
 * @param num1 Corresponde a un valor real. Puede ser entero o decimal.
 * @param num2 Corresponde a un valor real. Puede ser entero o decimal.
 * @return float | Resultado de la multiplicación.
 */ 
float multi( float num1, float num2 ){
    return num1 * num2;
}
```

### Llamada a la biblioteca dentro del programa principal **main.cpp**

``` cpp
#include ″bibliotecaNueva.h″
```

## Invocación de funciones

``` cpp
void main(){
    int valor1 = 1;
    int valor2 = 2;

    printf(″%d + %d = %f\n″, valor1, valor2, suma(valor1,valor2));
    printf(″%d - %d = %f\n″, valor1, valor2, resta(valor1,valor2));
    printf(″%d * %d = %f\n″, valor1, valor2, multi(valor1,valor2));
    
    return 0;
}
```

---

## Cómo organizar los archivos de la **Bibliotecas** en Platformio?

> Nótese que

``` sql
Proyecto
│
└─ lib
│  └─ bibliotecaNueva           <-- Carpeta de la biblioteca
│       bibliotecaNueva.h       <-- Archivo de encabezados
│       bibliotecaNueva.cpp     <-- Código de la biblioteca
└─ src
     main.cpp
```

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
