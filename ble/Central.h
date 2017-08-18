//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_CENTRAL_H
#define CONNECTED_MACHINES_CENTRAL_H

#include <functional>
#include <iostream>

class Central_p;
class CentralDelegate;

enum class CentralState {
    Off,
    On,
    NotReady,
    NotAvailable
};
class Central {

public:
    void startScan();
    void stopScan();

    bool isScanning();
    bool isValid();

    Central(CentralDelegate *delegate);
    ~Central();

    CentralState getState();
private:
    Central_p * d;
};


#endif //CONNECTED_MACHINES_CENTRAL_H
