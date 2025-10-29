#include <iostream>
#include "../Model/Matriz.hpp"

using namespace std;

int main() {
    int profundidad, filas , columnas;
    cout<<"Ingrese profunidad:";
    cin>>profundidad;
    cout<<"Ingrese filas:";
    cin>>filas;
    cout<<"Ingrese columnas:";
    cin>>columnas;

    Matriz<double> MatrizTest(profundidad, filas, columnas);
    MatrizTest.llenar();
    MatrizTest.mostrar();

    MatrizTest.trazaDiagonal();
    return 0;
}