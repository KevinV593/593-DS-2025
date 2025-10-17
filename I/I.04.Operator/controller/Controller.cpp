#include "Controller.hpp"
#include <iostream>
using namespace std;

template <typename T> 
T Controller::leerNumero(const string& mensaje, bool admitirCero) {
    T numero;
    string input;

    while (true) {
        cout<<mensaje;
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> numero) || !(ss.eof())) {
            cout << "Entrada Invalida. Solo valen numeros (ej: 5.97 o 20)."<<endl;
            continue;
        }
           
        if(!(admitirCero) && numero == 0) {
            cout<<"El denominador no puede ser cero."<<endl;
            continue;
        }
        return numero;
    }
};

template <typename T>
Fraccion<T> Controller::crearFraccion() {
    T numerador = leerNumero<T>("Ingrese el numerador: ");
    T denominador = leerNumero<T>("Ingrese el denominador: ", false);
    cout<<"Fraccion Creada.";
    return Fraccion<T>(numerador, denominador);
};