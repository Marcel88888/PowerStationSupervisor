#include "sensor.h"
#include "manager.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>
using namespace std;

void Sensor::measureTemp(Manager* ptr, int z) {
    int temp = ptr->getReactor(z)->getTemp();
    if (temp == 0) {
        cout << "The chosen reactor is not working now." << endl;
        return;
    }
    srand (static_cast <unsigned int> (time (nullptr) ) );
    int a, t, x = 0;
    char buffer[ 64 ];
    cout << "Temperature in the reactor: " << endl << endl;
    for (int i = 0; i < 10; ++i) {
        t = rand() % 101;
        a = rand() % 2;
        if (a == 0) temp -= t;
        else temp += t;
        time_t tim;
        time( & tim );
        tm timeTM = * localtime( & tim );
        strftime( buffer, sizeof( buffer ), "%H:%M:%S", & timeTM );
        cout << buffer << ":  " << temp << endl;
        sleep(1);
        if (temp >= 1200) {
            cout << "Temperature is TOO HIGH! Try to REDUCE it!!!" << endl;
            x = 1;
            ptr->getReactor(z)->setTemp(temp);
            break;
        }
        if (temp <= 800) {
            cout << "Temperature is TOO LOW! Try to RAISE it!!!" << endl;
            x = 1;
            ptr->getReactor(z)->setTemp(temp);
            break;
        }
    }
    if (x == 0) {
        cout << "Temperature is OK." << endl;
        ptr->getReactor(z)->setTemp(temp);
    }
}