#include "Student.hpp"
#include <iostream>
#include <iomanip>
#include <algorithm>

void Student::calculate() {
    average = (engMarks + mathMarks + sciMarks + lang2Marks + csMarks) / 5.0;
    if (average >= 90) grade = 'A';
    else if (average >= 75) grade = 'B';
    else if (average >= 50) grade = 'C';
    else grade = 'F';
}

void Student::getData() {
    std::cout << "\nEnter student's roll number: ";
    std::cin >> rollNo;
    std::cin.ignore();
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter marks for English, Math, Science, 2nd Language, and Computer Science (out of 100):\n";
    std::cin >> engMarks >> mathMarks >> sciMarks >> lang2Marks >> csMarks;
    calculate();
}

void Student::showData() const {
    std::cout << "\nRoll number: " << rollNo
              << "\nName: " << name
              << "\nEnglish: " << engMarks
              << "\nMath: " << mathMarks
              << "\nScience: " << sciMarks
              << "\n2nd Language: " << lang2Marks
              << "\nComputer Science: " << csMarks
              << "\nAverage: " << average
              << "\nGrade: " << grade << '\n';
}

int Student::getRollNo() const {
    return rollNo;
}

void Student::displayAll(const std::vector<Student>& students) {
    for (const auto& stud : students) {
        stud.showData();
        std::cout << "\n====================================\n";
    }
}

Student* Student::searchStudent(std::vector<Student>& students, int rollNo) {
    auto it = std::find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getRollNo() == rollNo;
    });
    if (it != students.end()) return &(*it);
    std::cout << "\nRecord not found.\n";
    return nullptr;
}

void Student::deleteStudent(std::vector<Student>& students, int rollNo) {
    auto it = std::remove_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getRollNo() == rollNo;
    });
    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "\nRecord deleted.\n";
    } else {
        std::cout << "\nRecord not found.\n";
    }
}

void Student::modifyStudent(std::vector<Student>& students, int rollNo) {
    Student* stud = searchStudent(students, rollNo);
    if (stud) {
        std::cout << "\nEnter new details:\n";
        stud->getData();
        std::cout << "\nRecord updated.\n";
    }
}
