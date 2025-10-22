#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
T*** reservarMemoria(int &profundidad, int &filas, int &columnas) {
    T*** celda = (T***) malloc(profundidad * sizeof(T**));

    for (int i = 0; i < profundidad; ++i) {
        *(celda + i) = (T**) malloc(filas * sizeof(T*));

        for (int j = 0; j < filas; ++j) {
            *(*(celda + i) + j) = (T*) calloc(columnas, sizeof(T));
        }
    }

    return celda;
}

int main() {
    int p = 2, f = 3, c = 4;
    int*** matriz = reservarMemoria<int>(p, f, c);

    // Asignar valores
    matriz[0][1][2] = 42;
    matriz[1][2][3] = 99;

    // Mostrar
    for (int i = 0; i < p; ++i) {
        cout << "\nCapa " << i << ":\n";
        for (int j = 0; j < f; ++j) {
            for (int k = 0; k < c; ++k)
                cout << matriz[i][j][k] << "\t";
            cout << endl;
        }
    }

    // Liberar
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < f; ++j)
            free(matriz[i][j]);
        free(matriz[i]);
    }
    free(matriz);
}