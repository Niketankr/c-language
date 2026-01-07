#include <stdio.h>
#include <string.h>

#define MAX 100

/* ---------- 1. Reverse Words in a String ---------- */
void reverseWords(char str[]) {
    char *words[MAX];
    int count = 0;

    char *token = strtok(str, " ");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    printf("Reversed Words: ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i != 0)
            printf(" ");
    }
    printf("\n");
}

/* ---------- 2. Longest Common Prefix ---------- */
char* longestCommonPrefix(char strs[][MAX], int n) {
    static char prefix[MAX];
    strcpy(prefix, strs[0]);

    for (int i = 1; i < n; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
    }
    return prefix;
}

/* ---------- Helper: Sort characters in a string ---------- */
void sortString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

/* ---------- 3. Group Anagrams ---------- */
void groupAnagrams(char words[][MAX], int n) {
    int visited[MAX] = {0};

    printf("Grouped Anagrams:\n");
    for (int i = 0; i < n; i++) {
        if (visited[i])
            continue;

        char key1[MAX];
        strcpy(key1, words[i]);
        sortString(key1);

        printf("[ %s", words[i]);
        visited[i] = 1;

        for (int j = i + 1; j < n; j++) {
            if (!visited[j]) {
                char key2[MAX];
                strcpy(key2, words[j]);
                sortString(key2);

                if (strcmp(key1, key2) == 0) {
                    printf(", %s", words[j]);
                    visited[j] = 1;
                }
            }
        }
        printf(" ]\n");
    }
}

/* ---------- Main Function ---------- */
int main() {

    char sentence[] = "the sky is blue";
    reverseWords(sentence);

    char strs[3][MAX] = {"flower", "flow", "flight"};
    printf("Longest Common Prefix: %s\n",
           longestCommonPrefix(strs, 3));

    char words[6][MAX] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(words, 6);

    return 0;
}
output:


Reversed Words: blue is sky the
Longest Common Prefix: fl
Grouped Anagrams:
[ eat, tea, ate ]
[ tan, nat ]
[ bat ]
