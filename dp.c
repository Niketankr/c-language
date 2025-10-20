#include <stdio.h>

void print_flame(int size) {
    int i, j, space;
    // Determines the height of the flame
    int flame_size = size / 2 + 1; 

    printf("\n");
    // --- Flame (Upward Pyramid) ---
    for (i = 1; i <= flame_size; i++) {
        // 1. Print leading spaces to center the flame
        for (space = 1; space <= size - i; space++) {
            printf(" ");
        }
        // 2. Print asterisks for the flame body
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_base(int size) {
    int i, j, space;

    // --- Base (Inverted Pyramid) ---
    // Start printing the base immediately after the flame ends.
    for (i = 1; i <= size; i++) {
        // 1. Print leading spaces to center the base (spaces increase)
        for (space = 1; space < i; space++) {
            printf(" ");
        }
        // 2. Print asterisks for the base body (stars decrease)
        for (j = 1; j <= 2 * (size - i) + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int k = 5; // Determines the size of the pattern. You can change this value.
    
    printf("Diya Pattern (Size: %d):\n", k); 

    // Call the functions to print the two parts of the Diya
    print_flame(k);
    print_base(k);
    
    return 0;
}
