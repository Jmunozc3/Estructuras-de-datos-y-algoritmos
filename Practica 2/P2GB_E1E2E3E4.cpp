#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm> // Necesario para std::swap
using namespace std;
using namespace std::chrono;

// Practica realizada por Juan Manuel Muñoz

// Función que toma una lista de números enteros y devuelve la suma de los números pares

int sum_num(const vector<int>& n) {
    int sum = 0;
    for (int num : n) {
        if (num % 2 == 0) {
            sum += num;
        }
    }
    return sum;
}

// Función que toma una cadena de caracteres y devuelve el número de vocales que contiene

int numVocales(const string& str) {
    int cont = 0;
    for (char elem : str) {
        if (elem == 'a' || elem == 'A' || elem == 'e' || elem == 'E' ||
            elem == 'i' || elem == 'I' || elem == 'o' || elem == 'O' ||
            elem == 'u' || elem == 'U') {
            ++cont;
        }
    }
    return cont;
}

// Algoritmo 1: Suma con bucle for

int suma_for(const int array[], int n) {
    int suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += array[i];
    }
    return suma;
}

// Algoritmo 2: Suma con recursión

int suma_recursion(const int array[], int n) {
    if (n == 1) {
        return array[0];
    } else {
        int mitad = n / 2;
        return suma_recursion(array, mitad) + suma_recursion(array + mitad, n - mitad);
    }
}

// Algoritmo 1

int productoA(const int array1[], const int array2[], int n) {
    int producto = 0;
    for (int i = 0; i < n; ++i) {
        producto += array1[i] * array2[i];
    }
    return producto;
}

// Algoritmo 2

int productoB(const int array1[], const int array2[], int n) {
    if (n == 1) {
        return array1[0] * array2[0];
    } else {
        int mitad = n / 2;
        return productoB(array1, array2, mitad) + productoB(array1 + mitad, array2 + mitad, n - mitad);
    }
}

// Algoritmo de ordenación 1: Selection sort

void ordenaArray1(int array[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minimo = i;
        for (int j = i + 1; j < n; ++j) {
            if (array[j] < array[minimo]) {
                minimo = j;
            }
        }
        swap(array[i], array[minimo]);
    }
}

// Algoritmo de ordenación 2: Bubble sort

void ordenaArray2(int array[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

// Algoritmo de ordenación 3: QuickSort

template <class Comparable>
void insertionSort(vector<Comparable>& a, int low, int high) {
    for (int p = low + 1; p <= high; ++p) {
        Comparable tmp = a[p];
        int j;
        for (j = p; j > low && tmp < a[j - 1]; --j) {
            a[j] = a[j - 1];
        }
        a[j] = tmp;
    }
}

template <class Comparable>
void quicksort(vector<Comparable>& a, int low, int high) {
    if (low + 10 > high) {
        insertionSort(a, low, high);
    } else {
        int middle = (low + high) / 2;
        if (a[middle] < a[low]) swap(a[low], a[middle]);
        if (a[high] < a[low]) swap(a[low], a[high]);
        if (a[high] < a[middle]) swap(a[middle], a[high]);

        Comparable pivot = move(a[middle]);
        swap(a[middle], a[high - 1]);

        int i, j;
        for (i = low, j = high - 1;;) {
            while (a[++i] < pivot) {}
            while (pivot < a[--j]) {}
            if (i < j) swap(a[i], a[j]);
            else break;
        }
        swap(a[i], a[high - 1]);

        quicksort(a, low, i - 1);
        quicksort(a, i + 1, high);
    }
}

template <class Comparable>
void quicksort(vector<Comparable>& a) {
    quicksort(a, 0, a.size() - 1);
}

// Función principal
int main() {
    int array1[8] = {875, 762, 990, 126, 788, 248, 408, 265};
    int array2[8] = {240, 716, 230, 876, 15, 81, 160, 206};
    int a = 8;

    const int REPEAT_TIMES = 10000000;

    
    high_resolution_clock::time_point startA, endA, startB, endB, startC, endC, startD, endD, startE, endE, startF, endF;
   
    milliseconds duration1, duration2, duration3, duration4, duration5, duration6;

    cout << endl << "EJECUTANDO FUNCIONES " << REPEAT_TIMES << " de veces." << endl << "Por favor, espere..." << endl << endl;

        startA = high_resolution_clock::now();
    for (long long i = 0; i < REPEAT_TIMES; ++i) {
        ordenaArray1(array1, a);
    }
    endA = high_resolution_clock::now();
    duration1 = duration_cast<milliseconds>(endA - startA);

      startB = high_resolution_clock::now();
    for (long long i = 0; i < REPEAT_TIMES; ++i) {
        ordenaArray2(array1, a);
    }
    endB = high_resolution_clock::now();
    duration2 = duration_cast<milliseconds>(endB - startB);

   
    startC = high_resolution_clock::now();
    for (long long i = 0; i < REPEAT_TIMES; ++i) {
        suma_for(array1, a);
    }
    endC = high_resolution_clock::now();
    duration3 = duration_cast<milliseconds>(endC - startC);

  
    startD = high_resolution_clock::now();
    for (long long i = 0; i < REPEAT_TIMES; ++i) {
        suma_recursion(array1, a);
    }
    endD = high_resolution_clock::now();
    duration4 = duration_cast<milliseconds>(endD - startD);

       startE = high_resolution_clock::now();
    for (long long i = 0; i < REPEAT_TIMES; ++i) {
        productoA(array1, array2, a);
    }
    endE = high_resolution_clock::now();
    duration5 = duration_cast<milliseconds>(endE - startE);

        startF = high_resolution_clock::now();
    for (long long i = 0; i < REPEAT_TIMES; ++i) {
        productoB(array1, array2, a);
    }
    endF = high_resolution_clock::now();
    duration6 = duration_cast<milliseconds>(endF - startF);

    // Se imprime todo
    cout << "ordenArray1 tardó " << duration1.count() << " milisegundos en ejecutarse " << REPEAT_TIMES << " veces." << endl;
    cout << "ordenArray2 tardó " << duration2.count() << " milisegundos en ejecutarse " << REPEAT_TIMES << " veces." << endl;
    cout << "suma_for tardó " << duration3.count() << " milisegundos en ejecutarse " << REPEAT_TIMES << " veces." << endl;
    cout << "suma_recursion tardó " << duration4.count() << " milisegundos en ejecutarse " << REPEAT_TIMES << " veces." << endl;
    cout << "productoA tardó " << duration5.count() << " milisegundos en ejecutarse " << REPEAT_TIMES << " veces." << endl;
    cout << "productoB tardó " << duration6.count() << " milisegundos en ejecutarse " << REPEAT_TIMES << " veces." << endl;

    return 0;
}
