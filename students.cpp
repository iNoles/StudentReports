#include "students.hpp"
#include <iomanip>
#include <algorithm>

void Student::calculate() {
    average = (engMarks + mathMarks + sciMarks + lang2Marks + csMarks) / 5.0;
    grade = (average >= 90) ? 'A' :
            (average >= 75) ? 'B' :
            (average >= 50) ? 'C' : 'F';
}

Student::Student(int r, const std::string& n, int eng, int math, int sci, int lang2, int cs)
    : rollNo(r), name(n), engMarks(eng), mathMarks(math), sciMarks(sci), lang2Marks(lang2), csMarks(cs) {
    calculate();
}

void Student::showData() const {
    std::cout << "\nRoll No: " << rollNo
              << "\nName: " << name
              << "\nEnglish: " << engMarks
              << "\nMath: " << mathMarks
              << "\nScience: " << sciMarks
              << "\n2nd Language: " << lang2Marks
              << "\nComputer Science: " << csMarks
              << "\nAverage: " << std::fixed << std::setprecision(2) << average
              << "\nGrade: " << grade << '\n';
}

int Student::getRollNo() const {
    return rollNo;
}

void Student::updateMarks(int eng, int math, int sci, int lang2, int cs) {
    if (eng < 0 || eng > 100 || math < 0 || math > 100 || sci < 0 || sci > 100 || lang2 < 0 || lang2 > 100 || cs < 0 || cs > 100) {
        std::cout << "\nInvalid marks entered. Please enter marks between 0 and 100.\n";
        return;
    }
    engMarks = eng;
    mathMarks = math;
    sciMarks = sci;
    lang2Marks = lang2;
    csMarks = cs;
    calculate();
}

void Student::displayAll(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo student records available.\n";
        return;
    }
    for (const auto& stud : students) {
        stud.showData();
        std::cout << "\n====================================\n";
    }
}

std::optional<std::reference_wrapper<Student>> Student::searchStudent(std::vector<Student>& students, int rollNo) {
    auto it = std::find_if(students.begin(), students.end(), [&](const Student& s) {
        return s.getRollNo() == rollNo;
    });

    if (it != students.end()) return *it;

    std::cout << "\nRecord not found for Roll No: " << rollNo << ".\n";
    return std::nullopt;
}

void Student::deleteStudent(std::vector<Student>& students, int rollNo) {
    auto beforeSize = students.size();
    std::erase_if(students, [&](const Student& s) { return s.getRollNo() == rollNo; });
    
    if (students.size() < beforeSize) {
        std::cout << "\nRecord deleted.\n";
    } else {
        std::cout << "\nRecord not found.\n";
    }
}

void Student::modifyStudent(std::vector<Student>& students, int rollNo) {
    auto studOpt = searchStudent(students, rollNo);
    if (studOpt) {
        Student& stud = studOpt.value();
        std::cout << "\nEnter new marks for English, Math, Science, 2nd Language, and Computer Science:\n";
        int eng, math, sci, lang2, cs;
        std::cin >> eng >> math >> sci >> lang2 >> cs;
        stud.updateMarks(eng, math, sci, lang2, cs);
        std::cout << "\nRecord updated.\n";
    }
}

void Student::displayTopPerformers(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo student records available.\n";
        return;
    }

    std::vector<Student> sortedStudents = students;
    std::sort(sortedStudents.begin(), sortedStudents.end(), [](const Student& a, const Student& b) {
        return a.average > b.average; // Sort in descending order
    });

    int limit = std::min(3, static_cast<int>(sortedStudents.size())); // Handle cases with <3 students

    std::cout << "\n====================================";
    std::cout << "\n\t🏆 TOP " << limit << " PERFORMERS 🏆";
    std::cout << "\n====================================\n";

    for (int i = 0; i < limit; i++) {
        std::cout << "Rank #" << (i + 1) << " (" << sortedStudents[i].grade << "):\n";
        sortedStudents[i].showData();  // Display full student data
        std::cout << "\n------------------------------------\n";
    }
}
