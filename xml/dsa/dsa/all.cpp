#include <iostream>
using namespace std;

/* Function to sort an array using insertion sort */
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

/* Function to print an array */
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Main function */
int main() {
    int arr[] = {8, 3, 5, 1, 9, 2, 7, 6, 4, 10};  // Example unsorted array
    int n = sizeof(arr) / sizeof(arr[0]);         // Calculate the size of the array

    cout << "Original array: ";
    printArray(arr, n);                           // Print the original array

    insertionSort(arr, n);                        // Call the insertion sort function

    cout << "Sorted array: ";
    printArray(arr, n);                           // Print the sorted array

    return 0;
}

