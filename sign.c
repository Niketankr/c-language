#include <stdio.h>
#include <stdlib.h>

// 1. Define the struct that represents the Singleton object
typedef struct {
    // You can add more members here to represent a database connection state
    int connection_id;
} DatabaseConnection;

// 2. A private static pointer to hold the single instance
static DatabaseConnection *instance = NULL;

// 3. A public function to get the single instance
DatabaseConnection* get_db_instance() {
    // Check if the instance has already been created
    if (instance == NULL) {
        printf("Creating a new database connection.\n");
        // Allocate memory and initialize the instance
        instance = (DatabaseConnection *)malloc(sizeof(DatabaseConnection));
        if (instance == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        // Initialize state (simulating a constructor)
        instance->connection_id = 1;
        printf("Initializing the database connection.\n");
    }
    return instance;
}

// 4. Implement a function to act like a method of the singleton object
void execute_query(DatabaseConnection* conn, const char* query) {
    if (conn != NULL) {
        printf("Executing query: %s\n", query);
    }
}

int main() {
    // Try to create the first instance
    DatabaseConnection* db1 = get_db_instance();

    // Try to create a second instance
    // It will return the *same* object as db1
    DatabaseConnection* db2 = get_db_instance();

    // Check if both pointers point to the same memory location
    if (db1 == db2) {
        printf("\nAre db1 and db2 the same object? True\n");
    } else {
        printf("\nAre db1 and db2 the same object? False\n");
    }
    
    // Both objects share the same state and methods
    execute_query(db1, "SELECT * FROM users;");
    execute_query(db2, "INSERT INTO products VALUES (1, 'Laptop');");
    
    // It is good practice to clean up allocated memory at the end
    if (instance != NULL) {
        free(instance);
        instance = NULL;
    }

    return 0;
}
