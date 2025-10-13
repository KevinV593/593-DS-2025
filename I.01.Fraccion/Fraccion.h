/***********************************************************************
 * Module:  Fraccion.h
 * Author:  KevinV593
 * Modified: Monday, October 6, 2025 10:04:33 PM
 * Purpose: Declaration of the class Fraccion
 ***********************************************************************/

#ifndef FRACCION_H
#define FRACCION_H   ///pragma once

class Fraccion {
private:

    int denominador;
    int numerador;
    
public:

    Fraccion(int numerador, int denominador);
    Fraccion();
    ~Fraccion();

    int getDenominador() const;
    int getNumerador() const;

    void setDenominador(int denominador);
    void setNumerador(int numerador);

    Fraccion crear();
    Fraccion multiplicar(Fraccion otraFraccion);
    void mostrar() const;

};

#endif