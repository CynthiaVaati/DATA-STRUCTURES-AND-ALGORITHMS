class Course:
    def __init__(self, code, name):
        self.course_code = code
        self.course_name = name

class Grade:
    def __init__(self):
        self.mark = 0
        self.the_grade = ' '

    def set_mark(self, mark):
        self.mark = mark
        if mark > 69:
            self.the_grade = 'A'
        elif mark > 59:
            self.the_grade = 'B'
        elif mark > 49:
            self.the_grade = 'C'
        elif mark > 39:
            self.the_grade = 'D'
        else:
            self.the_grade = 'E'

class Student:
    def __init__(self, reg_no, name, age, course):
        self.reg_no = reg_no
        self.name = name
        self.age = age
        self.course = course
        self.grade = Grade()

    def set_mark(self, mark):
        self.grade.set_mark(mark)

    def display(self):
        print(f"RegNo: {self.reg_no}, Name: {self.name}, Age: {self.age}, "
              f"Course: {self.course.course_code} - {self.course.course_name}, "
              f"Mark: {self.grade.mark}, Grade: {self.grade.the_grade}")

class StudentList:
    def __init__(self):
        self.capacity = 40
        self.students = [None] * self.capacity
        self.size = 0

    def add(self, student):
        if self.size < self.capacity:
            self.students[self.size] = student
            self.size += 1

    def display_all(self):
        for i in range(self.size):
            self.students[i].display()

# ------------------ Driver ------------------
if __name__ == "__main__":
    slist = StudentList()
    c = Course("CSC101", "Intro to Programming")

    for i in range(15):
        s = Student(f"S{100 + i + 1}", f"Student{i + 1}", 18 + (i % 5), c)
        slist.add(s)

    mark = 35
    for i in range(slist.size):
        slist.students[i].set_mark(mark)
        mark += 4
        if mark > 100:
            mark = 100

    print("=== Python Student List ===")
    slist.display_all()
