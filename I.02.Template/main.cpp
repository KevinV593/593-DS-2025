#include "Fraccion.h"
#include <iostream>
using namespace std;

int main() {
    cout << "--- Fracción con enteros ---" << endl;
    Fraccion<int> f1 = Fraccion<int>::mostrar();

    cout << "--- Fracción con decimales ---" << endl;
    Fraccion<float> f2 = Fraccion<float>::crear();

    cout << "Fracción 1: ";
    f1.mostrar();
    cout << "Fracción 2: ";
    f2.mostrar();

    auto resultado = f1.multiplicar(f2);
    cout << "Multiplicación: ";
    resultado.mostrar();

    return 0;
}
