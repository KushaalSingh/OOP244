// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

#ifndef SENECA_FILE_H
#define SENECA_FILE_H

namespace seneca {
	const int MAX_NO_RECS = 1000;

	bool openFile(const char* fname);
	void closeFile();
	bool readMark(StMark* mark);
	int readMarks(StMark* marks);
}

#endif