#include <iostream>
#include "Matriz.hpp"

using namespace std;


template <typename T>
Matriz<T>::Matriz(int filas, int columnas) : filas(filas), columnas(columnas) {
    celda = (T**) malloc(filas * sizeof(T*));
    for (int i = 0; i < filas; i++) {
            *(celda + i) = (T*) calloc(columnas, sizeof(T)); 
    }
}

template <typename T>
Matriz<T>::Matriz() : filas(2), columnas(2) {
    celda = (T**) malloc(filas * sizeof(T*));
    for (int i = 0; i < filas; i++) {
            *(celda + i) = (T*) calloc(columnas, sizeof(T)); 
    }
}

template <typename T> 
Matriz<T>::~Matriz() {
    for (int i = 0; i < filas; i++) {
        free(*(celda + i));
    }
free(celda);
}

template <typename T>
T Matriz<T>::getFilas() const { return filas; };

template <typename T>
T Matriz<T>::getColumnas() const { return columnas; };

    
template <typename T> 
void Matriz<T>::llenarMatriz() {
    cout << "Ingrese " << filas * columnas << " elementos:\n";
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++) {
                cout << "Ingrese valor de la celda ("<<i+1<<", "<<j+1<<")\n";
                cin >> *(*(celda+i)+j);
            }
};

template <typename T> 
void Matriz<T>::mostrar() const {
    for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++)
                cout << *(*(celda+i)+j) << " ";
            cout << endl;
        }
};

template <typename T> 
Matriz<T> Matriz<T>::operator*(const Matriz& otraMatriz) const {
    if (columnas != otraMatriz.getFilas()) {
        cout << "Incompatible dimensions!\n";
        exit(1);
    }   
Matriz<T> resultado(filas, otraMatriz.getColumnas());
for (int i = 0; i < filas; i++) {
    for (int j = 0; j < otraMatriz.columnas; j++) {
        for (int k = 0; k < columnas; k++) {
            *(*(resultado.celda + i) + j) += *(*(celda + i) + k) * *(*(otraMatriz.celda + k) + j);
        }
    }
}
return resultado;
};