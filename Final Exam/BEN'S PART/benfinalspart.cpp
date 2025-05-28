

// 26-87
class AcademicBST {
private:
    // Root node of the binary search tree
    StudentNode* root;

    // Helper function to insert a new student node into the BST
    StudentNode* insert(StudentNode* node, long studentNumber, const string& fullName, const string& ueEmail, const string& section, float grade) {
        // If current node is null (empty), create and return a new node
        if (node == nullptr)
            return new StudentNode(studentNumber, fullName, ueEmail, section, grade);

        // If studentNumber is less, insert into the left subtree
        if (studentNumber < node->studentNumber)
            node->left = insert(node->left, studentNumber, fullName, ueEmail, section, grade);
        // If studentNumber is greater, insert into the right subtree
        else if (studentNumber > node->studentNumber)
            node->right = insert(node->right, studentNumber, fullName, ueEmail, section, grade);

        // Return the (possibly updated) current node
        return node;
    }

    // Helper function to search for a student by student number (This looks for a student by their student number.)
    StudentNode* searchByNumber(StudentNode* node, long studentNumber) {
        // Base case: found the node or reached the end (If we find the student (or reach a dead-end), return the result.)
        if (node == nullptr || node->studentNumber == studentNumber)
            return node;
        
        // Decide to go left or right, depending on the number we’re looking for. 
        // Search left if target is smaller
        if (studentNumber < node->studentNumber)
            return searchByNumber(node->left, studentNumber);
        // Search right if target is larger
        else
            return searchByNumber(node->right, studentNumber);
    }

    // Helper function to delete a student node by student number (This function removes a student from the tree)
    StudentNode* deleteNode(StudentNode* node, long studentNumber) {
        // If the node is null, just return (If we can't find the student, just return.)
        if (node == nullptr) return node;

        // Recurse to the left if target is smaller
        // Keep looking left or right until we find the student to delete.
        if (studentNumber < node->studentNumber) {
            node->left = deleteNode(node->left, studentNumber);
        }
        // Recurse to the right if target is larger
        else if (studentNumber > node->studentNumber) {
            node->right = deleteNode(node->right, studentNumber);
        }
        // Found the student! Now we need to remove them.(Found the node to delete)
        else {
            // Case 1: If there’s no left child, replace the node with the right child.
            if (node->left == nullptr) {
                StudentNode* temp = node->right;
                delete node;
                return temp;
            }
            // Case 2: If there’s no right child, replace it with the left child.
            else if (node->right == nullptr) {
                StudentNode* temp = node->left;
                delete node;
                return temp;
            }

            // Case 3:(If the student has two children) Node has two children 
            // Find the in-order successor (smallest node in right subtree)
            StudentNode* temp = node->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }

            // Replace the deleted student’s data with the successor’s data. (Copy successor's data to current node) 
            node->studentNumber = temp->studentNumber;
            node->fullName = temp->fullName;
            node->ueEmail = temp->ueEmail;
            node->section = temp->section;
            node->grade = temp->grade;

            // Then delete the duplicate successor node. (Delete the in-order successor node)
            node->right = deleteNode(node->right, temp->studentNumber);
        }

        // Return the (updated) current node
        return node;
    }
};


// -------------------------------------------------------------------------------------------
//   331-368

void displaySortedBySection() {
    // Check if the studentTable is empty
    if (studentTable.empty()) {
        cout << "No students to display.\n";
        return; // Exit the function if there's nothing to display
    }

    // Create a vector to store pointers to all student nodes
    vector<StudentNode*> students;
    
    // Loop through the studentTable (probably an unordered_map or map)
    // and add each student node to the vector
    for (const auto& pair : studentTable) {
        students.push_back(pair.second);
    }

    // -------- Insertion Sort to sort students by section --------
    for (size_t i = 1; i < students.size(); ++i) {
        StudentNode* key = students[i];  // current student to be placed correctly
        int j = i - 1;

        // Compare and move students who have "higher" section names (lexicographically)
        while (j >= 0 && students[j]->section > key->section) {
            students[j + 1] = students[j];  // Shift student to the right
            --j;
        }
        students[j + 1] = key;  // Place the current student in the correct spot
    }

    // -------- Display the sorted list in table format --------
    cout << left << setw(15) << "Student No"
         << setw(30) << "Full Name"
         << setw(35) << "UE Email"
         << setw(12) << "Section"
         << setw(6) << "Grade" << endl;

    // Print a separator line
    cout << string(100, '-') << endl;

    // Loop through the sorted student list and print each one
    for (const auto& s : students) {
        cout << left << setw(15) << s->studentNumber
             << setw(30) << s->fullName
             << setw(35) << s->ueEmail
             << setw(12) << s->section
             << setw(6) << s->grade << endl;
    }
}
