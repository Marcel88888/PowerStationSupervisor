#include <iostream>
#include "reactor.h"
using namespace std;

int Reactor::getTemp() {
    return temperature;
}

int Reactor::getNumber() {
    return number;
}

double Reactor::getPower() {
    return power;
}

status Reactor::getStatus() {
    return stat;
}

void Reactor::setTemp(int t) {
    temperature = t;
}

void Reactor::setStatus(status a) {
    stat = a;
}

Reactor::Reactor(int num, double pow) {
    number = num;
    power = pow;
    temperature = 0;
    stat = rest;
}