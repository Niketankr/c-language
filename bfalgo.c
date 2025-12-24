#include <stdio.h>
#include <string.h>

/*
 Brute force string matching algorithm
 This program searches for a pattern
 inside a given text using brute force
*/

int main()
{
    char text[100];
    char pattern[50];
    int n, m;
    int i, j;
    int found = 0;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    text[strcspn(text, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    n = strlen(text);
    m = strlen(pattern);

    if (m > n)
    {
        printf("Pattern is longer than text\n");
        return 0;
    }

    for (i = 0; i <= n - m; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }

        if (j == m)
        {
            printf("Pattern found at index %d\n", i);
            found = 1;
        }
    }

    if (!found)
    {
        printf("Pattern not found\n");
    }

    return 0;
}
