#include <iostream>
#include <string>
using namespace std;

// Acepta tres tipos distintos, incluso string
template <typename T1, typename T2, typename T3>
auto suma(T1 a, T2 b, T3 c) -> decltype(a + b + c) {
    return a + b + c;
}

int main() {
    cout << "=== Pruebas con distintos tipos ===" << endl;

    // 1️⃣ Todos enteros
    cout << "suma(1, 2, 3) = " << suma(1, 2, 3) << endl;

    // 2️⃣ Combinación int, float, double
    cout << "suma(1, 2.5f, 3.7) = " << suma(1, 2.5f, 3.7) << endl;

    // 3️⃣ Todos float
    cout << "suma(1.1f, 2.2f, 3.3f) = " << suma(1.1f, 2.2f, 3.3f) << endl;

    // 4️⃣ Todos double
    cout << "suma(1.5, 2.5, 3.5) = " << suma(1.5, 2.5, 3.5) << endl;

    // 5️⃣ Mezcla float y double
    cout << "suma(1.0f, 2.0, 3.0f) = " << suma(1.0f, 2.0, 3.0f) << endl;

    // 6️⃣ Con strings (usa concatenación)
    cout << "suma(string) = " << suma(string("Hola "), string("C++ "), string("Templates")) << endl;

    return 0;
}
