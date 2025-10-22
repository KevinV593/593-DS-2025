#include <iostream>
#include "Matriz.hpp"
using namespace std;

int main() {
    int p, f, c;
    cout << "Ingrese profundidad, filas y columnas: ";
    cin >> p >> f >> c;

    Matriz<double> matriz(p, f, c);

    cout << "\n--- Llenando la matriz ---\n";
    matriz.llenar();

    cout << "\n--- Mostrando la matriz ---\n";
    matriz.mostrar();

    return 0;
}