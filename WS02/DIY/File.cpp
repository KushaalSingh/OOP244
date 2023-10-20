#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }

    void closeFile(void) {
        if (fptr) fclose(fptr);
    }

    bool read(const char* userInput, char*& prefix) {
        char temp[4];
        temp[0] = '\n';
        auto torf = fscanf(fptr, "%3[^,],", temp);
        if (torf) {
            if (!strcmp(userInput, temp)) {
                
            }
        }
        return false;
    }

    bool read(int& population) {
        auto torf = fscanf(fptr, "%d\n", &population);
        if (torf) return true;
        else return false;
    }

    int numberOfRecords(void){
        int numOfRecs = 0;
        char ch;
        if (fscanf(fptr, "%c", &ch) == 1) {
            numOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return numOfRecs;
    }

    int findMatch(const char* userInput) {
        int pop = 0;
        char temp[4];
        temp[0] = '\0';
        int numMatches = 0;
        while (fscanf(fptr, "%3[^,],%9d\n", temp, pop)) {
            const char* result = strstr(temp, userInput);
            if (result != nullptr) {
                numMatches += 1;
            }
        }
        return numMatches;
    }
}