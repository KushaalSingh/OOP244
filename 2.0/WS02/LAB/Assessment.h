#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

#ifndef ASSESSMENT_H
#define ASSESSMENT_H

namespace seneca {

	const int STRING_LEN = 60 + 1; // 1 for '\0'

	typedef struct {
		double* m_mark;
		char* m_title;
	} Assessment;

	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);
	bool read(Assessment& assess, FILE* fptr);
	void freeMem(Assessment*& aptr, int size);
	int read(Assessment*& aptr, FILE* fptr);

}

#endif 
