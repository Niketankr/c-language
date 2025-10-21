#include <stdio.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LEN 50

// DRY Principle: Reusable constants and functions
typedef struct {
    char name[NAME_LEN];
    int age;
} User;

User users[MAX_USERS];
int user_count = 0;

// Single Responsibility: Each function does one thing
void greet_user(const char *name) {
    printf("Welcome, %s!\n", name);
}

int add_user(const char *name, int age) {
    if (user_count >= MAX_USERS) return 0;

    strncpy(users[user_count].name, name, NAME_LEN);
    users[user_count].age = age;
    user_count++;
    return 1;
}

void list_users() {
    printf("\n--- User List ---\n");
    for (int i = 0; i < user_count; i++) {
        printf("Name: %s, Age: %d\n", users[i].name, users[i].age);
    }
}

// Open/Closed Principle: Extend behavior without modifying core logic
void perform_action(int choice) {
    switch (choice) {
        case 1: {
            char name[NAME_LEN];
            int age;
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter age: ");
            scanf("%d", &age);
            if (add_user(name, age)) {
                greet_user(name);
            } else {
                printf("User limit reached.\n");
            }
            break;
        }
        case 2:
            list_users();
            break;
        default:
            printf("Invalid choice.\n");
    }
}

// KISS Principle: Simple main loop
int main() {
    int choice;
    while (1) {
        printf("\n1. Add User\n2. List Users\n0. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 0) break;
        perform_action(choice);
    }
    return 0;
}
