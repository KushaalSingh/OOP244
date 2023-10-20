#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
namespace sdds {

	typedef struct {
		char* prefix;
		int population;
	} popDir;

	// returns true of the cstring starts with subString
	bool startsWith(const char* cString, const char* subString);

	bool load(popDir& info);

	bool load(void);

	void display(popDir& stats);

	void display(void);

}
#endif