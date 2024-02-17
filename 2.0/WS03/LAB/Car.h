#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#ifndef  CAR_H
#define CAR_H

namespace seneca {

	const int LP_LEN{ 8 };

	class Car {
	private:
		char m_licencePlate[LP_LEN];
		char* m_makeModel;
		char* m_serviceDesc;
		double m_cost;
	public:
		bool isEmpty() const;
	};







}

#endif // !
