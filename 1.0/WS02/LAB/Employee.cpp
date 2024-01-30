#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort(void) {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }

    bool load(void) {
        int i;
        auto opened = openFile("employees.csv");
        if (!opened) {
            cout << "Could not open data file: employees.csv" << endl;
            return false;
        }
        else {
            noOfEmployees = noOfRecords();
            employees = new Employee[noOfEmployees];
            for (i = 0; i < noOfEmployees; i++) {
                auto validate = read(employees[i].m_empNo) && read(employees[i].m_salary) && read(employees[i].m_name);
                if (!validate) {
                    cout << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                    return false;
                }
            }
            closeFile();
            return true;
        }
    }

    void display(Employee& emp) {
        cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
    }

    void display(void) {
        int i;
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;

        sort();

        for (i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << "- ";
            display(employees[i]);
        }
    }

    void deallocateMemory(void) {
        int i;
        for (i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;
        }
        delete[] employees;
    }
 
}