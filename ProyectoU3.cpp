#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include <stddef.h>
#include <chrono>

using namespace std;

// Implementación de los algoritmos de ordenamiento
void bubbleSort(vector<int> &arr);
void heapify(vector<int> &arr, int n, int i);
void heapSort(vector<int> &arr);
int partition(vector<int> &arr, int low, int high);
void quickSort(vector<int> &arr, int low, int high);
void merge(vector<int> &arr, int left, int mid, int right);
void mergeSort(vector<int> &arr, int begin, int end);
void selectionSort(vector<int> &arr);
void insertionSort(vector<int> &arr);
void shellSort(vector<int> &arr);
vector<int> generateDataSet(int size, int mode);

// Función para obtener el tiempo de ejecución de un algoritmo de ordenamiento
double getExecutionTime(vector<int> &arr, int algorithmOption, bool ascending);

int main()
{
    srand(time(nullptr));

    const int min_size1 = 1, max_size1 = 100000;
    const int min_size2 = 1, max_size2 = 70000;
    const int min_size3 = 1, max_size3 = 150000;
    int numRaces = 3;
    int numSortModes = 4;

   int sortOrderOption;
    cout << "Carrera de algoritmos" << endl;
    cout << "1. Ascendente" << endl;
    cout << "2. Descendente" << endl;
    cout << "Opcion elegida: ";
    cin >> sortOrderOption;
    bool ascending = true;
    if (sortOrderOption == 2) {
        ascending = false;
    }


    for (int race = 0; race < numRaces; ++race)
    {
        int size;
        if (race == 1)
        {
            size = min_size1 + rand() % (max_size1 - min_size1 + 1);
        }
        else if (race == 2)
        {
            size = min_size2 + rand() % (max_size2 - min_size2 + 1);
        }
        else
        {
            size = min_size3 + rand() % (max_size3 - min_size3 + 1);
        }

        cout << endl;

        for (int mode = 0; mode < numSortModes; ++mode)
        {
            cout << "Carrera " << race + 1 << ": Modo ";
            switch (mode)
            {
            case 0:
                cout << "ordenado" << endl;
                break;
            case 1:
                cout << "inversamente ordenado" << endl;
                break;
            case 2:
                cout << "aleatorio sin repetir datos" << endl;
                break;
            case 3:
                cout << "aleatorio con posibilidad de elementos duplicados" << endl;
                break;
            default:
                break;
            }
            vector<int> arr = generateDataSet(size, mode + 1);
            /*cout << "Contenido del vector arr: ";
            for (int i = 0; i < arr.size(); ++i)
            {
                cout << arr[i] << " ";
            }
            */
            cout << endl;
            // Run algorithms and record execution times
            unordered_map<string, double> results;
            vector<pair<string, double>> sortedResults;

            // Bubble Sort
            results["Bubble Sort"] = getExecutionTime(arr, 1, ascending);

            // Heap Sort
            results["Heap Sort"] = getExecutionTime(arr, 2, ascending);

            // Quick Sort
            results["Quick Sort"] = getExecutionTime(arr, 3, ascending);

            // Merge Sort
            results["Merge Sort"] = getExecutionTime(arr, 4, ascending);

            // Selection Sort
            results["Selection Sort"] = getExecutionTime(arr, 5, ascending);

            // Insertion Sort
            results["Insertion Sort"] = getExecutionTime(arr, 6, ascending);

            // Shell Sort
            results["Shell Sort"] = getExecutionTime(arr, 7, ascending);

            // Sort the results by execution time
            for (const auto &pair : results)
            {
                sortedResults.push_back(pair);
            }
            sort(sortedResults.begin(), sortedResults.end(), [](const auto &a, const auto &b)
                 { return a.second < b.second; });

            int position = 1;
            for (const auto &pair : sortedResults)
            {
                cout << position << ". " << pair.first << ", " << fixed << setprecision(5) << pair.second << " seconds" << endl;
                ++position;
            }

            // Print the winner
            cout << "El ganador es: " << sortedResults[0].first << " con un tiempo de " << fixed << setprecision(5) << sortedResults[0].second << " seconds" << endl;

            // Clear the vector for the next mode
            arr.clear();
        }
    }

    return 0;
}
vector<int> generateDataSet(int size, int mode)
{
    vector<int> arr;
    arr.reserve(static_cast<size_t>(size));

    if (mode == 1)
    {
        for (int i = 0; i < size; ++i)
        {
            arr.push_back(i + 1);
        }
    }
    else if (mode == 2)
    {
        for (int i = size; i >= 1; --i)
        {
            arr.push_back(i);
        }
    }
    else if (mode == 3)
    {
        for (int i = 1; i <= size; ++i)
        {
            arr.push_back(i);
        }
        random_shuffle(arr.begin(), arr.end());
    }
    else if (mode == 4)
    {
        for (int i = 1; i <= size; ++i)
        {
            arr.push_back(i);
        }
        random_shuffle(arr.begin(), arr.end());
        int duplicates = rand() % (size / 2); // Generate random number of duplicates
        for (int i = 0; i < duplicates; ++i)
        {
            int index = rand() % size;
            arr.push_back(arr[static_cast<size_t>(index)]);
        }
    }

    return arr;
}
double getExecutionTime(vector<int> &arr, int algorithmOption, bool ascending)
{
    vector<int> arrCopy = arr;
    auto start = chrono::high_resolution_clock::now();


    switch (algorithmOption)
    {
    case 1:
        bubbleSort(arrCopy);
        break;
    case 2:
        heapSort(arrCopy);
        break;
    case 3:
        quickSort(arrCopy, 0, static_cast<int>(arrCopy.size()) - 1);
        break;
    case 4:
        mergeSort(arrCopy, 0, static_cast<int>(arrCopy.size()) - 1);
        break;
    case 5:
        selectionSort(arrCopy);
        break;
    case 6:
        insertionSort(arrCopy);
        break;
    case 7:
        shellSort(arrCopy);
        break;
    default:
        break;
    }
      auto end = chrono::high_resolution_clock::now();

    // Calculate the duration in seconds with nanosecond precision
    chrono::duration<double> duration = end - start;
    double time_taken = duration.count();

    if (!ascending)
    {
        // Reverse the array to simulate descending order
        reverse(arrCopy.begin(), arrCopy.end());
    }
    

    return time_taken;
}

// Implementación de los algoritmos de ordenamiento

void bubbleSort(vector<int> &arr)
{
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[static_cast<size_t>(j)] > arr[static_cast<size_t>(j + 1)])
            {
                swap(arr[static_cast<size_t>(j)], arr[static_cast<size_t>(j + 1)]);
            }
        }
    }
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[static_cast<size_t>(left)] > arr[static_cast<size_t>(largest)])
    {
        largest = left;
    }

    if (right < n && arr[static_cast<size_t>(right)] > arr[static_cast<size_t>(largest)])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[static_cast<size_t>(i)], arr[static_cast<size_t>(largest)]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int> &arr)
{
    int n = static_cast<int>(arr.size());
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[static_cast<size_t>(i)]);
        heapify(arr, i, 0);
    }
}

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[static_cast<size_t>(high)];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[static_cast<size_t>(j)] < pivot)
        {
            i++;
            swap(arr[static_cast<size_t>(i)], arr[static_cast<size_t>(j)]);
        }
    }

    swap(arr[static_cast<size_t>(i + 1)], arr[static_cast<size_t>(high)]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(vector<int> &arr, int left, int mid, int right)
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    vector<int> leftArray(static_cast<size_t>(subArrayOne));
    vector<int> rightArray(static_cast<size_t>(subArrayTwo));

    for (int i = 0; i < subArrayOne; i++)
    {
        leftArray[static_cast<size_t>(i)] = arr[static_cast<size_t>(left + i)];
    }
    for (int j = 0; j < subArrayTwo; j++)
    {
        rightArray[static_cast<size_t>(j)] = arr[static_cast<size_t>(mid + 1 + j)];
    }

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[static_cast<size_t>(indexOfSubArrayOne)] <= rightArray[static_cast<size_t>(indexOfSubArrayTwo)])
        {
            arr[static_cast<size_t>(indexOfMergedArray)] = leftArray[static_cast<size_t>(indexOfSubArrayOne)];
            indexOfSubArrayOne++;
        }
        else
        {
            arr[static_cast<size_t>(indexOfMergedArray)] = rightArray[static_cast<size_t>(indexOfSubArrayTwo)];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne)
    {
        arr[static_cast<size_t>(indexOfMergedArray)] = leftArray[static_cast<size_t>(indexOfSubArrayOne)];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo)
    {
        arr[static_cast<size_t>(indexOfMergedArray)] = rightArray[static_cast<size_t>(indexOfSubArrayTwo)];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(vector<int> &arr, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

void selectionSort(vector<int> &arr)
{
    int n = static_cast<int>(arr.size());
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[static_cast<size_t>(j)] < arr[static_cast<size_t>(min_idx)])
            {
                min_idx = j;
            }
        }
        swap(arr[static_cast<size_t>(i)], arr[static_cast<size_t>(min_idx)]);
    }
}

void insertionSort(vector<int> &arr)
{
    int n = static_cast<int>(arr.size());
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[static_cast<size_t>(i)];
        j = i - 1;

        while (j >= 0 && arr[static_cast<size_t>(j)] > key)
        {
            arr[static_cast<size_t>(j + 1)] = arr[static_cast<size_t>(j)];
            j = j - 1;
        }
        arr[static_cast<size_t>(j + 1)] = key;
    }
}

void shellSort(vector<int> &arr)
{
    int n = static_cast<int>(arr.size());
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[static_cast<size_t>(i)];

            int j;
            for (j = i; j >= gap && arr[static_cast<size_t>(j - gap)] > temp; j -= gap)
                arr[static_cast<size_t>(j)] = arr[static_cast<size_t>(j - gap)];

            arr[static_cast<size_t>(j)] = temp;
        }
    }
}
