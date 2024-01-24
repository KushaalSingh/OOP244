// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "StMark.h"
#include "graph.h"
#include "io.h"
#include "file.h"

namespace seneca {

	bool printReport(const char* filename) {
		StMark stu[MAX_NO_RECS] = { 0 };

		openFile(filename);
		int stuNum = readMarks(stu);
		closeFile();
		sort(stu, stuNum);
		

		printGraph(stu, stuNum, "Students' mark distribution");
		printStudentList(stu, stuNum);
		
		
		return true;
	}

	void sort(StMark* stu, int numStu) {
		int i, k;
		StMark temp;
		for (i = 0; i < numStu - 1; i++) {
			for (k = 0; k < numStu - i - 1; k++) {
				if (stu[k].mark < stu[k + 1].mark) {
					temp = stu[k];
					stu[k] = stu[k + 1];
					stu[k + 1] = temp;
				}
			}
		}
	}

	void printStudentList(StMark* stu, int stuNum) {
		int i;
		for (i = 0; i < stuNum; i++) {
			std::cout << i + 1;
			if (i < 9) std::cout << "  : ";
			else if (i >= 9 && i < 99) std::cout << " : ";
			else std::cout << ": ";
			std::cout << "[" << stu[i].mark;
			if (stu[i].mark < 10) std::cout << "  ] ";
			else if (stu[i].mark >= 9 && stu[i].mark <= 99) std::cout << " ] ";
			else std::cout << "] ";
			std::cout << stu[i].name << " " << stu[i].surname << std::endl;
		}
	}
}