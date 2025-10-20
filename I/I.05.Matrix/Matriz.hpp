#pragma once

template <typename T>
class Matriz {
    private:
    int filas, columnas;
    T** celda;

    
    public:
    Matriz(int filas, int columnas);
    Matriz();
    ~Matriz();

    T getFilas() const;
    T getColumnas() const;
    


    void llenarMatriz();
    void mostrar() const;

    Matriz<T> operator*(const Matriz& otraMatriz) const;
};

#include "Matriz.tpp"