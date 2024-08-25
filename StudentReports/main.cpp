#include "student.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

void displayMenu();
void createStudent(std::vector<std::shared_ptr<Student>>& students);
void displayStudent(const std::vector<std::shared_ptr<Student>>& students, int rollNo);
void displayAllStudents(const std::vector<std::shared_ptr<Student>>& students);
void deleteStudent(std::vector<std::shared_ptr<Student>>& students, int rollNo);
void modifyStudent(std::vector<std::shared_ptr<Student>>& students, int rollNo);

int main() {
    try {
        std::vector<std::shared_ptr<Student>> students;
        displayMenu();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }
    return 0;
}

void displayMenu() {
    char choice;
    int rollNo;
    std::vector<std::shared_ptr<Student>> students;

    do {
        std::cout << "\n\n\t--- STUDENT MANAGEMENT SYSTEM ---";
        std::cout << "\n\n\t1. Create Student Record";
        std::cout << "\n\t2. Search Student Record";
        std::cout << "\n\t3. Display All Student Records";
        std::cout << "\n\t4. Delete Student Record";
        std::cout << "\n\t5. Modify Student Record";
        std::cout << "\n\t6. Exit";
        std::cout << "\n\n\tEnter your choice (1-6): ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                createStudent(students);
                break;
            case '2':
                std::cout << "\nEnter roll number: ";
                std::cin >> rollNo;
                displayStudent(students, rollNo);
                break;
            case '3':
                displayAllStudents(students);
                break;
            case '4':
                std::cout << "\nEnter roll number: ";
                std::cin >> rollNo;
                deleteStudent(students, rollNo);
                break;
            case '5':
                std::cout << "\nEnter roll number: ";
                std::cin >> rollNo;
                modifyStudent(students, rollNo);
                break;
            case '6':
                std::cout << "Exiting program...";
                break;
            default:
                std::cout << "Invalid choice! Please try again.";
        }
    } while (choice != '6');
}

void createStudent(std::vector<std::shared_ptr<Student>>& students) {
    auto stud = std::make_shared<Student>();
    stud->inputData();
    students.push_back(stud);
    std::cout << "\nStudent record created successfully.\n";
}

void displayStudent(const std::vector<std::shared_ptr<Student>>& students, int rollNo) {
    bool found = false;
    for (const auto& stud : students) {
        if (stud->getRollNo() == rollNo) {
            stud->displayData();
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "\nStudent record not found.\n";
    }
}

void displayAllStudents(const std::vector<std::shared_ptr<Student>>& students) {
    if (students.empty()) {
        std::cout << "\nNo student records available.\n";
    } else {
        std::cout << "\n\n\tDISPLAYING ALL RECORDS\n\n";
        for (const auto& stud : students) {
            stud->displayData();
            std::cout << "\n----------------------------------\n";
        }
    }
}

void deleteStudent(std::vector<std::shared_ptr<Student>>& students, int rollNo) {
    auto it = std::remove_if(students.begin(), students.end(),
                             [rollNo](const std::shared_ptr<Student>& stud) {
                                 return stud->getRollNo() == rollNo;
                             });
    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "\nStudent record deleted.\n";
    } else {
        std::cout << "\nStudent record not found.\n";
    }
}

void modifyStudent(std::vector<std::shared_ptr<Student>>& students, int rollNo) {
    bool found = false;
    for (auto& stud : students) {
        if (stud->getRollNo() == rollNo) {
            std::cout << "\nModifying student record:";
            stud->updateData();
            std::cout << "\nRecord updated successfully.\n";
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "\nStudent record not found.\n";
    }
}
