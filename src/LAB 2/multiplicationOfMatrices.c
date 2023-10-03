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

// Function to multiply two matrices
void multiplyMatrices(int rows1, int cols1, int matrix1[rows1][cols1],
                      int rows2, int cols2, int matrix2[rows2][cols2],
                      int result[rows1][cols2]) {
    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for the first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the number of rows and columns for the second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must be equal to the number of rows in the second matrix.\n");
        return 1;
    }

    int matrix1[rows1][cols1];
    int matrix2[rows2][cols2];
    int result[rows1][cols2];

    printf("For Matrix 1:\n");
    readMatrix(rows1, cols1, matrix1);

    printf("For Matrix 2:\n");
    readMatrix(rows2, cols2, matrix2);

    multiplyMatrices(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

    printf("Resultant Matrix after multiplication:\n");
    displayMatrix(rows1, cols2, result);

    return 0;
}
