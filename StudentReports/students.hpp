#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

class Student {
private:
    int rollNo;
    std::string name;
    int engMarks, mathMarks, sciMarks, lang2Marks, csMarks;
    double average;
    char grade;

    void calculateGrade();

public:
    Student();
    void inputData();
    void displayData() const;
    int getRollNo() const;
    void updateData();

    // JSON/Serialization features can be added here for advanced storage options
};

#endif // STUDENT_HPP
