#include <stdio.h>
#include <string.h>

/* Function to find Longest Common Prefix */
char* longestCommonPrefix(char strs[][20], int n) {
    static char prefix[20];
    if (n == 0) return "";

    strcpy(prefix, strs[0]);

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j])
            j++;
        prefix[j] = '\0';
    }
    return prefix;
}

/* Function to sort characters in a string */
void sortString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
}

/* Main Function */
int main() {
    /* Longest Common Prefix */
    char prefixWords[][20] = {"flower", "flow", "flight"};
    int pCount = 3;
    printf("Longest Common Prefix: %s\n\n",
           longestCommonPrefix(prefixWords, pCount));

    /* Group Anagrams */
    char words[][20] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int n = 6;
    char sorted[6][20];
    int visited[6] = {0};

    for (int i = 0; i < n; i++) {
        strcpy(sorted[i], words[i]);
        sortString(sorted[i]);
    }

    printf("Grouped Anagrams:\n");
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        printf("[ ");
        for (int j = i; j < n; j++) {
            if (strcmp(sorted[i], sorted[j]) == 0) {
                printf("%s ", words[j]);
                visited[j] = 1;
            }
        }
        printf("]\n");
    }

    return 0;
}
