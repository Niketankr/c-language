#include <stdio.h>
#include <string.h>

#define MAX_SUBJECTS 20
#define MAX_FACULTY 10
#define DAYS 6
#define HOURS 6
#define SEMESTER_WEEKS 15

typedef struct {
    char name[50];
    int credit;
    int isLab;              // 1 = Lab, 0 = Theory
    int facultyId;
    int weeklyClasses;
    int totalSemesterClasses;
} Subject;

typedef struct {
    char name[50];
    int weeklyLoad;
} Faculty;

Subject subjects[MAX_SUBJECTS];
Faculty faculty[MAX_FACULTY];

char timetable[DAYS][HOURS][50];

int subjectCount = 0;
int facultyCount = 0;
int studentCount;

/* ---------- Function Prototypes ---------- */
void inputData();
void calculateClasses();
void generateRoutine();
void displayRoutine();
void displayFacultyLoad();
void checkStudentFacultyRatio();
int slotAvailable(int day, int hour);
int facultyAvailable(int facultyId, int day, int hour);

/* ---------- Main Function ---------- */
int main() {

    inputData();
    calculateClasses();
    checkStudentFacultyRatio();
    generateRoutine();
    displayRoutine();
    displayFacultyLoad();

    return 0;
}

/* ---------- Input Section ---------- */
void inputData() {

    printf("Enter number of students: ");
    scanf("%d", &studentCount);

    printf("Enter number of faculty: ");
    scanf("%d", &facultyCount);

    for(int i = 0; i < facultyCount; i++) {
        printf("Enter Faculty %d Name: ", i+1);
        scanf("%s", faculty[i].name);
        faculty[i].weeklyLoad = 0;
    }

    printf("Enter number of subjects: ");
    scanf("%d", &subjectCount);

    for(int i = 0; i < subjectCount; i++) {
        printf("\nSubject %d Name: ", i+1);
        scanf("%s", subjects[i].name);

        printf("Credit (2 or 3): ");
        scanf("%d", &subjects[i].credit);

        printf("Is Lab? (1 = Yes, 0 = No): ");
        scanf("%d", &subjects[i].isLab);

        printf("Faculty ID (0 to %d): ", facultyCount-1);
        scanf("%d", &subjects[i].facultyId);
    }
}

/* ---------- Calculate Weekly & Semester Classes ---------- */
void calculateClasses() {

    for(int i = 0; i < subjectCount; i++) {

        if(subjects[i].isLab == 0) {
            // Theory
            subjects[i].weeklyClasses = subjects[i].credit;

            subjects[i].totalSemesterClasses =
                subjects[i].weeklyClasses * SEMESTER_WEEKS;

            if(subjects[i].totalSemesterClasses < 35)
                subjects[i].totalSemesterClasses = 35;

        } else {
            // Lab (2 hours per week minimum)
            subjects[i].weeklyClasses = 2;

            subjects[i].totalSemesterClasses =
                subjects[i].weeklyClasses * SEMESTER_WEEKS;

            if(subjects[i].totalSemesterClasses < 10)
                subjects[i].totalSemesterClasses = 10;
        }
    }
}

/* ---------- Student-Faculty Ratio Check ---------- */
void checkStudentFacultyRatio() {

    if(studentCount / facultyCount > 20)
        printf("\nWARNING: Student-Faculty ratio exceeds 20:1\n");
    else
        printf("\nStudent-Faculty ratio is maintained.\n");
}

/* ---------- Generate Routine ---------- */
void generateRoutine() {

    int day = 0, hour = 0;

    for(int i = 0; i < DAYS; i++)
        for(int j = 0; j < HOURS; j++)
            strcpy(timetable[i][j], "FREE");

    for(int i = 0; i < subjectCount; i++) {

        int count = subjects[i].weeklyClasses;

        while(count > 0) {

            if(slotAvailable(day, hour) &&
               facultyAvailable(subjects[i].facultyId, day, hour)) {

                strcpy(timetable[day][hour], subjects[i].name);
                faculty[subjects[i].facultyId].weeklyLoad++;
                count--;
            }

            hour++;
            if(hour == HOURS) {
                hour = 0;
                day++;
                if(day == DAYS)
                    day = 0;
            }
        }
    }
}

/* ---------- Utility Checks ---------- */
int slotAvailable(int day, int hour) {

    if(strcmp(timetable[day][hour], "FREE") == 0)
        return 1;
    return 0;
}

int facultyAvailable(int facultyId, int day, int hour) {
    // Simple version (can expand for multi-section)
    return 1;
}

/* ---------- Display Routine ---------- */
void displayRoutine() {

    char *days[DAYS] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

    printf("\n\n===== WEEKLY ROUTINE =====\n\n");

    for(int i = 0; i < DAYS; i++) {
        printf("%s: ", days[i]);
        for(int j = 0; j < HOURS; j++) {
            printf("%s | ", timetable[i][j]);
        }
        printf("\n");
    }
}

/* ---------- Faculty Load ---------- */
void displayFacultyLoad() {

    printf("\n\n===== FACULTY WEEKLY LOAD =====\n");

    for(int i = 0; i < facultyCount; i++) {
        printf("%s : %d Hours/Week\n",
               faculty[i].name,
               faculty[i].weeklyLoad);

        if(faculty[i].weeklyLoad > 24)
            printf("  OVERLOAD!\n");
    }
}



output:

Enter number of students: 5
Enter number of faculty: 2
Enter Faculty 1 Name: Sumit
Enter Faculty 2 Name: amitav
Enter number of subjects: 5

Subject 1 Name: Artificial Intelligence
Credit (2 or 3): Is Lab? (1 = Yes, 0 = No): Faculty ID (0 to 1): 
Subject 2 Name: Credit (2 or 3): Dicrete Mathematics
Is Lab? (1 = Yes, 0 = No): Faculty ID (0 to 1): 
Subject 3 Name: Credit (2 or 3): Is Lab? (1 = Yes, 0 = No): Faculty ID (0 to 1): 
Subject 4 Name: Credit (2 or 3): data analytics
Is Lab? (1 = Yes, 0 = No): Faculty ID (0 to 1): 
Subject 5 Name: Credit (2 or 3): Is Lab? (1 = Yes, 0 = No): Faculty ID (0 to 1): 
Student-Faculty ratio is maintained.


===== WEEKLY ROUTINE =====

Mon: FREE | FREE | FREE | FREE | FREE | FREE | 
Tue: FREE | FREE | FREE | FREE | FREE | FREE | 
Wed: FREE | FREE | FREE | FREE | FREE | FREE | 
Thu: FREE | FREE | FREE | FREE | FREE | FREE | 
Fri: FREE | FREE | FREE | FREE | FREE | FREE | 
Sat: FREE | FREE | FREE | FREE | FREE | FREE | 


===== FACULTY WEEKLY LOAD =====
Sumit : 0 Hours/Week
amitav : 0 Hours/Week


=== Code Execution Successful ===
