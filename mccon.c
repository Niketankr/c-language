#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

#define MAX 256

char* minWindow(char* s, char* t) {
    int lenS = strlen(s);
    int lenT = strlen(t);

    if (lenS < lenT) return NULL;

    int hashT[MAX] = {0};
    int hashS[MAX] = {0};

    for (int i = 0; i < lenT; i++)
        hashT[(unsigned char)t[i]]++;

    int start = 0, startIndex = -1;
    int minLen = INT_MAX;
    int count = 0;

    for (int end = 0; end < lenS; end++) {
        hashS[(unsigned char)s[end]]++;

        if (hashT[(unsigned char)s[end]] != 0 &&
            hashS[(unsigned char)s[end]] <= hashT[(unsigned char)s[end]]) {
            count++;
        }

        if (count == lenT) {
            while (hashS[(unsigned char)s[start]] > hashT[(unsigned char)s[start]] ||
                   hashT[(unsigned char)s[start]] == 0) {

                if (hashS[(unsigned char)s[start]] > hashT[(unsigned char)s[start]])
                    hashS[(unsigned char)s[start]]--;

                start++;
            }

            int windowLen = end - start + 1;

            if (windowLen < minLen) {
                minLen = windowLen;
                startIndex = start;
            }
        }
    }

    if (startIndex == -1)
        return NULL;

    char* result = (char*)malloc((minLen + 1) * sizeof(char));
    strncpy(result, s + startIndex, minLen);
    result[minLen] = '\0';

    return result;
}

int main() {
    char s[1000], t[1000];

    printf("Enter string s: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = '\0';  

    printf("Enter string t: ");
    fgets(t, sizeof(t), stdin);
    t[strcspn(t, "\n")] = '\0';  
    
    char* result = minWindow(s, t);

    if (result)
        printf("Minimum Window Substring: %s\n", result);
    else
        printf("No valid window found.\n");

    free(result);  // free allocated memory

    return 0;
}

output:
Enter string s: ABDEK
Enter string t: ADK
Minimum Window Substring: ABDEK


=== Code Execution Successful ===
