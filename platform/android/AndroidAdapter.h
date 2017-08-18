//
// Created by Yannick Heinrich on 18.08.17.
//

#ifndef CPP_BLE_ANDROIDADAPTER_H
#define CPP_BLE_ANDROIDADAPTER_H

#include <jni.h>

class AndroidAdapter {

public:
    AndroidAdapter();
    ~AndroidAdapter();
private:
    jobject adapter;
    JNIEnv *env;
};


#endif //CPP_BLE_ANDROIDADAPTER_H
