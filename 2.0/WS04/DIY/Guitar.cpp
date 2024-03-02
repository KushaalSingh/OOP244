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
        deString();
    }

    bool Guitar::changeString(const GuitarStr& gs, int sn) {
        if (sn >= 0 && sn <= m_numStrings) {
            m_strings[sn] = gs;
            return true;
        }
        else return false;
    }

    void Guitar::reString(GuitarStr strs[], int ns) {
        deString();
        m_numStrings = ns;
        m_strings = new GuitarStr[m_numStrings];
        for (int i = 0; i < m_numStrings; i++) m_strings[i] = strs[i];
    }

    void Guitar::setEmpty() {
        m_strings = nullptr;
        m_numStrings = 0;
    }

    void Guitar::deString() {
        delete[] m_strings;
        m_strings = nullptr;
    }

    bool Guitar::strung() {
        return m_strings;
    }

    bool Guitar::matchGauge(double ga) const {
        for (int i = 0; i < m_numStrings; i++) if (ga == m_strings[i].gauge()) return true;
        return false;
    }



}