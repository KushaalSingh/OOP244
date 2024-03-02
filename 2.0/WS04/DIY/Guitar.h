#define _CRT_SECURE_NO_WARNINGS


#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>
#include <cstring>

namespace seneca {

#define MAT_LEN 10
#define MOD_LEN 15

	class GuitarStr {
	private:
		char m_material[MAT_LEN]{};
		double m_gauge{};
	public:
		GuitarStr();
		GuitarStr(const char* ma, double ga);
		const char* material() const;
		double gauge() const;
	};

	class Guitar {
	private:
		GuitarStr* m_strings;
		int m_numStrings;
		char m_model[MOD_LEN];
	public:
		Guitar(const char* mod = "Stratocaster");
		Guitar(GuitarStr strs[], int ns, const char* mod);
		~Guitar();
	};

}


#endif