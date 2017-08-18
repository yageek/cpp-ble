//
//  CustomCentralDelegate.cpp
//  TestBLEMac
//
//  Created by Yannick Heinrich on 18.08.17.
//  Copyright © 2017 yageek. All rights reserved.
//

#include "CustomCentralDelegate.hpp"

CustomCentralDelegate::CustomCentralDelegate() {}

void CustomCentralDelegate::central_updated_state(Central *central) {

    switch (central->getState()) {
        case CentralState::On:
            std::cout << "Will start Scanning..." << std::endl;
            central->startScan();
        case CentralState::Off:
            std::cout << "Powered Off" << std::endl;
        case CentralState::NotReady:
            std::cout << "Not Ready" << std::endl;
        case CentralState::NotAvailable:
            std::cout << "NotAvailable" << std::endl;
    }
}
