#include "Car.h"

#ifndef CUSTOMER_H
#define CUSTOEMR_H

namespace seneca {

	class Customer {
	private:
		int m_id;
		char* m_name;
		const Car* m_car;
	public:
		bool isEmpty() const;
		void setEmpty();
		void deallocateMemory();
		void set(int customerId, const char* name, const Car* car);
		void display() const;
		const Car& car()const;
	};

	bool validName(const char* name);


}


#endif