#include <stdio.h>

#define MAX 5

// Function declarations
void inputMarks(int marks[], int n);
int calculateTotal(int marks[], int n);
float calculateAverage(int total, int n);
void displayResult(int marks[], int n, int total, float avg);

int main() {
    int marks[MAX];
    int total;
    float average;

    printf("Student Marks Management Program\n");
    printf("--------------------------------\n");

    // Input marks
    inputMarks(marks, MAX);

    // Calculate total marks
    total = calculateTotal(marks, MAX);

    // Calculate average marks
    average = calculateAverage(total, MAX);

    // Display result
    displayResult(marks, MAX, total, average);

    printf("\nProgram executed successfully.\n");
    return 0;
}

// Function to input marks
void inputMarks(int marks[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Enter marks for subject %d: ", i + 1);
        scanf("%d", &marks[i]);
    }
}

// Function to calculate total marks
int calculateTotal(int marks[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; i++) {
        sum += marks[i];
    }
    return sum;
}

// Function to calculate average marks
float calculateAverage(int total, int n) {
    return (float)total / n;
}

// Function to display result
void displayResult(int marks[], int n, int total, float avg) {
    int i;
    printf("\nMarks Entered:\n");
    for (i = 0; i < n; i++) {
        printf("Subject %d: %d\n", i + 1, marks[i]);
    }

    printf("\nTotal Marks: %d", total);
    printf("\nAverage Marks: %.2f\n", avg);

    if (avg >= 5)
        printf("Result: PASS\n");
    else
        printf("Result: FAIL\n");
}
Student Marks Management Program
--------------------------------
Enter marks for subject 1: 10
Enter marks for subject 2: 10
Enter marks for subject 3: 10
Enter marks for subject 4: 10
Enter marks for subject 5: 10

Marks Entered:
Subject 1: 10
Subject 2: 10
Subject 3: 10
Subject 4: 10
Subject 5: 10

Total Marks: 50
Average Marks: 10.00
Result: PASS

Program executed successfully.


=== Code Execution Successful ===
