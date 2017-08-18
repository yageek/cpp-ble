//
//  CustomCentralDelegate.hpp
//  TestBLEMac
//
//  Created by Yannick Heinrich on 18.08.17.
//  Copyright © 2017 yageek. All rights reserved.
//

#ifndef CustomCentralDelegate_hpp
#define CustomCentralDelegate_hpp

#include <stdio.h>
#include "ble/CentralDelegate.h"

class CustomCentralDelegate: public CentralDelegate {

public:
    CustomCentralDelegate();
    void central_updated_state(Central* central);

};
#endif /* CustomCentralDelegate_hpp */
