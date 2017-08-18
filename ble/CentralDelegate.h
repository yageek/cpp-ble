//
// Created by Yannick Heinrich on 18.08.17.
//

#ifndef CPP_BLE_CENTRALDELEGATE_H
#define CPP_BLE_CENTRALDELEGATE_H

#include <string>
#include <iostream>

class Central;

class CentralDelegate {
public:
    virtual void device_discovered(std::string &name, double RSSI) {
        std::cout << "Device found:" << name << " RSSI:" << RSSI << std::endl;
    };

    virtual void central_updated_state(Central* central) {
            std::cout << "Manager has updated state" << std::endl;
    };
};

#endif //CPP_BLE_CENTRALDELEGATE_H
