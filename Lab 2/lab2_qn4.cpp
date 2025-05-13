#include <iostream>
#include <string>
using namespace std;


class Grade {
private:
    int mark;
    char the_grade;
public:
    Grade() : mark(0), the_grade(' ') {}

    void setMark(int m) { mark = m; }
    int getMark() const { return mark; }
    void setGradeChar(char g) { the_grade = g; }
    char getGradeChar() const { return the_grade; }

    void display() const {
        cout << "Mark: " << mark << ", Grade: " << the_grade;
    }
};


class Course {
private:
    string course_code;
    string course_name;
public:
    Course(string code = "", string name = "") : course_code(code), course_name(name) {}

    void setCourseCode(string code) { course_code = code; }
    void setCourseName(string name) { course_name = name; }
    string getCourseCode() const { return course_code; }
    string getCourseName() const { return course_name; }

    void display() const {
        cout << course_code << " - " << course_name;
    }
};


class Student {
private:
    string regNo;
    string name;
    int age;
    Course course;
    Grade grade;
public:
    Student(string r = "", string n = "", int a = 0, Course c = Course())
        : regNo(r), name(n), age(a), course(c) {}

    void setMark(int m) { grade.setMark(m); }

    void calculate_grade() {
        int m = grade.getMark();
        char g;
        if (m > 69) g = 'A';
        else if (m > 59) g = 'B';
        else if (m > 49) g = 'C';
        else if (m > 39) g = 'D';
        else g = 'E';
        grade.setGradeChar(g);
    }

    void display() const {
        cout << "RegNo: " << regNo 
             << ", Name: " << name 
             << ", Age: " << age 
             << ", Course: ";
        course.display();
        cout << ", ";
        grade.display();
        cout << endl;
    }
};


class StudentList {
private:
    static const int MAX = 40;
    Student students[MAX];
    int size;
public:
    StudentList() : size(0) {}

    void addStudent(const Student& s) {
        if (size < MAX) {
            students[size++] = s;
        } else {
            cout << "List is full!" << endl;
        }
    }

    Student& getStudent(int index) {
        return students[index];
    }

    int getSize() const {
        return size;
    }

    void displayAll() const {
        for (int i = 0; i < size; i++) {
            cout << i + 1 << ". ";
            students[i].display();
        }
    }
};


int main() {
    StudentList studentList;
    Course commonCourse("CSC101", "Intro to Programming");

    
    for (int i = 1; i <= 15; ++i) {
        string reg = "S" + to_string(100 + i);
        string name = "Student" + to_string(i);
        int age = 18 + (i % 5); // Vary age slightly
        Student s(reg, name, age, commonCourse);
        studentList.addStudent(s);
    }

    
    for (int i = 0; i < studentList.getSize(); ++i) {
        int mark = 35 + (i * 4);
        if (mark > 100) mark = 100;
        studentList.getStudent(i).setMark(mark);
        studentList.getStudent(i).calculate_grade();
    }

    
    cout << "==== List of Students with Calculated Grades ====" << endl;
    studentList.displayAll();

    return 0;
}
