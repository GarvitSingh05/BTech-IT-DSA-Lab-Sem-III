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

// Function to add two matrices
void addMatrices(int rows, int cols, int matrix1[rows][cols], int matrix2[rows][cols], int result[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[rows][cols];
    int matrix2[rows][cols];
    int result[rows][cols];

    printf("For Matrix 1:\n");
    readMatrix(rows, cols, matrix1);

    printf("For Matrix 2:\n");
    readMatrix(rows, cols, matrix2);

    addMatrices(rows, cols, matrix1, matrix2, result);

    printf("Resultant Matrix after addition:\n");
    displayMatrix(rows, cols, result);

    return 0;
}
