#ifndef SENECA_TIME_CPP
#define SENECA_TIME_CPP

#include "Utils.h"

namespace seneca {

	class Time {
	private:
		uint32_t minutes;
		Time& reset();
	public:
		Time(unsigned int min = 0u);
		std::ostream& write(std::ostream& print = std::cout);
	};

}

#endif 