#include "Student.hpp"
#include <iostream>
#include <vector>

void displayMenu();
void createStudent(std::vector<Student>& students);
void handleChoice(std::vector<Student>& students, char choice);

int main() {
    std::vector<Student> students;
    char choice;
    do {
        displayMenu();
        std::cin >> choice;
        handleChoice(students, choice);
    } while (choice != '6');
    return 0;
}

void displayMenu() {
    std::cout << "\n\n\n\tMENU"
              << "\n\n1. Create student record"
              << "\n2. Search student record"
              << "\n3. Display all student records"
              << "\n4. Delete student record"
              << "\n5. Modify student record"
              << "\n6. Exit"
              << "\n\nYour choice: ";
}

void createStudent(std::vector<Student>& students) {
    Student stud;
    stud.getData();
    students.push_back(stud);
    std::cout << "\nStudent record has been created.\n";
}

void handleChoice(std::vector<Student>& students, char choice) {
    int rollNo;
    switch (choice) {
        case '1':
            createStudent(students);
            break;
        case '2':
            std::cout << "\nEnter roll number: ";
            std::cin >> rollNo;
            if (Student* stud = Student::searchStudent(students, rollNo)) {
                stud->showData();
            }
            break;
        case '3':
            Student::displayAll(students);
            break;
        case '4':
            std::cout << "\nEnter roll number: ";
            std::cin >> rollNo;
            Student::deleteStudent(students, rollNo);
            break;
        case '5':
            std::cout << "\nEnter roll number: ";
            std::cin >> rollNo;
            Student::modifyStudent(students, rollNo);
            break;
        case '6':
            std::cout << "Exiting, thank you!\n";
            break;
        default:
            std::cout << "\nInvalid choice! Please try again.\n";
    }
}
