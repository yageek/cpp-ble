//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_CENTRAL_H
#define CONNECTED_MACHINES_CENTRAL_H

#include <functional>
#include <iostream>

#ifdef __APPLE__
    #include <CoreBluetooth/CoreBluetooth.h>
    #include "../platform/apple/AppleCentralDelegate.h"
#endif

class CentralDelegate;

enum class CentralState {
    Off,
    On,
    NotReady,
    NotAvailable
};
class Central {
private:
    CentralDelegate *delegate;

#ifdef __APPLE__
private:
    CBCentralManager *apple_manager;
    AppleCentralDelegate *apple_delegate;

    static CentralState stateFromAppleState(CBManagerState state);
#endif
public:
    void startScan();
    void stopScan();

    CentralState getState();

    Central(CentralDelegate *delegate);
    ~Central();
};


#endif //CONNECTED_MACHINES_CENTRAL_H
