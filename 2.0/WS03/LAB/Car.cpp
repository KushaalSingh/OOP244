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

		}
		else setEmpty();

	}

	void Car::setDynamicPointersToNull() {
		m_makeModel = nullptr;
		m_serviceDesc = nullptr;
	}

	bool validLicencePlate(const char* plate) {
		return (plate) && (strlen(plate) > 0 && strlen(plate) < 9);
	}
}