#include <iostream>
#include <iomanip>
using namespace std;

// Maximum number of samples in an graph
const int MAX_NO_OF_SAMPLES = 20;
const int GRAPH_WIDTH = 65;
// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);
// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70. 
int findMax(int samples[], int noOfSamples);
// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);
// Prints a graph comparing the sample values visually 
void printGraph(int samples[], int noOfSamples, const char* label);
// prints the int value in width of fieldWidth
void printInt(int value, int fieldWidth);
// erturns number of digits in an integer
int intDigits(int value);
// Performs a fool-proof integer entry assuming the user will only enter numeric values.
// if the user enters non digit values, the function will hang in an endless loop.
int getInt(int min, int max);
// moves the cursor backwards
void goBack(int n);
// displays the user interface menu
int menu(int noOfSamples);
// prints samples error message
void samplesFirst();
// Draws a line and adds a label
void labelLine(int n, const char* label);
// Draws a line
void line(int n);