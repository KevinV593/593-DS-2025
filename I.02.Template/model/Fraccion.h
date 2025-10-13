#pragma once

template <typename T>
class Fraccion {
    private:

    T denominador;
    T numerador;

    public:

    Fraccion(T numerador, T denominador);
    Fraccion();
    ~Fraccion();

    T getDenominador() const;
    T getNumerador() const;

    void setDenominador(T denominador);
    void setNumerador(T numerador);

    Fraccion<T> crear();
    Fraccion<T> multiplicar(Fraccion<T> otraFraccion);
    void mostrar();

};

#include "Fraccion.tpp"