#pragma once
#include <string>
#include <sstream>
#include <stdexcept>

#include "../model/Fraccion.hpp"
using namespace std;

class Controller {
public:
    template <typename T>
    T leerNumero(const string& mensaje, bool admitirCero = true);
    
    template <typename T>
    Fraccion<T> crearFraccion();
};