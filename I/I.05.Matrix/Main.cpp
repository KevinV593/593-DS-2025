#include <iostream>
#include "Matriz.hpp"

using namespace std;

int main() {
    int filas1, columnas1, filas2, columnas2;

    cout << "Ingresa filas y columnas de la primera matriz: ";
    cin >> filas1 >> columnas1;

    cout << "Ingresa filas y columnas de la segunda matriz: ";
    cin >> filas2 >> columnas2;

    if (columnas1 != filas2) {
        cout << "Error: las matrices no se pueden multiplicar." << endl;
        return 1;
    }

    Matriz<int> A(filas1, columnas1);
    Matriz<int> B(filas2, columnas2);

    cout << "\nLlenando la primera matriz:\n";
    A.llenarMatriz();
    cout << "\nLlenando la segunda matriz:\n";
    B.llenarMatriz();

    auto llamarMatriz = [](const Matriz<int>& M, const string& mensaje) {
        cout << "\n" << mensaje << ":\n";
        M.mostrar();
    };

    llamarMatriz(A, "Primera Matriz");
    llamarMatriz(B, "Segunda Matriz");

    Matriz<int> C = A * B;
    cout << "\nResultado de A * B:\n";
    C.mostrar();

    return 0;
}