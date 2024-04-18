#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Employee {
    string surname;
    string initials;
    string position;
    int hire_year;
    double salary;
};

void inputEmployee(Employee& employee) {
    cout << "Enter surname: ";
    cin >> employee.surname;
    cout << "Enter initials: ";
    cin >> employee.initials;
    cout << "Enter position: ";
    cin >> employee.position;
    cout << "Enter hire year: ";
    cin >> employee.hire_year;
    cout << "Enter salary: ";
    cin >> employee.salary;
}

void printEmployee(const Employee& employee) {
    cout << "Surname: " << employee.surname << "\nInitials: " << employee.initials
        << "\nPosition: " << employee.position
        << "\nHire Year: " << employee.hire_year
        << "\nSalary: " << employee.salary << endl;
}

void saveToFile(const vector<Employee>& employees, const string& filename) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    for (const auto& employee : employees) {
        file.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));
    }

    file.close();
}

void loadFromFile(vector<Employee>& employees, const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    Employee employee;
    while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
        employees.push_back(employee);
    }

    file.close();
}

int main() {
    vector<Employee> employees;
    string filename;
    cout << "Enter filename: ";
    cin >> filename;

    loadFromFile(employees, filename);

    while (true) {
        cout << "1. Add employee\n2. Edit employee\n3. Print employee\n4. Print all employees\n5. Save and exit\n";
        int choice;
        cin >> choice;
        if (choice == 1) {
            Employee employee;
            inputEmployee(employee);
            employees.push_back(employee);
        }
        else if (choice == 2) {
            string surname;
            cout << "Enter surname: ";
            cin >> surname;
            for (auto& employee : employees) {
                if (employee.surname == surname) {
                    inputEmployee(employee);
                    break;
                }
            }
        }
        else if (choice == 3) {
            string surname;
            cout << "Enter surname: ";
            cin >> surname;
            for (const auto& employee : employees) {
                if (employee.surname == surname) {
                    printEmployee(employee);
                    break;
                }
            }
        }
        else if (choice == 4) {
            for (const auto& employee : employees) {
                printEmployee(employee);
                cout << endl;
            }
        }
        else if (choice == 5) {
            saveToFile(employees, filename);
            break;
        }
    }

    return 0;
}
