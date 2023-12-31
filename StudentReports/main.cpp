//
//  main.cpp
//  StudentReports
//
//  Created by Jonathan Steele on 6/22/23.
//

#include "students.hpp"
#include <iostream>
#include<fstream>

using namespace std;

//function declaration
void displayMenu();
void create_student();
void display_sp(int);//display particular record
void display_all(); // display all records
void delete_student(int);//delete particular record
void change_student(int);//edit particular record

int main(int argc, const char * argv[]) {
    displayMenu();
    return 0;
}

void displayMenu() {
    char ch;
    int num;
    cout<<"\n\n\n\tMENU";
    cout<<"\n\n\t1.Create student record";
    cout<<"\n\n\t2. Search student record";
    cout<<"\n\n\t3. Display all students records ";
    cout<<"\n\n\t4.Delete student record";
    cout<<"\n\n\t5.Modify student record";
    cout<<"\n\n\t6.Exit";
    cout<<"\n\n\tWhat is your Choice (1/2/3/4/5/6)\n";
    cin>>ch;
    switch(ch) {
        case '1':
            create_student();
            displayMenu();
            break;
        case '2':
            cout<<"\n\n\tEnter The roll number ";
            cin>>num;
            display_sp(num);
            displayMenu();
            break;
        case '3':
            display_all();
            break;
        case '4':
            cout<<"\n\n\tEnter The roll number: ";
            cin>>num;
            delete_student(num);
            displayMenu();
            break;
        case '5':
            cout<<"\n\n\tEnter The roll number ";
            cin>>num;
            change_student(num);
            displayMenu();
            break;
        case '6':
            cout<<"Exiting, Thank you!";
            exit(0);
    }
}

//write student details to file
void create_student() {
    student stud;
    ofstream oFile;
    oFile.open("student.dat",ios::binary|ios::app);
    stud.getdata();
    oFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
    oFile.close();
    cout<<"\n\nStudent record Has Been Created ";
    cin.ignore();
    cin.get();
}

// read file records
void display_all() {
    student stud;
    ifstream inFile;
    inFile.open("student.dat",ios::binary);
    if(!inFile) {
        cout<<"File could not be opened !! Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    cout<<"\n\n\n\t\tDISPLAYING ALL RECORDS\n\n";
    while(inFile.read(reinterpret_cast<char *> (&stud), sizeof(student))) {
        stud.showdata();
        cout<<"\n\n====================================\n";
    }
    inFile.close();
    cin.ignore();
    cin.get();
}

//read specific record based on roll number
void display_sp(int n) {
    student stud;
    ifstream iFile;
    iFile.open("student.dat",ios::binary);
    if(!iFile) {
        cout<<"File could not be opened... Press any Key to exit";
        cin.ignore();
        cin.get();
        return;
    }
    bool flag=false;
    while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(student))) {
        if(stud.retrollno()==n) {
            stud.showdata();
            flag=true;
        }
    }
    iFile.close();
    if(flag==false)
        cout<<"\n\nrecord does not exist";
    cin.ignore();
    cin.get();
}

// modify record for specified roll number
void change_student(int n) {
    bool found=false;
    student stud;
    fstream fl;
    fl.open("student.dat",ios::binary|ios::in|ios::out);
    if(!fl) {
        cout<<"File could not be opened. Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    while(!fl.eof() && found==false) {
        fl.read(reinterpret_cast<char *> (&stud), sizeof(student));
        if(stud.retrollno()==n) {
            stud.showdata();
            cout<<"\n\Enter new student details:"<<endl;
            stud.getdata();
            int pos=(-1)*static_cast<int>(sizeof(stud));
            fl.seekp(pos,ios::cur);
            fl.write(reinterpret_cast<char *> (&stud), sizeof(student));
            cout<<"\n\n\t Record Updated";
            found=true;
        }
    }
    fl.close();
    if(found==false)
        cout<<"\n\n Record Not Found ";
    cin.ignore();
    cin.get();
}

//delete record with particular roll number
void delete_student(int n) {
    student stud;
    ifstream iFile;
    iFile.open("student.dat",ios::binary);
    if(!iFile) {
        cout<<"File could not be opened... Press any Key to exit...";
        cin.ignore();
        cin.get();
        return;
    }
    ofstream oFile;
    oFile.open("Temp.dat",ios::out);
    iFile.seekg(0,ios::beg);
    while(iFile.read(reinterpret_cast<char *> (&stud), sizeof(student))) {
        if(stud.retrollno()!=n) {
            oFile.write(reinterpret_cast<char *> (&stud), sizeof(student));
        }
    }
    oFile.close();
    iFile.close();
    remove("student.dat");
    rename("Temp.dat","student.dat");
    cout<<"\n\n\tRecord Deleted ..";
    cin.ignore();
    cin.get();
}
