#pragma once

#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class Matriz {
private:
    int profundidad;
    int filas;
    int columnas;
    T*** celda; 

public:
    Matriz(int &profundidad, int &filas, int &columnas) 
        : profundidad(profundidad), filas(filas), columnas(columnas), celda(nullptr) {
        reservarMemoria();
    }

    ~Matriz() {
        liberarMemoria();
    }

    void reservarMemoria() {
        celda = (T***) malloc(profundidad * sizeof(T**));
        for (int i = 0; i < profundidad; ++i) {
            *(celda + i) = (T**) malloc(filas * sizeof(T*));
            for (int j = 0; j < filas; ++j) {
                *(*(celda + i) + j) = (T*) calloc(columnas, sizeof(T));
            }
        }
    }

    void llenar() {
        for (int i = 0; i < profundidad; ++i) {
            cout << "\nCapa " << i + 1 << ":\n";
            for (int j = 0; j < filas; ++j) {
                for (int k = 0; k < columnas; ++k) {
                    cout << "Elemento [" << i << "][" << j << "][" << k << "]: ";
                    cin >> *(*(*(celda + i) + j) + k);
                }
            }
        }
    }

    void mostrar() const {
        for (int i = 0; i < profundidad; ++i) {
            cout << "\nCapa " << i + 1 << ":\n";
            for (int j = 0; j < filas; ++j) {
                for (int k = 0; k < columnas; ++k) {
                    cout << *(*(*(celda + i) + j) + k) << "\t";
                }
                cout << endl;
            }
        }
    }

    void liberarMemoria() {
        if (!celda) return;

        for (int i = 0; i < profundidad; ++i) {
            for (int j = 0; j < filas; ++j) {
                free(*(*(celda + i) + j));
            }
            free(*(celda + i));
        }
        free(celda);
        celda = nullptr;
    }

    T& get(int i, int j, int k) {
        return *(*(*(celda + i) + j) + k);
    }
};