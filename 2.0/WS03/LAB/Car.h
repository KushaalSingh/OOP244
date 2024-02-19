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
		void setEmpty();
		void deallocateMemory();
		void set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost);
		void display() const;

		void setDynamicPointersToNull();
	};

	bool validLicencePlate(const char* plate);







}

#endif 
