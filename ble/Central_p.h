//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_CENTRAL_P_H
#define CONNECTED_MACHINES_CENTRAL_P_H

#include <functional>

#ifdef __APPLE__
    #include "../platform/apple/CentralProxy.h"
#endif

struct CentralCallbackSet {
    std::function<void(int)> device_discovered;
};

class Central_p {
private:
    // TODO: Should use smart pointers to avoid deallocation
    CentralCallbackSet *callbacks;
#ifdef __APPLE__
private:
    AppleCentralDelegate *apple_delegate;
    CBCentralManager *apple_manager;
#endif

public:
    Central_p();
    void startScan(std::function<void(int)> device_discovered);
    void stopScan();
};

#endif //CONNECTED_MACHINES_CENTRAL_P_H
