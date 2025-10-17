#pragma once


class Operacion {
public:
    template <typename T1>
    //Dos parametros del mismo tipo
    T1 suma (T1 a, T1 b);
    
    template <typename T1>
    //Tres parametros del mismo tipo
    T1 suma (T1 a, T1 b, T1 c);

    template <typename T1, typename T2>
    //Dos parametros de distinto tipo
    auto suma (T1 a, T2 b) -> decltype(a + b);

    template <typename T1, typename T2, typename T3>
    //Tres parametros de distinto tipo
    auto suma (T1 a, T2 b, T3 c) -> decltype(a + b + c);  
};

#include "Operacion.tpp"