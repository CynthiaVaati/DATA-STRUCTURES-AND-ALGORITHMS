#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Course {
private:
    string course_code;
    string course_name;
public:
    Course() {}
    Course(string code, string name) : course_code(code), course_name(name) {}

    void setCourseCode(string code) { course_code = code; }
    void setCourseName(string name) { course_name = name; }
    string getCourseCode() const { return course_code; }
    string getCourseName() const { return course_name; }
};


class Grade {
private:
    int mark;
    char the_grade;
public:
    Grade() : mark(-1), the_grade(' ') {}

    void setMark(int m) {
        mark = m;
        if (m > 69) the_grade = 'A';
        else if (m > 59) the_grade = 'B';
        else if (m > 49) the_grade = 'C';
        else if (m > 39) the_grade = 'D';
        else the_grade = 'E';
    }

    int getMark() const { return mark; }
    char getGrade() const { return the_grade; }
};


class Student {
private:
    string regNo;
    string name;
    int age;
    Course course;
    Grade grade;
public:
    Student() {}

    Student(string reg, string n, int a, Course c) {
        regNo = reg;
        name = n;
        age = a;
        course = c;
    }

    void setRegNo(string reg) { regNo = reg; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setCourse(Course c) { course = c; }
    void setGrade(Grade g) { grade = g; }

    string getRegNo() const { return regNo; }
    string getName() const { return name; }
    int getAge() const { return age; }
    Course getCourse() const { return course; }
    Grade getGrade() const { return grade; }

    void setMark(int mark) {
        grade.setMark(mark);
    }

    void display() const {
        cout << "Reg No: " << regNo << "\n"
             << "Name: " << name << "\n"
             << "Age: " << age << "\n"
             << "Course: " << course.getCourseCode() << " - " << course.getCourseName() << "\n"
             << "Mark: " << grade.getMark() << "\n"
             << "Grade: " << grade.getGrade() << "\n"
             << "-------------------------\n";
    }
};


int main() {
    vector<Student> students;

    
    for (int i = 0; i < 5; ++i) {
        string reg = "S" + to_string(100 + i);
        string name = "Student_" + to_string(i + 1);
        int age = 18 + i;
        Course c("CSC101", "Intro to CS");

        Student s(reg, name, age, c);

        int mark = 50 + (i * 5); 
        s.setMark(mark);

        students.push_back(s);
    }

    
    for (const auto& student : students) {
        student.display();
    }

    return 0;
}
