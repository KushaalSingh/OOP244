#ifndef SENECA_GRAPH_H
#define SENECA_GRAPH_H

namespace seneca {
	void printGraph(int samples[], int noOfSamples, const char* label);
	void printBar(int val, int max);
	void getSamples(int samples[], int noOfSamples);
	int findMax(int samples[], int noOfSamples);
}

#endif
