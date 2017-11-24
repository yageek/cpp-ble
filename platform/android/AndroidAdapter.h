//
// Created by Yannick Heinrich on 18.08.17.
//

#ifndef CPP_BLE_ANDROIDADAPTER_H
#define CPP_BLE_ANDROIDADAPTER_H

#include <jni/jni.hpp>
#include "../../ble/CentralDelegate.h"
#include <memory>
class AndroidAdapter: CentralDelegate {

public:
    AndroidAdapter(CentralDelegate *delegate);
    ~AndroidAdapter();

    void startScan();
    void stopScan();

private:
    CentralDelegate *delegate;
    jni::UniqueGlobalRef<jni::jclass> jazz;
    jni::jobject* object;
};


#endif //CPP_BLE_ANDROIDADAPTER_H
