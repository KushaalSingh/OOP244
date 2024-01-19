#ifndef SENECA_FILE_H
#define SENECA_FILE_H

#include <cstdio>
#include "StMark.h"

namespace seneca {
	const int MAX_NO_RECS = 1000;

	bool openFile(const char* fname);
	void closeFile();
	bool readMark(StMark* mark);
	int readMarks(StMark* marks);
}

#endif