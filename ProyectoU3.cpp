#include <iostream>
#include <chrono>
#include <algorithm>
#include <random>

using namespace std;
using namespace std::chrono;

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            arr[j] = temp;
        }
    }
    return 0;
}
// Función para generar un conjunto de datos ascendente
void generateAscending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Función para generar un conjunto de datos descendente
void generateDescending(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

// Función para generar un conjunto de datos aleatorio con números duplicados
void generateRandomWithDuplicates(int arr[], int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(1, n / 2);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
}

// Función para generar un conjunto de datos aleatorio sin duplicados
void generateRandomWithoutDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    random_device rd;
    mt19937 gen(rd());
    shuffle(arr, arr + n, gen);
}

// Función para medir el tiempo de ejecución de un algoritmo de ordenamiento en un conjunto de datos
void measureSortingTime(int arr[], int n, string algorithm) {
    auto start = high_resolution_clock::now();
    if (algorithm == "bubble") {
        bubbleSort(arr, n);
    } else if (algorithm == "heap") {
        heapSort(arr, n);
    } else if (algorithm == "quick") {
        quickSort(arr, 0, n - 1);
    } else if (algorithm == "merge") {
        mergeSort(arr, 0, n - 1);
    } else if (algorithm == "selection") {
        selectionSort(arr, n);
    } else if (algorithm == "insertion") {
        insertionSort(arr, n);
    } else if (algorithm == "shell") {
        shellSort(arr, n);
    } else {
        cout << "Algoritmo inválido." << endl;
        return;
    }
    auto stop = high_resolution_clock::now();

    // Cálculo del tiempo transcurrido
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Algoritmo: " << algorithm << ", Tiempo transcurrido: " << duration.count() << " ms" << endl;
}
int main() {
    const int SIZE1 = 100000; // Tamaño máximo del conjunto de datos 1
    const int SIZE2 = 70000; // Tamaño máximo del conjunto de datos 2
    const int SIZE3 = 1000; // Tamaño máximo del conjunto de datos 3

    // Conjunto de datos 1: Tablero de puntaje
    int arr1[SIZE1];

    cout << "Conjunto de datos 1: Tablero de puntaje" << endl;

    // Modo ascendente
    generateAscending(arr1, SIZE1);
    cout << "Modo: Ascendente" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr1, SIZE1, algorithm);
    }
    cout << endl;

    // Modo descendente
    generateDescending(arr1, SIZE1);
    cout << "Modo: Descendente" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr1, SIZE1, algorithm);
    }
    cout << endl;

    // Modo aleatorio con números duplicados
    generateRandomWithDuplicates(arr1, SIZE1);
    cout << "Modo: Aleatorio con números duplicados" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr1, SIZE1, algorithm);
    }
    cout << endl;

    // Modo aleatorio sin duplicados
    generateRandomWithoutDuplicates(arr1, SIZE1);
    cout << "Modo: Aleatorio sin duplicados" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr1, SIZE1, algorithm);
    }
    cout << endl;

    // Conjunto de datos 2: Determinación de camino entre aldeas
    int arr2[SIZE2];

    cout << "Conjunto de datos 2: Determinación de camino entre aldeas" << endl;

    // Modo ascendente
    generateAscending(arr2, SIZE2);
    cout << "Modo: Ascendente" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr2, SIZE2, algorithm);
    }
    cout << endl;

    // Modo descendente
    generateDescending(arr2, SIZE2);
    cout << "Modo: Descendente" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr2, SIZE2, algorithm);
    }
    cout << endl;

    // Modo aleatorio con números duplicados
    generateRandomWithDuplicates(arr2, SIZE2);
    cout << "Modo: Aleatorio con números duplicados" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr2, SIZE2, algorithm);
    }
    cout << endl;

    // Modo aleatorio sin duplicados
    generateRandomWithoutDuplicates(arr2, SIZE2);
    cout << "Modo: Aleatorio sin duplicados" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr2, SIZE2, algorithm);
    }
    cout << endl;

    // Conjunto de datos 3: Dibujo o renderizado de objetos
    int arr3[SIZE3];

    cout << "Conjunto de datos 3: Dibujo o renderizado de objetos" << endl;

    // Modo ascendente
    generateAscending(arr3, SIZE3);
    cout << "Modo: Ascendente" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr3, SIZE3, algorithm);
    }
    cout << endl;

    // Modo descendente
    generateDescending(arr3, SIZE3);
    cout << "Modo: Descendente" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr3, SIZE3, algorithm);
    }
    cout << endl;

    // Modo aleatorio con números duplicados
    generateRandomWithDuplicates(arr3, SIZE3);
    cout << "Modo: Aleatorio con números duplicados" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr3, SIZE3, algorithm);
    }
    cout << endl;

    // Modo aleatorio sin duplicados
    generateRandomWithoutDuplicates(arr3, SIZE3);
    cout << "Modo: Aleatorio sin duplicados" << endl;
    for (string algorithm : {"bubble", "heap", "quick", "merge", "selection", "insertion", "shell"}) {
        measureSortingTime(arr3, SIZE3, algorithm);
    }
    cout << endl;

    return 0;
}