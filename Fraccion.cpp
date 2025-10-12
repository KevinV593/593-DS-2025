#include "Fraccion.h"
#include <iostream>
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
    
    do {
        cout << "Ingrese el numerador (entero): ";
        if (!(cin >> numerador)) {
            cout << "Invalido. Solo se permiten números enteros." << endl;
            cin.clear();                
            cin.ignore(999, '\n');    
        } else {
            break;
        }
    } while (true);

   do {
       cout << "Ingrese el denominador (entero, distinto de cero): ";
       if (!(cin >> denominador) || denominador == 0) {
           cout << "Invalido. Solo se permiten números enteros, ni el cero." << endl;
           cin.clear();
           cin.ignore(999, '\n');
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