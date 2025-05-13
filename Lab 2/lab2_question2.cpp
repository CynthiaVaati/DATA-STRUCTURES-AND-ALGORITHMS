#include <iostream>
#include <string>
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

    void display() const {
        cout << course_code << " - " << course_name;
    }
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

    void display() const {
        cout << "Mark: " << mark << ", Grade: " << the_grade;
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
    Student() {}

    Student(string r, string n, int a, Course c) : regNo(r), name(n), age(a), course(c) {}

    
    void setRegNo(string r) { regNo = r; }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setCourse(Course c) { course = c; }
    void setGrade(Grade g) { grade = g; }
    void setMark(int m) { grade.setMark(m); } 

    
    string getRegNo() const { return regNo; }
    string getName() const { return name; }
    int getAge() const { return age; }
    Course getCourse() const { return course; }
    Grade getGrade() const { return grade; }
    int getMark() const { return grade.getMark(); }

    
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

    
    bool equals(const Student& other) const {
        return regNo == other.regNo;
    }
};


int main() {
    Course c1("CSC101", "Intro to Computer Science");

    Student s1("S001", "Alice", 20, c1);
    s1.setMark(75); // Grade = A

    Student s2("S002", "Bob", 21, c1);
    s2.setMark(63); // Grade = B

    Student s3("S003", "Carol", 22, c1);
    s3.setMark(49); // Grade = D

    cout << "Student Records:\n";
    s1.display();
    s2.display();
    s3.display();

    return 0;
}
