#include <stdio.h>

int main() {
    int i, j;

    // Print chimneys
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            if (j % 2 == 0)
                printf("  ||  ");
            else
                printf("      ");
        }
        printf("\n");
    }

    // Print roof
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 30 - i * 2; j++)
            printf(" ");
        for (j = 0; j < i * 4 + 1; j++)
            printf("^");
        printf("\n");
    }

    // Print walls
    for (i = 0; i < 5; i++) {
        printf("|");
        for (j = 0; j < 39; j++)
            printf(" ");
        printf("|\n");
    }

    // Print base
    printf("+");
    for (i = 0; i < 39; i++)
        printf("-");
    printf("+\n");

    return 0;
}
