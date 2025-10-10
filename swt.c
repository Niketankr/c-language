#include <stdio.h>

void check_number(int num) {
    printf("Checking number: %d\n", num);

    switch (num) {
        // --- Multiple Case Labels for Single Action ---
        case 1:
        case 3:
        case 5:
            printf("  Odd number (1, 3, or 5).\n");
            break;

        // --- Intentional Fall-through Demonstration ---
        case 7:
            printf("  Seven is a lucky number! (Fall-through starts)\n");
            // NO break here -> Intentional Fall-through to case 8
        case 8:
            printf("  This code runs for both 7 (due to fall-through) and 8.\n");
            break; // Stops execution for both case 7 and case 8

        // --- Standard Case Block with Break ---
        case 10:
            printf("  The number is exactly ten.\n");
            break;

        // --- Default Case ---
        default:
            printf("  No specific case matched (Default action).\n");
            // Break here is optional, as it is the last block, but good practice.
            break;
    }
    printf("Switch statement finished.\n\n");
}

int main() {
    // Example 1: Standard Case with break
    check_number(5);

    // Example 2: Intentional Fall-through
    check_number(7);

    // Example 3: Case reached via Fall-through
    check_number(8);

    // Example 4: Default Case
    check_number(100);

    return 0;
}
