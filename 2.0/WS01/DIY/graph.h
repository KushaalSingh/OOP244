// I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H

namespace seneca {
	
	const int NUM_CATEGORIES = 10;
	const int GRAPH_WIDTH = 65;

	/*void _printGraph(int samples[], int noOfSamples, const char* label);
	void _printBar(int val, int max);
	void getSamples(int samples[], int noOfSamples);*/

	void printHistogram(StMark* stu, int stuNum, const char* label);
	void categorizing(StMark* stu, int stuNum, int* category);
	int mostNumerousCategory(int* category);

}

#endif