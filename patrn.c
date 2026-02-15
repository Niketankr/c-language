#include <stdio.h>
#include <string.h>

void computeLPSArray(char* pat, int m, int* lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search(char* pat, char* txt) {
    int m = strlen(pat);
    int n = strlen(txt);

    int lps[m];
    computeLPSArray(pat, m, lps);

    int i = 0; 
    int j = 0; 

    while (i < n) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }

        if (j == m) {
            printf("Pattern found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < n && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    char txt[] = "AABAACAADAABAABA";
    char pat[] = "AABA";
    search(pat, txt);
    return 0;
}


output:


Pattern found at index 0
Pattern found at index 9
Pattern found at index 12


=== Code Execution Successful ===
#include <stdio.h>

int main() {
    int i, j, n = 5;
    
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}


#include <stdio.h>

int main() {
    int i, j, n = 5;
    
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}

#include <stdio.h>

int main() {
    int i, j, n = 5;
    
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    
    return 0;
}
