#include <iostream>
#include "menu.h"
using namespace std;

void Menu::menuOperation() {
    int c;
    Graph <int> gr;
    cout << "---------------------MENU---------------------";
    cout << endl << "Options: " << endl;
    cout << " 1- " << endl;
    cout << " 2- " << endl;
    cout << " 3- " << endl;
    cout << " 4- " << endl;
    cout << " 5- " << endl;
    do {
        cout << endl << "Your choice: ";
        cin >> c;
        switch (c) {
            case 1: {
                string file;
                cout << "Type the name of the file containing the 's data: ";
                cin >> file;

                break;
            }
            case 2: {

                break;
            }
            case 3: {

                break;
            }
            case 4: {

                break;
            }
            case 5: {
                exit(0);
            }
            default: {
                cout << "There is no such a choice. ";
                break;
            }
        }
    }
    while(c != 5);
}