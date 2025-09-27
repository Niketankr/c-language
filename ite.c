#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ------------------------------------------------------------------
// 1. Aggregate Structure (The collection to be iterated over)
// ------------------------------------------------------------------

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int count;
} IntArray;

// Function to create and initialize the IntArray
IntArray* create_int_array() {
    IntArray* array = (IntArray*)malloc(sizeof(IntArray));
    if (array) {
        array->count = 0;
    }
    return array;
}

// Function to add an item to the array
void add_item(IntArray* array, int item) {
    if (array && array->count < MAX_SIZE) {
        array->items[array->count++] = item;
    }
}

// ------------------------------------------------------------------
// 2. Iterator Interface (The Iterator structure and its methods)
// ------------------------------------------------------------------

// Forward declarations
typedef struct IntArrayIterator IntArrayIterator;

// Function pointer types for the iterator methods
typedef bool (*HasNextFunc)(IntArrayIterator*);
typedef int (*GetNextFunc)(IntArrayIterator*);

struct IntArrayIterator {
    // State of the iteration
    IntArray* aggregate; // Reference to the aggregate object
    int position;        // Current position in the array

    // Iterator methods (Interface)
    HasNextFunc has_next;
    GetNextFunc get_next;
};

// Concrete Iterator Implementation: has_next()
bool int_array_has_next(IntArrayIterator* iterator) {
    if (iterator && iterator->aggregate) {
        return iterator->position < iterator->aggregate->count;
    }
    return false;
}

// Concrete Iterator Implementation: get_next()
int int_array_get_next(IntArrayIterator* iterator) {
    if (int_array_has_next(iterator)) {
        return iterator->aggregate->items[iterator->position++];
    }
    // Return a sentinel value or handle error if no next element
    return -1; 
}

// Factory function to create the Iterator for a given Aggregate
IntArrayIterator* create_iterator(IntArray* array) {
    IntArrayIterator* iterator = (IntArrayIterator*)malloc(sizeof(IntArrayIterator));
    if (iterator) {
        iterator->aggregate = array;
        iterator->position = 0;
        iterator->has_next = int_array_has_next;
        iterator->get_next = int_array_get_next;
    }
    return iterator;
}

// ------------------------------------------------------------------
// 3. Client Code (Main function to use the pattern)
// ------------------------------------------------------------------

int main() {
    printf("--- Iterator Pattern Demonstration (C) ---\n");

    // 1. Create the Aggregate
    IntArray* numbers = create_int_array();
    add_item(numbers, 10);
    add_item(numbers, 20);
    add_item(numbers, 30);
    add_item(numbers, 40);

    // 2. Create the Iterator (abstracts the traversal logic)
    IntArrayIterator* iterator = create_iterator(numbers);

    // 3. Traverse the collection without knowing its internal structure (array)
    printf("Traversing the IntArray:\n");
    int sum = 0;
    
    while (iterator->has_next(iterator)) {
        int item = iterator->get_next(iterator);
        printf("Accessed item: %d\n", item);
        sum += item;
    }

    printf("\nIteration complete. Sum of elements: %d\n", sum);

    // Cleanup
    free(iterator);
    free(numbers);

    return 0;
}
