#include "Car.h"

namespace seneca {

	bool Car::isEmpty() const {
		return (!m_makeModel || strlen(m_makeModel) == 0) || (!m_serviceDesc || strlen(m_serviceDesc) == 0);
	}

	void Car::setEmpty() {
		m_licencePlate[0] = '\0';
		m_cost = 0.00;
		setDynamicPointersToNull();
	}

	void Car::deallocateMemory() {
		if (m_makeModel != nullptr) delete[] m_makeModel;
		if (m_serviceDesc != nullptr) delete[] m_serviceDesc;
		setDynamicPointersToNull();
	}

	void Car::set(const char plateNo[], const char* carMakeModel, const char* serviceDesc, double serviceCost) {
		deallocateMemory();
		if (!isEmpty() && validLicencePlate(plateNo)) {
			m_cost = serviceCost;
			strcpy(m_licencePlate, plateNo);
			m_makeModel = new char[strlen(carMakeModel) + 1];
			strcpy(m_makeModel, carMakeModel);
			m_serviceDesc = new char[strlen(serviceDesc) + 1];
			strcpy(m_serviceDesc, serviceDesc);
		}
		else setEmpty();
	}

	void Car::display() const {
		displayAttribute("Licence Plate:", m_licencePlate);
		displayAttribute("Model:", m_makeModel);
		displayAttribute("Service Name:", m_serviceDesc);
		std::cout.width(15);
		std::cout.setf(std::ios::left);
		std::cout << "Service Cost:";
		std::cout.width(20);
		std::cout.setf(std::ios::right);
		std::cout.precision(2);
		std::cout << m_cost << std::endl;
	}

	void displayAttribute(const char* attribute, const char* value) {
		std::cout.width(15);
		std::cout.setf(std::ios::left);
		std::cout << attribute;
		std::cout.width(20);
		std::cout.setf(std::ios::right);
		std::cout << value << std::endl;
	}

	void Car::setDynamicPointersToNull() {
		m_makeModel = nullptr;
		m_serviceDesc = nullptr;
	}

	bool validLicencePlate(const char* plate) {
		return (plate) && (strlen(plate) > 0 && strlen(plate) < 9);
	}
}