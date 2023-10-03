#include <stdio.h>

// Function to read an array
void readArray(int arr[], int size) {
    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to insert an element into an array at a specific position
void insertElement(int arr[], int *size, int element, int position) {
    if (position < 0 || position > *size) {
        printf("Invalid position. Element cannot be inserted.\n");
        return;
    }

    // Shift elements to the right to make space for the new element
    for (int i = *size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert the new element
    arr[position] = element;
    
    (*size)++; // Increase the size of the array
}

int main() {
    int arr[100]; // Assuming a maximum array size of 100
    int size, element, position;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size > 100 || size < 0) {
        printf("Invalid array size.\n");
        return 1; // Exit program with an error code
    }

    readArray(arr, size);

    printf("Enter the element to insert: ");
    scanf("%d", &element);

    printf("Enter the position to insert (0-based index): ");
    scanf("%d", &position);

    insertElement(arr, &size, element, position);

    printf("Array after insertion:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
