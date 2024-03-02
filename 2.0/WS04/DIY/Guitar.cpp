#include "Guitar.h"

namespace seneca {

    GuitarStr::GuitarStr() {}

    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN);
        m_gauge = ga;
    }

    const char* GuitarStr::material() const {
        return m_material;
    }

    double GuitarStr::gauge() const {
        return m_gauge;
    }

    Guitar::Guitar() {
        setEmpty();
    }

    Guitar::Guitar(const char* mod) {
        m_strings = nullptr;
        m_numStrings = 0;
        strcpy(m_model, mod);
    }

    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {
        m_numStrings = ns;
        m_strings = new GuitarStr[m_numStrings];
        for (int i = 0; i < m_numStrings; i++) m_strings[i] = strs[i];
        strcpy(m_model, mod);
    }

    Guitar::~Guitar() {
        delete[] m_strings;
    }

    bool Guitar::changeString(const GuitarStr& gs, int sn) {

    }

    void Guitar::setEmpty() {
        m_strings = nullptr;
        m_numStrings = 0;
    }

    bool Guitar::isEmpty() {
        return !m_strings && m_numStrings == 0;
    }

}