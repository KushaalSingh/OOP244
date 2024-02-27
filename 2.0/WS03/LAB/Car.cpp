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
		setEmpty();
		if (validMakeAndService(carMakeModel, serviceDesc) && validLicencePlate(plateNo)) {
			m_cost = serviceCost;
			strcpy(m_licencePlate, plateNo);
			m_makeModel = new char[strlen(carMakeModel) + 1];
			strcpy(m_makeModel, carMakeModel);
			m_serviceDesc = new char[strlen(serviceDesc) + 1];
			strcpy(m_serviceDesc, serviceDesc);
		}
	}

	void Car::display() const {
		if (!isEmpty()) {
			displayAttribute("Licence Plate:", m_licencePlate);
			displayAttribute("Model:", m_makeModel);
			displayAttribute("Service Name:", m_serviceDesc);
			displayNum("Service Cost:", m_cost, 0);
		}
	}

	void Car::displayAttribute(const char* attribute, const char* value) const {
		std::cout.width(15);
		std::cout.setf(std::ios::left);
		std::cout << attribute;
		std::cout.width(20);
		std::cout.unsetf(std::ios::left);
		std::cout.setf(std::ios::right);
		std::cout << value << std::endl;
		std::cout.unsetf(std::ios::right);
	}

	void Car::displayNum(const char* attribute, const double num, int toInt) const {
		std::cout.width(15);
		std::cout.setf(std::ios::left);
		std::cout << attribute;
		std::cout.unsetf(std::ios::left);
		std::cout.width(20);
		std::cout.setf(std::ios::right);
		std::cout.setf(std::ios::fixed);
		std::cout.precision(2);
		if (toInt) std::cout << (int)num << std::endl;
		else std::cout << num << std::endl;
		std::cout.unsetf(std::ios::fixed);
		std::cout.unsetf(std::ios::right);
	}

	void Car::setDynamicPointersToNull() {
		m_makeModel = nullptr;
		m_serviceDesc = nullptr;
	}

	bool validMakeAndService(const char* make, const char* service) {
		return (make && make[0] != '\0') && (service && service[0] != '\0');
	}

	bool validLicencePlate(const char* plate) {
		return (plate) && (strlen(plate) > 0 && strlen(plate) < 9);
	}
}