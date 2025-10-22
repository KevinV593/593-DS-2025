#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int leerNumero(const string& mensaje) {
    string input;
    int numero;

    while (true) {
        cout << mensaje;
        getline(cin, input);
        stringstream ss(input);

        if (!(ss >> numero) || !(ss.eof())) {
            cout << "Entrada invalida. Solo enteros." << endl;
            continue;
        }    
        return numero;
    }
}

void mostrarArreglo(int* arr, int n) {
    cout << "Arreglo: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n = leerNumero("Ingresa la cantidad de numeros para el arreglo: ");

    int* arr = new int[n]();

    for (int i = 0; i < n; i++) {
        arr[i] = leerNumero("Ingresa el valor de #" + to_string(i + 1) + ": ");
        mostrarArreglo(arr, i + 1);
    }

    delete[] arr; 
    return 0;
}