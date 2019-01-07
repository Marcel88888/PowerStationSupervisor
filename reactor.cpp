#include <iostream>
#include <cstdlib>
#include <ctime>
#include "reactor.h"
using namespace std;

void Reactor::measureTemp() {
    srand (static_cast <unsigned int> (time (nullptr) ) );
    int a, t, x = 0;
    char buffer[ 64 ];
    time_t tim;
    time( & tim );
    tm timeTM = * localtime( & tim );
    strftime( buffer, sizeof( buffer ), "%H:%M:%S", & timeTM );
    cout << "Temperature in the reactor: " << endl << endl;
    for (int i = 0; i < 50; ++i) {
        t = rand() % 101;
        a = rand() % 2;
        if (a == 0) temperature -= t;
        else temperature += t;
        cout << buffer << ":  " << temperature << endl;
        if (temperature >= 1200) {
            cout << "Temperature is TOO HIGH! Try to REDUCE it!!!" << endl;
            x = 1;
            break;
        }
        if (temperature <= 800) {
            cout << "Temperature is TOO LOW! Try to RAISE it!!!" << endl;
            x = 1;
            break;
        }
    }
    if (x == 0)
        cout << "Temperature is OK." << endl;
}

int Reactor::getTemp() {
    return temperature;
}

int Reactor::getNumber() {
    return number;
}

double Reactor::getPower() {
    return power;
}

Reactor::Reactor(int num, double pow) {
    number = num;
    power = pow;
    temperature = 1000;
}