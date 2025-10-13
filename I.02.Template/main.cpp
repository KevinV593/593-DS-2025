#include <iostream>
#include "Fraccion.h"
using namespace std;

int main() {
    Fraccion<int> f1, f2, resultado;

    f1 = f1.crear();       // crear() returns Fraccion<int>
    f2 = f2.crear();
    resultado = f1.multiplicar(f2);

    cout << "Resultado: ";
    resultado.mostrar();
    cout << endl;

    return 0;
}