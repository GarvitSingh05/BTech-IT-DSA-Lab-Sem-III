#include <stdio.h>

// Function to read an array of N integers
void readArray(int arr[], int N) {
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to perform selection sort on the array
void selectionSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < N; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Swap arr[i] and arr[minIndex]
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
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

    readArray(arr, N);  // Read the array
    selectionSort(arr, N); // Sort the array
    displayArray(arr, N); // Display the sorted array

    return 0;
}
