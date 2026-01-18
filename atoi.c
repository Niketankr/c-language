#include <stdio.h>
#include <limits.h>

/*
    Program: String to Integer Conversion
    Description:
    - Converts a string to an integer manually
    - Handles negative numbers
    - Validates input characters
    - Prevents integer overflow
*/

int stringToInt(char str[], int *result) {
    int i = 0;
    int sign = 1;
    long num = 0;

    /* Check for empty string */
    if (str[0] == '\0') {
        return 0;
    }

    /* Check for sign */
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    /* Process each character */
    while (str[i] != '\0') {

        /* Check if character is a digit */
        if (str[i] < '0' || str[i] > '9') {
            return 0;   // Invalid character
        }

        /* Convert character to digit */
        num = num * 10 + (str[i] - '0');

        /* Check for overflow */
        if (sign == 1 && num > INT_MAX) {
            return 0;
        }

        if (sign == -1 && -num < INT_MIN) {
            return 0;
        }

        i++;
    }

    /* Apply sign */
    *result = (int)(num * sign);
    return 1;
}

int main() {
    char str[100];
    int value;
    int status;

    /* Prompt user for input */
    printf("Enter a numeric string: ");
    scanf("%99s", str);

    /* Convert string to integer */
    status = stringToInt(str, &value);

    /* Display result */
    if (status == 1) {
        printf("Converted integer: %d\n", value);
    } else {
        printf("Invalid input or overflow occurred.\n");
    }

    /* Program end */
    return 0;
}
