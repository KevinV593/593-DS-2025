#pragma once

template <typename T>
class Matriz {
    private:
    int profundidad, filas, columnas;
    T*** celda;

    void reservarMemoria();
    void liberarMemoria();
    
    public:
    Matriz(int profundidad, int filas, int columnas);
    ~Matriz();

    void llenar();
    void mostrar() const;
    T trazaDiagonal() const;

    int getProfundidad() const { return profundidad; };
    int getFilas() const { return filas; };
    int getColumnas() const { return columnas; };
};

#include "Matriz.tpp"