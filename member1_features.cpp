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

// Feature 2: Mark Daily Attendance
void markAttendance(std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo students registered yet. Please add students first.\n";
        return;
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::string date;
    std::cout << "\n--- Mark Daily Attendance ---\n";
    std::cout << "Enter Date (DD-MM-YYYY): ";
    std::getline(std::cin, date);

    std::cout << "Enter 1 for Present, 0 for Absent:\n";
    for (auto& s : students) {
        int status;
        std::cout << "Roll " << s.rollNo << " (" << s.name << "): ";
        std::cin >> status;

        s.totalClasses += 1;
        if (status == 1) {
            s.attendedClasses += 1;
        }
    }

    saveRecordsToFile(students);
    std::cout << "Attendance recorded for " << date << "!\n";
}