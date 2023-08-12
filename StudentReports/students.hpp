//
//  students.hpp
//  StudentReports
//
//  Created by Jonathan Steele on 6/22/23.
//

#ifndef students_hpp
#define students_hpp

#include <stdio.h>

// the class that stores data
class student
{
    int rollno;
    char name[50];
    int eng_marks, math_marks, sci_marks, lang2_marks, cs_marks;
    double average;
    char grade;
public:
    void getdata();
    void showdata() const;
    void calculate();
    int retrollno() const;
}; //class ends here

#endif /* students_hpp */
