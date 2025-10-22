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

void ingresarDimension(int &dim, const string &nombre) {
    cout << "Ingrese el nivel de " << nombre << " de la Matriz 3D: ";
    cin >> dim;
}

int main() {
    int p = 0, f = 0, c = 0;
    ingresarDimension(p, "profundidad");
    ingresarDimension(f, "filas");
    ingresarDimension(c, "columnas");

    int*** matriz = reservarMemoria<int>(p, f, c);

    // Asignar valores dentro del rango


        matriz[0][1][2] = 42;
        *(*(*(matriz + 0)+1)+3) = 12;
        matriz[1][2][3] = 99;

    // Mostrar matriz
    for (int i = 0; i < p; ++i) {
        cout << "\nCapa " << i << ":\n";
        for (int j = 0; j < f; ++j) {
            for (int k = 0; k < c; ++k)
                cout << matriz[i][j][k] << "\t";
            cout << endl;
        }
    }

    // Liberar memoria
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < f; ++j)
            free(matriz[i][j]);
        free(matriz[i]);
    }
    free(matriz);
}