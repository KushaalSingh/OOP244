#include "Assessment.h"

namespace seneca {

	bool read(int& value, FILE* fptr) {
		return fscanf(fptr, "%d", &value) == 1;
	}

	bool read(double& value, FILE* fptr) {
		return fscanf(fptr, "%lf", &value) == 1;
	}

	bool read(char* cstr, FILE* fptr) {
		return fscanf(fptr, ",%60[^\n]\n", cstr) == 1;
	}

	bool read(Assessment& assess, FILE* fptr) {
		double tempMark;
		char tempTitle[STRING_LEN];

		if (read(tempMark, fptr) && read(tempTitle, fptr)) {
			assess.m_mark = new double[tempMark];
			assess.m_title = new char[STRING_LEN];
			strcpy(assess.m_title, tempTitle);
			return true;
		}

		return false;
	}

}