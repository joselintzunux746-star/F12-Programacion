#include <iostream>
#include <vector>
#include <algorithm> // Para std::max y std::min

// Ejercicio 1: Función de Búsqueda de 2 en 2 con Retroceso
int busqueda_dos_en_dos(const std::vector<int>& lista, int n, int objetivo) {
    int i = 0;

    // 1. Avanzar de 2 en 2 mientras el elemento sea menor al objetivo
    while (i < n && lista[i] < objetivo) {
        i = i + 2;
    }

    // 2. Retroceder 1 posición
    i = i - 1;

    // 3. Revisar hasta 2 posiciones a partir de i
    // Usamos max y min para no salirnos de los índices válidos (0 a n-1)
    for (int j = std::max(0, i); j <= std::min(i + 1, n - 1); ++j) {
        if (lista[j] == objetivo) {
            return j; // Retorna el índice si lo encuentra
        }
    }

    return -1; // Retorna -1 si no existe
}

int main() {
    int n, objetivo;

    // Leer la cantidad de elementos (N)
    if (!(std::cin >> n)) return 0;

    // Leer la lista de elementos
    std::vector<int> lista(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> lista[i];
    }

    // Leer el valor a buscar (objetivo)
    std::cin >> objetivo;

    // Llamar a la función e imprimir el resultado
    int resultado = busqueda_dos_en_dos(lista, n, objetivo);
    std::cout << resultado << std::endl;

    return 0;
}
