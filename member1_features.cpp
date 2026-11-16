#include "attendance.h"
#include <iostream>
#include <iomanip>
#include <limits>

// Feature 1: Add / Register New Student
void addStudent(std::vector<Student>& students) {
    Student s;
    std::cout << "\n--- Register New Student ---\n";
    std::cout << "Enter Roll Number: ";
    std::cin >> s.rollNo;

    for (const auto& existing : students) {
        if (existing.rollNo == s.rollNo) {
            std::cout << "Error: Student with Roll Number " << s.rollNo << " already exists!\n";
            return;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter Full Name: ";
    std::getline(std::cin, s.name);
    std::cout << "Enter Department: ";
    std::getline(std::cin, s.department);

    s.totalClasses = 0;
    s.attendedClasses = 0;
    students.push_back(s);
    saveRecordsToFile(students);
    std::cout << "Student registered successfully!\n";
}

