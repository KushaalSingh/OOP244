//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "EmailFile.h"

namespace seneca {

    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

    Email::~Email() {
        delete[] m_name;
        delete[] m_email;
    }

    void EmailFile::setFilename(const char* filename) {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty() {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        std::ifstream file(m_filename);

        if (!file.is_open()) {
            std::cout << "Failed to open file: " << m_filename << std::endl;
        }
        else {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const {
        if (m_filename) {
            ostr << m_filename << std::endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << std::endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
                ostr.width(35);
                ostr.setf(std::ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << std::endl;
            }
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text) {
        return text.view(ostr);
    }

    void EmailFile::loadEmails() {
        if (!m_filename) return;

        delete[] m_emailLines;
        m_emailLines = nullptr;
        m_emailLines = new Email[m_noOfEmails];
        std::ifstream fistr(m_filename);
        for (int i = 0; i < m_noOfEmails; i++) if (!m_emailLines[i].load(fistr))
            std::cerr << "Error reading from the file." << std::endl;
    }

    EmailFile::operator bool() const {
        return m_filename != nullptr;
    }


    EmailFile::EmailFile() {
        setEmpty();
    }

    EmailFile::EmailFile(const char* filename) {
        if (filename == nullptr) setEmpty();
        setFilename(filename);
        if (setNoOfEmails()) std::cout << "Error, could not set m_noOfEmails" << std::endl;
        loadEmails();
    }

    EmailFile::EmailFile(const EmailFile& src) {
        setEmpty();
        if ((bool)src) *this = src;
    }

    EmailFile& EmailFile::operator=(const EmailFile& src) {
        if (this != &src) {
            setEmpty();
            setFilename(src.m_filename);
            m_noOfEmails = src.m_noOfEmails;
            m_emailLines = new Email[m_noOfEmails];
            for (int i = 0; i < m_noOfEmails; i++) m_emailLines[i] = src.m_emailLines[i];
        }
        return *this;
    }

    bool EmailFile::saveToFile(const char* filename) const {
        std::ofstream fostr(filename);
        if (!fostr.is_open()) {
            std::cout << "Error: Could not open file: " << filename << std::endl;
            return false;
        }
        for (int i = 0; i < m_noOfEmails; i++) fostr << m_emailLines[i].m_email << ", " << 
            m_emailLines[i].m_name << ", " << m_emailLines[i].m_year << std::endl;
        return true;
    }

    void EmailFile::fileCat(const EmailFile& obj, const char* name = nullptr) {
        if (!*this || !obj) return;
        int total_emails = m_noOfEmails + obj.m_noOfEmails;
        Email* merged;
        merged = new Email[total_emails];
        for (int i = 0; i < m_noOfEmails; i++) merged[i] = m_emailLines[i];
        for (int i = 0; i < obj.m_noOfEmails; i++) merged[m_noOfEmails + i] = obj.m_emailLines[i];
        delete[] m_emailLines;
        m_emailLines = merged;
        m_noOfEmails = total_emails;
        if (name) {
            delete[] m_filename;
            setFilename(name);
        }
    }
}