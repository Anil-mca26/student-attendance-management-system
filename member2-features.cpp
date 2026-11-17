#include "attendance.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

// Feature 4: Search Student Attendance by Roll Number
void searchStudentByRoll(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo records available to search.\n";
        return;
    }

    int targetRoll;
    std::cout << "\n--- Search Student Attendance ---\n";
    std::cout << "Enter Roll Number to search: ";
    std::cin >> targetRoll;

    for (const auto& s : students) {
        if (s.rollNo == targetRoll) {
            double pct = (s.totalClasses > 0) ? (s.attendedClasses * 100.0 / s.totalClasses) : 0.0;
            std::cout << "\nRecord Found:\n";
            std::cout << "Roll Number : " << s.rollNo << "\n";
            std::cout << "Name        : " << s.name << "\n";
            std::cout << "Department  : " << s.department << "\n";
            std::cout << "Attendance  : " << s.attendedClasses << " / " << s.totalClasses
                      << " (" << std::fixed << std::setprecision(2) << pct << "%)\n";
            return;
        }
    }
    std::cout << "No student found with Roll Number " << targetRoll << ".\n";
}git add member2_features.cpp