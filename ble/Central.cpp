//
// Created by Yannick Heinrich on 16.08.17.
//

#include "Central.h"

void Central::startScan(std::function<void(int)> scan_callback) {
    d->startScan(scan_callback);
}

void Central::stopScan() {
}

bool Central::isScanning() {
    return false;
}

bool Central::isValid() {
    return false;
}

Central::Central(): d() {

}
