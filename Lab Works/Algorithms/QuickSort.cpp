#include <iostream>
using namespace std;

// Function to perform the partitioning step of QuickSort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int i = (low - 1);      // Pointer for the smaller element (starts one before 'low')

    // Traverse the array from 'low' to 'high-1'
    for (int j = low; j < high; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;  // Increment the smaller element index
            swap(arr[i], arr[j]);  // Swap the elements at i and j
        }
    }
    // Place the pivot in the correct position by swapping it with arr[i + 1]
    swap(arr[i + 1], arr[high]);
    return (i + 1);  // Return the partition index (position of pivot)
}

// Function to implement QuickSort (using low as the pivot)
void quickSort(int arr[], int low, int high) {
    if (low < high) {  // If there are more than one elements to sort
        // Find the pivot index using partition, where arr[pi] is the correct position of pivot
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after the pivot (i.e., in the left and right subarrays)
        quickSort(arr, low, pi - 1);  // Recursively sort the left subarray (before the pivot)
        quickSort(arr, pi + 1, high);  // Recursively sort the right subarray (after the pivot)
    }
}

// Helper function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {24, 9, 29, 14, 19, 27};  // array
    int n = sizeof(arr) / sizeof(arr[0]);  // Get the size of the array

    // Print the original array
    cout << "Original array: ";
    printArray(arr, n);

    // Perform QuickSort on the array
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;  // Return 0 to indicate successful execution
}
