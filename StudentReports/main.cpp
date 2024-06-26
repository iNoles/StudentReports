//  main.cpp
//  StudentReports
//
//  Created by Jonathan Steele on 6/22/23.
//

#include "students.hpp"
#include <iostream>
#include <fstream>

using namespace std;

// Function declarations
void displayMenu();
void create_student();
void display_sp(int); // Display particular record
void display_all();   // Display all records
void delete_student(int); // Delete particular record
void change_student(int); // Edit particular record

int main() {
    displayMenu();
    return 0;
}

void displayMenu() {
    char ch;
    int num;
    do {
        cout << "\n\n\n\tMENU";
        cout << "\n\n\t1. Create student record";
        cout << "\n\n\t2. Search student record";
        cout << "\n\n\t3. Display all student records";
        cout << "\n\n\t4. Delete student record";
        cout << "\n\n\t5. Modify student record";
        cout << "\n\n\t6. Exit";
        cout << "\n\n\tWhat is your choice (1/2/3/4/5/6)? ";
        cin >> ch;

        switch (ch) {
            case '1':
                create_student();
                break;
            case '2':
                cout << "\n\n\tEnter the roll number: ";
                cin >> num;
                display_sp(num);
                break;
            case '3':
                display_all();
                break;
            case '4':
                cout << "\n\n\tEnter the roll number: ";
                cin >> num;
                delete_student(num);
                break;
            case '5':
                cout << "\n\n\tEnter the roll number: ";
                cin >> num;
                change_student(num);
                break;
            case '6':
                cout << "Exiting, thank you!";
                break;
            default:
                cout << "\n\n\tInvalid choice! Please try again.";
        }
    } while (ch != '6');
}

// Write student details to file
void create_student() {
    student stud;
    ofstream oFile("student.dat", ios::binary | ios::app);
    if (!oFile) {
        cout << "File could not be opened! Press any key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    stud.getdata();
    oFile.write(reinterpret_cast<char*>(&stud), sizeof(student));
    oFile.close();
    cout << "\n\nStudent record has been created.";
    cin.ignore();
    cin.get();
}

// Read and display all records
void display_all() {
    student stud;
    ifstream inFile("student.dat", ios::binary);
    if (!inFile) {
        cout << "File could not be opened! Press any key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    cout << "\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
    while (inFile.read(reinterpret_cast<char*>(&stud), sizeof(student))) {
        stud.showdata();
        cout << "\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

// Read and display specific record based on roll number
void display_sp(int n) {
    student stud;
    ifstream iFile("student.dat", ios::binary);
    if (!iFile) {
        cout << "File could not be opened! Press any key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    bool found = false;
    while (iFile.read(reinterpret_cast<char*>(&stud), sizeof(student))) {
        if (stud.retrollno() == n) {
            stud.showdata();
            found = true;
        }
    }
    iFile.close();
    if (!found) {
        cout << "\n\nRecord does not exist.";
    }
    cin.ignore();
    cin.get();
}

// Modify record for specified roll number
void change_student(int n) {
    bool found = false;
    student stud;
    fstream fl("student.dat", ios::binary | ios::in | ios::out);
    if (!fl) {
        cout << "File could not be opened! Press any key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    while (!fl.eof() && !found) {
        fl.read(reinterpret_cast<char*>(&stud), sizeof(student));
        if (stud.retrollno() == n) {
            stud.showdata();
            cout << "\n\nEnter new student details:\n";
            stud.getdata();
            int pos = static_cast<int>(fl.tellp()) - sizeof(stud);
            fl.seekp(pos, ios::beg);
            fl.write(reinterpret_cast<char*>(&stud), sizeof(student));
            cout << "\n\n\tRecord updated.";
            found = true;
        }
    }
    fl.close();
    if (!found) {
        cout << "\n\nRecord not found.";
    }
    cin.ignore();
    cin.get();
}

// Delete record with particular roll number
void delete_student(int n) {
    student stud;
    ifstream iFile("student.dat", ios::binary);
    if (!iFile) {
        cout << "File could not be opened! Press any key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream oFile("Temp.dat", ios::binary);
    while (iFile.read(reinterpret_cast<char*>(&stud), sizeof(student))) {
        if (stud.retrollno() != n) {
            oFile.write(reinterpret_cast<char*>(&stud), sizeof(student));
        }
    }
    oFile.close();
    iFile.close();
    remove("student.dat");
    rename("Temp.dat", "student.dat");
    cout << "\n\n\tRecord deleted.";
    cin.ignore();
    cin.get();
}
