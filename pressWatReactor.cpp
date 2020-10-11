#include "pressWatReactor.h"
#include <iostream>
using namespace std;

void PressWatReactor::writeCoolant() {
    cout << "You need to use PRESSED WATER to cool the reactor." << endl;
}

PressWatReactor::PressWatReactor(int num, double pow, int t) : Reactor(num, pow, t) { };
