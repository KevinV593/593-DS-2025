#pragma once

#include "../Model/Operacion.hpp"

class Controller {
private:
    Operacion op;  // Modelo
public:
    void ejecutar();
};