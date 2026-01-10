#include <stdio.h>

void generateDoublyEvenMagicSquare(int n) {
    int magicSquare[n][n];
    
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = (i * n) + j + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          
            if ((i / (n / 4)) % 2 == (j / (n / 4)) % 2) {
                magicSquare[i][j] = (n * n + 1) - magicSquare[i][j];
            }
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

    printf("Enter an even number (multiple of 4) for the order of the magic square: ");
    scanf("%d", &n);

    if (n % 4 != 0) {
        printf("Magic square can only be generated for orders that are multiples of 4 (e.g., 4x4, 8x8, etc.).\n");
    } else {
        generateDoublyEvenMagicSquare(n);
    }

    return 0;
}

output:

Enter an even number (multiple of 4) for the order of the magic square: 4
Magic Square of size 4 x 4:
 16   2  14   4 
  5  11   7   9 
  8  10   6  12 
 13   3  15   1 
