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

void clearScreen() {
    cout << "\x1B[2J\x1B[H";  // ANSI escape code to clear screen
}

void display() {
    clearScreen();
    cout << "\033[95m";
    cout << "\n\n";
    cout << "\t\t\t\t╔═════════════════════════════════════════════════════════════════════════════════╗\n";
    cout << "\t\t\t\t║                                                                                 ║\n";
    cout << "\t\t\t\t║      ▓█▓    ▓█▓   ▓██████▓              ▓████████▓    ▓██████▓    ▓███████▓     ║\n";
    cout << "\t\t\t\t║      ▓█▓    ▓█▓   ▓█▓                   ▓█▓    ▓█▓   ▓█▓    ▓█▓   ▓█▓           ║\n";
    cout << "\t\t\t\t║      ▓█▓    ▓█▓   ▓█▓                   ▓█▓    ▓█▓   ▓█▓    ▓█▓   ▓█▓           ║\n";
    cout << "\t\t\t\t║      ▓█▓    ▓█▓   ▓██████▓   ▒▓▓▓▓▒     ▓████████▓   ▓███████▓    ▓███████▓     ║\n";
    cout << "\t\t\t\t║      ▓█▓    ▓█▓   ▓█▓                   ▓█▓    ▓█▓   ▓█▓    ▓█▓         ▓█▓     ║\n";                                                                                                                                                                                                                
    cout << "\t\t\t\t║      ▓█▓    ▓█▓   ▓█▓                   ▓█▓    ▓█▓   ▓█▓    ▓█▓         ▓█▓     ║\n";
    cout << "\t\t\t\t║       ▓██████▓    ▓██████▓              ▓█▓    ▓█▓   ▓█▓    ▓█▓   ▓███████▓     ║\n";                               
    cout << "\t\t\t\t║                                                                                 ║\n";  
    cout << "\t\t\t\t║                           Data Structures and Algorithms                        ║\n";      
    cout << "\t\t\t\t║                                Course Code: NCP_1203                            ║\n";                  
    cout << "\t\t\t\t╚═════════════════════════════════════════════════════════════════════════════════╝\n";
}

int main() {
    display();

    cout << "\n\n\n\t\t
    
    Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    AcademicBST bst;
// Preload students
    bst.insert(20221112603, "Tyron Jonas", "Bernardo", 91);
    bst.insert(20241117362, "Roven Jules", "Respicio", 95);
    bst.insert(20241141071, "Dwyane Allen", "Dela Cruz", 81);
    bst.insert(20241120682, "Patrick", "Alde", 69);
    bst.insert(20241138896, "Kate Clouie", "Formon", 92);
    bst.insert(20221111815, "Ellaine Jemima", "Castro", 84);
    bst.insert(20241105099, "John Andrew", "Gungon", 91);
    bst.insert(20221105062, "Argelina Ryle", "Bautista", 83);
    bst.insert(20221115635, "Johnmeynard", "Oguez", 79);
    bst.insert(20241118149, "Althea", "Bautista", 96);
    bst.insert(20221118645, "Arabela Grace", "Dela Cruz", 97);
    bst.insert(20221111166, "Ann Nicole", "Geronimo", 91);
    bst.insert(20221131846, "Steven Zeddriq", "Natividad", 78);
    bst.insert(20241110021, "Ron Kyle", "Boadilla", 84);
    bst.insert(20241107313, "Mariane", "Eustaquio", 94);
    bst.insert(20181114136, "Chang Hyun", "Park", 74);
    bst.insert(20241120810, "Jaylord", "Gaspi", 95);
    bst.insert(20221112090, "Luis Gabriel", "Santiago", 94);
    bst.insert(20241120809, "Alexandria", "Timbol", 80);
    bst.insert(20241116336, "Rayne Bernadette", "Roque", 90);
    bst.insert(20241100947, "Ian Benedict", "Untalan", 83);
    bst.insert(20221113297, "Raiden", "Muñoz", 80);
    bst.insert(20121154856, "Moses Ivan", "Bartolome", 84);
    bst.insert(20241125382, "Andrew Jae", "Salas", 89);
    bst.insert(20241123079, "Ashley", "Astor", 81);
    bst.insert(20241139140, "Rakim Krishna", "Joven", 92);
    bst.insert(20221110505, "Matthew Jeric", "Nuñez", 93);
    bst.insert(20181122190, "Justine Paul", "Cano", 88);
    bst.insert(20241112765, "Mark Einjelo", "Alaba", 77);
    bst.insert(20241119517, "Edward Lleyton", "Robillos", 71);
    bst.insert(20241125746, "Angela", "Tolentino", 91);
    bst.insert(20241124685, "Patrick", "Ayag", 84);
    bst.insert(20221125560, "Earl Dominique", "Muñoz", 89);
    bst.insert(20241130596, "John Lord", "Zambrano", 91);
    bst.insert(20241129475, "Jon Adrian", "Maula", 92);
    bst.insert(20241126669, "Jeremy Jetok", "Velasquez", 93);
    bst.insert(20241124674, "Jennilie", "Adame", 94);
    bst.insert(20221104923, "Hernan Jay", "Nem", 93);
    bst.insert(20241110145, "Ben Justin", "Espiritu", 99);
    bst.insert(20241110350, "Paul Wesley", "Gomez", 84);
    bst.insert(20171140844, "Jeanne Charlotte Belle", "Ng", 72);
    bst.insert(20221104592, "Christine", "Alcantara", 81);
    bst.insert(20241130767, "Neil", "Obsioma", 85);
    bst.insert(20221104036, "Denisse Andrew", "Abarro", 95);
    bst.insert(20241107380, "Aron", "Roxas", 97);
    bst.insert(20241130029, "Gwen Angelynn", "Lopez", 83);
    bst.insert(20241120229, "Karl Sebastian", "Gabiano", 90);
    bst.insert(20241120901, "John Roldan", "Garbin", 83);
    bst.insert(20241139093, "Chantelle Venice", "Alejandrino", 89);
    bst.insert(20241100049, "Jhon Cristopher", "Bamo", 84);
    bst.insert(0, "Jonel", "Laraquel", 84);  // Student ID missing
    bst.insert(20221124523, "Karl Angelo", "Basconcillo", 82);
    bst.insert(20241110918, "Ivan Jhed", "Dumolong", 97);


    while (true) {
        clearScreen();  // Instead of display()
        cout << "\033[95m";
        cout << "\n\n";
        cout << "              █████   ██████  █████  ██████  ███████ ███    ███ ██  ██████     ██████  ███████  ██████  ██████  ██████  ██████   \n";
        cout << "             ██   ██ ██      ██   ██ ██   ██ ██      ████  ████ ██ ██          ██   ██ ██      ██      ██    ██ ██   ██ ██   ██  \n";
        cout << "             ███████ ██      ███████ ██   ██ █████   ██ ████ ██ ██ ██          ██████  █████   ██      ██    ██ ██████  ██   ██  \n";
        cout << "             ██   ██ ██      ██   ██ ██   ██ ██      ██  ██  ██ ██ ██          ██   ██ ██      ██      ██    ██ ██   ██ ██   ██  \n";
        cout << "             ██   ██  ██████ ██   ██ ██████  ███████ ██      ██ ██  ██████     ██   ██ ███████  ██████  ██████  ██   ██ ██████   \n";
        cout << "                                                                                                                                                                                                                        \n";
        cout << "                                                                                                                                                                                                                        \n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t|  [1] Search student by student number   |\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t|  [2] Add new student data               |\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t|  [3] Find student with highest grade    |\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t|  [4] Find student with lowest grade     |\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t|  [5] List students who failed           |\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n";
        cout << "\t\t\t\t\t\t|  [6] Exit                               |\n";
        cout << "\t\t\t\t\t\t ------------------------------------------\n\n\n";
        cout << "\t\t\t\tEnter choice: ";   

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 1) {
            clearScreen();
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
            clearScreen();
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
            clearScreen();
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
            clearScreen();
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
            clearScreen();
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
            clearScreen();
             cout << "\n\n";
             cout << "\033[95m";
    cout << "\t\t\t\t████████ ██   ██  █████  ███    ██ ██   ██     ██    ██  ██████  ██    ██ ██\n";
    cout << "\t\t\t\t   ██    ██   ██ ██   ██ ████   ██ ██  ██       ██  ██  ██    ██ ██    ██ ██ \n";
    cout << "\t\t\t\t   ██    ███████ ███████ ██ ██  ██ █████         ████   ██    ██ ██    ██ ██ \n";
    cout << "\t\t\t\t   ██    ██   ██ ██   ██ ██  ██ ██ ██  ██         ██    ██    ██ ██    ██    \n";
    cout << "\t\t\t\t   ██    ██   ██ ██   ██ ██   ████ ██   ██        ██     ██████   ██████  ██ \n";
    cout << "\t\t\t\t                                                                             \n";
    cout << "\t\t\t\t                                                                             \n";
    cout << "\t\t\t\t                           Exiting Program.....                              \n";
    cout << "\t\t\t\t                                                                             \n";
    cout << "\t\t\t\t                                                                             \n";
    cout << "\t\t\t\t                                                                             \n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "\nPress Enter to return to menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}
