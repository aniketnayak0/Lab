#include <iostream>
using namespace std;

class EMPLOYEE {
private:
    int empNumber;
    string empName;
    float basic;
    float DA;
    float IT;
    float netSalary;

public:
    void inputEmployeeData() {
        cout << "Enter Employee Number: ";
        cin >> empNumber;
        cout << "Enter Employee Name: ";
        cin >> empName;
        cout << "Enter Basic Salary: ";
        cin >> basic;
        DA = 0.52 * basic;
        float grossSalary = basic + DA;
        IT = 0.30 * grossSalary;
        netSalary = grossSalary - IT;
    }
    void printEmployeeData() const {
        cout << "\nEmployee Number: " << empNumber << endl;
        cout << "Employee Name: " << empName << endl;
        cout << "Basic Salary: " << basic << endl;
        cout << "DA: " << DA << endl;
        cout << "IT: " << IT << endl;
        cout << "Net Salary: " << netSalary << endl;
    }
};

int main() {
    int N;
    cout << "Enter the number of employees: ";
    cin >> N;
    EMPLOYEE employee;
    for (int i = 0; i < N; i++) {
        cout << "\nEnter details for employee " << i + 1 << ":" << endl;
        employee.inputEmployeeData();
        employee.printEmployeeData();
    }

    return 0;
}
