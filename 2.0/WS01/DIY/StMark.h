#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H

namespace seneca {
	typedef struct {
		char name[21];
		char surname[31];
		int mark;
	} StMark;

	bool printReport(const char* filename);
}

#endif 
