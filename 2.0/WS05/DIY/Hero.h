#ifndef HERO_H
#define HERO_H

#include "Power.h"

#define NL std::endl

namespace seneca {

	class Hero {
	private:
		char name[MAX_NAME_LENGTH];
		int power_count;
		int power_level;
		Power* power;
		void setEmpty();
	public:
		Hero();
		Hero(const char* name, Power _power[], int powerCount);
		std::ostream& displayHeroInfo(std::ostream& print = std::cout) const;
		Hero& operator+=(Power& pwr);
	};

	int updatePowerLevel(Power* pwr, int power_count);


}

#endif