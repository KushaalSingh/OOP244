#include "Car.h"

namespace seneca {

	bool Car::isEmpty() const {
		return (!m_makeModel || strlen(m_makeModel)) || (!m_serviceDesc || strlen(m_serviceDesc));
	}




}