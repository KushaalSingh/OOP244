//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef EMAIL_FILE_CPP
#define EMAIL_FILE_CPP

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>

#define BUFFER_SIZE 1024

namespace seneca {

	class Email {
	private:
		char* m_email{ nullptr };
		char* m_name{ nullptr };
		char m_year[5]{ '\0' };
		Email() {};
		Email& operator=(const Email&);
		Email(const Email& email) = delete;
		bool load(std::ifstream& in);
		~Email();
		friend class EmailFile;
	};

	class EmailFile {
	private:
		Email* m_emailLines{ nullptr };
		char* m_filename{};
		int m_noOfEmails{ 0 };
		void setFilename(const char* filename);
		void setEmpty();
		bool setNoOfEmails();
		void loadEmails();
		operator bool()const;

	public:
		EmailFile();
		EmailFile(const char* filename);
		EmailFile(const EmailFile& src);
		EmailFile& operator=(const EmailFile& src);
		std::ostream& view(std::ostream& ostr) const;
		bool saveToFile(const char* filename) const;
		void fileCat(const EmailFile& obj, const char* name = nullptr);
	};

	std::ostream& operator<<(std::ostream& ostr, const EmailFile& text);

}

#endif