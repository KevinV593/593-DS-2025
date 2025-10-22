#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

// --- Código original a probar ---
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

void liberarMemoria(int*** matriz, int p, int f) {
    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < f; ++j)
            free(matriz[i][j]);
        free(matriz[i]);
    }
    free(matriz);
}

// --- Funciones de prueba ---
void testReservaYAcceso() {
    int p = 2, f = 3, c = 4;
    int*** matriz = reservarMemoria<int>(p, f, c);

    matriz[0][1][2] = 42;
    matriz[1][2][3] = 99;

    assert(matriz[0][1][2] == 42);
    assert(matriz[1][2][3] == 99);

    // Los demás deben seguir siendo 0 (calloc inicializa en 0)
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < f; ++j)
            for (int k = 0; k < c; ++k)
                if (!((i==0 && j==1 && k==2) || (i==1 && j==2 && k==3)))
                    assert(matriz[i][j][k] == 0);

    liberarMemoria(matriz, p, f);
    cout << "testReservaYAcceso pasado correctamente.\n";
}

void testInicializacionCero() {
    int p = 1, f = 2, c = 3;
    int*** matriz = reservarMemoria<int>(p, f, c);

    for (int i = 0; i < p; ++i)
        for (int j = 0; j < f; ++j)
            for (int k = 0; k < c; ++k)
                assert(matriz[i][j][k] == 0);

    liberarMemoria(matriz, p, f);
    cout << "testInicializacionCero pasado correctamente.\n";
}

// --- Main para ejecutar todos los tests ---
int main() {
    cout << "Iniciando pruebas unitarias...\n";
    testReservaYAcceso();
    testInicializacionCero();
    cout << "Todas las pruebas pasaron correctamente.\n";
    return 0;
}