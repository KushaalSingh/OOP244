#include "Flight.h"

namespace sdds {

	Flight::Flight() {
		setFlightToEmpty();
	}

	Flight::Flight(int passengers, double fuel, const char* title) {
		bool valid = (passengers > 0 && passengers < MAX_PSG_CAP) && (fuel > 0.00 && fuel < MAX_FUL_CAP);
		if (valid) {
			m_passangers = passengers;
			m_fuel = fuel;
			m_title = new char[(int)strlen(title) + 1];
			strcpy(m_title, title);
		}
		else setFlightToEmpty();
	}

	Flight::~Flight() {
		delete[] m_title;
		m_title = nullptr;
	}

	std::ostream& Flight::display() const {
		if (!readyToDepart()) {
			if (~*this) std::cout << " Flight  |  Empty Plane";
			else if (m_fuel < returnMinFuel()) {
				std::cout << " Flight  |  Low Fuel";
				std::cout.width(18);
				std::cout.setf(std::ios::right);
				std::cout << m_title;
				std::cout << " | Pass:";
				std::cout.width(11);
				std::cout << m_passangers << " |";
				std::cout.width(13);
				std::cout.setf(std::ios::fixed);
				std::cout.precision(2);
				std::cout << m_fuel << " Liters";
				std::cout.unsetf(std::ios::right);
				std::cout.unsetf(std::ios::fixed);
			}
		}
		else {
			std::cout << " Flight  |  Ready to Depart";
			std::cout.width(11);
			std::cout.setf(std::ios::right);
			std::cout << m_title;
			std::cout << " | Pass:";
			std::cout.width(11);
			std::cout << m_passangers << " |";
			std::cout.width(13);
			std::cout.setf(std::ios::fixed);
			std::cout.precision(2);
			std::cout << m_fuel << " Liters";
			
		}
		return std::cout;
	}

	Flight::operator bool() const {
		return (m_passangers > 0) && (m_fuel >= returnMinFuel());
	}

	Flight::operator int() const {
		return m_passangers;
	}

	Flight::operator double() const {
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		return m_fuel;
	}

	Flight::operator const char* () const {
		return m_title;
	}

	bool Flight::operator~() const {
		return m_passangers == 0;
	}

	Flight& Flight::operator = (Flight& src) {
		m_title = new char[(int)strlen(src.m_title) + 1];
		strcpy(m_title, src.m_title);
		m_passangers = src.m_passangers;
		m_fuel = src.m_fuel;
		src.setFlightToEmpty();
		return *this;
	}

	Flight& Flight::operator = (int psg) {
		if (psg > 0 && psg <= MAX_PSG_CAP) m_passangers = psg;
		return *this;
	}

	Flight& Flight::operator = (double ful) {
		if (ful <= MAX_FUL_CAP && ful > 0) m_fuel = ful;
		return *this;
	}

	Flight& Flight::operator += (double addFuel) {
		if (addFuel > 0 && m_fuel < MAX_FUL_CAP) {
			if (MAX_FUL_CAP - m_fuel < addFuel) m_fuel = MAX_FUL_CAP;
			else m_fuel += addFuel;
		}
		return *this;
	}

	Flight& Flight::operator += (int addPsg) {
		if (addPsg > 0 && m_passangers < MAX_PSG_CAP) {
			if (MAX_PSG_CAP - m_passangers < addPsg) m_passangers = MAX_PSG_CAP;
			else m_passangers += addPsg;
		}
		return *this;
	}

	Flight& Flight::operator -= (double rmvFuel) {
		if (rmvFuel > 0 && m_fuel != 0.00) {
			if (rmvFuel > m_fuel) m_fuel = 0.00;
			else m_fuel -= rmvFuel;
		}
		return *this;
	}

	Flight& Flight::operator -= (int rmvPsg) {
		if (rmvPsg > 0 && m_passangers != 0) {
			if (rmvPsg > m_passangers) m_passangers = 0;
			else m_passangers -= rmvPsg;
		}
		return *this;
	}

	Flight& Flight::operator << (Flight& src) {
		if (m_passangers != MAX_PSG_CAP) {
			if (MAX_PSG_CAP - m_passangers < src.m_passangers) {
				m_passangers = MAX_PSG_CAP;
				src.m_passangers -= MAX_PSG_CAP - m_passangers;
			}
			else {
				m_passangers += src.m_passangers;
				src.m_passangers = 0;
			}
		}
		return *this;
	}

	Flight& Flight::operator >> (Flight& src) {
		if (src.m_passangers != MAX_PSG_CAP) {
			if (MAX_PSG_CAP - src.m_passangers < m_passangers) {
				m_passangers -= MAX_PSG_CAP - src.m_passangers;
				src.m_passangers = MAX_PSG_CAP;
			}
			else {
				src.m_passangers += m_passangers;
				m_passangers = 0;
			}
		}
		return *this;
	}

	int Flight::operator + (const Flight& src) {
		if (*this && src) return m_passangers + src.m_passangers;
		else return 0;
	}

	int operator += (int& intRef, const Flight& src) {
		intRef += (int)src;
		return intRef;
	}

	void Flight::formattedLayout(int format) const {
		std::cout << " Flight  |  Low Fuel";
		std::cout.width(format);
		std::cout.setf(std::ios::right);
		std::cout << m_title;
		std::cout << " | Pass:";
		std::cout.width(11);
		std::cout << m_passangers << " |";
		std::cout.width(13);
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		std::cout << m_fuel << " Liters";
		std::cout.unsetf(std::ios::right);
		std::cout.unsetf(std::ios::fixed);
	}

	void Flight::setFlightToEmpty() {
		m_title = new char[11];
		strcpy(m_title, "EmptyPlane");
		m_fuel = 0.00;
		m_passangers = 0;
	}
	
	double Flight::returnMinFuel() const {
		double minFuel = 600 * m_passangers;
		return minFuel;
	}

	bool Flight::planeEmptyOrNot() const {
		return (m_passangers > 0 && m_passangers < MAX_PSG_CAP);
	}

	bool Flight::readyToDepart() const {
		return planeEmptyOrNot() && (m_fuel >= returnMinFuel());
	}
}