#include <stdio.h>

void generateMagicSquare(int n) {
    int magicSquare[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    int row = 0, col = n / 2;

    for (int num = 1; num <= n * n; num++) {
        magicSquare[row][col] = num;

        int newRow = (row - 1 + n) % n;
        int newCol = (col + 1) % n;

        if (magicSquare[newRow][newCol] != 0) {
            
            row = (row + 1) % n;
        } else {
       
            row = newRow;
            col = newCol;
        }
    }

    printf("Magic Square of size %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter an odd number for the order of the magic square: ");
    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("Magic square can only be generated for odd-order matrices.\n");
    } else {
        generateMagicSquare(n);
    }

    return 0;
}

output:

Enter an odd number for the order of the magic square: 3
Magic Square of size 3 x 3:
  8   1   6 
  3   5   7 
  4   9   2 
