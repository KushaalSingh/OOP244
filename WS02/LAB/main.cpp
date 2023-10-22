#include "Employee.h"
using namespace sdds;
int main(void) {
    if (load()) {
        display();
    }
    deallocateMemory();
    return 0;
}