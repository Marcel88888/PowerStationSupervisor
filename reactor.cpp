#include <iostream>
#include "reactor.h"
using namespace std;

void Reactor::writeCoolant() {
    exit(0);
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

status Reactor::getStatus() {
    return stat;
}

int Reactor::getType() {
    return type;
}

void Reactor::setTemp(int t) {
    temperature = t;
}

void Reactor::setStatus(status a) {
    stat = a;
}

Reactor::Reactor(int num, double pow, int t) {
    number = num;
    power = pow;
    temperature = 0;
    stat = rest;
    type = t;
}