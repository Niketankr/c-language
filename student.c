#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    char name[50];
    int student_id;
    int roll_no;
    char gender;
    int maths;
    int english;
    int science;
};

int main() {
    struct Student s[MAX];
    int n, i;
    int male = 0, female = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Student ID: ");
        scanf("%d", &s[i].student_id);

        printf("Roll No: ");
        scanf("%d", &s[i].roll_no);

        printf("Gender (M/F): ");
        scanf(" %c", &s[i].gender);

        printf("Maths Marks: ");
        scanf("%d", &s[i].maths);

        printf("English Marks: ");
        scanf("%d", &s[i].english);

        printf("Science Marks: ");
        scanf("%d", &s[i].science);

        if (s[i].gender == 'M' || s[i].gender == 'm')
            male++;
        else if (s[i].gender == 'F' || s[i].gender == 'f')
            female++;
    }

    /* Histogram for Maths and English */
    printf("\n\nHISTOGRAM (Each * = 5 Marks)\n");

    for (i = 0; i < n; i++) {
        int j;

        printf("\n%s - Maths:   ", s[i].name);
        for (j = 0; j < s[i].maths / 5; j++)
            printf("*");

        printf("\n%s - English: ", s[i].name);
        for (j = 0; j < s[i].english / 5; j++)
            printf("*");
        printf("\n");
    }

    /* Pie Chart (Male vs Female) */
    printf("\n\nPIE CHART (Gender Distribution)\n");

    float male_percent = (male * 100.0) / n;
    float female_percent = (female * 100.0) / n;

    printf("\nMale   : %.2f%% ", male_percent);
    for (i = 0; i < male_percent / 2; i++)
        printf("*");

    printf("\nFemale : %.2f%% ", female_percent);
    for (i = 0; i < female_percent / 2; i++)
        printf("*");

    printf("\n");

    return 0;
}
  output:
  
  
  Enter number of students: 2

--- Student 1 ---
Name: Niketan
Student ID: 1
Roll No: 2
Gender (M/F): m
Maths Marks: 87
English Marks: 69
Science Marks: 90

--- Student 2 ---
Name: Nilimesh
Student ID: 2
Roll No: 3
Gender (M/F): m
Maths Marks: 78
English Marks: 89
Science Marks: 87


HISTOGRAM (Each * = 5 Marks)

Niketan - Maths:   *****************
Niketan - English: *************

Nilimesh - Maths:   ***************
Nilimesh - English: *****************


PIE CHART (Gender Distribution)

Male   : 100.00% **************************************************
Female : 0.00% 


=== Code Execution Successful ===
