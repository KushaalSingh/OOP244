#include <iostream>

#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {

    typedef struct {
        char* m_name;
        int m_empNo;
        double m_salary;
    } Employee;

    void sort(void);

    bool load(Employee& emp);
    
    bool load(void);

    void display(void);

    void deallocateMemory(void);
    
}
#endif // SDDS_EMPLOYEE_H_