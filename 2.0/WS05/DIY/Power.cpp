#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
#include "Power.h"

namespace seneca {

	Power::Power() {
		setEmpty();
	}

	Power::Power(const char* name, int rarity) {
		createPower(name, rarity);
	}

	void Power::setEmpty() {
		m_name[0] = '\0';
		m_rarity = 0;
	}

	void Power::createPower(const char* name, int rarity) {
		if (name && name[0] != '\0' && rarity > 0) {
			strncpy(m_name, name, MAX_NAME_LENGTH);
			m_rarity = rarity;
		}
		else {
			setEmpty();
		}
	}

	const char* Power::checkName() const {
		return m_name;
	}

	int Power::checkRarity() const {
		return m_rarity;
	}

	bool Power::isEmpty() const {
		return (m_name[0] == '\0' || m_rarity == 0);
	}

	void displayDetails(Power* powers, int size) {
		std::cout << "List of available powers: " << std::endl;
		for (int i = 0; i < size; i++) {
			if (!powers[i].isEmpty()) {
				std::cout << "  Name: " << powers[i].checkName() << ", "
					<< "Rarity: " << powers[i].checkRarity() << std::endl;
			}
		}
	}

}