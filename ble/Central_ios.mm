//
// Created by Yannick Heinrich on 17.08.17.
//

#include <iostream>
#include "Central.h"

void Central::startScan() {
    std::cout << "[Apple] Start scanning" << std::endl;
    [apple_manager scanForPeripheralsWithServices:nil options:nil];
}

void Central::stopScan() {
    [apple_manager stopScan];
}

Central::Central(CentralDelegate *delegate) {

    this->delegate = delegate;
    std::cout << "Central Apple init" << std::endl;
    apple_delegate = [[AppleCentralDelegate alloc] initWithDelegate:delegate forCentral:this];
    apple_manager = [[CBCentralManager alloc] initWithDelegate:apple_delegate queue:nil];
}


CentralState Central::getState() {
    return stateFromAppleState([apple_manager state]);
}

CentralState Central::stateFromAppleState(CBManagerState state) {
    std::cout <<"Raw state:" << state << std::endl;
    switch (state) {
        case CBManagerStateUnknown:
            return CentralState::NotReady;
        case CBManagerStateResetting:
            return CentralState::NotReady;
        case CBManagerStateUnauthorized:
        std::cout <<"Not Authorized" << std::endl;
        case CBManagerStateUnsupported:
            return CentralState::NotAvailable;
        case CBManagerStatePoweredOff:
            return CentralState::Off;
        case CBManagerStatePoweredOn:
            return CentralState::On;
    }
}
