#include "controller\Controller.cpp"

#include <iostream>

int main() {
    try {
        Controller controller;
        auto f1 = controller.crearFraccion<double>();
        auto f2 = controller.crearFraccion<double>();
        
        auto resultado = f1 / f2; // ejemplo de división

        cout<<"El resultado de la division es: ";
        resultado.mostrar();

    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

}