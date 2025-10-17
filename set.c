#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TABLE_SIZE 10
#define MAX_SIZE 100

// **HashMap Implementation**
typedef struct {
    char key[50];
    int value;
} HashNode;

HashNode* hashTable[TABLE_SIZE] = {NULL};

int hashFunction(char* key) {
    int hash = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        hash += key[i];
    }
    return hash % TABLE_SIZE;
}

void insert(char* key, int value) {
    int index = hashFunction(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    strcpy(newNode->key, key);
    newNode->value = value;
    hashTable[index] = newNode;
}

int search(char* key) {
    int index = hashFunction(key);
    if (hashTable[index] != NULL && strcmp(hashTable[index]->key, key) == 0) {
        return hashTable[index]->value;
    }
    return -1; // Not found
}

// **Set Implementation**
int set[MAX_SIZE];
int size = 0;

bool contains(int element) {
    for (int i = 0; i < size; i++) {
        if (set[i] == element) return true;
    }
    return false;
}

void add(int element) {
    if (!contains(element)) {
        set[size++] = element;
    }
}

void displaySet() {
    for (int i = 0; i < size; i++) {
        printf("%d ", set[i]);
    }
    printf("\n");
}

// **Abstraction Example**
typedef struct {
    int length;
    int width;
} Rectangle;

int calculateArea(Rectangle* rect) {
    return rect->length * rect->width;
}

void displayArea(Rectangle* rect) {
    printf("Area: %d\n", calculateArea(rect));
}

// **Polymorphism Example**
typedef struct {
    void (*speak)();
} Animal;

void dogSpeak() {
    printf("Woof!\n");
}

void catSpeak() {
    printf("Meow!\n");
}

// **Main Function**
int main() {
    // HashMap Example
    printf("**HashMap Example**\n");
    insert("apple", 10);
    insert("banana", 20);
    printf("Value for 'apple': %d\n", search("apple"));
    printf("Value for 'banana': %d\n", search("banana"));
    printf("Value for 'grape': %d\n\n", search("grape")); // Not found

    // Set Example
    printf("**Set Example**\n");
    add(10);
    add(20);
    add(10); // Duplicate
    printf("Set elements: ");
    displaySet();
    printf("\n");

    // Abstraction Example
    printf("**Abstraction Example**\n");
    Rectangle rect = {10, 5};
    displayArea(&rect); // Output: Area: 50
    printf("\n");

    // Polymorphism Example
    printf("**Polymorphism Example**\n");
    Animal dog = {dogSpeak};
    Animal cat = {catSpeak};

    printf("Dog says: ");
    dog.speak(); // Output: Woof!
    printf("Cat says: ");
    cat.speak(); // Output: Meow!

    return 0;
}




output   


**HashMap Example**
Value for 'apple': 10
Value for 'banana': 20
Value for 'grape': -1

**Set Example**
Set elements: 10 20 

**Abstraction Example**
Area: 50

**Polymorphism Example**
Dog says: Woof!
Cat says: Meow!

