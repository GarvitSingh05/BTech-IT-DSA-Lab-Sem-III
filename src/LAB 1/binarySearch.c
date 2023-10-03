#include <stdio.h>

// Function to read a sorted array
void readSortedArray(int arr[], int size) {
    printf("Enter %d sorted elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to perform binary search in a sorted array
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found at index mid
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int arr[100]; // Assuming a maximum array size of 100
    int size, target;

    printf("Enter the size of the sorted array: ");
    scanf("%d", &size);

    if (size > 100 || size < 0) {
        printf("Invalid array size.\n");
        return 1; // Exit program with an error code
    }

    readSortedArray(arr, size);

    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element %d found at index %d.\n", target, result);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
