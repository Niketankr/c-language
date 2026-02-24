#include <stdio.h>
#include <string.h>

void longestPalindrome(char str[]) {
    int n = strlen(str);
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {

        // Odd length palindrome
        int left = i, right = i;
        while (left >= 0 && right < n && str[left] == str[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }

        // Even length palindrome
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && str[left] == str[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }

    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLen; i++)
        printf("%c", str[i]);
}

int main() {
    char str[] = "babad";
    longestPalindrome(str);
    return 0;
}

output:
Longest Palindromic Substring: bab


#include <stdio.h>
#include <string.h>

void reverse(char *start, char *end) {
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main() {
    char str[] = "the sky is blue";
    int n = strlen(str);

    
    reverse(str, str + n - 1);

    char *word_start = str;
    for (int i = 0; i <= n; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            reverse(word_start, str + i - 1);
            word_start = str + i + 1;
        }
    }

    printf("Reversed String: %s\n", str);
    return 0;
}

output:

Reversed String: blue is sky the


=== Code Execution Successful ===
