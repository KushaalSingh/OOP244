#include "Fridge.h"

namespace seneca {


    Fridge::Fridge() {
        m_numFoods = 0;
        m_model = nullptr;
    }

    Fridge::Fridge(Food farr[], int nf, const char* mod) {

    }


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