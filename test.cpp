#include "test.h"
#include "cmath"

bool Test::testAddingReactors(Manager *ptr) {
    int a = 0;
    double epsilon = 0.001;
    vector <Reactor*> rs;
    Reactor* reactor0 = new Reactor(12489, 1.0); rs.push_back(reactor0);
    Reactor* reactor1 = new Reactor(36974, 0.3); rs.push_back(reactor1);
    Reactor* reactor2 = new Reactor(39874, 0.1); rs.push_back(reactor2);
    Reactor* reactor3 = new Reactor(33348, 0.9); rs.push_back(reactor3);
    Reactor* reactor4 = new Reactor(49926, 0.4); rs.push_back(reactor4);
    Reactor* reactor5 = new Reactor(77264, 0.5); rs.push_back(reactor5);
    Reactor* reactor6 = new Reactor(11236, 0.3); rs.push_back(reactor6);
    Reactor* reactor7 = new Reactor(77826, 2.0); rs.push_back(reactor7);
    Reactor* reactor8 = new Reactor(46210, 3.6); rs.push_back(reactor8);
    Reactor* reactor9 = new Reactor(10008, 3.3); rs.push_back(reactor9);
    Reactor* reactor10 = new Reactor(10084, 2.7); rs.push_back(reactor10);
    Reactor* reactor11 = new Reactor(14589, 2.5); rs.push_back(reactor11);
    Reactor* reactor12 = new Reactor(45654, 2.8); rs.push_back(reactor12);
    Reactor* reactor13 = new Reactor(41234, 1.9); rs.push_back(reactor13);
    Reactor* reactor14 = new Reactor(21100, 1.0); rs.push_back(reactor14);
    Reactor* reactor15 = new Reactor(96541, 3.5); rs.push_back(reactor15);

    for (int i = 0; i < ptr->getSize(); ++i)
    {
        if ( ptr->getReactor(i)->getNumber() == rs[i]->getNumber() && abs( ptr->getReactor(i)->getPower() - rs[i]->getPower() ) < epsilon ) {
            cout << i <<": CORRECT" << endl;
            ++a;
        }
        else cout << i << ": INCORRECT" << endl;
    }
    if ( a == ptr->getSize()) {
        cout << "Test is CORRECT." << endl;
        return true;
    }
    cout << "Test is INCORRECT." << endl;
}

bool Test::testPower(Manager *ptr) {
    double epsilon = 0.001;
    ptr->calculatePower();
    if ( abs( 26.8 - ptr->getTotalPower() ) < epsilon ) {
        cout << "Test is CORRECT" << endl;
        return true;
    }
    else {
        cout << "Test is INCORRECT." << endl;
        return false;
    }
}

bool Test::testTime(Manager *ptr) {
    double epsilon = 0.001;
    if ( abs( 432 - ptr->calculateTime(1000) ) < epsilon ) {
        cout << "Test is CORRECT." << endl;
        return true;
    }
    else {
        cout << "Test is INCORRECT" << endl;
        return false;
    }
}

bool Test::testSize(Manager *ptr) {
    if ( ptr->getSize() == 16) {
        cout << "Test is CORRECT." << endl;
        return true;
    }
    else {
        cout << "Test is INCORRECT." << endl;
        return false;
    }
}