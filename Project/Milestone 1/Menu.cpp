/*
Citation and Sources...
Final Project Milestone 1
Module: Menu
Filename: Menu.cpp
Version  1.0
Author   Kushaal Singh
Revision History
-----------------------------------------------------------
Date      Reason
2023/?/?  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include "Menu.h"

namespace seneca {

	Menu::Menu(const char* menuContent, int numberOfTabs) {
		setEmpty();
		m_text = new char[strlen(menuContent) + 1];
		strcpy(m_text, menuContent);
		m_numberOfTabs = numberOfTabs;
		m_numOptions = returnNumOptions(menuContent);
	}

	int Menu::returnNumOptions(const char* str) {
		int options = 0;
		for (int i = 0; i < strlen(str); i++) if (str[i] == '\n') options++;
		return options;
	}

	void Menu::setEmpty() {
		m_text = nullptr;
		m_numberOfTabs = 0;
		m_numOptions = 0;
	}

	Menu::~Menu() {
		delete[] m_text;
		m_text = nullptr;
	}

	std::ostream& Menu::display(std::ostream& out) {
		for (int i = 0; i < strlen(m_text); i++) {
			for (int k = 0; k < m_numberOfTabs * 3 && (i == 0 || m_text[i - 1] == '\n'); std::cout << " ", k++);
			std::cout << m_text[i];
		}
		std::cout << "0- Exit" << std::endl << "> ";
	}
}