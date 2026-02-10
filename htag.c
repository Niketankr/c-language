#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TABLE_SIZE 1000
#define WORD_SIZE 50


struct Node {
    char word[WORD_SIZE];
    int count;
    struct Node *next;
};


struct Node *hashTable[TABLE_SIZE];


void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}


int hashFunction(char *word) {
    int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash += word[i];
    }
    return hash % TABLE_SIZE;
}


void toLowerCase(char *word) {
    for (int i = 0; word[i]; i++) {
        word[i] = tolower(word[i]);
    }
}


void insertWord(char *word) {
    int index = hashFunction(word);
    struct Node *temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
            temp->count++;
            return;
        }
        temp = temp->next;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->word, word);
    newNode->count = 1;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}


int searchWord(char *word) {
    int index = hashFunction(word);
    struct Node *temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}


int readFileAndStore(char *filename) {
    FILE *file = fopen(filename, "r");
    char word[WORD_SIZE];
    int totalWords = 0;

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);
        insertWord(word);
        totalWords++;
    }

    fclose(file);
    return totalWords;
}


int readFileAndCompare(char *filename, int *matchedWords) {
    FILE *file = fopen(filename, "r");
    char word[WORD_SIZE];
    int totalWords = 0;

    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);
        if (searchWord(word)) {
            (*matchedWords)++;
        }
        totalWords++;
    }

    fclose(file);
    return totalWords;
}


int main() {
    char file1[100], file2[100];
    int totalWordsFile2, matchedWords = 0;
    float plagiarismPercentage;

    initHashTable();

    printf("Enter first file name: ");
    scanf("%s", file1);

    printf("Enter second file name: ");
    scanf("%s", file2);

    readFileAndStore(file1);
    totalWordsFile2 = readFileAndCompare(file2, &matchedWords);

    plagiarismPercentage = ((float)matchedWords / totalWordsFile2) * 100;

    printf("\n----- Plagiarism Report -----\n");
    printf("Total words in %s: %d\n", file2, totalWordsFile2);
    printf("Matching words: %d\n", matchedWords);
    printf("Plagiarism Percentage: %.2f%%\n", plagiarismPercentage);

    return 0;
}
