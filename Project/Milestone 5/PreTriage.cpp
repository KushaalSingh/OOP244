#include "PreTriage.h"

namespace seneca {

	PreTriage::PreTriage(const char* file) : m_avgContaigenTime(15), m_avgTriageTime(5), m_dataFile(nullptr), m_numPatients(0) {
		for (int i = 0; i < MAX_PATIENTS; i++) m_patients[i] == nullptr;
		if (file) {
			U.allocStringCopy(m_dataFile, file);
			load();
		}
		else std::cerr << "ERROR: Bad File!!!" << std::endl;
	}

	PreTriage::~PreTriage() {
		// save(); FUNCTION NEEDS TO BE IMPLEMENTED
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

	}
}