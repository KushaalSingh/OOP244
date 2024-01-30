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
        char temp[128];
        temp[0] = '\0';
        auto val = fscanf(fptr, "%127[^\n]\n", temp);
        if (val) {
            name = new char[(int)strlen(temp) + 1];
            strcpy(name, temp);
            return true;
        }
        return false;
    }

    bool read(int& empNum) {
        auto val = fscanf(fptr, "%d,", &empNum);
        if (val) return true;
        else return false;
    }

    bool read(double& empSal) {
        auto val = fscanf(fptr, "%lf,", &empSal);
        return val != 0;
    }
}