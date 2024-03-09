#ifndef HERO_H
#define HERO_H

#include "Power.h"

namespace seneca {

	class Hero {
	private:
		char name[MAX_NAME_LENGTH];
		int numPowers;
		int tier;
		Power* power;
	public:
		Hero();
		Hero(const char* name, Power _power[], int powerCount);
	};

}

#endif