#include <stdexcept> // para std::invalid_argument
#include <iostream>

using namespace std;

template <typename T>
Fraccion<T>::Fraccion(T numerador, T denominador) : numerador(numerador) { 
    if (denominador == 0) {
    throw invalid_argument("Denominador no puede ser 0");
    } 
    this->denominador = denominador;
}

template <typename T>
Fraccion<T>::Fraccion() : denominador(1), numerador(1) {};

template <typename T>
Fraccion<T>::~Fraccion(){ /*Destructor*/ }; 

template <typename T>
T Fraccion<T>::getNumerador() const { return numerador; };

template <typename T>
T Fraccion<T>::getDenominador() const { return denominador; };

template <typename T>
void Fraccion<T>::setNumerador(T numerador) { this->numerador = numerador; };

template <typename T>
void Fraccion<T>::setDenominador(T denominador) { 
    if (denominador == 0) {
    throw invalid_argument("Denominador no puede ser 0");
    }
    this->denominador = denominador;
};

template <typename T>
void Fraccion<T>::mostrar() const { 
    cout << getNumerador() << "/" << getDenominador(); 
}

template <typename T>
Fraccion<T> Fraccion<T>::multiplicar(const Fraccion<T>& otraFraccion) const {
    return Fraccion<T>(getNumerador() * otraFraccion.getNumerador(),
                    getDenominador() * otraFraccion.getDenominador());
};

template <typename T>
Fraccion<T> Fraccion<T>::operator/(const Fraccion<T>& otraFraccion) const {
    return Fraccion<T>(getNumerador() * otraFraccion.getDenominador(),
                    getDenominador() * otraFraccion.getNumerador());
};