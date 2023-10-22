#include <iostream>
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_
#define DATAFILE "employees.csv"
namespace sdds {

    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };

    void sort(void);

    bool load(void);

    void display(Employee& emp);

    void display(void);

    void deallocateMemory(void);

}
#endif
