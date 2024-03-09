#include "Hero.h"

namespace seneca {

	Hero::Hero() {
		setEmpty();
	}

	Hero::Hero(const char* _name, Power _power[], int powerCount) {
		setEmpty();
		if (_name != nullptr) strcpy(name, _name);
		power_count = powerCount;
		power = new Power[power_count];
		for (int i = 0; i < power_count; i++) power[i] = _power[i];
		power_level = updatePowerLevel(power, power_count);
	}

	std::ostream& Hero::displayHeroInfo(std::ostream& print) const {
		print << "Name: " << name << NL;
		print << "List of available powers:" << NL;
		for (int i = 0; i < power_count; i++) print << "  " << power[i].checkName() << NL;
		print << "Power Level:" << power_level;
		return print;
	}

	Hero& Hero::operator+=(Power& pwr) {
		power[power_count++] = pwr;
		power_level = updatePowerLevel(power, power_count);
		return *this;
	}

	Hero& Hero::operator-=(int decrement) {
		power_level -= decrement;
		return *this;
	}
	
	bool operator<(Hero& lhs, Hero& rhs) {
		return lhs.returnLevel() < rhs.returnLevel();
	}

	bool operator>(Hero& lhs, Hero& rhs) {
		return lhs.returnLevel() > rhs.returnLevel();
	}

	void operator>>(Power& power, Hero& hero) {
		hero += power;
	}

	void operator<<(Hero& hero, Power& power) {
		hero += power;
	}

	void Hero::setEmpty() {
		name[0] = '\0';
		power_count = 0;
		power_level = 0;
		power = nullptr;
	}

	int Hero::returnLevel() {
		return power_level;
	}

	int updatePowerLevel(Power* pwr, int power_count) {
		int total_rarity = 0;
		for (int i = 0; i < power_count; i++) total_rarity += pwr[i].checkRarity();
		return total_rarity * power_count;
	}

}