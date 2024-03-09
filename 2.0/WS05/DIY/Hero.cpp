#include "Hero.h"

namespace seneca {

	Hero::Hero() {
		name[0] = '\0';
 		numPowers = 0;
		tier = 0;
		power = nullptr;
	}

	Hero::Hero(const char* _name, Power _power[], int powerCount) {
		if (_name != nullptr) strcpy(name, _name);
		numPowers = powerCount;
		power = new Power[numPowers];
		for (int i = 0; i < numPowers; i++) {

		}
	}

}