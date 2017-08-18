//
// Created by Yannick Heinrich on 17.08.17.
//

#include <iostream>
#include "Central_p.h"
#include "Central.h"
#include "../ble/Central_p.h"

void Central_p::startScan() {
    std::cout << "[Apple] Start scanning" << std::endl;
    [apple_manager scanForPeripheralsWithServices:nil options:nil];
}

void Central_p::stopScan() {
    [apple_manager stopScan];
}

Central_p::Central_p(Central* central, CentralDelegate *delegate) {

    this->delegate = delegate;
    this->proxyedCentral = central;
    std::cout << "Central Apple init" << std::endl;
    apple_delegate = [[AppleCentralDelegate alloc] initWithDelegate:delegate forCentral:this];
    apple_manager = [[CBCentralManager alloc] initWithDelegate:apple_delegate queue:nil];
}


CentralState Central_p::getState() {
    return stateFromAppleState([apple_manager state]);
}

CentralState Central_p::stateFromAppleState(CBCentralManagerState state) {
    switch (state) {
        case CBCentralManagerStateUnknown:
            return CentralState::NotReady;
        case CBCentralManagerStateResetting:
            return CentralState::NotReady;
        case CBCentralManagerStateUnauthorized:
        case CBCentralManagerStateUnsupported:
            return CentralState::NotAvailable;
        case CBCentralManagerStatePoweredOff:
            return CentralState::Off;
        case CBCentralManagerStatePoweredOn:
            return CentralState::On;
    }
}
