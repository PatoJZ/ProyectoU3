#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <random>
using namespace std;

void SelectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
double getResultFromAlg(vector<int> &arr, int option)
{
    time_t start, end;
    double time_taken;
    time(&start);
    ios_base::sync_with_stdio(false);
    SelectionSort(arr);
    time(&end);
    time_taken = double(end - start);
    return time_taken;
}
int main(int argc, char *argv[])
{
    cout << "Generando set de datos: " << endl;
    for (int i = 0; i < amount; ++i)
    {
        arrSorted.push_back(i + 1);
        arrReverse.push_back(amount - i);
        if (i == 0)
        {
            random_value = 1 + rand() % (amount);
            arr.push_back(random_value);
        }
        else
        {
            random_value = 1 + rand() % (amount);
            arr.push_back(random_value);
        }
    }
    unordered_map<string, double> results;
    results["SeleciontSort"] = getResultFromAlg(arr);
    vector<int> arr1, arr2;
    arr1.assign(arr.begin(), arr.end());
    arr2.assign(arr.begin(), arr.end());
    int id = 1;
    for (const auto &pair : results)
    {
        const string &key = pair.first;
        double value = pair.second;
        cout << id << ". " << key << ", " << fixed << value << setprecision(5)
             << endl;
        id++;
    }
    return 0;
}
