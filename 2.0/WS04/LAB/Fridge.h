#define _CRT_SECURE_NO_WARNINGS

#ifndef FRIDGE_H
#define FRIDGE_H

#include <iostream>
#include <cstring>

namespace seneca {

#define NAME_LEN 20
#define FRIDGE_CAP 3

    class Food {
    private:
        char m_name[NAME_LEN]{};
        int m_weight{};
    public:
        Food();
        Food(const char* nm, int wei);
        const char* name()const;
        int weight()const;
    };

    ////////////// Class Functions //////////////

    class Fridge {
    private:
        Food m_foods[FRIDGE_CAP];
        int m_numFoods;
        char* m_model;
        void setEmpty();
        void deallocateMod();
    public:
        Fridge();
        Fridge(Food farr[], int nf);
        Fridge(Food farr[], int nf, const char* mod);
        ~Fridge();
        bool addFood(const Food& f);
        void changeModel(const char* m);
        bool fullFridge() const;
        bool findFood(const char* f) const;
        std::ostream& display(std::ostream& os = std::cout) const;
    };


    bool validString(const char* str);

}

#endif