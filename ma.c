#include <stdio.h>

#define MAX 10 // Maximum size of matrix (adjust if needed)

// Function to multiply two matrices
void multiplyMatrices(int first[MAX][MAX], int second[MAX][MAX], int result[MAX][MAX], int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        printf("Matrix multiplication is not possible.\n");
        return;
    }

    // Initializing all elements of result matrix to 0
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
        }
    }

    // Performing matrix multiplication
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            for (int k = 0; k < col1; k++) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int row1, col1, row2, col2;

    // Input matrix dimensions
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &row1, &col1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &row2, &col2);

    // Check if multiplication is possible
    if (col1 != row2) {
        printf("Matrix multiplication not possible. Number of columns of first matrix must be equal to number of rows of second matrix.\n");
        return 1;
    }

    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];

    // Input elements for first matrix
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            scanf("%d", &first[i][j]);
        }
    }

    // Input elements for second matrix
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            scanf("%d", &second[i][j]);
        }
    }

    // Multiply matrices
    multiplyMatrices(first, second, result, row1, col1, row2, col2);

    // Output result
    printf("Product of the matrices:\n");
    printMatrix(result, row1, col2);

    return 0;
}

output:

Enter rows and columns for first matrix: 2 2
Enter rows and columns for second matrix: 2 2
Enter elements of first matrix:
14 45
45 86
Enter elements of second matrix:
86 52 
85 75
Product of the matrices:
5029 4103 
11180 8790 


Enter rows and columns for first matrix: 3 3 
Enter rows and columns for second matrix: 3 3 
Enter elements of first matrix:
7 8 9 
45 65 45
47 89 85
Enter elements of second matrix:
78 98 68
86 76 98 
65 45 68
Product of the matrices:
1819 1699 1872 
12025 11375 12490 
16845 15195 17698 
