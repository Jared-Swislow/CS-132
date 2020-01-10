#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int NUM_OF_DISKS = 7;

struct Peg {
    vector<int> peg;
    string name;
};

void addDisks(Peg& peg, int amountToAdd);
void displayPeg(Peg peg);
void display3Pegs(Peg peg1, Peg peg2, Peg peg3);
void movePeg(Peg &peg1, Peg &peg2);
void hanoi(Peg &startPeg, Peg &goalPeg, Peg &tempPeg, int amountOfPegs);

int main()
{
    Peg peg1, peg2, peg3;
    peg1.name = "peg1";
    peg2.name = "peg2";
    peg3.name = "peg3";

    addDisks(peg1, NUM_OF_DISKS);

    displayPeg(peg1);
    displayPeg(peg2);
    displayPeg(peg3);
}

void addDisks(Peg& peg, int amountToAdd) {
    for (int i = amountToAdd; i > 0; i--) {
        peg.peg.push_back(i);
    }
}

void displayPeg(Peg peg) {
    cout << "Peg: ";
    for (int i = 0; i < static_cast<int>(peg.peg.size()); i++) {
        cout << peg.peg[i];
    }
    cout << endl;
}

void display3Pegs(Peg peg1, Peg peg2, Peg peg3) {
    displayPeg(peg1);
    displayPeg(peg2);
    displayPeg(peg3);
}

void movePeg(Peg& peg1, Peg& peg2) {
    assert(!peg1.peg.empty());
    if (!peg2.peg.empty()) {
        assert(peg2.peg.back() > peg1.peg.back());
    }
    peg1.peg.push_back(peg2.peg.back);
    peg2.peg.pop_back;
    cout << "Moved disk " << peg2.peg.back() << " from " << peg1.name << " to " << peg2.name;
}