
#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 40

// Grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Course structure
struct Course {
    char course_code[20];
    char course_name[50];
};

// Student structure
struct Student {
    char registration_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grades;
};

// Function prototypes
void addStudent(struct Student students[], int* studentCount);
void editStudent(struct Student students[], int studentCount);
void addMarksAndCalculateGrades(struct Student students[], int studentCount);
void displayStudentDetails(struct Student students[], int studentCount);

int main() {
    struct Student students[MAX_STUDENTS];
    int studentCount = 0;

    // Menu
    int choice;
    do {
        printf("\n1. Add Student\n");
        printf("2. Edit Student\n");
        printf("3. Add Marks and Calculate Grades\n");
        printf("4. Display Student Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

         switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                editStudent(students, studentCount);
                break;
            case 3:
                addMarksAndCalculateGrades(students, studentCount);
                break;
            case 4:
                displayStudentDetails(students, studentCount);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void addStudent(struct Student students[], int* studentCount) {
    if (*studentCount < MAX_STUDENTS) {
        struct Student newStudent;

        printf("Enter registration number: ");
        scanf("%s", newStudent.registration_number);

        printf("Enter name: ");
        scanf(" %[^\n]s", newStudent.name);

        printf("Enter age: ");
        scanf("%d", &newStudent.age);

        printf("Enter course code: ");
        scanf("%s", newStudent.course.course_code);

        printf("Enter course name: ");
        scanf(" %[^\n]s", newStudent.course.course_name);

        // Initialize grades to -1, indicating not calculated yet
        newStudent.grades.mark = -1;
        newStudent.grades.the_grade = ' ';

        students[(*studentCount)++] = newStudent;

        printf("Student added successfully.\n");
    } else {
        printf("Maximum number of students reached.\n");
    }
}

void editStudent(struct Student students[], int studentCount) {
    char regNum[20];
    printf("Enter registration number of the student to edit: ");
    scanf("%s", regNum);

    for (int i = 0; i < studentCount; ++i) {
        if (strcmp(students[i].registration_number, regNum) == 0) {
            // Allow editing name and age
            printf("Enter new name: ");
            scanf(" %[^\n]s", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Student details updated successfully.\n");
            return;
        }
    }

    printf("Student with registration number %s not found.\n", regNum);
}

void addMarksAndCalculateGrades(struct Student students[], int studentCount) {
    char regNum[20];
    printf("Enter registration number of the student: ");
    scanf("%s", regNum);

    for (int i = 0; i < studentCount; ++i) {
        if (strcmp(students[i].registration_number, regNum) == 0) {
            // Check if grades are not calculated yet
            if (students[i].grades.mark == -1) {
                printf("Enter marks (0-100): ");
                scanf("%d", &students[i].grades.mark);

                // Calculate grades based on the grading system
                if (students[i].grades.mark > 69)
                    students[i].grades.the_grade = 'A';
                else if (students[i].grades.mark > 59)
                    students[i].grades.the_grade = 'B';
                else if (students[i].grades.mark > 49)
                    students[i].grades.the_grade = 'C';
                else if (students[i].grades.mark > 39)
                    students[i].grades.the_grade = 'D';
                else
                    students[i].grades.the_grade = 'E';

                printf("Grades calculated and added successfully.\n");
            } else {
                printf("Grades for this student already calculated and cannot be altered.\n");
            }
            return;
        }
    }

    printf("Student with registration number %s not found.\n", regNum);
}

void displayStudentDetails(struct Student students[], int studentCount) {
    if (studentCount > 0) {
        printf("\nStudent Details:\n");
        for (int i = 0; i < studentCount; ++i) {
            printf("\nName: %s\n", students[i].name);
            printf("Registration Number: %s\n", students[i].registration_number);
            printf("Course Code: %s\n", students[i].course.course_code);
            printf("Course Name: %s\n", students[i].course.course_name);

            if (students[i].grades.mark != -1) {
                printf("Marks: %d\n", students[i].grades.mark);
                printf("Grade: %c\n", students[i].grades.the_grade);
            } else {
                printf("Marks and Grade not available\n");
            }
        }
    } else {
        printf("No students available.\n");
    }
}
