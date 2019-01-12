#include "switchgear.h"
#include <unistd.h>

void Switchgear::turnOnReactor(Manager* ptr, int a) {
    int j = 0, n = 1;
    if (ptr->getReactor(a)->getStatus() == active) {
        cout << "This reactor is already TURNED ON." << endl;
        return;
    }
    ptr->getReactor(a)->setStatus(active);
    ptr->getReactor(a)->writeCoolant();
    cout << "Lowering the fuel rods..." << endl << endl;
    for (int i = 0; i < 5; ++i) {
        j = 0;
        while (j != n) {
            cout << "####################";
            ++j;
        }
        sleep(1);
        cout << " " << n * 20 << " %" << endl;
        ++n;
    }
    cout << endl << "FUEL RODS ARE ALREADY WORKING." << endl;
    ptr->getReactor(a)->setTemp(1000);
    cout << "Temperature amounts to 1000 degrees Celsius." << endl << endl;
}