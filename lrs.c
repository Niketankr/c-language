#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// ---------------- Bit Operations ----------------
int countBits(int n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

void bitOperationsDemo() {
    int a = 5, b = 3;
    printf("AND: %d\n", a & b);
    printf("OR: %d\n", a | b);
    printf("XOR: %d\n", a ^ b);
    printf("Left Shift: %d\n", a << 1);
    printf("Right Shift: %d\n", a >> 1);
    printf("Count Bits in %d: %d\n", a, countBits(a));
}

// ---------------- Linear Data Structure ----------------
void linearDataStructureDemo() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Array elements:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// ---------------- Hash Table with Probing ----------------
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

int hashFunction2(int key) {
    return 7 - (key % 7);
}

void insertLinearProbing(int table[], int key) {
    int index = hashFunction(key);
    int i = 0;
    while (table[(index + i) % TABLE_SIZE] != -1) {
        i++;
    }
    table[(index + i) % TABLE_SIZE] = key;
}

void insertQuadraticProbing(int table[], int key) {
    int index = hashFunction(key);
    int i = 0;
    while (table[(index + i * i) % TABLE_SIZE] != -1) {
        i++;
    }
    table[(index + i * i) % TABLE_SIZE] = key;
}

void insertDoubleHashing(int table[], int key) {
    int index1 = hashFunction(key);
    int index2 = hashFunction2(key);
    int i = 0;
    while (table[(index1 + i * index2) % TABLE_SIZE] != -1) {
        i++;
    }
    table[(index1 + i * index2) % TABLE_SIZE] = key;
}

void hashTableDemo() {
    int table1[TABLE_SIZE], table2[TABLE_SIZE], table3[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table1[i] = table2[i] = table3[i] = -1;
    }

    int keys[] = {23, 43, 13, 27};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        insertLinearProbing(table1, keys[i]);
        insertQuadraticProbing(table2, keys[i]);
        insertDoubleHashing(table3, keys[i]);
    }

    printf("Linear Probing:\n");
    for (int i = 0; i < TABLE_SIZE; i++) printf("%d ", table1[i]);
    printf("\nQuadratic Probing:\n");
    for (int i = 0; i < TABLE_SIZE; i++) printf("%d ", table2[i]);
    printf("\nDouble Hashing:\n");
    for (int i = 0; i < TABLE_SIZE; i++) printf("%d ", table3[i]);
    printf("\n");
}

// ---------------- Main ----------------
int main() {
    printf("=== Bit Operations ===\n");
    bitOperationsDemo();

    printf("\n=== Linear Data Structure ===\n");
    linearDataStructureDemo();

    printf("\n=== Hash Table Probing Techniques ===\n");
    hashTableDemo();

    return 0;
}
   
   
   
   
   output:
   
   
   === Bit Operations ===
AND: 1
OR: 7
XOR: 6
Left Shift: 10
Right Shift: 2
Count Bits in 5: 2

=== Linear Data Structure ===
Array elements:
10 20 30 40 50 

=== Hash Table Probing Techniques ===
Linear Probing:
-1 -1 -1 23 43 13 -1 27 -1 -1 
Quadratic Probing:
-1 -1 -1 23 43 -1 -1 13 27 -1 
Double Hashing:
-1 -1 -1 23 13 -1 -1 27 -1 43 


=== Code Execution Successful ===
