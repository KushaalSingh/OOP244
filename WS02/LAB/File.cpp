#include "File.h"

namespace sdds {
    FILE* fptr;

    bool openFile(const char filename[]) {
        fptr = fopen(filename, "r");
        return fptr != NULL;
    }
    
    int noOfRecords() {
        int noOfRecs = 0;
        char ch;
        while (fscanf(fptr, "%c", &ch) == 1) {
            noOfRecs += (ch == '\n');
        }
        rewind(fptr);
        return noOfRecs;
    }

    void closeFile() {
        if (fptr) fclose(fptr);
    }

    bool read(char*& name) {
        char buffer[BUF_LEN];
        if (fscanf(fptr, "%127[^\n]\n", buffer) == 1) {
            name = new char[strlen(buffer) + 1];
            strcpy(name, buffer);
            return true;
        }
        return false;
    }

    bool read(int& empNum) {
        if (fscanf(fptr, "%d,", &empNum) == 1) return true;
        return false;
    }

    bool read(double& sal) {
        if (fscanf(fptr, "%lf,", &sal) == 1) return true;
        return false;
    }
}