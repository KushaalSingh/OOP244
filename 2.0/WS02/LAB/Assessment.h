#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

#ifndef SENECA_ASSESSMENT_H
#define SENECA_ASSESSMENT_H

namespace seneca {

	const int STRING_LEN = 60 + 1; // 1 for '\0'

	typedef struct {
		double* m_mark;
		char* m_title;
	} Assessement;

	bool read(int& value, FILE* fptr);
	bool read(double& value, FILE* fptr);
	bool read(char* cstr, FILE* fptr);
	bool read(Assessement& assess, FILE* fptr);
	void freeMem(Assessment*& aptr, int size);
	int read(Assessment*& aptr, FILE* fptr);

}

#endif 
