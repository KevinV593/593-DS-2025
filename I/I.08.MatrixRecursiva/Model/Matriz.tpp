#include "Matriz.hpp"

#include <functional>

using namespace std;

template <typename T>
Matriz<T>::Matriz(int profundidad, int filas, int columnas)
    : profundidad(profundidad), filas(filas), 
    columnas(columnas), celda(nullptr) {
    reservarMemoria();
};

template <typename T>
void Matriz<T>::reservarMemoria() {
    try {
        celda = (T***) malloc(profundidad * sizeof(T**));
        
        for (int i = 0; i < profundidad; i++) {
            *(celda + i) = (T**) malloc(filas * sizeof(T*));
            for (int j = 0; j < filas; j++) {                    
                *(*(celda + i)+j) = (T*) calloc(columnas, sizeof(T));
            }
        }    
    } catch (const exception& e) {
        cerr << "Excepcion en reserva: " << e.what() << endl;
        liberarMemoria();
        throw;
    }
}

template <typename T>
Matriz<T>::~Matriz(){
    liberarMemoria();
};

template <typename T>
void Matriz<T>::liberarMemoria(){
    if(celda != nullptr) {
        for (int i = 0; i < profundidad; i++) {
            if(*(celda+i)) {
                for(int j = 0; j < 0; j++) {
                    free(*(*celda + i)+j); 
                }
                free(*(celda+i));
            }
        }
        free(celda);
        celda = nullptr;
    }
}

template <typename T>
void Matriz<T>::llenar() {
    cout << "Llenando matriz 3D (" << profundidad << "x" << filas << "x" << columnas << "):\n";
    for (int i = 0; i < profundidad; ++i) {
        for (int j = 0; j < filas; ++j) {
            for (int k = 0; k < columnas; ++k) {
                cout << "[" << i << "][" << j << "][" << k << "] = ";
                cin >> *(*(*(celda+i)+j)+k);
            }
        }
    }
}

template <typename T>
void Matriz<T>::mostrar() const {
    auto recorrer = [&](int i, int j, int k, auto&& self) -> void {

        if (i == profundidad) return;

        if (j == filas) {
            cout << "\n";
            self(i + 1, 0, 0, self); 
            return;
        }

        // Cuando llegamos al final de una columna, pasamos a la siguiente fila
        if (k == columnas) {
            cout << "\n";
            self(i, j + 1, 0, self);
            return;
        }

        // Mostrar elemento actual
        if (k == 0 && j == 0) {
            std::cout << "Capa " << i + 1 << ":\n";
        }

        std::cout << *(*(*(celda + i)+j)+k) << "\t";

        self(i, j, k + 1, self);
    };

    recorrer(0, 0, 0, recorrer);
};

template <typename T>
T Matriz<T>::trazaDiagonal() const {
    T traza = T();

    auto recorrer = [&](int i, int j, auto&& self) -> void {
        if (i >= profundidad) return;

        if(j >= filas || j >=columnas) {
            self(i + 1,0, self);
            return;
        }
        
        traza += *(*(*(celda + i) + j) + j);

        self(i,j + 1, self);

    };

    recorrer(0,0,recorrer);

    cout<<"Traza Diagonal Total es: "<< traza << endl;
    
    return traza;
};