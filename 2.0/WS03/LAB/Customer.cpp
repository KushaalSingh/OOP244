#include "Customer.h"

namespace seneca {

	bool Customer::isEmpty() const {
		return (!m_name) || (strlen(m_name) == 0) || (m_car == nullptr);
	}

	void Customer::setEmpty() {
		m_id = 0;
		m_name = nullptr;
		m_car = nullptr;
	}

	void Customer::deallocateMemory() {
		if (m_name != nullptr) delete[] m_name;
	}

	void Customer::set(int customerId, const char* name, const Car* car) {
		deallocateMemory();
		setEmpty();
		if (validName(name) && m_car != nullptr) {
			m_id = customerId;
			m_car = car;
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	}

	void Customer::display() const {
		if (!isEmpty()) {
			m_car->displayNum("Customer ID:", m_id, 1);
			m_car->displayAttribute("First Name:", m_name);
			m_car->display();
		}
	}

	const Car& Customer::car() const {
		return *m_car;
	}

	bool validName(const char* name) {
		return (name) && (name[0] != '\0');
	}

}