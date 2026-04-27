#include "students.hpp"
#include <iomanip>
#include <algorithm>
#include <limits>

// ----------------------
//  PRIVATE CALCULATIONS
// ----------------------
void Student::calculate() {
    average = (engMarks + mathMarks + sciMarks + lang2Marks + csMarks) / 5.0;
    grade = (average >= 90) ? 'A' :
            (average >= 75) ? 'B' :
            (average >= 50) ? 'C' : 'F';
}

// ----------------------
//  CONSTRUCTOR
// ----------------------
Student::Student(int r, const std::string& n, int eng, int math, int sci, int lang2, int cs)
    : rollNo(r), name(n), engMarks(eng), mathMarks(math), sciMarks(sci), lang2Marks(lang2), csMarks(cs) {
    calculate();
}

// ----------------------
//  DISPLAY SINGLE RECORD
// ----------------------
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

double Student::getAverage() const {
    return average;
}

// ----------------------
//  UPDATE MARKS
// ----------------------
bool Student::updateMarks(int eng, int math, int sci, int lang2, int cs) {
    if (eng < 0 || eng > 100 || math < 0 || math > 100 ||
        sci < 0 || sci > 100 || lang2 < 0 || lang2 > 100 ||
        cs < 0 || cs > 100) {
        std::cout << "\nInvalid marks entered. Please enter marks between 0 and 100.\n";
        return false;
    }

    engMarks = eng;
    mathMarks = math;
    sciMarks = sci;
    lang2Marks = lang2;
    csMarks = cs;
    calculate();
    return true;
}

// ----------------------
//  DISPLAY ALL RECORDS
// ----------------------
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

// ----------------------
//  SEARCH (NO PRINTING)
// ----------------------
std::optional<std::reference_wrapper<Student>> 
Student::searchStudent(std::vector<Student>& students, int rollNo) {

    auto it = std::find_if(students.begin(), students.end(),
                           [&](const Student& s) { return s.getRollNo() == rollNo; });

    if (it != students.end()) return *it;
    return std::nullopt;
}

// ----------------------
//  DELETE RECORD
// ----------------------
void Student::deleteStudent(std::vector<Student>& students, int rollNo) {
    auto beforeSize = students.size();
    std::erase_if(students, [&](const Student& s) { return s.getRollNo() == rollNo; });

    if (students.size() < beforeSize)
        std::cout << "\nRecord deleted.\n";
    else
        std::cout << "\nRecord not found.\n";
}

// ----------------------
//  MODIFY RECORD
// ----------------------
void Student::modifyStudent(std::vector<Student>& students, int rollNo) {
    auto studOpt = searchStudent(students, rollNo);
    if (!studOpt) {
        std::cout << "\nRecord not found.\n";
        return;
    }

    Student& stud = studOpt.value();

    std::cout << "\nEnter new marks for English, Math, Science, 2nd Language, and Computer Science:\n";

    int eng, math, sci, lang2, cs;
    if (!(std::cin >> eng >> math >> sci >> lang2 >> cs)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\nInvalid input. Marks must be numbers.\n";
        return;
    }

    if (stud.updateMarks(eng, math, sci, lang2, cs))
        std::cout << "\nRecord updated.\n";
}

// ----------------------
//  TOP 3 PERFORMERS
// ----------------------
void Student::displayTopPerformers(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo student records available.\n";
        return;
    }

    std::vector<std::reference_wrapper<const Student>> sorted;
    sorted.reserve(students.size());
    for (const auto& s : students) sorted.push_back(s);

    std::sort(sorted.begin(), sorted.end(),
              [](const Student& a, const Student& b) {
                  return a.average > b.average;
              });

    int limit = std::min(3, static_cast<int>(sorted.size()));

    std::cout << "\n====================================";
    std::cout << "\n\t🏆 TOP " << limit << " PERFORMERS 🏆";
    std::cout << "\n====================================\n";

    for (int i = 0; i < limit; i++) {
        std::cout << "Rank #" << (i + 1) << " (" << sorted[i].get().grade << "):\n";
        sorted[i].get().showData();
        std::cout << "\n------------------------------------\n";
    }
}
