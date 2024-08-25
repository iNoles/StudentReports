#include "student.hpp"
#include <iostream>
#include <iomanip>

void Student::calculateGrade() {
    average = (engMarks + mathMarks + sciMarks + lang2Marks + csMarks) / 5.0;
    if (average >= 90) grade = 'A';
    else if (average >= 75) grade = 'B';
    else if (average >= 50) grade = 'C';
    else grade = 'F';
}

Student::Student() : rollNo(0), engMarks(0), mathMarks(0), sciMarks(0), lang2Marks(0), csMarks(0), average(0.0), grade('F') {}

void Student::inputData() {
    std::cout << "Enter student's roll number: ";
    std::cin >> rollNo;
    std::cin.ignore(); // Clear input buffer
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter marks (out of 100) for English: ";
    std::cin >> engMarks;
    std::cout << "Enter marks for Math: ";
    std::cin >> mathMarks;
    std::cout << "Enter marks for Science: ";
    std::cin >> sciMarks;
    std::cout << "Enter marks for 2nd Language: ";
    std::cin >> lang2Marks;
    std::cout << "Enter marks for Computer Science: ";
    std::cin >> csMarks;
    calculateGrade();
}

void Student::displayData() const {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\nStudent Roll No: " << rollNo;
    std::cout << "\nName: " << name;
    std::cout << "\nEnglish: " << engMarks;
    std::cout << "\nMath: " << mathMarks;
    std::cout << "\nScience: " << sciMarks;
    std::cout << "\n2nd Language: " << lang2Marks;
    std::cout << "\nComputer Science: " << csMarks;
    std::cout << "\nAverage Marks: " << average;
    std::cout << "\nGrade: " << grade << "\n";
}

int Student::getRollNo() const {
    return rollNo;
}

void Student::updateData() {
    inputData(); // Allows updating the student’s data
}
