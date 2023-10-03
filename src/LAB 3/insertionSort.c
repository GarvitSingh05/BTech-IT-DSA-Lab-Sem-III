#include <stdio.h>

// Function to read an array of N integers
void readArray(int arr[], int N) {
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to perform insertion sort on the array
void insertionSort(int arr[], int N) {
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to display the elements of the array
void displayArray(int arr[], int N) {
    printf("Sorted Array:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int N;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &N);

    int arr[N];

    readArray(arr, N);      // Read the array
    insertionSort(arr, N); // Sort the array
    displayArray(arr, N);   // Display the sorted array

    return 0;
}
