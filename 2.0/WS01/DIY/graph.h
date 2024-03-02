#ifndef GRAPH_H
#define GRAPH_H

namespace seneca {
	const int NUM_CATEGORIES = 10;
	const int GRAPH_WIDTH = 65;

	void printGraph(StMark* students, int numberOfStudents, const char* label);
	void categorizing(StMark* students, int numberOfStudents, int* category);
	int mostNumerousCategory(int* category);
	int printBar(int val, int max);
}

#endif