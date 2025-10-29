#include <iostream>

#include "../Model/Matriz.hpp"

using namespace std;

int main() {
    try {
        int i, j, k;
        std::cout<<"Matriz tresde. Inserta profundidad: ";
        std::cin>>i;
        std::cout<<"Inserta filas: ";
        std::cin>>j;
        std::cout<<"Inserta columnas: ";
        std::cin>>k;

        Matriz<double> M(i, j, k);
        M.llenar();
        M.mostrar();

}
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}