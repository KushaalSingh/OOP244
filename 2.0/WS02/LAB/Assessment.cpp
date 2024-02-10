#include "Assessment.h"

namespace seneca {

	bool read(int& value, FILE* fptr) {
		return fscanf(fptr, "%d", &value);
	}

	bool read(double& value, FILE* fptr) {
		return fscanf(fptr, "%lf", &value);
	}

	bool read(char* cstr, FILE* fptr) {
		return fscanf(fptr, ",%60[^\n]\n", cstr);
	}

	bool read(Assessement& assess, FILE* fptr) {
		double mk;
		char str[STRING_LEN];
		if (!read(mk, fptr) || !read(str, fptr)) return false;
		assess.m_mark = new double;
		*assess.m_mark = mk;
		assess.m_title = new char[strlen(str) + 1];
		strcpy(assess.m_title, str);
		return true;
	}

}