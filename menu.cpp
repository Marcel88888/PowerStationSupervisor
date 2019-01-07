#include <iostream>
#include "menu.h"
#include "manager.h"
using namespace std;

void Menu::menuOperation() {
    int c, n, p, a;
    Manager man;
    do {
        cout << "---------------------MENU---------------------";
        cout << endl << "Options: " << endl;
        cout << " 1- add reactors" << endl;
        cout << " 2- write out all the reactors" << endl;
        cout << " 3- test the temperature of the reactor" << endl;
        cout << " 4- check the total power of the power station" << endl;
        cout << " 5- check how long it will take to produce some amount of energy" << endl;
        cout << " 6- exit" << endl;
        cout << "Your choice: ";
        cin >> c;
        switch (c) {
            case 1: {
                string file;
                cout << "Type the name of the file containing the reactors' data: ";
                cin >> file;
                man.addReactors(file);
                break;
            }
            case 2: {
                man.writeReactors();
                break;
            }
            case 3: {
                do {
                    a = 0;
                    cout << "Type the ordinal number of the reactor you want to test: ";
                    cin >> n;
                    if (n >= 1 && n <= man.getSize())
                        break;
                    cout << "There is no such a reactor." << endl;
                } while (a == 0);
                man.getReactor(n-1)->measureTemp();
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