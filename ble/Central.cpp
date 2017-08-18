//
// Created by Yannick Heinrich on 16.08.17.
//

#include "Central.h"
#include "Central_p.h"
#include "CentralDelegate.h"

void Central::startScan() {
    d->startScan();
}

void Central::stopScan() {
}

bool Central::isScanning() {
    return false;
}

bool Central::isValid() {
    return false;
}

Central::Central(CentralDelegate *delegate) {
    d = new Central_p(this, delegate);
}

Central::~Central() {
    delete d;
}
