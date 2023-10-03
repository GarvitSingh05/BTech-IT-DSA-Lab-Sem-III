#include <stdio.h>

// Function to read an array
void readArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to perform linear search in an array
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Element found at index i
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[100]; // Assuming a maximum array size of 100
    int size, target;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > 100 || size < 0) {
        printf("Invalid array size.\n");
        return 1; // Exit program with an error code
    }

    readArray(arr, size);

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
