#include <iostream>
#include <cstdlib>
#include <functional>

using namespace std;

int main()
{
    const int DIM = 3;

    // Asignar memoria dinámica para las matrices usando malloc
    int **matriz1 = (int **)malloc(DIM * sizeof(int *));
    int **matriz2 = (int **)malloc(DIM * sizeof(int *));
    int **matrizResultado = (int **)malloc(DIM * sizeof(int *));

    for (int i = 0; i < DIM; i++)
    {
        *(matriz1 + i) = (int *)malloc(DIM * sizeof(int));
        *(matriz2 + i) = (int *)malloc(DIM * sizeof(int));
        *(matrizResultado + i) = (int *)malloc(DIM * sizeof(int));
    }

    // Función lambda para inicializar una matriz con valores
    auto inicializarMatriz = [](int **matriz, int dim, int valorInicial)
    {
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                *(*(matriz + i) + j) = valorInicial + (i * dim + j);
            }
        }
    };

    // Función lambda para mostrar una matriz
    auto mostrarMatriz = [](int **matriz, int dim, const char *nombre)
    {
        cout << "\n"
             << nombre << ":\n";
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                cout << ((matriz + i) + j) << "\t";
            }
            cout << endl;
        }
    };

    // Función lambda recursiva para sumar dos matrices


    //DIRECTA:  La función se llama a sí misma
    //Lineal: Una llamada recursiva en cada paso, no varias simultáneas
    function<void(int **, int **, int **, int, int, int)> sumarMatrices =
        [&sumarMatrices](int **m1, int **m2, int **resultado, int dim, int i, int j)
    {
        // Caso base: si hemos recorrido todas las filas
        if (i >= dim)
        {
            return;
        }
        // Sumar el elemento actual
        *(*(resultado + i) + j) = *(*(m1 + i) + j) + *(*(m2 + i) + j);

        // Caso recursivo: avanzar a la siguiente columna
        if (j + 1 < dim)
        {
            sumarMatrices(m1, m2, resultado, dim, i, j + 1);
        }
        // Si terminamos la fila, pasar a la siguiente fila
        else
        {
            sumarMatrices(m1, m2, resultado, dim, i + 1, 0);
        }
    };

    // Inicializar las matrices
    cout << "=== PROGRAMA DE SUMA DE MATRICES 3x3 ===\n";
    cout << "Usando funciones lambda y memoria dinamica (malloc)\n";

    inicializarMatriz(matriz1, DIM, 10);
    inicializarMatriz(matriz2, DIM, 20);

    // Mostrar las matrices originales
    mostrarMatriz(matriz1, DIM, "Matriz 1");
    mostrarMatriz(matriz2, DIM, "Matriz 2");

    // Sumar las matrices usando la función lambda recursiva
    sumarMatrices(matriz1, matriz2, matrizResultado, DIM, 0, 0);

    // Mostrar el resultado
    mostrarMatriz(matrizResultado, DIM, "Matriz Resultado (Matriz1 + Matriz2)");

    // Liberar la memoria asignada
    for (int i = 0; i < DIM; i++)
    {
        free(*(matriz1 + i));
        free(*(matriz2 + i));
        free(*(matrizResultado + i));
    }
    free(matriz1);
    free(matriz2);
    free(matrizResultado);

    cout << "\nMemoria liberada correctamente.\n";

    return 0;
}