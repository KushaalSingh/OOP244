// I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H

namespace seneca {
	
	const int NUM_CATEGORIES = 10;
	const int GRAPH_WIDTH = 65;

	/*
	void _printBar(int val, int max);*/

	void printGraph(StMark* students, int numberOfStudents, const char* label);
	void categorizing(StMark* students, int numberOfStudents, int* category);
	int mostNumerousCategory(int* category);
	void printBar(int val, int max);

}

#endif