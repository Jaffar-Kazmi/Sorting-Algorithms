#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Sorting algorithms
void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++)
        for(int j=0; j<n-i-1; j++)
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

void selectionSort(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        int min_idx = i;
        for(int j=i+1; j<n; j++)
            if(arr[j] < arr[min_idx])
                min_idx = j;
        swap(arr[min_idx], arr[i]);
    }
}

void insertionSort(vector<int> arr) {
    int n = arr.size();
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    vector<int> L(n1), R(n2);
    for(int i=0; i<n1; i++) L[i] = arr[l+i];
    for(int j=0; j<n2; j++) R[j] = arr[m+1+j];
    
    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while(i<n1) arr[k++] = L[i++];
    while(j<n2) arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if(l<r) {
        int m = l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void mergeSortStart(vector<int> arr) {
    mergeSort(arr, 0, arr.size()-1);
}

// Measure execution time
template<typename Func>
double measureTime(Func sortFunction, vector<int> arr) {
    auto start = high_resolution_clock::now();
    sortFunction(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count();
}

void testSortingAlgorithm(string name, void(*sortFunction)(vector<int>), vector<vector<int>> arrays) {
    cout << "\n=== " << name << " ===\n";
    for(auto arr : arrays) {
        double total_time = 0;
        for(int i=0; i<5; i++) { // 5 runs
            total_time += measureTime(sortFunction, arr);
        }
        double avg_time = total_time / 5.0;
        cout << "Size: " << arr.size() << " -> Average Time: " << avg_time << " microseconds\n";
    }
}

int main() {
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> arr3;
    for(int i=1; i<=50; i++) arr3.push_back(i);
    vector<int> arr4;
    for(int i=1; i<=100; i++) arr4.push_back(i);

    vector<vector<int>> arrays = {arr1, arr2, arr3, arr4};

    testSortingAlgorithm("Bubble Sort", bubbleSort, arrays);
    testSortingAlgorithm("Selection Sort", selectionSort, arrays);
    testSortingAlgorithm("Insertion Sort", insertionSort, arrays);
    testSortingAlgorithm("Merge Sort", mergeSortStart, arrays);

    return 0;
}
