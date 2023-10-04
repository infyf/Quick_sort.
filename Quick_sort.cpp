#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> 
#include <algorithm> 

using namespace std;

void quickSortDescending(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[left]; 
        int i = left;
        int j = right;

        while (i <= j) {
            while (arr[i] > pivot) {
                i++;
            }
            while (arr[j] < pivot) {
                j--;
            }

            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        quickSortDescending(arr, left, j);
        quickSortDescending(arr, i, right);
    }
}

void initializeRandomArray(int arr[], int n) {
    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 2001 - 1000;
    }
}

void initializeArrayWithDuplicates(int arr[], int n) {
    initializeRandomArray(arr, n);
    int pos1 = rand() % n;
    int pos2;
    do {
        pos2 = rand() % n;
    } while (pos2 == pos1); 
    arr[pos1] = arr[pos2];
}

void initializeArrayWithAllDuplicates(int arr[], int n) {
    int value = rand() % 2001 - 1000; 
    for (int i = 0; i < n; ++i) {
        arr[i] = value; 
}

int main() {
    const int N = 100000;    int arr[N];

    
    initializeRandomArray(arr, N);
    auto start = chrono::high_resolution_clock::now();
    quickSortDescending(arr, 0, N - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> elapsed_time = end - start;
    cout << "Time taken for sorting spad: " << elapsed_time.count() << " ms" << endl;

    
    initializeRandomArray(arr, N);
    start = chrono::high_resolution_clock::now();
    quickSortDescending(arr, 0, N - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_time = end - start;
    cout << "Time taken for sorting random: " << elapsed_time.count() << " ms" << endl;

    
    initializeArrayWithDuplicates(arr, N);
    start = chrono::high_resolution_clock::now();
    quickSortDescending(arr, 0, N - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_time = end - start;
    cout << "Time taken for sorting array with 2 value: " << elapsed_time.count() << " ms" << endl;
    initializeArrayWithAllDuplicates(arr, N);
    start = chrono::high_resolution_clock::now();
    quickSortDescending(arr, 0, N - 1);
    end = chrono::high_resolution_clock::now();
    elapsed_time = end - start;
    cout << "Time taken for sorting array with all: " << elapsed_time.count() << " ms" << endl;

    return 0;
}
