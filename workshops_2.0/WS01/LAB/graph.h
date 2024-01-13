// I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H

namespace seneca {

	const int MAX_NO_OF_SAMPLES = 20;
	const int GRAPH_WIDTH = 65;

	int findMax(int samples[], int noOfSamples);
	void getSamples(int samples[], int noOfSamples);
	void printGraph(int samples[], int noOfSamples, const char* label);
	void printBar(int val, int max);



}

#endif
