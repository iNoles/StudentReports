#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <vector>

class Student {
    int rollNo;
    std::string name;
    int engMarks, mathMarks, sciMarks, lang2Marks, csMarks;
    double average;
    char grade;

    void calculate();

public:
    void getData();
    void showData() const;
    int getRollNo() const;
    static void displayAll(const std::vector<Student>& students);
    static Student* searchStudent(std::vector<Student>& students, int rollNo);
    static void deleteStudent(std::vector<Student>& students, int rollNo);
    static void modifyStudent(std::vector<Student>& students, int rollNo);
};

#endif /* STUDENT_HPP */
