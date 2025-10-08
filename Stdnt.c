#include <stdio.h>
int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    if(n <= 0){
        printf("Invalid number of students!\n");
        return 0;
    }
    char names[n][50];
    int marks[n];
    for(int i = 0; i < n; i++){
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", names[i]);
        printf("Enter marks of %s: ", names[i]);
        scanf("%d", &marks[i]);
        if(marks[i] < 0 || marks[i] > 100){
            printf("Invalid marks, setting to 0.\n");
            marks[i] = 0;
        }
    }
    int choice;
    do {
        printf("\n--- Student Marks Menu ---\n");
        printf("1. Display all students\n");
        printf("2. Display students with marks > 50\n");
        printf("3. Search for a student by name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("All Students:\n");
                for(int i = 0; i < n; i++)
                    printf("%s - %d\n", names[i], marks[i]);
                break;
            case 2:
                printf("Students with marks > 50:\n");
                for(int i = 0; i < n; i++)
                    if(marks[i] > 50)
                        printf("%s - %d\n", names[i], marks[i]);
                break;
            case 3:
            {
                char searchName[50];
                int found = 0;
                printf("Enter student name to search: ");
                scanf("%s", searchName);
                for(int i = 0; i < n; i++){
                    if((names[i], searchName) == 0){
                        printf("Found: %s - %d\n", names[i], marks[i]);
                        found = 1;
                        break;
                    }
                }
                if(!found)
                    printf("Student not found!\n");
                break;
            }
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while(choice != 4);
    return 0;
}
