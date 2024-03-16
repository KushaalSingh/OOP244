#ifndef EMAIL_FILE_CPP
#define EMAIL_FILE_CPP

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <istream>

#define BUFFER_SIZE 1024

namespace seneca {

	class Email {
	private:
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{ '\0' };
		Email() {};
		Email& operator=(const Email&);
		Email(const Email& email);
		bool load(std::ifstream& in);
		~Email();
		friend class EmailFile;
	};

	class EmailFile : private Email {

	};

}

#endif