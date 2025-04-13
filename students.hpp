#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <vector>
#include <optional>

class Student {
    int rollNo;
    std::string name;
    int engMarks, mathMarks, sciMarks, lang2Marks, csMarks;
    double average;
    char grade;

    void calculate();

public:
    Student(int rollNo, const std::string& name, int eng, int math, int sci, int lang2, int cs);
    
    void showData() const;
    int getRollNo() const;
    void updateMarks(int eng, int math, int sci, int lang2, int cs);

    static void displayAll(const std::vector<Student>& students);
    static std::optional<std::reference_wrapper<Student>> searchStudent(std::vector<Student>& students, int rollNo);
    static void deleteStudent(std::vector<Student>& students, int rollNo);
    static void modifyStudent(std::vector<Student>& students, int rollNo);
    static void displayTopPerformers(const std::vector<Student>& students);
};

#endif /* STUDENT_HPP */
