#include "Label.h"
#include "LabelMaker.h"
using namespace sdds;
using namespace std;
int main() {
    int noOfLabels;
    Label
        theProgram("/-\\|/-\\|"),
        test1,
        test2("ABCDEFGH");
    test1.printLabel();
    test2.printLabel();
    theProgram.printLabel();
    test1.text("Testing one, two, three");
    test1.printLabel() << endl;
    theProgram.text("Professor's Label Maker Program Tester");
    theProgram.printLabel() << endl << endl;
    cout << "Number of labels to create: ";
    cin >> noOfLabels;
    cin.ignore(10000, '\n');
    LabelMaker lblMkr(noOfLabels);
    lblMkr.readLabels();
    lblMkr.printLabels();
    return 0;
}