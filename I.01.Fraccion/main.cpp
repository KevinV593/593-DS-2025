#include <iostream>
#include "Fraccion.h"
using namespace std;

int main() {
    Fraccion fraccion1, fraccion2, resultado;

    cout << "CREACION DE Fraccion1:" << endl;
    fraccion1 = fraccion1.crear();
    cout << "CREACION DE Fraccion2:" << endl;
    fraccion2 = fraccion2.crear();
    resultado = fraccion1.multiplicar(fraccion2);

    cout << "El resultado de la multiplicación de la fracción: "; 
    fraccion1.mostrar(); cout << endl;
    cout << " Y la fracción: "; 
    fraccion2.mostrar(); cout << " es: "; resultado.mostrar();

    return 0;
}