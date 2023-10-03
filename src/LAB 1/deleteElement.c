#include <stdio.h>

// Function to read an array
void readArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to delete an element from an array at a specific position
void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position. Element cannot be deleted.\n");
        return;
    }

    // Shift elements to the left to remove the element
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    
    (*size)--; // Decrease the size of the array
}

int main() {
    int arr[100]; // Assuming a maximum array size of 100
    int size, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > 100 || size < 0) {
        printf("Invalid array size.\n");
        return 1; // Exit program with an error code
    }

    readArray(arr, size);

    printf("Enter the position to delete (0-based index): ");
    scanf("%d", &position);

    deleteElement(arr, &size, position);

    printf("Array after deletion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
