//
// Created by Yannick Heinrich on 17.08.17.
//

#include "Central_p.h"
#include "../ble/Central_p.h"

void Central_p::startScan(std::function<void(int)> device_discovered) {
    [apple_manager scanForPeripheralsWithServices:nil options:nil];
}

void Central_p::stopScan() {
    [apple_manager stopScan];
}

Central_p::Central_p() {
    callbacks = new CentralCallbackSet();

    apple_delegate = [[AppleCentralDelegate alloc] initWithSet:callbacks];
    apple_manager = [[CBCentralManager alloc] initWithDelegate:apple_delegate queue:nil];
}
