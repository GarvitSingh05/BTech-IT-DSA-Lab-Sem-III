#include <stdio.h>

// Function to read a matrix from the user
void readMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to display a matrix
void displayMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to find the transpose of a matrix
void transposeMatrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns for the matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix[rows][cols];
    int result[cols][rows];

    printf("Enter the elements of the matrix:\n");
    readMatrix(rows, cols, matrix);

    transposeMatrix(rows, cols, matrix, result);

    printf("Transpose of the matrix:\n");
    displayMatrix(cols, rows, result);

    return 0;
}
