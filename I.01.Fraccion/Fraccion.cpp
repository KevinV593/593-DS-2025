#include "Fraccion.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Fraccion::Fraccion(int numerador, int denominador) {
    this->numerador = numerador;
    this->denominador = (denominador != 0) ? denominador : 1;
    
    if (denominador == 0) {
        cout << "El denominador no puede ser cero. Se asigna 1 por defecto." << endl;
    }
}

Fraccion::Fraccion(){
	numerador = 1;
	denominador = 1;
}

Fraccion::~Fraccion(){
    //Destructor
}

int Fraccion::getDenominador() const{
    return denominador;
}

int Fraccion::getNumerador() const{
    return numerador;
}

void Fraccion::setDenominador(int denominador) {
    if (denominador != 0) {
        this->denominador=denominador;
        }
    else {
        cout<<"El denominador no puede ser cero. No hay modificaciones";
    }
}

void Fraccion::setNumerador(int numerador) {
    this->numerador=numerador;
}
   
Fraccion Fraccion::crear(){
    int numerador, denominador;
    string input;
    
    do {
        cout << "Ingrese el numerador (entero): ";
        getline(cin, input);
        
        stringstream ss(input);
        if (!(ss >> numerador) || !(ss.eof())) {
            cout << "Invalido. Solo se permiten números enteros." << endl;
        } else {
            break;
        }
    } while (true);

    do {
        cout << "Ingrese el denominador (entero, distinto de cero): ";
        getline(cin, input);

        stringstream ss(input);

        if (!(ss >> denominador) || !(ss.eof()) || denominador == 0) {
            cout << "Invalido. Solo se permiten números enteros distintos del cero." << endl;
        } else {
            break;
        }
    } while (true);

    return Fraccion(numerador, denominador);
}

Fraccion Fraccion::multiplicar(Fraccion otraFraccion) {
    return Fraccion(numerador * otraFraccion.getNumerador(), denominador * otraFraccion.getDenominador());
}

void Fraccion::mostrar() const {
    cout << getNumerador() << "/" << getDenominador() << endl;
}   