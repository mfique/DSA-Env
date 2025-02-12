#include <iostream>
using namespace std;

// Function to partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Taking the last element as pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) { // If the current element is smaller or equal to the pivot
            i++;
            swap(arr[i], arr[j]); // Swap elements at i and j
        }
    }
    swap(arr[i + 1], arr[high]); // Swap pivot element with element at i + 1
    return (i + 1); // Return the partition index
}

// Function to implement QuickSort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pi = partition(arr, low, high);

        // Recursively sort the elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // Call QuickSort
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

