// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "io.h"
#include "StMark.h"
#include "graph.h"
using namespace std;

namespace seneca {
    const int MAX_NO_OF_SAMPLES = 20;
    const int GRAPH_WIDTH = 65;

    void printGraph(StMark* stu, int stuNum, const char* label) {
        int category[10] = { 0 };
        labelLine(79, label);

        //cateogryWithMostStudents(stu, stuNum, category);
        for (int i = 0; i < 9; i++) {
            std::cout << category[i] << std::endl;
        }
    }

    int cateogryWithMostStudents(StMark* stu, int stuNum, int* category) {
        int i;
       
        for (i = 0; i < stuNum; i++) {
            if (stu[i].mark >= 0 && stu[i].mark <= 10) category[0]++;
            else if (stu[i].mark >= 11 && stu[i].mark <= 20) category[1]++;
            else if (stu[i].mark >= 21 && stu[i].mark <= 30) category[2]++;
            else if (stu[i].mark >= 31 && stu[i].mark <= 40) category[3]++;
            else if (stu[i].mark >= 41 && stu[i].mark <= 50) category[4]++;
            else if (stu[i].mark >= 51 && stu[i].mark <= 60) category[5]++;
            else if (stu[i].mark >= 61 && stu[i].mark <= 70) category[6]++;
            else if (stu[i].mark >= 71 && stu[i].mark <= 80) category[7]++;
            else if (stu[i].mark >= 81 && stu[i].mark <= 90) category[8]++;
            else if (stu[i].mark >= 91 && stu[i].mark <= 100) category[9]++;
        }
    }







    void _printGraph(int samples[], int noOfSamples, const char* label) {
        int max = findMax(samples, noOfSamples);
        labelLine(GRAPH_WIDTH + 10, label);
        for (int i = 0; i < noOfSamples; i++) {
            printBar(samples[i], max);
        }
        line(GRAPH_WIDTH + 10);
    }

    void printBar(int val, int max) {
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

    int findMax(int samples[], int noOfSamples) {
        int max = samples[0];
        int i;
        for (i = 1; i < noOfSamples; i++) {
            if (max < samples[i]) max = samples[i];
        }
        return max < GRAPH_WIDTH ? GRAPH_WIDTH : max;
    }
}