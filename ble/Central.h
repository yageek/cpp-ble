//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_CENTRAL_H
#define CONNECTED_MACHINES_CENTRAL_H

#include <functional>
#include "Central_p.h"

class Central {

public:
    void startScan(std::function<void(int)> scan_callback);
    void stopScan();

    bool isScanning();
    bool isValid();
    Central();
private:
    Central_p * d;
};


#endif //CONNECTED_MACHINES_CENTRAL_H
