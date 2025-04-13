# Student Records Management System

A C++ console-based application that manages student records with Create, Read, Update, and Delete (CRUD) operations. This project demonstrates file handling, object-oriented programming (OOP) principles, and basic data management techniques.

## Features

- **Add Student Records**: Input student details like name, roll number, and marks.
- **Display All Records**: View all stored student records in a formatted output.
- **Search Student Records**: Find a specific student by their roll number.
- **Delete Student Records**: Remove a student's data from the system.
- **Modify Student Records**: Update existing student information.
- **File Handling**: Records are saved and loaded using file operations for persistent storage.

## Prerequisites

To run this project, you need a C++ compiler like:

- [GCC](https://gcc.gnu.org/)
- [MinGW](http://www.mingw.org/) (for Windows)
- [Clang](https://clang.llvm.org/)
- Any C++ IDE like [Code::Blocks](http://www.codeblocks.org/), [Dev-C++](https://sourceforge.net/projects/orwelldevcpp/), [Visual Studio](https://visualstudio.microsoft.com/), etc.

## Getting Started

1. Clone the repository:
   ```bash
   git clone https://github.com/iNoles/StudentReports.git
   ```
2. Navigate to the project directory:
   ```bash
   cd StudentReports
   ```
3. Compile the source code:
   ```bash
   g++ -o student_reports main.cpp students.cpp students.hpp
   ```
## How to Run
After building the project, execute the program with:
```bash
./student_reports
```
