#include <iostream>
#include "Population.h"
using namespace sdds;
int main(void) {
    char code[4]{};
    while (getPostalCode(code)) {
        if (load("PCpopulationsComplete.csv", code)) {
            display();
        }
        deallocateMemory();
    }
    return 0;
}