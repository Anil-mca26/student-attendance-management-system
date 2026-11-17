#include<iostream>
#include"attendance.h"
#include <limits>

// Shared version banner (Modify this same line on both branches to create a merge conflict)
const std::string APP_VERSION = "v2.0 - Full Release (Member 1 + Member 2)";

int main(){
    std::vector<Student> students;
    loadRecordsFromFile(students);

    int choice = 0;
    while (true) {
        std::cout << "\n=============================================\n";
        std::cout << "  STUDENT ATTENDANCE MANAGEMENT SYSTEM\n";
        std::cout << "  Build: " << APP_VERSION << "\n";
        std::cout << "=============================================\n";
        std::cout << "1. Add New Student (Member 1)\n";
        std::cout << "2. Mark Daily Attendance (Member 1)\n";
        std::cout << "3. View All Attendance Records (Member 1)\n";
        std::cout << "4. Search Student by Roll No (Member 2)\n";
        std::cout << "5. Generate 75% Eligibility Report (Member 2)\n";
        std::cout << "6. Update Attendance Record (Member 2)\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice (1-7): ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addStudent(students); break;
            case 2: markAttendance(students); break;
            case 3: viewAllAttendance(students); break;
            
            case 4: searchStudentByRoll(students); break;
            case 5: generateEligibilityReport(students); break;
            case 6: updateAttendanceRecord(students); break;
            case 0:
                std::cout << "Exiting system. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}