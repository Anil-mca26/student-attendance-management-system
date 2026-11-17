# Student Attendance Management System

A console-based **Student Attendance Management System** built in **C++** using collaborative Git and GitHub workflows (`feature-member1` and `feature-member2` branching, pull requests, code reviews, and merge conflict resolution).

## Objectives
- Automate student registration, daily attendance tracking, and 75% exam eligibility reporting.
- Demonstrate structured multi-file C++ programming and persistent file storage.
- Practice collaborative version control using Git and [GitHub](https://github.com).

## Team Members & Contributions

| Member | Branch | Assigned Features | Source File |
| **Anil Kumar** (Student 1) | `feature-member1` | Add Student, Mark Daily Attendance, View All Records | `member1_features.cpp` |
| **Anand Kumar** (Student 2) | `feature-member2` | Search by Roll No, 75% Eligibility Report, Update & File I/O | `member2_features.cpp` |

## Project Structure
```text
student-attendance-management-system/
├── attendance.h            # Shared Student struct & function prototypes
├── member1_features.cpp    # Student 1 features (Options 1–3)
├── member2_features.cpp    # Student 2 features (Options 4–6 + File I/O)
├── main.cpp                # Application entry point & interactive menu
├── .gitignore              # Excludes compiled binaries and local data
├── README.md               # Project documentation
