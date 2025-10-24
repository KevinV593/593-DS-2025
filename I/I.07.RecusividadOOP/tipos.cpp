#include <iostream>
#include <functional>
using namespace std;

int main() {
    cout << "=== TIPOS DE RECURSIVIDAD EN C++ ===\n\n";

    //-----------------------------------
    // 🧩 1. Recursividad DIRECTA
    //-----------------------------------
    cout << "1️⃣ Recursividad directa:\n";
    function<void(int)> directa = [&directa](int n) {
        if (n == 0) return;               // Caso base
        cout << "Llamada directa con n = " << n << endl;
        directa(n - 1);                   // Se llama a sí misma → directa
    };
    directa(3);
    cout << endl;

    //-----------------------------------
    // 🔁 2. Recursividad INDIRECTA
    //-----------------------------------
    cout << "2️⃣ Recursividad indirecta:\n";
    function<void(int)> A, B;

    A = [&A, &B](int n) {
        if (n == 0) return;
        cout << "A llama con n = " << n << endl;
        B(n - 1);                         // A llama a B
    };
    B = [&A, &B](int n) {
        if (n == 0) return;
        cout << "B llama con n = " << n << endl;
        A(n - 1);                         // B llama a A → ciclo mutuo
    };
    A(3);
    cout << endl;

    //-----------------------------------
    // 🪞 3. Recursividad MÚLTIPLE (DOBLE)
    //-----------------------------------
    cout << "3️⃣ Recursividad múltiple:\n";
    function<void(int)> multiple = [&multiple](int n) {
        if (n == 0) return;
        cout << "n = " << n << endl;
        multiple(n - 1);  // primera llamada recursiva
        multiple(n - 2);  // segunda llamada → múltiple
    };
    multiple(3);
    cout << endl;

    //-----------------------------------
    // 🎯 4. Recursividad DE COLA (Tail Recursion)
    //-----------------------------------
    cout << "4️⃣ Recursividad de cola:\n";
    function<void(int)> cola = [&cola](int n) {
        if (n == 0) {
            cout << "Fin de la recursion.\n";
            return;
        }
        cout << "Llamada con n = " << n << endl;
        cola(n - 1);  // Última instrucción → recursión de cola
    };
    cola(3);
    cout << endl;

    //-----------------------------------
    // 🧮 EXTRA: Ejemplo con MATRIZ y recursión directa
    //-----------------------------------
    cout << "🧮 Ejemplo extra: recorrer matriz 2x2 recursivamente\n";
    int matriz[2][2] = {{1, 2}, {3, 4}};
    function<void(int, int)> recorrer =
        [&recorrer, &matriz](int i, int j) {
            if (i >= 2) return;
            cout << "Elemento[" << i << "][" << j << "] = " << matriz[i][j] << endl;

            if (j + 1 < 2) recorrer(i, j + 1);
            else recorrer(i + 1, 0);
        };
    recorrer(0, 0);

    return 0;
}
