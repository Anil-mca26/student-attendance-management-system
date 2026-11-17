#ifndef ATTENDANCE_H
#define ATTENDANCE_H

#include <string>
#include <vector>

struct Student {
    int rollNo;
    std::string name;
    std::string department;
    int totalClasses;
    int attendedClasses;
};



// Person 2 Features (Branch: feature-member2)
void searchStudentByRoll(const std::vector<Student>& students);
void generateEligibilityReport(const std::vector<Student>& students);
void updateAttendanceRecord(std::vector<Student>& students);

// File Persistence Helpers
void saveRecordsToFile(const std::vector<Student>& students, const std::string& filename = "attendance_data.txt");
void loadRecordsFromFile(std::vector<Student>& students, const std::string& filename = "attendance_data.txt");

#endif