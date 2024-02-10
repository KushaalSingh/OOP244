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

	bool read(Assessment& assess, FILE* fptr) {
		double mk;
		char str[STRING_LEN];
		if (!read(mk, fptr) || !read(str, fptr)) return false;
		assess.m_mark = new double;
		*(assess.m_mark) = mk;
		assess.m_title = new char[strlen(str) + 1];
		strcpy(assess.m_title, str);
		return true;
	}

	void freeMem(Assessment*& aptr, int size) {
		int i;
		for (i = 0; i < size; i++) {
			delete aptr[i].m_mark;
			delete[] aptr[i].m_title;
		}
		delete[] aptr;
		aptr = nullptr;
	}

	int read(Assessment*& aptr, FILE* fptr) {
		int i, size, count = 0;
		read(size, fptr);
		aptr = new Assessment[size];
		for (i = 0; i < size; i++) {
			if (!read(aptr, fptr)) break;
			++count;
		}
		if (size != count) {
			delete[] aptr;
			return 0;
		}
		return size;
	}
}