#include <stdio.h>
#include <string.h>

#define MAX 1000

// Function to return the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to expand from the center and return palindrome length
int expandFromCenter(char *str, int left, int right, int n) {
    while (left >= 0 && right < n && str[left] == str[right]) {
        left--;
        right++;
    }
    return right - left - 1;
}

int main() {

    char str[MAX];

    printf("Enter a string:\n");
    fgets(str, MAX, stdin);

    int n = strlen(str);

    // Remove newline if present
    if (str[n - 1] == '\n') {
        str[n - 1] = '\0';
        n--;
    }

    if (n == 0) {
        printf("Empty string.\n");
        return 0;
    }

    int start = 0;
    int maxLen = 1;

    for (int i = 0; i < n; i++) {

        // Odd length palindrome
        int len1 = expandFromCenter(str, i, i, n);

        // Even length palindrome
        int len2 = expandFromCenter(str, i, i + 1, n);

        int len = (len1 > len2) ? len1 : len2;

        if (len > maxLen) {
            maxLen = len;
            start = i - (len - 1) / 2;
        }
    }

    printf("Longest Palindromic Substring: ");

    for (int i = start; i < start + maxLen; i++) {
        printf("%c", str[i]);
    }

    printf("\nLength: %d\n", maxLen);

    return 0;
}
