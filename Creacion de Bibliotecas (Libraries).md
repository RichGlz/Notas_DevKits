/***


``` cpp

// Creamos dos archivos
#include <Arduino.h>

```

### NombreDeLaBilioteca.h

``` cpp
#ifndef _NOMBREDELABIBLIOTECA_H
#define _NOMBREDELABIBLIOTECA_H

#include <Arduino.h>
.
. // Código
.
#endif // Final de _NOMBREDELABILIOTECA_H
```



``` cpp

// Creamos un constructor
class NombreDeClase
{
    public:
        funcion1();         // Constructor
        ~funcion1();        // Destructor

        void setup(
            const uint8_t pin,
            float(*ecuacion)(
                float,
                float[],
                uint8_t
            ),
            flaot coeff[],
            uint8_t num_coeff
        );

        float read();
    private:
        uint8_t _pin;
        float (*_equation)(float, float[], uint8_y);
        float *coeff;
        uint8_t _num_coeff;

    protected:
};
```

## Creación de implementación _"NombreDeLaBiblioteca.cpp"_

``` cpp
// Creamos un constructor
#include <NombreDeLaBiblioteca.h>

NombreDeLaBiblioteca::funcion1()
{

}

NombreDeLaBiblioteca::~funcion1()
{

}

NombreDeLaBiblioteca::setup(
            const uint8_t pin,
            float(*ecuacion)(
                float,
                float[],
                uint8_t
            ),
            flaot coeff[],
            uint8_t num_coeff
        );
{
    _pin = pin;

}

NombreDeLaBiblioteca::read()
{

}

;
```