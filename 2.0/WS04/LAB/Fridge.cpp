#include "Fridge.h"

namespace seneca {
	
	Fridge::Fridge() {
		setEmpty();
	}

	Fridge::Fridge(Food farr[], int nf, const char* mod) {
		setEmpty();
		if (notEmptyString(mod) && nf > 0) {
			m_numFoods = nf;
			m_model = new char[strlen(mod) + 1];
			strcpy(m_model, mod);
			for (int i = 0; i < nf && i < FRIDGE_CAP; i++) {
				m_foods[i] = farr[i];
			}
		}
		else {
			m_model = new char[strlen("Ice Age") + 1];
			strcpy(m_model, "Ice Age");
		}
	}

	Fridge::~Fridge() {
		delete[] m_model;
	}

	void Fridge::setEmpty() {
		m_numFoods = 0;
		m_model = nullptr;
	}

	//////////////////////////////////////////////

	Food::Food() {}

	Food::Food(const char* nm, int wei) {
		strncpy(m_name, nm, NAME_LEN);
		m_weight = wei;
	}

	const char* Food::name() const {
		return m_name;
	}

	int Food::weight() const {
		return m_weight;
	}
	
	///////////////////////////////////////////////

	bool notEmptyString(const char* str) {
		return str && str[0] != '\0';
	}
}