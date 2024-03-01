#include "Fridge.h"

namespace seneca {

    Food::Food() {}

    Food::Food(const char* nm, int wei) {
        strncpy(m_name, nm, NAME_LEN);
        m_weight = wei;
    }

    const char* Food::name() const {
        return m_name;
    }

    int Food::weight() const {
        return m_weight;
    }


}