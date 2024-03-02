#include "io.h"
using namespace std;
namespace seneca {
    void printInt(int value, int fieldWidth, const char* symbol) {
        cout << value;
        for (int i = 0; i < fieldWidth - intDigits(value); i++) cout << " ";
        std::cout << symbol;
    }

    int intDigits(int value) {
        int count = (value == 0);
        while (value != 0) {
            value /= 10;
            ++count;
        }
        return count;
    }

    void goBack(int n) {
        for (int i = 0; i < n; cout << "\b", i++);
    }

    void labelLine(int n, const char* label) {
        cout << "+";
        for (int i = 0; i < n - 2; cout << "-", i++);
        cout << "+";
        if (label) {
            goBack(n - 4);
            cout << label;
        }
        cout << endl;
    }

    void line(int n) {
        cout << "+";
        for (int i = 0; i < n - 2; cout << "-", i++);
        cout << "+";
        cout << endl;
    }
}