#include "students.hpp"
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
    } while (choice != '7');
    return 0;
}

void displayMenu() {
    std::cout << "\n====================================";
    std::cout << "\n\t STUDENT MANAGEMENT SYSTEM";
    std::cout << "\n====================================";
    std::cout << "\n 1.Create Student Record";
    std::cout << "\n 2.Search Student Record";
    std::cout << "\n 3. Display All Student Records";
    std::cout << "\n 4. Delete Student Record";
    std::cout << "\n 5. Modify Student Record";
    std::cout << "\n 6. Display Top 3 Performers";
    std::cout << "\n 7. Exit";
    std::cout << "\n====================================";
    std::cout << "\nEnter your choice: ";
}


void createStudent(std::vector<Student>& students) {
    int rollNo, eng, math, sci, lang2, cs;
    std::string name;

    std::cout << "\nEnter roll number: ";
    std::cin >> rollNo;
    std::cin.ignore();
    std::cout << "Enter student name: ";
    std::getline(std::cin, name);
    std::cout << "Enter marks for English, Math, Science, 2nd Language, and Computer Science:\n";
    std::cin >> eng >> math >> sci >> lang2 >> cs;

    students.emplace_back(rollNo, name, eng, math, sci, lang2, cs);
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
            if (auto studOpt = Student::searchStudent(students, rollNo)) {
                studOpt->get().showData();
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
            Student::displayTopPerformers(students);
            break;
        case '7':
            std::cout << "Exiting, thank you!\n";
            break;
        default:
            std::cout << "\nInvalid choice! Please try again.\n";
    }
}
