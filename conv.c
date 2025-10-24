#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Convert binary string to decimal
int binaryToDecimal(char *binary) {
    int decimal = 0;
    for (int i = 0; binary[i] != '\0'; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

// Convert decimal to binary string
void decimalToBinary(int decimal) {
    char binary[32];
    int i = 0;
    while (decimal > 0) {
        binary[i++] = (decimal % 2) + '0';
        decimal /= 2;
    }
    binary[i] = '\0';

    // Reverse the string
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", binary[j]);
    }
    printf("\n");
}

// Convert decimal to octal
void decimalToOctal(int decimal) {
    printf("Octal: %o\n", decimal);
}

// Convert octal to decimal
int octalToDecimal(int octal) {
    int decimal = 0, base = 1;
    while (octal > 0) {
        decimal += (octal % 10) * base;
        octal /= 10;
        base *= 8;
    }
    return decimal;
}

// Convert decimal to hexadecimal
void decimalToHex(int decimal) {
    printf("Hexadecimal: %X\n", decimal);
}

// Convert hexadecimal string to decimal
int hexToDecimal(char *hex) {
    int decimal = 0;
    sscanf(hex, "%x", &decimal);
    return decimal;
}

int main() {
    int choice, decimal, octal;
    char binary[32], hex[32];

    do {
        printf("\n--- Number System Converter ---\n");
        printf("1. Binary to Decimal\n");
        printf("2. Decimal to Binary\n");
        printf("3. Decimal to Octal\n");
        printf("4. Octal to Decimal\n");
        printf("5. Decimal to Hexadecimal\n");
        printf("6. Hexadecimal to Decimal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter binary number: ");
                scanf("%s", binary);
                printf("Decimal: %d\n", binaryToDecimal(binary));
                break;
            case 2:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                printf("Binary: ");
                decimalToBinary(decimal);
                break;
            case 3:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                decimalToOctal(decimal);
                break;
            case 4:
                printf("Enter octal number: ");
                scanf("%d", &octal);
                printf("Decimal: %d\n", octalToDecimal(octal));
                break;
            case 5:
                printf("Enter decimal number: ");
                scanf("%d", &decimal);
                decimalToHex(decimal);
                break;
            case 6:
                printf("Enter hexadecimal number: ");
                scanf("%s", hex);
                printf("Decimal: %d\n", hexToDecimal(hex));
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
    
    output:
         
         
         
         --- Number System Converter ---
1. Binary to Decimal
2. Decimal to Binary
3. Decimal to Octal
4. Octal to Decimal
5. Decimal to Hexadecimal
6. Hexadecimal to Decimal
0. Exit
Enter your choice: 2
Enter decimal number: 58
Binary: 111010
