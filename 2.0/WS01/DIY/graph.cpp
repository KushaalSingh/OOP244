// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "io.h"
#include "StMark.h"
#include "graph.h"
using namespace std;

namespace seneca {


    void printGraph(StMark* students, int numberOfStudents, const char* label) {
        int category[NUM_CATEGORIES] = { 0 };
        labelLine(79, label);
        categorizing(students, numberOfStudents, category);
        int mostStudentsCategory = mostNumerousCategory(category);
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

    

    /*void _printgraph(int samples[], int noofsamples, const char* label) {
        int max = findmax(samples, noofsamples);
        labelline(graph_width + 10, label);
        for (int i = 0; i < noofsamples; i++) {
            printbar(samples[i], max);
        }
        line(graph_width + 10);
    }

    void _printBar(int val, int max) {
        int i;
        int barlength = GRAPH_WIDTH * val / max;
        cout << "| ";
        for (i = 0; i < barlength; i++) {
            cout << "*";
        }
        cout << " ";
        printInt(val, (GRAPH_WIDTH + 6 - barlength));
        cout << "|" << endl;
    }

    void getSamples(int samples[], int noOfSamples) {
        int i;
        for (i = 0; i < noOfSamples; i++) {
            line(28);
            cout << "\\ " << (i + 1) << "/";
            printInt(noOfSamples, 2);
            cout << ":                    /";
            goBack(20);
            samples[i] = getInt(1, 1000000);
        }
    }*/
}