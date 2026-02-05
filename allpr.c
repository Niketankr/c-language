#include <stdio.h>
#include <stdlib.h>

#define THRESHOLD 64


int** alloc_matrix(int n);
void free_matrix(int **m, int n);
void standard_mul(int **A, int **B, int **C, int n);
void add(int **A, int **B, int **C, int n);
void sub(int **A, int **B, int **C, int n);
void strassen(int **A, int **B, int **C, int n);
void strassen_wrapper(int **A, int **B, int **C, int n);


int** alloc_matrix(int n) {
    int **m = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++)
        m[i] = (int*)calloc(n, sizeof(int));
    return m;
}

void free_matrix(int **m, int n) {
    for (int i = 0; i < n; i++)
        free(m[i]);
    free(m);
}


void standard_mul(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
}

void add(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void sub(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}


void strassen(int **A, int **B, int **C, int n) {
    if (n <= THRESHOLD) {
        standard_mul(A, B, C, n);
        return;
    }

    int k = n / 2;

    int **A11 = alloc_matrix(k);
    int **A12 = alloc_matrix(k);
    int **A21 = alloc_matrix(k);
    int **A22 = alloc_matrix(k);
    int **B11 = alloc_matrix(k);
    int **B12 = alloc_matrix(k);
    int **B21 = alloc_matrix(k);
    int **B22 = alloc_matrix(k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }

    int **M1 = alloc_matrix(k);
    int **M2 = alloc_matrix(k);
    int **M3 = alloc_matrix(k);
    int **M4 = alloc_matrix(k);
    int **M5 = alloc_matrix(k);
    int **M6 = alloc_matrix(k);
    int **M7 = alloc_matrix(k);
    int **T1 = alloc_matrix(k);
    int **T2 = alloc_matrix(k);

    add(A11, A22, T1, k);
    add(B11, B22, T2, k);
    strassen(T1, T2, M1, k);

    add(A21, A22, T1, k);
    strassen(T1, B11, M2, k);

    sub(B12, B22, T2, k);
    strassen(A11, T2, M3, k);

    sub(B21, B11, T2, k);
    strassen(A22, T2, M4, k);

    add(A11, A12, T1, k);
    strassen(T1, B22, M5, k);

    sub(A21, A11, T1, k);
    add(B11, B12, T2, k);
    strassen(T1, T2, M6, k);

    sub(A12, A22, T1, k);
    add(B21, B22, T2, k);
    strassen(T1, T2, M7, k);

    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) {
            C[i][j]         = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + k]     = M3[i][j] + M5[i][j];
            C[i + k][j]     = M2[i][j] + M4[i][j];
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }

    free_matrix(A11,k); free_matrix(A12,k); free_matrix(A21,k); free_matrix(A22,k);
    free_matrix(B11,k); free_matrix(B12,k); free_matrix(B21,k); free_matrix(B22,k);
    free_matrix(M1,k); free_matrix(M2,k); free_matrix(M3,k); free_matrix(M4,k);
    free_matrix(M5,k); free_matrix(M6,k); free_matrix(M7,k);
    free_matrix(T1,k); free_matrix(T2,k);
}


void strassen_wrapper(int **A, int **B, int **C, int n) {
    if (n % 2 == 0) {
        strassen(A, B, C, n);
        return;
    }

    int m = n + 1;
    int **A2 = alloc_matrix(m);
    int **B2 = alloc_matrix(m);
    int **C2 = alloc_matrix(m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A2[i][j] = A[i][j];
            B2[i][j] = B[i][j];
        }

    strassen(A2, B2, C2, m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = C2[i][j];

    free_matrix(A2, m);
    free_matrix(B2, m);
    free_matrix(C2, m);
}


int main() {
    int n = 3;

    int **A = alloc_matrix(n);
    int **B = alloc_matrix(n);
    int **C = alloc_matrix(n);

    int val = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = val;
            B[i][j] = val;
            val++;
        }

    strassen_wrapper(A, B, C, n);

    printf("Result Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d ", C[i][j]);
        printf("\n");
    }

    free_matrix(A, n);
    free_matrix(B, n);
    free_matrix(C, n);

    return 0;
}


output:

Result Matrix:
  30   36   42 
  66   81   96 
 102  126  150 
