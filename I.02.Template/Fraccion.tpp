#include "Fraccion.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
Fraccion<T>::Fraccion(T numerador, T denominador) {
    this -> numerador = numerador;
    this -> denominador = denominador;
    if (denominador == 0) {
        cout << "El denominador no puede ser cero. Se asigna 1 por defecto." << endl;
    }
};
    
template <typename T>
Fraccion<T>::Fraccion(){   
    denominador=1;
    numerador=1;
};

template <typename T>
Fraccion<T>::~Fraccion(){
    //Destructor
};  

template <typename T>
T Fraccion<T>::getNumerador() const {
    return numerador;
}

template <typename T>
T Fraccion<T>::getDenominador() const {
    return denominador;
}

template <typename T>
void Fraccion<T>::setNumerador(T numerador) {
    this->numerador = numerador;
}

template <typename T>
void Fraccion<T>::setDenominador(T denominador) {
if (denominador != 0) {
        this->denominador=denominador;
        }
    else {
        cout<<"El denominador no puede ser cero. No hay modificaciones";
    }
}

template <typename T>
Fraccion<T> Fraccion<T>::crear() {
    T numerador, denominador;
    string input;

    do {
        cout << "Ingrese el numerador: ";
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> numerador) || !(ss.eof())) {
            cout << "Invalido. Solo se permiten números." << endl;
        } else break;
    } while (true);

    do {
        cout << "Ingrese el denominador (distinto de cero): ";
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> denominador) || !(ss.eof()) || denominador == 0) {
            cout << "Invalido. Solo se permiten números distintos de cero." << std::endl;
        } else break;
    } while (true);

    return Fraccion<T>(numerador, denominador);
}

template <typename T>
Fraccion<T> Fraccion<T>::multiplicar(Fraccion<T> otraFraccion){
    return Fraccion<T>(numerador * otraFraccion.getNumerador(), denominador * otraFraccion.getDenominador());
}

template <typename T>
void Fraccion<T>::mostrar() {
    cout << getNumerador() << "/" << getDenominador() << endl;
};