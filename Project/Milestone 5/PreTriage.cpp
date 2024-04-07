/*
Citation and Sources...
Final Project Milestone 1
Module: PreTriage
Filename: PreTriage.cpp
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

#include "PreTriage.h"

namespace seneca {

	PreTriage::PreTriage(const char* file) : m_avgContaigenTime(15), m_avgTriageTime(5), m_dataFile(nullptr), m_numPatients(0) {
		for (int i = 0; i < MAX_PATIENTS; i++) m_patients[i] = nullptr;
		if (file) {
			U.allocStringCopy(m_dataFile, file);
			load();
		}
		else std::cerr << "ERROR: Bad File!!!" << std::endl;
	}

	PreTriage::~PreTriage() {
		save();
		for (int i = 0; i < MAX_PATIENTS; i++) delete[] m_patients[i];
		delete[] m_dataFile;
	}


	Time PreTriage::getWaitTime(const Patient& src) const {
		int mins = 0, count = 0;
		for (int i = 0; i < m_numPatients; i++) {
			if (*m_patients[i] == src) {
				count++;
				mins += m_patients[i]->time();
			}
		}
		int avg = mins / count;
		return Time(avg);
	}

	void PreTriage::setAverageWaitTime(const Patient& src) {
		char type = src.type();
		Time currTime;
		currTime.reset();
		Time ticketTime = src.time();
		Time& avgWaitTime = type == 'C' ? m_avgContaigenTime : m_avgTriageTime;
		int ticketNumber = src.number();
		avgWaitTime = ((currTime - ticketTime) + (avgWaitTime * (ticketNumber - 1))) / ticketNumber;
	}

	int PreTriage::indexOfFirstInLine(char type) {
		for (int i = 0; i < m_numPatients; i++) if (type == *m_patients[i]) return i;
		return -1;
	}

	void PreTriage::load() {
		Patient* patient{ nullptr };
		char type{};
		int i = 0;

		std::cout << "Loading data..." << std::endl;
		std::ifstream fin(m_dataFile);
		if (!fin.is_open()) {
			std::cerr << "ERROR: File couldn't open!!!" << std::endl;
			return;
		}

		else {
			fin >> m_avgContaigenTime;
			fin.ignore(10000, ',');
			fin >> m_avgTriageTime;
			fin.ignore(10000, '\n');

			while (fin >> type) {
				fin.ignore(10000, ',');
				if (type == 'C') patient = new TestPatient();
				else patient = new TriagePatient();
				if (fin >> *patient) {
					if (m_numPatients < MAX_PATIENTS) {
						m_patients[m_numPatients++] = patient;
					}
					else {
						std::cerr << "Warning: number of records exceeded " << MAX_PATIENTS << std::endl;
						delete patient;
						break;
					}
				}
				else {
					delete patient;
					std::cerr << "Error: Bad Data!!!" << std::endl;
					break;
				}
				fin.ignore(10000, '\n');
			}
			fin.close();
			if (m_numPatients) std::cout << m_numPatients << " Records imported..." << std::endl;
			else std::cout << "No data or bad data file!" << std::endl;
		}
	}

	void PreTriage::save() {
		int cont = 0, tri = 0, i;
		std::cout << "Saving lineup..." << std::endl;
		std::ofstream fout(m_dataFile);
		fout << m_avgContaigenTime << "," << m_avgTriageTime << std::endl;
		for (i = 0; i < m_numPatients; i++) {
			fout << *m_patients[i] << std::endl;
			if (m_patients[i]->type() == 'C') cont++;
			else tri++;
		}
		std::cout << cont << " Contagion Tests and " << tri << " Triage records were saved!" << std::endl;
	}

	void PreTriage::Register() {
		if (m_numPatients == MAX_PATIENTS) {
			std::cout << "Line up full!" << std::endl;
			return;
		}

		int selection{ 0 };
		Patient* patient{ nullptr };
		Menu subMenu("Select Type of Registration:\n1 - Contagion Test\n2 - Triage\n", 1);
		subMenu.display();
		subMenu.read(selection);
		if (selection == 1) {
			patient = new TestPatient();
		}
		else if (selection == 2) {
			patient = new TriagePatient();
		}
		else if (selection == 0) {
			return;
		}

		patient->setArrivalTime();
		std::cout << "Please enter patient information: " << std::endl;
		std::cin >> *patient;
		std::cout << std::endl;
		std::cout << "******************************************" << std::endl;
		std::cout << *patient << std::endl;
		std::cout << getWaitTime(*patient) << std::endl;
		std::cout << "******************************************" << std::endl << std::endl;
		m_patients[m_numPatients++] = patient;
	}

	void PreTriage::admit() {
		int selection{ 0 };
		char type{};
		Menu subMenu("Select Type of Admittance:\n1 - Contagion Test\n2 - Triage\n", 1);
		subMenu.display();
		subMenu.read(selection);
		if (selection == 1) {
			type = 'C';
		}
		else if (selection == 2) {
			type = 'T';
		}
		else if (selection == 0) {
			return;
		}
		int index = type == 'C' ? indexOfFirstInLine('C') : indexOfFirstInLine('F');
		if (index == -1) {
			std::cerr << "Lineup is empty!" << std::endl;
			return;
		}
		Patient* patient = m_patients[index];
		std::cout << "******************************************" << std::endl;
		std::cout << "Call time [" << patient->time() << "]";
		std::cout << "Calling for " << *patient;
		std::cout << "******************************************" << std::endl << std::endl;
		setAverageWaitTime(*patient);
		U.removeDynamicElement(m_patients, index, m_numPatients);
	}

	void PreTriage::lineup() const {
		int selection{ 0 };
		char type{};
		Menu subMenu("Select The Lineup:\n1 - Contagion Test\n2 - Triage\n", 1);
		subMenu.display();
		subMenu.read(selection);
		if (selection == 1) {
			type = 'C';
		}
		else if (selection == 2) {
			type = 'T';
		}
		else if (selection == 0) {
			return;
		}
		if (m_numPatients == 0) {
			std::cerr << "Lineup is empty!" << std::endl;
			return;
		}
		else {
			std::cout << "Row - Patient name                                          OHIP     Tk #  Time" << std::endl;
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
			for (int i = 0; i < m_numPatients; i++) if (*m_patients[i] == type) std::clog << *m_patients[i];
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
		}
	}

	void PreTriage::run() {
		int selection{ 0 };
		Menu mainMenu("General Healthcare Facility Pre-Triage Application\n1 - Register\n2 - Admit\n3 - View Lineup\n");
		mainMenu.display();
		if (selection == 1) {
			Register();
		}
		else if (selection == 2) {
			admit();
		}
		else if (selection == 3) {
			lineup();
		}
		else if (selection == 0) {
			return;
		}
	}
}