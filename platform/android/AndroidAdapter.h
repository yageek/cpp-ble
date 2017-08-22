//
// Created by Yannick Heinrich on 18.08.17.
//

#ifndef CPP_BLE_ANDROIDADAPTER_H
#define CPP_BLE_ANDROIDADAPTER_H

#include <jni.h>
#include "../../ble/CentralDelegate.h"
#include <memory>
class AndroidAdapter {

public:
    AndroidAdapter(CentralDelegate *delegate);
    ~AndroidAdapter();

    void startScan();
    void stopScan();

private:
    CentralDelegate *delegate;
};


#endif //CPP_BLE_ANDROIDADAPTER_H
