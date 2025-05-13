#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME 50
#define MAX_REGNO 20
#define MAX_COURSE_CODE 10
#define MAX_COURSE_NAME 50

// ---------- Course ADT ----------
typedef struct {
    char course_code[MAX_COURSE_CODE];
    char course_name[MAX_COURSE_NAME];
} Course;

// ---------- Grade ADT ----------
typedef struct {
    int mark;
    char the_grade;
} Grade;

// ---------- Student ADT ----------
typedef struct {
    char reg_no[MAX_REGNO];
    char name[MAX_NAME];
    int age;
    Course course;
    Grade grade;
} Student;

// ---------- Student List ----------
typedef struct {
    Student students[MAX_STUDENTS];
    int size;
} StudentList;
