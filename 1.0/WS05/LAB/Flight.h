#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#ifndef FLIGHT_H
#define FLIGHT_H

#define MAX_PSG_CAP 388
#define MAX_FUL_CAP 238840.00

namespace sdds {

	class Flight {
	private:
		char* m_title;
		double m_fuel;
		int m_passangers;

	public:
		Flight();
		Flight(int passengers, double fuel, const char* title);
		~Flight();
		std::ostream& display() const;
		operator bool() const;
		operator int() const;
		operator double() const;
		operator const char* () const;
		bool operator~() const;
		Flight& operator = (Flight& src);
		Flight& operator = (int psg);
		Flight& operator = (double fuel);
		Flight& operator += (double addFuel);
		Flight& operator += (int addPsg);
		Flight& operator -= (double rmvFuel);
		Flight& operator -= (int rmvPsg);
		Flight& operator << (Flight& src);
		Flight& operator >> (Flight& src);
		int operator + (const Flight& src);
		void formattedLayout(int width) const;
		bool readyToDepart() const;
		void setFlightToEmpty();
		bool planeEmptyOrNot() const;
		double returnMinFuel() const;
	};

	int operator += (int& intRef, const Flight& src);

}




#endif