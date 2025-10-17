#include "Controller.hpp"

#include <iostream>
using namespace std;

void Controller::ejecutar() {
    
    int a = 2, b = 3, c = 4;
    double x = 1.5, y = 2.3;
    float z = 0.012f;

    cout << "Resultado 1: " << op.suma(a, b) << endl;
    cout << "Resultado 2: " << op.suma(x, y) << endl;
    cout << "Resultado 3: " << op.suma(a, z, z) << endl;
    cout << "Resultado 4: " << op.suma(3, 2.5, 1.2f) << endl;
}