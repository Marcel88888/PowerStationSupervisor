#include "heavyWatReactor.h"
#include <iostream>
using namespace std;

void HeavyWatReactor::writeCoolant() {
    cout << "You need to use HEAVY WATER to cool the reactor." << endl;
}

HeavyWatReactor::HeavyWatReactor(int num, double pow, int t) : Reactor(num, pow, t) { };