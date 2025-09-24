#include <stdio.h>

int main() {
    printf(" First :\n'+', '/', '*', '\\':\n\n");

    // Top support beam
    printf("   +++++++++++++++++++++++++++++++\n");

    // Diagonal suspensions (top part)
    printf("  /                             \\\n");
    printf(" /                               \\\n");

    // Main roadway / structure using '*'
    printf("/*********************************\\\n"); // Top of the roadway
    printf("* * * * * * * * * * * * * * * * * *\n"); // Middle part of the roadway
    printf("\\*********************************/\n"); // Bottom of the roadway

    // Diagonal suspensions (bottom part)
    printf(" \\                               /\n");
    printf("  \\                             /\n");

    // Bottom support beam
    printf("   +++++++++++++++++++++++++++++++\n");

    printf("\n\n");

    // Another, simpler interpretation of a bridge (more abstract)
    printf("Another :\n\n");

    printf("   +---+\n");
    printf("  /     \\\n");
    printf(" *-------*\n");
    printf("  \\     /\n");
    printf("   +---+\n");

    return 0;
}
