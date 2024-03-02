#include "Fridge.h"

namespace seneca {

	Food::Food() {}

	Food::Food(const char* nm, int wei) {
		strncpy(m_name, nm, NAME_LEN);
		m_weight = wei;
	}

	const char* Food::name() const { return m_name; }

	int Food::weight() const { return m_weight; }

	////////////// Provided Functions //////////////

	void Fridge::setEmpty() {
		m_model = nullptr;
		m_numFoods = 0;
	}

	Fridge::Fridge() {
		setEmpty();
	}

	Fridge::Fridge(Food farr[], int nf, const char* mod) {
		setEmpty();
		if (validString(mod) && nf > 0) {
			m_numFoods = nf;
			m_model = new char[strlen(mod) + 1];
			strcpy(m_model, mod);
			for (int i = 0; i < nf && i < FRIDGE_CAP; i++) m_foods[i] = farr[i];
		}
		else {
			m_model = new char[strlen("Ice Age") + 1];
			strcpy(m_model, "Ice Age");
		}
	}

	Fridge::~Fridge() {
		deallocateMod();
	}

	bool Fridge::addFood(const Food& f) {
		if (m_numFoods < FRIDGE_CAP) {
			m_foods[m_numFoods++] = f;
			return true;
		}
		return false;
	}

	void Fridge::changeModel(const char* m) {
		if (validString(m)) {
			deallocateMod();
			m_model = new char[strlen(m) + 1];
			strcpy(m_model, m);
		}
	}

	bool Fridge::fullFridge() const {
		return m_numFoods == FRIDGE_CAP;
	}

	bool Fridge::findFood(const char* f) const {
		if (validString(f)) {
			for (int i = 0; i < m_numFoods; i++) if (!strcmp(m_foods[i].name(), f)) return true;
		}
		return false;
	}

	std::ostream& Fridge::display(std::ostream& os = std::cout) const {
		if (!validString(m_model) || !strcmp(m_model, "Ice Age")) return os;
		os << "Fridge Model: " << m_model << std::endl;
		os << "Food count: " << m_numFoods << " Capacity: " << FRIDGE_CAP << std::endl;
		os << "List of Foods" << std::endl;
		if (m_numFoods > 0) {
			for (int i = 0; i < m_numFoods; i++) {
				os.width(NAME_LEN);
				os << m_foods[i].name() << " | " << m_foods[i].weight() << std::endl;
			}
		}
		return os;
	}

	void Fridge::deallocateMod() {
		delete[] m_model;
		m_model = nullptr;
	}

	bool validString(const char* str) {
		return str && str[0] != '\0';
	}

}