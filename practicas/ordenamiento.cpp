#include <iostream>
#include <vector>
#include <string>

using namespace std;

// --- Parte A: Ordenamiento de Burbuja ---
void bubbleSort(vector<int>& lista) {
    int n = lista.size();
    bool intercambiado;
    for (int i = 0; i < n - 1; i++) {
        intercambiado = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (lista[j] > lista[j + 1]) {
                swap(lista[j], lista[j + 1]);
                intercambiado = true;
            }
        }
        // Optimización: si no hubo intercambios, la lista ya está ordenada
        if (!intercambiado) break;
    }
}

// --- Parte B: Ordenamiento por Selección ---
void selectionSort(vector<int>& lista) {
    int n = lista.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (lista[j] < lista[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(lista[i], lista[min_idx]);
        }
    }
}

// --- Parte C: Merge Sort (Funciones auxiliares) ---
void merge(vector<int>& lista, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = lista[left + i];
    for (int j = 0; j < n2; j++) R[j] = lista[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            lista[k] = L[i];
            i++;
        } else {
            lista[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        lista[k] = L[i];
        i++; k++;
    }
    while (j < n2) {
        lista[k] = R[j];
        j++; k++;
    }
}

void mergeSort(vector<int>& lista, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(lista, left, mid);
        mergeSort(lista, mid + 1, right);
        merge(lista, left, mid, right);
    }
}

// --- Función Principal (Formato de Entrada/Salida) ---
int main() {
    string algoritmo;
    int N;

    if (!(cin >> algoritmo >> N)) return 0;

    vector<int> datos(N);
    for (int i = 0; i < N; i++) {
        cin >> datos[i];
    }

    if (algoritmo == "burbuja") {
        bubbleSort(datos);
    } else if (algoritmo == "seleccion") {
        selectionSort(datos);
    } else if (algoritmo == "mergesort") {
        mergeSort(datos, 0, N - 1);
    }

    for (int i = 0; i < N; i++) {
        cout << datos[i] << (i == N - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}