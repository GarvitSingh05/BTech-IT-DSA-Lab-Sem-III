#include <stdio.h>

// Function to read an array of N integers
void readArray(int arr[], int N) {
    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to perform bubble sort on the array
void bubbleSort(int arr[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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
    bubbleSort(arr, N); // Sort the array
    displayArray(arr, N); // Display the sorted array

    return 0;
}
