#include "StMark.h"
#include "graph.h"
#include "io.h"
#include "file.h"

namespace seneca {
	bool printReport(const char* filename) {
		StMark students[MAX_NO_RECS] = { 0 };

		openFile(filename);
		int numberOfStudents = readMarks(students);
		closeFile();

		sort(students, numberOfStudents);
		printGraph(students, numberOfStudents, "Students' mark distribution");
		printStudentList(students, numberOfStudents);
		
		return true;
	}

	void sort(StMark* students, int numberOfStudents) {
		int i, k;
		StMark temp;
		for (i = 0; i < numberOfStudents - 1; i++) {
			for (k = 0; k < numberOfStudents - i - 1; k++) {
				if (students[k].mark < students[k + 1].mark) {
					temp = students[k];
					students[k] = students[k + 1];
					students[k + 1] = temp;
				}
			}
		}
	}

	void printStudentList(StMark* students, int numberOfStudents) {
		int i;
		for (i = 0; i < numberOfStudents; i++) {
			printInt(i + 1, 3, ": ");
			std::cout << "[";
			printInt(students[i].mark, 3, "] ");
			std::cout << students[i].name << " " << students[i].surname << std::endl;
		}
		std::cout << "----------------------------------------" << std::endl;
	}
}