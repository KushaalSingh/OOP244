// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "io.h"
#include "StMark.h"
#include "graph.h"
using namespace std;

namespace seneca {


    void printHistogram(StMark* stu, int stuNum, const char* label) {
        int category[NUM_CATEGORIES] = { 0 };
        labelLine(79, label);
        categorizing(stu, stuNum, category);
        int maxStudents = mostNumerousCategory(category);
    }

    void categorizing(StMark* stu, int stuNum, int* category) {
        int i, k;
        for (i = 0; i < stuNum; i++) {
            for (k = 0; k < NUM_CATEGORIES; k++) {
                int lowerLimit = (k == 0) ? 0 : (k * 10) + 1;
                int upperLimit = (k + 1) * 10;
                if (stu[i].mark >= lowerLimit && stu[i].mark <= upperLimit) category[k]++;
            }
        }
    }

    int mostNumerousCategory(int* category) {
        int i, numStudents = 0;
        for (i = 0; i < NUM_CATEGORIES; i++) if (category[i] > numStudents) numStudents = category[i];
        return numStudents;
    }

    

    void _printgraph(int samples[], int noofsamples, const char* label) {
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
    }
}