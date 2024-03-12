/*
Citation and Sources...
Final Project Milestone 1
Module: Utils
Filename: Utils.cpp
Version  1.0
Author   Kushaal Singh
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "Time.h"

namespace seneca {

	Time& Time::reset() {
		minutes = U.getTime();
		return *this;
	}

	Time::Time(unsigned int min) {
		minutes = min;
	}

	std::ostream& Time::write(std::ostream& out) const {
		uint32_t hours = minutes / 60;
		uint32_t mints = minutes % 60;
		out.width(2);
		out.fill('0');
		out << hours << ":";
		out.width(2);
		out << mints << std::endl;
	}

	std::istream& Time::read(std::istream& in = std::cin) {
		uint32_t hours = 0, mints = 0;
		char divd;
		in >> hours >> divd >> mints;
		if (divd != ':') {
			in.setstate(std::ios::failbit);
			return in;
		}
		else minutes = hours * 60 + mints;
		return in;
	}

	Time::operator unsigned int() const {
		return minutes;
	}

	Time& Time::operator*=(int val) {
		minutes += val;
		return *this;
	}

	Time& Time::operator-=(const Time& D) {
		if (minutes <= D.minutes) minutes = (minutes + 1440) - D.minutes;	// Check <= if any error appear.
		else minutes = minutes - D.minutes;
		return *this;
	}

	Time Time::operator-(const Time& T) const {
		Time temp;
		temp -= T;
		return temp;
	}

}