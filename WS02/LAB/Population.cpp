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

    bool load(Employee& emp) {
        auto success = read(emp.m_name) && read(emp.m_empNo) && read(emp.m_salary);
        return success;
    }

    bool load(void) {
        int i;

        if (!(openFile("employees.csv"))) {
            cerr << "Could not open data file: data_file_name" << endl;
        }
        noOfEmployees = noOfRecords();
        employees = new Employee[noOfEmployees];
        
        for (i = 0; i < noOfEmployees; i++) {
            auto check = load(employees[i]);
            if (!check) {
                cerr << "Error: incorrect number of records read; the data is possibly corrupted." << endl;
                return false;
            }
            closeFile();
        }
        return true;
    }

    void display(const Employee& emp) {
        cout << emp.m_empNo << ": " << emp.m_name << ", $" << emp.m_salary << endl;
    }

    void display(void) {
        int i;

        cout << "Employee Salary report, sorted by employee number" << endl << "no- Empno, Name, Salary" << endl
            << "------------------------------------------------" << endl;

        for (i = 0; i < noOfEmployees; i++) {
            cout << i + 1 << ": ";
            display(employees[i]);
        }
    }

    void deallocateMemory(void) {
        if (employees != nullptr) {
            delete[] employees;
        }
        employees = nullptr;
    }

}