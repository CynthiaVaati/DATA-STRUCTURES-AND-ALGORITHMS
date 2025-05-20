#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structs for Course and Grade
typedef struct {
    char course_code[20];
    char course_name[50];
} Course;

typedef struct {
    int mark;
    char the_grade;
} Grade;

// Struct for Student
typedef struct Student {
    char regNo[20];
    char name[50];
    int age;
    Course course;
    Grade grade;
    struct Student* next;
} Student;

// Function to create a student node
Student* createStudent(char* regNo, char* name, int age, Course course) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->regNo, regNo);
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->course = course;
    newStudent->grade.mark = 0;
    newStudent->grade.the_grade = ' ';
    newStudent->next = NULL;
    return newStudent;
}

// Add student to end of list
void addStudent(Student** head, Student* newStudent) {
    if (*head == NULL) {
        *head = newStudent;
    } else {
        Student* temp = *head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newStudent;
    }
}

// Set mark and calculate grade
void setMarkAndCalculateGrade(Student* s, int mark) {
    s->grade.mark = mark;
    if (mark > 69) s->grade.the_grade = 'A';
    else if (mark > 59) s->grade.the_grade = 'B';
    else if (mark > 49) s->grade.the_grade = 'C';
    else if (mark > 39) s->grade.the_grade = 'D';
    else s->grade.the_grade = 'E';
}

// Display all students
void displayStudents(Student* head) {
    Student* temp = head;
    int i = 1;
    while (temp != NULL) {
        printf("%d. RegNo: %s, Name: %s, Age: %d, Course: %s - %s, Mark: %d, Grade: %c\n",
               i++, temp->regNo, temp->name, temp->age,
               temp->course.course_code, temp->course.course_name,
               temp->grade.mark, temp->grade.the_grade);
        temp = temp->next;
    }
}

// Free memory
void destroyList(Student* head) {
    Student* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// ---------------- MAIN ----------------
int main() {
    Student* studentList = NULL;
    Course c = {"CSC101", "Intro to Programming"};

    // Create and add 15 students
    for (int i = 1; i <= 15; i++) {
        char reg[10], name[20];
        sprintf(reg, "S%d", 100 + i);
        sprintf(name, "Student%d", i);
        Student* s = createStudent(reg, name, 18 + i % 5, c);
        addStudent(&studentList, s);
    }

    // Update marks and calculate grades
    Student* temp = studentList;
    int mark = 35;
    while (temp != NULL) {
        setMarkAndCalculateGrade(temp, mark);
        mark += 4;
        if (mark > 100) mark = 100;
        temp = temp->next;
    }

    // Display list
    printf("=== Linked List of Students ===\n");
    displayStudents(studentList);

    destroyList(studentList);
    return 0;
}
