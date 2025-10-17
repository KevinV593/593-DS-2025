#pragma once

template <typename T>
class Fraccion {
    private:
    T numerador;
    T denominador;

    public:
    Fraccion(T numerador, T denominador);
    Fraccion();
    ~Fraccion();

    T getNumerador() const;
    T getDenominador() const;

    void setNumerador(T numerador);    
    void setDenominador(T denominador);

    void mostrar() const;
    Fraccion<T> multiplicar(const Fraccion<T>& otraFraccion) const ;
    Fraccion<T> operator/(const Fraccion<T>& otraFraccion) const;

};

#include "Fraccion.tpp"