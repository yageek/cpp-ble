//
// Created by Yannick Heinrich on 18.08.17.
//
#include "Central.h"
#include <android/log.h>
#include "../ble/Central.h"
#include "../ble/CentralDelegate.h"

Central::Central(CentralDelegate *delegate) {

    __android_log_print(ANDROID_LOG_DEBUG, "CPPAPP", "Start Android central");
    this->delegate = delegate;

    android_adapter = new AndroidAdapter(delegate);
}

void Central::startScan() {

}

void Central::stopScan() {

}

CentralState Central::getState() {
    return CentralState::NotAvailable;
}

// MAIN CODE for the library to test
extern "C"
JNIEXPORT void JNICALL
Java_net_yageek_cppble_mainlibcode_TestLibCall_startScan(JNIEnv *env, jobject instance) {
    CentralDelegate *delegate = new CentralDelegate();
    Central *central = new Central(delegate);
    central->startScan();
}
