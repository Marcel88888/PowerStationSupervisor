#include <iostream>
#include "menu.h"
#include "manager.h"
using namespace std;

void Menu::menuOperation() {
    int c, n, p, a = 0, b = 0, d = 0;
    Manager man;
    cout << "---------------------MENU---------------------";
    cout << endl << "Options: " << endl;
    cout << " 1- add a reactor" << endl;
    cout << " 2- write out all the reactors" << endl;
    cout << " 3- test the temperature of the reactor" << endl;
    cout << " 4- check the total power of the power station" << endl;
    cout << " 5- check how long it will take to produce some amount of energy" << endl;
    cout << " 6- exit" << endl;
    do {
        cout << "Your choice: ";
        cin >> c;
        switch (c) {
            case 1: {
                do {
                    cout << "Number: ";
                    cin >> n;
                    if (n > 0) {
                        b = 1;
                        break;
                    }
                    cout << "Incorrect data." << endl;
                } while (b == 0);
                do {
                    cout << "Power [kW]: ";
                    cin >> p;
                    if (p > 0) {
                        d = 1;
                        break;
                    }
                    cout << "Incorrect data." << endl;
                } while (d == 0);
                man.addReactor(n, p);
                break;
            }
            case 2: {
                man.writeReactors();
                break;
            }
            case 3: {
                do {
                    cout << "Type the ordinal number of the reactor you want to test: ";
                    cin >> n;
                    if (n >= 0 && n < man.getSize()) {
                        a = 1;
                        break;
                    }
                    cout << "There is no such a reactor." << endl;
                } while (a == 0);
                man.getReactor(n)->measureTemp();
                break;
            }
            case 4: {
                man.calculatePower();
                cout << "Total power of the power station amounts to: " << man.getTotalPower() << " MW" << endl;
                break;
            }
            case 5: {
                cout << "Amount of energy [GJ]: ";
                cin >> p;
                cout << "It will take " << man.calculateTime(p) << " days." << endl;
                break;
            }
            case 6: {
                exit(0);
            }
            default: {
                cout << "There is no such a choice. ";
                break;
            }
        }
    }
    while(c != 6);
}