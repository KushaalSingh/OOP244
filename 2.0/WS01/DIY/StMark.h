#include "io.h"

#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H

namespace seneca {
	typedef struct {
		char name[21];
		char surname[31];
		int mark;
	} StMark;

	bool printReport(const char* filename);
	void sort(StMark* students, int numberOfStudents);
	void printStudentList(StMark* students, int numberOfStudents);
}

#endif 
