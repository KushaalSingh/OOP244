#include "Time.h"

namespace seneca {

	Time& Time::reset() {
		minutes = U.getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		minutes = min;
	}

	std::ostream& Time::write(std::ostream& print = std::cout) {
		uint32_t hours = minutes / 
	}

}