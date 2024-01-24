// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "io.h"
#include "StMark.h"
#include "graph.h"
using namespace std;

namespace seneca {


    void printGraph(StMark* students, int numberOfStudents, const char* label) {
        int i, category[NUM_CATEGORIES] = { 0 };
        categorizing(students, numberOfStudents, category);
        int mostStudentsCategory = mostNumerousCategory(category);

        labelLine(79, label);
        for (i = NUM_CATEGORIES - 1; i >= 0; i--) {
            printInt((i + 1) * 10, 4, "| ");
            int barLength = printBar(category[i], mostStudentsCategory);
            printInt(category[i], GRAPH_WIDTH - (barLength - 6), "|");
            std::cout << std::endl;
        }
        line(79);
    }

    void categorizing(StMark* students, int numberOfStudents, int* category) {
        int i, k;
        for (i = 0; i < numberOfStudents; i++) {
            for (k = 0; k < NUM_CATEGORIES; k++) {
                int lowerLimit = (k == 0) ? 0 : (k * 10) + 1;
                int upperLimit = (k + 1) * 10;
                if (students[i].mark >= lowerLimit && students[i].mark <= upperLimit) category[k]++;
            }
        }
    }

    int mostNumerousCategory(int* category) {
        int i, numStudents = 0;
        for (i = 0; i < NUM_CATEGORIES; i++) if (category[i] > numStudents) numStudents = category[i];
        return numStudents;
    }

    int printBar(int val, int max) {
        int barLength = GRAPH_WIDTH * val / max;
        for (int i = 0; i < barLength; i++) std::cout << "*";
        std::cout << " ";
        return barLength;
    }
}