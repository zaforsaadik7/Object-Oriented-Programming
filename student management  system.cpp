#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

class student {
private:
    int rollno, age;
    string name;

public:
    student(int stdRollno, int stdAge, string stdName) {
        rollno = stdRollno;
        age = stdAge;
        name = stdName;
    }

    void setroll(int stdRollno) {
        rollno = stdRollno;
    }

    void setName(string stdName) {
        name = stdName;
    }

    void setage(int stdAge) {
        age = stdAge;
    }

    int getroll() const {
        return rollno;
    }

    int getage() {
        return age;
    }

    string getname() {
        return name;
    }

    void displayStudent() const {
        cout << "Roll no: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    void writeToFile(ofstream& file) const {
        file << rollno << "," << name << "," << age << "\n";
    }
};

void readFromFile(vector<student>& students) {
    ifstream file("studentDetails.csv");
    if (!file.is_open()) {
        cout << "File does not exist yet or could not be opened!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string token;
        int roll, age;
        string name;

        getline(ss, token, ',');
        roll = stoi(token);

        getline(ss, name, ',');

        getline(ss, token, '\n');
        age = stoi(token);

        student newStudent(roll, age, name);
        students.push_back(newStudent);
    }
    file.close();
}

void writeAllToFile(vector<student>& students) {
    ofstream file("studentDetails.csv");
    if (!file.is_open()) {
        cout << "Error in opening the file!" << endl;
        return;
    }

    sort(students.begin(), students.end(), [](const student& a, const student& b) {
        return a.getroll() < b.getroll();
    });

    for (const auto& s : students) {
        s.writeToFile(file);
    }
    file.close();
}

void DisplayAllStudent(vector<student>& students) {
    vector<student> allStudents;
    readFromFile(allStudents);

    if (allStudents.empty()) {
        cout << "\t No students found..." << endl;
        return;
    }

    for (const auto& s : allStudents) {
        s.displayStudent();
        cout << endl;
    }
}

void addNewStudent(vector<student>& students) {
    int rollno, age;
    string name;
    cout << "Enter Roll:";
    cin >> rollno;
    cout << endl;

    for (const auto& s : students) {
        if (s.getroll() == rollno) {
            cout << "\tStudent already exists..." << endl;
            return;
        }
    }

    cout << "Enter Name:";
    cin.ignore();
    getline(cin, name);
    cout << endl;

    cout << "Enter Age:";
    cin >> age;
    cout << endl;

    student newStudent(rollno, age, name);
    students.push_back(newStudent);

    writeAllToFile(students);
    cout << "\tStudent added successfully" << endl;
}

void DeleteStudent(vector<student>& students) {
    string name;
    cout << "Enter Name to delete:";
    cin.ignore();
    getline(cin, name);

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->getname() == name) {
            students.erase(it);
            writeAllToFile(students);
            cout << "\tStudent removed successfully" << endl;
            return;
        }
    }
    cout << "\tStudent not found" << endl;
}




void SearchStudent(vector<student>& students) {
    int roll;
    cout << "\t\tEnter Your Roll: ";
    cin >> roll;
    bool found = false;
    for (const auto& s : students) {
        if (s.getroll() == roll) {
            cout << "\t\t-----Student Found-------" << endl;
            s.displayStudent();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "\t\tStudent not found" << endl;
    }
}

void UpdateStudent(vector<student>& students) {
    int roll;
    cout << "\t\tEnter Roll of Student to Update: ";
    cin >> roll;
    bool found = false;
    for (auto& s : students) {
        if (s.getroll() == roll) {
            found = true;
            cout << "\t\t-------Student Found:--------" << endl;
            cout << "\t\tUpdate Your Name" << endl;
            cout << "\t\tUpdate Your Roll" << endl;
            cout << "\t\tUpdate Your Age" << endl;
            cout << "\t\tEnter Your choice: ";
            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                int newRoll;
                cout << "\t\tEnter new Roll no: ";
                cin >> newRoll;
                s.setroll(newRoll);
                break;
            }
            case 2: {
                string newName;
                cout << "\t\tEnter new Name: ";
                cin.ignore();
                getline(cin, newName);
                s.setName(newName);
                break;
            }
            case 3: {
                int newAge;
                cout << "\t\tEnter new Age: ";
                cin >> newAge;
                s.setage(newAge);
                break;
            }
            default:
                cout << "\t\tInvalid Number" << endl;
            }
            writeAllToFile(students);
            cout << "\t\tStudent Updated Successfully" << endl;
            break;
        }
    }
    if (!found) {
        cout << "\t\tStudent not found" << endl;
    }
}






int main() {
    vector<student> students;
    readFromFile(students);

    char choice;
    do {
        system("cls");
        int op;
        cout << "\t\t------------------------------" << endl;
        cout << "\t\t**Student Management System**\t" << endl;
        cout << "\t\t------------------------------" << endl;

        cout << "\t1. Add Student" << endl;
        cout << "\t2. Display all students" << endl;
        cout << "\t3. Search Student" << endl;
        cout << "\t4. Update Student" << endl;
        cout << "\t5. Delete Student" << endl;
        cout << "\t6. Exit" << endl;
        cout << "\tEnter your choice:" << endl;
        cin >> op;

        switch (op) {
        case 1:
            addNewStudent(students);
            break;
        case 2:
            DisplayAllStudent(students);
            break;
        case 3:
            SearchStudent(students);
            break;
        case 4:
            UpdateStudent(students);
            break;
        case 5:
            DeleteStudent(students);
            break;
        case 6:
            exit(1);
        default:
            cout << "\tInvalid Number..." << endl;
        }

        cout << "Do you want to continue [Yes/No]? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
