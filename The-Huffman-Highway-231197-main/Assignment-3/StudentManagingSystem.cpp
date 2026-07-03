#include <iostream>
#include <string>
#include <map>
#include <limits> 
using namespace std;

struct Student {
    int roll_no;
    string name;
    string course;
    int total_marks;
};

class StudentRecordManagementSystem {
private:
    map<int, Student> students;

public:
    void insertStudent(int roll_no, string name, string course, int total_marks) {
        students[roll_no] = {roll_no, name, course, total_marks};
    }

    void deleteStudent(int roll_no) {
        auto it = students.find(roll_no);
        if (it != students.end()) {
            students.erase(it);
        } else {
            cout << "No student found with roll no " << roll_no << "." << endl;
        }
    }

    void showStudent(int roll_no) {
        auto it = students.find(roll_no);
        if (it != students.end()) {
            const Student& student = it->second;
            cout << "Name: " << student.name << ", Roll No: " << student.roll_no << ", Course: " << student.course << ", Total Marks: " << student.total_marks << endl;
        } else {
            cout << "No student found with roll no " << roll_no << "." << endl;
        }
    }

    void searchStudent(int roll_no) {
        auto it = students.find(roll_no);
        if (it != students.end()) {
            const Student& student = it->second;
            cout << "Student found - Name: " << student.name << ", Roll No: " << student.roll_no << ", Course: " << student.course << ", Total Marks: " << student.total_marks << endl;
        } else {
            cout << "No student found with roll no " << roll_no << "." << endl;
        }
    }
};

void print_menu() {
    cout << "Student Record Management System" << endl;
    cout << "1. Insert Student" << endl;
    cout << "2. Delete Student" << endl;
    cout << "3. Show Student" << endl;
    cout << "4. Search Student" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    StudentRecordManagementSystem rec;
    while (true) {
        print_menu();
        int command;
        cin >> command;

        switch (command) {
        case 5:
            return 0;
        case 1: {
            int roll_no, total_marks;
            string name, course;
            cout << "Enter roll number: ";
            cin >> roll_no;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Enter name: ";
            getline(cin, name);
            cout << "Enter course: ";
            getline(cin, course);
            cout << "Enter total marks: ";
            cin >> total_marks;
            rec.insertStudent(roll_no, name, course, total_marks);
            break;
        }
        case 2: {
            int roll_no;
            cout << "Enter roll number to delete: ";
            cin >> roll_no;
            rec.deleteStudent(roll_no);
            break;
        }
        case 3: {
            int roll_no;
            cout << "Enter roll number to show: ";
            cin >> roll_no;
            rec.showStudent(roll_no);
            break;
        }
        case 4: {
            int roll_no;
            cout << "Enter roll number to search: ";
            cin >> roll_no;
            rec.searchStudent(roll_no);
            break;
        }
        default:
            cout << "Invalid input, please try again." << endl;
        }
    }
    return 0;
}
