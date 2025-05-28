#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <unordered_map> 
#include <iomanip>  
#include <algorithm>

using namespace std;


struct StudentNode {
    long studentNumber;
    string fullName;
    string ueEmail;
    string section;
    float grade;
    StudentNode* left;
    StudentNode* right;

    StudentNode(long sn, const string& fn, const string& ue, const string& sc, float gr)
        : studentNumber(sn), fullName(fn), ueEmail(ue), section(sc), grade(gr), left(nullptr), right(nullptr) {}
};


class AcademicBST {
private:
    StudentNode* root;

    StudentNode* insert(StudentNode* node, long studentNumber, const string& fullName, const string& ueEmail, const string& section, float grade) {
        if (node == nullptr)
            return new StudentNode(studentNumber, fullName, ueEmail, section, grade);

        if (studentNumber < node->studentNumber)
            node->left = insert(node->left, studentNumber, fullName, ueEmail, section, grade);
        else if (studentNumber > node->studentNumber)
            node->right = insert(node->right, studentNumber, fullName, ueEmail, section, grade);
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

    StudentNode* deleteNode(StudentNode* node, long studentNumber) {
        if (node == nullptr) return node;

        if (studentNumber < node->studentNumber) {
            node->left = deleteNode(node->left, studentNumber);
        } else if (studentNumber > node->studentNumber) {
            node->right = deleteNode(node->right, studentNumber);
        } else {
            
            if (node->left == nullptr) {
                StudentNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                StudentNode* temp = node->left;
                delete node;
                return temp;
            }

            
            StudentNode* temp = node->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }

            
            node->studentNumber = temp->studentNumber;
            node->fullName = temp->fullName;
            node->ueEmail = temp->ueEmail;
            node->section = temp->section;
            node->grade = temp->grade;

            
            node->right = deleteNode(node->right, temp->studentNumber);
        }
        return node;
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

    void calculatePerformance(StudentNode* node, float& totalGrades, int& count, int& passedCount, int& failedCount, float failThreshold) {
        if (node == nullptr)
            return;
        totalGrades += node->grade;
        count++;
        if (node->grade < failThreshold) {
            failedCount++;
        } else {
            passedCount++;
        }
        calculatePerformance(node->left, totalGrades, count, passedCount, failedCount, failThreshold);
        calculatePerformance(node->right, totalGrades, count, passedCount, failedCount, failThreshold);
    }

public:
    AcademicBST() : root(nullptr) {}

    ~AcademicBST() {
        deleteTree(root);
    }

    StudentNode* getRoot() const {
        return root;
    }

    
    void collectAllStudents(StudentNode* node, vector<StudentNode*>& students) const {
        if (!node) return;
        collectAllStudents(node->left, students);
        students.push_back(node);
        collectAllStudents(node->right, students);
    }

    
    vector<StudentNode*> getAllStudents() const {
        vector<StudentNode*> students;
        collectAllStudents(root, students);
        return students;
    }

    void insert(long studentNumber, const string& fullName, const string& ueEmail, const string& section, float grade) {
        root = insert(root, studentNumber, fullName, ueEmail, section, grade);
    }

    StudentNode* searchByNumber(long studentNumber) {
        return searchByNumber(root, studentNumber);
    }

    void deleteStudent(long studentNumber) {
        root = deleteNode(root, studentNumber);
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

    vector<StudentNode*> getFailedStudents(float failThreshold = 74.0f) {
        vector<StudentNode*> failed;
        findFailedStudents(root, failed, failThreshold);
        return failed;
    }

    void showOverallPerformance(float failThreshold = 75.0f) {
        float totalGrades = 0.0f;
        int count = 0;
        int passedCount = 0;
        int failedCount = 0;

        calculatePerformance(root, totalGrades, count, passedCount, failedCount, failThreshold);

        if (count == 0) {
            cout << "No student records available to calculate performance.\n";
            return;
        }

        float averageGrade = totalGrades / count;
        cout << "\t\t\t--------------------------------------------------\n";
        cout << "\t\t\tOverall Performance:\n";
        cout << "\t\t\t--------------------------------------------------\n";
        cout << "\t\t\t--------------------------------------------------\n";
        cout << "\t\t\tTotal Students: " << count << endl;
        cout << "\t\t\tAverage Grade: " << averageGrade << endl;
        cout << "\t\t\tStudents Passed: " << passedCount << endl;
        cout << "\t\t\tStudents Failed: " << failedCount << endl;
        cout << "\t\t\t--------------------------------------------------\n";
    }
};

class StudentGraph {
private:
    unordered_map<long, StudentNode*> studentTable;

    
    vector<StudentNode*> merge(const vector<StudentNode*>& left, const vector<StudentNode*>& right) {
        vector<StudentNode*> result;
        size_t i = 0, j = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i]->grade >= right[j]->grade) {  
                result.push_back(left[i++]);
            } else {
                result.push_back(right[j++]);
            }
        }

        while (i < left.size()) result.push_back(left[i++]);
        while (j < right.size()) result.push_back(right[j++]);

        return result;
    }

   
    vector<StudentNode*> mergeSort(const vector<StudentNode*>& students) {
        if (students.size() <= 1)
            return students;

        size_t mid = students.size() / 2;
        vector<StudentNode*> left(students.begin(), students.begin() + mid);
        vector<StudentNode*> right(students.begin() + mid, students.end());

        return merge(mergeSort(left), mergeSort(right));
    }

public:
    void addStudent(StudentNode* student) {
        if (student)
            studentTable[student->studentNumber] = student;
    }

    void buildFromBST(StudentNode* node) {
        if (!node) return;
        addStudent(node);
        buildFromBST(node->left);
        buildFromBST(node->right);
    }

    void displayAll() {
        if (studentTable.empty()) {
            cout << "No students to display.\n";
            return;
        }

        vector<StudentNode*> students;
        for (const auto& pair : studentTable) {
            students.push_back(pair.second);
        }

        
        vector<StudentNode*> sortedStudents = mergeSort(students);

        cout << left << setw(15) << "Student No"
             << setw(30) << "Full Name"
             << setw(35) << "UE Email"
             << setw(12) << "Section"
             << setw(6) << "Grade" << endl;
        cout << string(100, '-') << endl;

        for (const auto& s : sortedStudents) {
            cout << left << setw(15) << s->studentNumber
                 << setw(30) << s->fullName
                 << setw(35) << s->ueEmail
                 << setw(12) << s->section
                 << setw(6) << s->grade << endl;
        }
    }

    void displaySortedByName() {
        if (studentTable.empty()) {
            cout << "No students to display.\n";
            return;
        }
        vector<StudentNode*> students;
        for (const auto& pair : studentTable) {
            students.push_back(pair.second);
        }
        sort(students.begin(), students.end(), [](StudentNode* a, StudentNode* b) {
            return a->fullName < b->fullName;
        });

        cout << left << setw(15) << "Student No"
             << setw(30) << "Full Name"
             << setw(35) << "UE Email"
             << setw(12) << "Section"
             << setw(6) << "Grade" << endl;
        cout << string(100, '-') << endl;

        for (const auto& s : students) {
            cout << left << setw(15) << s->studentNumber
                 << setw(30) << s->fullName
                 << setw(35) << s->ueEmail
                 << setw(12) << s->section
                 << setw(6) << s->grade << endl;
        }
    }

    void displaySortedByGrade() {
        displayAll();
    }
    void displaySortedBySection() {
        if (studentTable.empty()) {
            cout << "No students to display.\n";
            return;
        }

        vector<StudentNode*> students;
        for (const auto& pair : studentTable) {
            students.push_back(pair.second);
        }

       
        for (size_t i = 1; i < students.size(); ++i) {
            StudentNode* key = students[i];
            int j = i - 1;

            while (j >= 0 && students[j]->section > key->section) {
                students[j + 1] = students[j];
                --j;
            }
            students[j + 1] = key;
        }

        cout << left << setw(15) << "Student No"
             << setw(30) << "Full Name"
             << setw(35) << "UE Email"
             << setw(12) << "Section"
             << setw(6) << "Grade" << endl;
        cout << string(100, '-') << endl;

        for (const auto& s : students) {
            cout << left << setw(15) << s->studentNumber
                 << setw(30) << s->fullName
                 << setw(35) << s->ueEmail
                 << setw(12) << s->section
                 << setw(6) << s->grade << endl;
        }
    }
   
};


void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void clearScreen() {
    cout << "\x1B[2J\x1B[H"; 
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

    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();

    AcademicBST bst;
    
    
    bst.insert(20221112603, "Tyron Jonas Bernardo", "bernardo.tyronjonas@ue.du.ph", "1CPE-2B", 91);
    bst.insert(20241117362, "Roven Jules Respicio", "respecio.rovenjules@ue.edu.ph", "1CPE-2B", 95);
    bst.insert(20241141071, "Dwyane Allen Dela Cruz", "delacruz.dwyaneallen@ue.edu.ph", "1CPE-2B", 81);
    bst.insert(20241120682, "Patrick Alde", "alde.patrick@ue.edu.ph", "1CPE-2B", 69);
    bst.insert(20241138896, "Kate Clouie Formon", "formon.kateclouie@ue.edu.ph", "1CPE-2B", 92);
    bst.insert(20221111815, "Ellaine Jemima Castro", "castro.ellainejemima@ue.edu.ph", "1CPE-2B", 84);
    bst.insert(20241105099, "John Andrew Gungon", "gungon.johnandrew@ue.edu.ph", "1CPE-2B", 91);
    bst.insert(20221105062, "Argelina Ryle Bautista", "bautista.argelinaryle@ue.edu.ph", "1CPE-2A", 83);
    bst.insert(20221115635, "John Meynard Oguez", "oguez.johnmeynard@ue.edu.ph", "1CPE-2A", 79);
    bst.insert(20241118149, "Althea Bautista", "bautista.althea@ue.edu.ph", "1CPE-2A", 96);
    bst.insert(20221118645, "Arabela Grace Dela Cruz", "delacruz.arabelagrace@ue.edu.ph", "1CPE-2A", 97);
    bst.insert(20221111166, "Ann Nicole Gernimo", "geromino.annnicole@ue.edu.ph", "1CPE-2A", 91);
    bst.insert(20221131846, "Steven Zeddriq Natividad", "natividad.stevenzeddriq@ue.edu.ph", "1CPE-2A", 78);
    bst.insert(20241110021, "Ron Kyle Boadilla", "boadilla.ronkyle@ue.edu.ph", "1CPE-2A", 84);
    bst.insert(20241107313, "Mariane Eustaquio", "eustaquio.mariane@ue.edu.ph", "1CPE-2A", 94);
    bst.insert(20181114136, "Chang Hyun Park", "park.changhyun@ue.edu.ph", "1CPE-2B", 74);
    bst.insert(20241120810, "Jaylord Gaspi", "gaspi.jaylord@ue.edu.ph", "1CPE-2B", 95);
    bst.insert(20221112090, "Luis Gabriel Santiago", "santiago.luisgabriel@ue.edu.ph", "1CPE-2B", 94);
    bst.insert(20241120809, "Alexandria Timbol", "timbol.alexandria@ue.edu.ph", "1CPE-2B", 80);
    bst.insert(20241116336, "Rayne Bernadette Roque", "roque.raynebernadette@ue.edu.ph", "1CPE-2B", 90);
    bst.insert(20241100947, "Ian Benedict Untalan", "untalan.ianbenedict@ue.edu.ph", "1CPE-2B", 83);
    bst.insert(20221113297, "Raiden Munoz", "munoz.raiden@ue.edu.ph", "1CPE-2B", 80);
    bst.insert(20121154856, "Moses Ivan Bartolome", "bartolome.mosesivan@ue.edu.ph", "1CPE-2B", 84);
    bst.insert(20241125382, "Andrew Jae Salas", "salas.andrewjae@ue.edu.ph", "1CPE-2B", 89);
    bst.insert(20241123079, "Ashley Astor", "astor.ashley@ue.edu.ph", "1CPE-2A", 81);
    bst.insert(20241139140, "Rakim Krishna Joven", "joven.rakimkrishna@ue.edu.ph", "1CPE-2A", 92);
    bst.insert(20221110505, "Matthew Jeric Nunez", "nunez.matthewjeric@ue.edu.ph", "1CPE-2A", 93);
    bst.insert(20181122190, "Justine Paul Cano", "cano.justinepaul@ue.edu.ph", "1CPE-2A", 88);
    bst.insert(20241112765, "Mark Einjelo Alaba", "alaba.markeinjelo@ue.edu.ph", "1CPE-2A", 77);
    bst.insert(20241119517, "Edward Lleyton Robillos", "robillos.edwardlleyton@ue.edu.ph", "1CPE-2A", 71);
    bst.insert(20241125746, "Angela Tolentino", "tolentino.angela@ue.edu.ph", "1CPE-2B", 91);
    bst.insert(20241124685, "Patrick Ayag", "ayag.kimpatrick@ue.edu.ph", "1CPE-2A", 84);
    bst.insert(20241130596, "John Lord Zambrano", "zambrano.johnlord@ue.edu.ph", "1CPE-2A", 91);
    bst.insert(20241129475, "Jon Adrian Maula", "maula.jonadrian@ue.edu.ph", "1CPE-2A", 92);
    bst.insert(20241126669, "Jeremy Jetok Velasquez", "velasquez.jeremyjetok@ue.edu.ph", "1CPE-2A", 93);
    bst.insert(20241124674, "Jennilie Adame", "adame.jennilie@ue.edu.ph", "1CPE-2A", 94);
    bst.insert(20221104923, "Hernan Jay Nem", "nem.hernanjay@ue.edu.ph", "1CPE-2A", 93);
    bst.insert(20241110145, "Ben Justin Espiritu", "esperitu.benjustin@ue.edu.ph", "1CPE-2A", 99);
    bst.insert(20241110350, "Paul Wesley Gomez", "gomez.paulwesley@ue.edu.ph", "1CPE-2A", 84);
    bst.insert(20171140844, "Jeanne Charlotte Belle Ng", "ng.jeannecharlottebelle@ue.edu.ph", "1CPE-2A", 72);
    bst.insert(20221104592, "Christine Alcantara", "alcantara.christine1@ue.edu.ph", "1CPE-2A", 81);
    bst.insert(20241130767, "Neil Obsioma", "obsioma.neilarenz@ue.edu.ph", "1CPE-2A", 85);
    bst.insert(20221104036, "Denisse Andrew Abarro", "abarro.denisseandrew@ue.edu.ph", "1CPE-2A", 95);
    bst.insert(20241107380, "Aron Roxas", "roxas.aron@ue.edu.ph", "1CPE-2A", 97);
    bst.insert(20241130029, "Gwen Angelynn Lopez", "lopez.gwenangelynn@ue.edu.ph", "1CPE-2B", 83);
    bst.insert(20241120229, "Karl Sebastian Gabiano", "gabiano.karlsebastian@ue.edu.ph", "1CPE-2A", 90);
    bst.insert(20241120901, "John Roldan Garbin", "garbinjohnroldan@ue.edu.ph", "1CPE-2B", 83);
    bst.insert(20241139093, "Chantelle Venice Alejandrino", "alejandrino.chantellevenice@ue.edu.ph", "1CPE-2B", 89);
    bst.insert(20241100049, "Jhon Cristopher Bamo", "bamo.jhoncristopher@ue.edu.ph", "1CPE-2B", 84);
    bst.insert(20221116137, "Jonel Laraquel", "laraquel.jonel@ue.edu.ph", "1CPE-2B", 84); 
    bst.insert(20221124523, "Karl Angelo Basconcillo", "basconcillo.karlangelo@ue.edu.ph", "1CPE-2B", 82);
    bst.insert(20241110918, "Ivan Jhed Dumolong", "dumulong.ivanjhed@ue.edu.ph", "1CPE-2B", 67);

    StudentGraph graph;

    while (true) {
        clearScreen();
cout << "\n\n";
        cout << "              █████   ██████  █████  ██████  ███████ ███    ███ ██  ██████     ██████  ███████  ██████  ██████  ██████  ██████   \n";
        cout << "             ██   ██ ██      ██   ██ ██   ██ ██      ████  ████ ██ ██          ██   ██ ██      ██      ██    ██ ██   ██ ██   ██  \n";
        cout << "             ███████ ██      ███████ ██   ██ █████   ██ ████ ██ ██ ██          ██████  █████   ██      ██    ██ ██████  ██   ██  \n";
        cout << "             ██   ██ ██      ██   ██ ██   ██ ██      ██  ██  ██ ██ ██          ██   ██ ██      ██      ██    ██ ██   ██ ██   ██  \n";
        cout << "             ██   ██  ██████ ██   ██ ██████  ███████ ██      ██ ██  ██████     ██   ██ ███████  ██████  ██████  ██   ██ ██████   \n";
        cout << "                                                                                                                                                                                                                        \n";
        cout << "                                                                                                                                                                                                                        \n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t|  [1] Search Student by Student Number   |  |  [6] Find Student with Lowest Grade       |\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t|  [2] Add New Student Data               |  |  [7] List students who failed             |\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t|  [3] Update Student Data                |  |  [8] Show Overall Performance             |\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t|  [4] Delete Student Data                |  |  [9] Search Student by Student Name       |\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t|  [5] Find Student with Highest Grade    |  |  [10] Display all student records         |\n";
        cout << "\t\t\t -----------------------------------------    -------------------------------------------\n";
        cout << "\t\t\t                       ------------------------------------------\n";
        cout << "\t\t\t                      |  [11] Exit                               |\n";
        cout << "\t\t\t                       ------------------------------------------\n\n\n";
        cout << "\t\t\tEnter Choice: "; 
        
        int choice;
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid Input. Please Enter a Number.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 1) {
            clearScreen();
            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tEnter Student Number: ";
            long sn;
            cin >> sn;
            if (cin.fail()) {
                cout << "Invalid Input for Student Number.\n";
                clearInputBuffer();
                continue;
            }

            StudentNode* student = bst.searchByNumber(sn);
            if (student) {
                cout << "\t\t\t--------------------------------------------------\n";
                cout << "\t\t\t--------------------------------------------------";
                cout << "\n\n";
                cout << "\t\t\tStudent Found!\n";
                cout << "\t\t\tStudent Number: " << student->studentNumber << endl;
                cout << "\t\t\tName: " << student->fullName << endl;
                cout << "\t\t\tUE Email: " << student->ueEmail << endl;
                cout << "\t\t\tSection: " << student->section << endl;
                cout << "\t\t\tGrade: " << student->grade << endl;
                cout << "\n";

                cout << "\t\t\t--------------------------------------------------\n";
            } else {
                cout << "\t\t\tStudent with Number " << sn << " not found.\n";
            }
        } else if (choice == 2) {
            clearScreen();
            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tEnter New Student Number: ";
            long newSn;
            cin >> newSn;
            if (cin.fail()) {
                cout << "\t\t\tInvalid Input for Student Number.\n";
                clearInputBuffer();
                continue;
            }

            if (bst.searchByNumber(newSn) != nullptr) {
                cout << "\t\t\tStudent number already exists! Cannot add duplicate.\n";
                continue;
            }

            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tEnter Student's Name: ";
            string fn;
            cin >> ws;
            getline(cin, fn);
            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tEnter Student's UE Email: ";
            string ue;
            cin >> ws;
            getline(cin, ue);
            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tEnter Student's Section: ";
            string sc;
            cin >> ws;
            getline(cin, sc);
            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tEnter Grade (0.0 to 100.0): ";
            float gr;
            cin >> gr;
            if (cin.fail() || gr < 0.0 || gr > 100.0) {
                cout << "\t\t\tInvalid Grade Input.\n";
                clearInputBuffer();
                continue;
            }

            bst.insert(newSn, fn, ue, sc, gr);
            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tNew Student Data Added Successfully.\n";
        } else if (choice == 3) {
            clearScreen();
            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tEnter Student Number to Update: ";
            long sn;
            cin >> sn;
            if (cin.fail()) {
                cout << "\t\t\tInvalid Input for Student Number.\n";
                clearInputBuffer();
                continue;
            }

            StudentNode* student = bst.searchByNumber(sn);
            if (student) {
                cout << "\t\t\tUpdating Data for Student Number: " << sn << endl;
                char updateChoice;
                
                cout << "\t\t\tCurrent Name: " << student->fullName << "\n\t\t\tUpdate? (y/n): ";
                cin >> updateChoice;
                if (updateChoice == 'y' || updateChoice == 'Y') {
                    cout << "\t\t\tEnter New Name: ";
                    string fn;
                    cin >> ws;
                    getline(cin, fn);
                    student->fullName = fn;
                }
               
                cout << "\t\t\tCurrent UE Email: " << student->ueEmail << "\n\t\t\tUpdate? (y/n): ";
                cin >> updateChoice;
                if (updateChoice == 'y' || updateChoice == 'Y') {
                    cout << "\t\t\tEnter New UE Email: ";
                    string ue;
                    cin >> ws;
                    getline(cin, ue);
                    student->ueEmail = ue;
                }
                
                cout << "\t\t\tCurrent Section: " << student->section << "\n\t\t\tUpdate? (y/n): ";
                cin >> updateChoice;
                if (updateChoice == 'y' || updateChoice == 'Y') {
                    cout << "\t\t\tEnter New Section: ";
                    string sc;
                    cin >> ws;
                    getline(cin, sc);
                    student->section = sc;
                }
                
                cout << "\t\t\tCurrent Grade: " << student->grade << "\n\t\t\tUpdate? (y/n): ";
                cin >> updateChoice;
                if (updateChoice == 'y' || updateChoice == 'Y') {
                    cout << "\t\t\tEnter New Grade (0.0 to 100.0): ";
                    float gr;
                    cin >> gr;
                    if (cin.fail() || gr < 0.0 || gr > 100.0) {
                        cout << "\t\t\tInvalid Grade Input. Grade Not Updated.\n";
                        clearInputBuffer();
                    } else {
                        student->grade = gr;
                    }
                }

                cout << "\t\t\tStudent Data Updated Successfully.\n";
                cout << "\t\t\t--------------------------------------------------\n";
            } else {
                cout << "\t\t\tStudent With Number " << sn << " \t\t\tNot Found.\n";
                
            }
        } else if (choice == 4) {
            clearScreen();
            cout << "\t\t\t--------------------------------------------------\n";
            cout << "\t\t\tEnter Student Number to Delete: ";
            long sn;
            cin >> sn;
            if (cin.fail()) {
                cout << "\t\t\tInvalid Input for Student Number.\n";
                clearInputBuffer();
                continue;
            }

            bst.deleteStudent(sn);
            cout << "\t\t\t--------------------------------------------------";
            cout << "\n";
            cout << "\n\t\t\tStudent With Number " << sn << " Deleted Successfully (if existed).\n";
            cout << "\n";
            cout << "\t\t\t--------------------------------------------------\n";
        } else if (choice == 5) {
            clearScreen();
            StudentNode* highest = bst.getHighestGradeStudent();
            if (highest) {
                cout << "\t\t\t--------------------------------------------------\n";
                cout << "\t\t\tStudent with Highest Grade:\n";
                cout << "\t\t\t--------------------------------------------------\n";
                cout << "\t\t\tStudent Number: " << highest->studentNumber << endl;
                cout << "\t\t\tName: " << highest->fullName << endl;
                cout << "\t\t\tUE Email: " << highest->ueEmail << endl;
                cout << "\t\t\tSection: " << highest->section << endl;
                cout << "\t\t\tGrade: " << highest->grade << endl;
                cout << "\t\t\t--------------------------------------------------\n";
            } else {
                cout << "\t\t\tNo Student Records Found.\n";
            }
        } else if (choice == 6) {
            clearScreen();
            StudentNode* lowest = bst.getLowestGradeStudent();
            if (lowest) {
                cout << "\t\t\t--------------------------------------------------\n";
                cout << "\t\t\tStudent with Lowest Grade:\n";
                cout << "\t\t\t--------------------------------------------------\n";
                cout << "\t\t\tStudent Number: " << lowest->studentNumber << endl;
                cout << "\t\t\tName: " << lowest->fullName << endl;
                cout << "\t\t\tUE Email: " << lowest->ueEmail << endl;
                cout << "\t\t\tSection: " << lowest->section << endl;
                cout << "\t\t\tGrade: " << lowest->grade << endl;
                cout << "\t\t\t--------------------------------------------------\n";
            } else {
                cout << "\t\t\tNo Student Records Found.\n";
            }
        } else if (choice == 7) {
            clearScreen();
            vector<StudentNode*> failedStudents = bst.getFailedStudents();
            if (failedStudents.empty()) {
                cout << "\t\t\tNo Students Have Failed.\n";
            } else {
                
                cout << "\t\t\t--------------------------------------------------\n";
                cout << "\t\t\tStudents Who Failed (Grade Below 75):\n";
                for (auto student : failedStudents) {
                    cout << "\t\t\t--------------------------------------------------\n";
                    cout << "\t\t\t--------------------------------------------------\n";
                    cout << "\t\t\t- Student Number: " << student->studentNumber
                         << "\n\t\t\t Name: " << student->fullName
                         << "\n\t\t\t UE Email: " << student->ueEmail
                         << "\n\t\t\t Section: " << student->section
                         << "\n\t\t\t Grade: " << student->grade << endl;
                    cout << "\t\t\t--------------------------------------------------\n";
                    
                }
            } 
        } else if (choice == 8) {
            clearScreen();
            bst.showOverallPerformance();
        }
        else if (choice == 9) { 
            clearScreen();
            cout << "\t\t\t----------------------------------------\n";
            cout << "\t\t\tEnter Student's Name: ";
            
            string searchName;
            cin >> ws; 
            getline(cin, searchName);

            
            string searchNameLower = searchName;
            transform(searchNameLower.begin(), searchNameLower.end(), searchNameLower.begin(), ::tolower);

            
            vector<StudentNode*> allStudents = bst.getAllStudents();
            vector<StudentNode*> foundStudents;


            
            for (const auto& student : allStudents) {
                string currentNameLower = student->fullName;
                transform(currentNameLower.begin(), currentNameLower.end(), currentNameLower.begin(), ::tolower);

                if (currentNameLower.find(searchNameLower) != string::npos) {
                    foundStudents.push_back(student);
                }
            }

            if (foundStudents.empty()) {
                
                cout << "\t\t\tNo Students Found Matching '" << searchName << "'.\n";
            } else {
                cout << "\t\t\t----------------------------------------\n";
                cout << "\t\t\tStudents Matching '" << searchName << "':\n";
                for (const auto& student : foundStudents) {
                    cout << "\t\t\t----------------------------------------\n";
                    cout << "\t\t\t----------------------------------------\n";
                    cout << "\t\t\tStudent Number: " << student->studentNumber << endl;
                    cout << "\t\t\tName: " << student->fullName << endl;
                    cout << "\t\t\tUE Email: " << student->ueEmail << endl;
                    cout << "\t\t\tSection: " << student->section << endl;
                    cout << "\t\t\tGrade: " << student->grade << endl;
                }
                cout << "\t\t\t----------------------------------------\n";
            }
        }
       else if (choice == 10) {
    clearScreen();
    graph = StudentGraph(); 
    graph.buildFromBST(bst.getRoot());  

    int sortOption;
    cout << "\t\t\t----------------------------------------\n";
    cout << "\t\t\tDisplay All Student Records Sorted By:\n";
    cout << "\t\t\t1. Alphabetically by Name\n";
    cout << "\t\t\t2. Order by Grade\n";
    cout << "\t\t\t3. Order by Section\n";
    cout << "\t\t\t----------------------------------------\n";
    cout << "\t\t\tEnter Choice: ";
    
    cin >> sortOption;

    if (cin.fail() || (sortOption < 1 || sortOption > 3)) {
        cout << "\t\t\tInvalid choice. Displaying Unsorted Records.\n";
        graph.displayAll();
    } else {
        if (sortOption == 1) {
            graph.displaySortedByName();
        } else if (sortOption == 2) {
            graph.displaySortedByGrade();
        } else if (sortOption == 3) {
            graph.displaySortedBySection();
        }
    }    
}

        else if (choice == 11) {
            clearScreen();
            cout << "\n\n";
            cout << "\t\t\t\t████████ ██   ██  █████  ███    ██ ██   ██     ██    ██  ██████  ██    ██ ██\n";
            cout << "\t\t\t\t   ██    ██   ██ ██   ██ ████   ██ ██  ██       ██  ██  ██    ██ ██    ██ ██ \n";
            cout << "\t\t\t\t   ██    ███████ ███████ ██ ██  ██ █████         ████   ██    ██ ██    ██ ██ \n";
            cout << "\t\t\t\t   ██    ██   ██ ██   ██ ██  ██ ██ ██  ██         ██    ██    ██ ██    ██    \n";
            cout << "\t\t\t\t   ██    ██   ██ ██   ██ ██   ████ ██   ██        ██     ██████   ██████  ██ \n";
            cout << "\t\t\t\t                                                                             \n";
            cout << "\t\t\t\t                           Exiting Program.....                              \n";
            break;
        }

        else {
            cout << "\t\t\tInvalid Choice. Please Try Again.\n";
        }

        cout << "\nPress Enter to Return to Menu...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

    return 0;
}