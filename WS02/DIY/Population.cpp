#include "Population.h"
#include "File.h"
#include <iostream>
#include <cstring>
namespace sdds {
    popDir* population;

    bool getPostalCode(char* code) {
        int stst = 1;
        while (stst) {
            char temp[128];
            std::cout << "Population Report" << std::endl;
            std::cout << "-----------------" << std::endl;
            std::cout << "Enter postal code:" << std::endl << "> ";
            std::cin >> code;
            if (code[0] == '!') return false;
            else if (!strcmp(temp, "all")) {
                // INSERT CODE HERE
            }
            else {
                
            }
            
        }
    }
    
    bool load(const char* filename, const char* prefix) {
        int i;
        int numberOfAreas = numberOfRecords();
        auto fileOpened = openFile(filename);
        if (!fileOpened) {
            std::cout << "** Could not open the file ** " << std::endl;
            return false;
        }
        else {
            population = new popDir[numberOfAreas];
            for (i = 0; i < 15; i++) {
                auto validate = load(population[i]);
                if (!validate) return false;
            }
            closeFile();
        }
    }
}