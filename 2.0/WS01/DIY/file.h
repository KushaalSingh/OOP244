#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "StMark.h"

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