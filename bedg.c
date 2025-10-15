#include <stdio.h>

int main() {
    int rows = 16;
    int arm_length = 15; // Length of each cantilever arm
    int gap = 30;        // Central gap or bridge span

    for (int i = 0; i < rows; i++) {
        // Left cantilever arm
        for (int j = 0; j < arm_length - i; j++)
            printf(" ");
        printf("/");

        // Central gap or bridge span
        for (int j = 0; j < gap + 2 * i; j++)
            printf(" ");

        // Right cantilever arm
        printf("\\\n");
    }
{
#include <stdio.h>

int main() {
    int rows = 16;
    int arm_length = 15; // Length of each cantilever arm
    int gap = 30;        // Central gap or bridge span

    for (int i = 0; i < rows; i++) {
        // Left cantilever arm
        for (int j = 0; j < arm_length - i; j++)
            printf(" ");
        printf("/");

        // Central gap or bridge span
        for (int j = 0; j < gap + 2 * i; j++)
            printf(" ");

        // Right cantilever arm
        printf("\\\n");
    }

#include <stdio.h>

int main() {
    int rows = 16;
    int width = 30;

    for (int i = 0; i < rows; i++) {
        // Left cables
        for (int j = 0; j < rows - i - 1; j++)
            printf(" ");
        printf("/");

        // Bridge deck and tower
        for (int j = 0; j < width; j++) {
            if (i == rows - 1)
                printf("_"); // deck
            else if (j == width / 2)
                printf("|"); // central tower
            else
                printf(" ");
        }

        // Right cables
        printf("\\\n");
    }

    return 0;
}
