//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_CENTRAL_P_H
#define CONNECTED_MACHINES_CENTRAL_P_H

#include <functional>
#include <string>

#ifdef __APPLE__
    #include "../platform/apple/AppleCentralDelegate.h"
#endif

#include "CentralDelegate.h"

class Central;

class Central_p {
    friend class Central;
    friend class CentralDelegate;
private:
    // TODO: Should use smart pointers to avoid deallocation
    CentralDelegate *delegate;
    Central *proxyedCentral;
#ifdef __APPLE__
private:
    AppleCentralDelegate *apple_delegate;
    CBCentralManager *apple_manager;

    static CentralState stateFromAppleState(CBCentralManagerState state);
#endif

public:
    Central_p(Central* central, CentralDelegate *delegate);
    void startScan();
    void stopScan();
    CentralState getState();
};

#endif //CONNECTED_MACHINES_CENTRAL_P_H
