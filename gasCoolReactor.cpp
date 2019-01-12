#include "gasCoolReactor.h"
#include <iostream>
using namespace std;

void GasCoolReactor::writeCoolant() {
    cout << "You need to use GAS to cool the reactor." << endl;
}

GasCoolReactor::GasCoolReactor(int num, double pow, int t) : Reactor(num, pow, t) { };