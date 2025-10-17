#include "Operacion.hpp"

#include <iostream>
using namespace std;

template <typename T1>
//Dos parametros del mismo tipo
T1 Operacion::suma(T1 a, T1 b) {
    cout<<"(Suma de DOS parametros del MISMO tipo)" << endl;
    return a + b;
};

template <typename T1>
//Tres parametros del mismo tipo
T1 Operacion::suma (T1 a, T1 b, T1 c) {
    cout<<"(Suma de TRES parametros del MISMO tipo)" << endl;
    return a + b + c;
};
   
template <typename T1, typename T2>
//Dos parametros de distinto tipo
auto Operacion::suma(T1 a, T2 b) -> decltype(a + b) {
    cout<<"(Suma de DOS parametros de DISTINTO tipo)"<< endl;
    return a + b;
};

template <typename T1, typename T2, typename T3>
//Tres parametros de distinto tipo
auto Operacion::suma (T1 a, T2 b, T3 c) -> decltype(a + b + c) {
    cout<<"(Suma de TRES parametros de DISTINTO tipo)"<< endl;
    return a + b + c;
};