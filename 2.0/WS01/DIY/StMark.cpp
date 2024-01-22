// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include "StMark.h"
#include "io.h"
#include "file.h"

namespace seneca {

	bool printReport(const char* filename) {
		int i;
		StMark stu[MAX_NO_RECS] = { 0 };

		openFile(filename);
		int stuNum = readMarks(stu);
		sort(stu, stuNum);
		labelLine(79, "Students' mark distribution");
		for (i = 0; i < stuNum; ++i) {
			std::cout << i + 1;
			if (i < 9) std::cout << "++: " << std::endl;
			else if (i >= 9 && i < 99) std::cout << "+: " << std::endl;
			else std::cout << ": " << std::endl;
		}
		
		
		closeFile();
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
}