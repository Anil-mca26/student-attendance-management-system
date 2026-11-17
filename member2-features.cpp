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
}

// Feature 5: Calculate Attendance Percentage & 75% Exam Eligibility Report
void generateEligibilityReport(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo students registered.\n";
        return;
    }

    std::cout << "\n==========================================================================\n";
    std::cout << std::left << std::setw(10) << "Roll No"
              << std::setw(22) << "Name"
              << std::setw(15) << "Percentage"
              << std::setw(20) << "Exam Status" << "\n";
    std::cout << "==========================================================================\n";

    for (const auto& s : students) {
        double pct = (s.totalClasses > 0) ? (s.attendedClasses * 100.0 / s.totalClasses) : 0.0;
        std::string status = (pct >= 75.0) ? "ELIGIBLE" : "SHORTAGE (<75%)";

        std::cout << std::left << std::setw(10) << s.rollNo
                  << std::setw(22) << s.name
                  << std::fixed << std::setprecision(2) << std::setw(14) << pct << "%"
                  << std::setw(20) << status << "\n";
    }
    std::cout << "==========================================================================\n";
}


// Feature 6: Update / Correct Attendance Record
void updateAttendanceRecord(std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "\nNo records available to update.\n";
        return;
    }

    int targetRoll;
    std::cout << "\n--- Update Attendance Record ---\n";
    std::cout << "Enter Roll Number to update: ";
    std::cin >> targetRoll;

    for (auto& s : students) {
        if (s.rollNo == targetRoll) {
            int newTotal, newAttended;
            std::cout << "Current Attendance for " << s.name << ": "
                      << s.attendedClasses << "/" << s.totalClasses << "\n";
            std::cout << "Enter corrected Total Classes: ";
            std::cin >> newTotal;
            std::cout << "Enter corrected Attended Classes: ";
            std::cin >> newAttended;

            if (newTotal < 0 || newAttended < 0 || newAttended > newTotal) {
                std::cout << "Error: Invalid class counts entered.\n";
                return;
            }

            s.totalClasses = newTotal;
            s.attendedClasses = newAttended;
            saveRecordsToFile(students);
            std::cout << "Attendance updated and saved successfully!\n";
            return;
        }
    }
    std::cout << "Student with Roll Number " << targetRoll << " not found.\n";
}
