#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Structure for a student node in BST
struct StudentNode {
    long studentNumber;
    string firstName;
    string lastName;
    float grade;
    StudentNode* left;
    StudentNode* right;

    StudentNode(long sn, const string& fn, const string& ln, float gr)
        : studentNumber(sn), firstName(fn), lastName(ln), grade(gr), left(nullptr), right(nullptr) {}
};

// Class for the Binary Search Tree managing students
class AcademicBST {
private:
    StudentNode* root;

    StudentNode* insert(StudentNode* node, long studentNumber, const string& firstName, const string& lastName, float grade) {
        if (node == nullptr)
            return new StudentNode(studentNumber, firstName, lastName, grade);

        if (studentNumber < node->studentNumber)
            node->left = insert(node->left, studentNumber, firstName, lastName, grade);
        else if (studentNumber > node->studentNumber)
            node->right = insert(node->right, studentNumber, firstName, lastName, grade);
        // If studentNumber already exists, do nothing
        return node;
    }

    StudentNode* searchByNumber(StudentNode* node, long studentNumber) {
        if (node == nullptr || node->studentNumber == studentNumber)
            return node;

        if (studentNumber < node->studentNumber)
            return searchByNumber(node->left, studentNumber);
        else
            return searchByNumber(node->right, studentNumber);
    }

    void deleteTree(StudentNode* node) {
        if (node == nullptr)
            return;

        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }

    void findHighestGrade(StudentNode* node, StudentNode*& highest) {
        if (node == nullptr)
            return;
        if (highest == nullptr || node->grade > highest->grade)
            highest = node;
        findHighestGrade(node->left, highest);
        findHighestGrade(node->right, highest);
    }

    void findLowestGrade(StudentNode* node, StudentNode*& lowest) {
        if (node == nullptr)
            return;
        if (lowest == nullptr || node->grade < lowest->grade)
            lowest = node;
        findLowestGrade(node->left, lowest);
        findLowestGrade(node->right, lowest);
    }

    void findFailedStudents(StudentNode* node, vector<StudentNode*>& failed, float failThreshold) {
        if (node == nullptr)
            return;
        if (node->grade < failThreshold)
            failed.push_back(node);
        findFailedStudents(node->left, failed, failThreshold);
        findFailedStudents(node->right, failed, failThreshold);
    }

public:
    AcademicBST() : root(nullptr) {}

    ~AcademicBST() {
        deleteTree(root);
    }

    void insert(long studentNumber, const string& firstName, const string& lastName, float grade) {
        root = insert(root, studentNumber, firstName, lastName, grade);
    }

    StudentNode* searchByNumber(long studentNumber) {
        return searchByNumber(root, studentNumber);
    }

    StudentNode* getHighestGradeStudent() {
        StudentNode* highest = nullptr;
        findHighestGrade(root, highest);
        return highest;
    }

    StudentNode* getLowestGradeStudent() {
        StudentNode* lowest = nullptr;
        findLowestGrade(root, lowest);
        return lowest;
    }

    vector<StudentNode*> getFailedStudents(float failThreshold = 75.0f) {
        vector<StudentNode*> failed;
        findFailedStudents(root, failed, failThreshold);
        return failed;
    }
};

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void display()
{
    printf("\x1B[2J");   
    printf("\n");
    printf("  \t\t\t\t\t      \t /$$   /$$   /$$$$$$$$                                  \t    \n");
    printf("  \t\t\t\t\t      \t| $$  | $$  | $$_____/                                         \t    \n");
    printf("  \t\t\t\t\t      \t| $$  | $$  | $$       \t    \n");
    printf("  \t\t\t\t\t      \t| $$  | $$  | $$$$$       \t    \n");
    printf("  \t\t\t\t\t      \t| $$  | $$  | $$__/          \t    \n");
    printf("  \t\t\t\t\t      \t| $$  | $$  | $$          \t    \n");
    printf("  \t\t\t\t\t      \t|  $$$$$$/  | $$$$$$$$        \t    \n");
    printf("  \t\t\t\t\t      \t \______/   |________/   \t    \n\n");
    printf("\n\n");
}

int main() {
    display();

    cout << "Press any key to continue...";
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    printf("\x1B[2J"); // ANSI escape code to clear screen
    printf("\x1B[H");

    AcademicBST bst;

    // Preload students
    bst.insert(2021001, "John", "Doe", 87.5);
    bst.insert(20210041111, "Alice", "Smith", 92.0);
    bst.insert(20210031111, "Bob", "Johnson", 75.3);
    bst.insert(20210021111, "Emily", "Davis", 58.8); // failed grade example
    bst.insert(20221111166, "Michael", "Brown", 45.4); // failed grade example

    while (true) {
        cout << "\nAcademic Management System\n";
        cout << "1. Search student by student number\n";
        cout << "2. Add new student data\n";
        cout << "3. Find student with highest grade\n";
        cout << "4. Find student with lowest grade\n";
        cout << "5. List students who failed\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 1) {
            cout << "Enter student number: ";
            long sn;
            cin >> sn;
            if (cin.fail()) {
                cout << "Invalid input for student number.\n";
                clearInputBuffer();
                continue;
            }

            StudentNode* student = bst.searchByNumber(sn);
            if (student) {
                cout << "Student found:\n";
                cout << "Student Number: " << student->studentNumber << endl;
                cout << "Name: " << student->firstName << " " << student->lastName << endl;
                cout << "Grade: " << student->grade << endl;
            } else {
                cout << "Student with number " << sn << " not found.\n";
            }
        } else if (choice == 2) {
            cout << "Enter new student number: ";
            long newSn;
            cin >> newSn;
            if (cin.fail()) {
                cout << "Invalid input for student number.\n";
                clearInputBuffer();
                continue;
            }

            if (bst.searchByNumber(newSn) != nullptr) {
                cout << "Student number already exists! Cannot add duplicate.\n";
                continue;
            }

            cout << "Enter first name: ";
            string fn;
            cin >> fn;
            cout << "Enter last name: ";
            string ln;
            cin >> ln;

            cout << "Enter grade (0.0 to 100.0): ";
            float gr;
            cin >> gr;
            if (cin.fail() || gr < 0.0 || gr > 100.0) {
                cout << "Invalid grade input.\n";
                clearInputBuffer();
                continue;
            }

            bst.insert(newSn, fn, ln, gr);
            cout << "New student data added successfully.\n";
        } else if (choice == 3) {
            StudentNode* highest = bst.getHighestGradeStudent();
            if (highest) {
                cout << "Student with highest grade:\n";
                cout << "Student Number: " << highest->studentNumber << endl;
                cout << "Name: " << highest->firstName << " " << highest->lastName << endl;
                cout << "Grade: " << highest->grade << endl;
            } else {
                cout << "No student records found.\n";
            }
        } else if (choice == 4) {
            StudentNode* lowest = bst.getLowestGradeStudent();
            if (lowest) {
                cout << "Student with lowest grade:\n";
                cout << "Student Number: " << lowest->studentNumber << endl;
                cout << "Name: " << lowest->firstName << " " << lowest->lastName << endl;
                cout << "Grade: " << lowest->grade << endl;
            } else {
                cout << "No student records found.\n";
            }
        } else if (choice == 5) {
            vector<StudentNode*> failedStudents = bst.getFailedStudents();
            if (failedStudents.empty()) {
                cout << "No students have failed.\n";
            } else {
                cout << "Students who failed (grade below 75):\n";
                for (auto student : failedStudents) {
                    cout << "- Student Number: " << student->studentNumber
                         << ", Name: " << student->firstName << " " << student->lastName
                         << ", Grade: " << student->grade << endl;
                }
            }
        } else if (choice == 6) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}