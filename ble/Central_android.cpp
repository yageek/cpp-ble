//
// Created by Yannick Heinrich on 18.08.17.
//
#include "Central.h"
#include <android/log.h>

Central::Central(CentralDelegate *delegate) {

    __android_log_print(ANDROID_LOG_DEBUG, "CPPAPP", "Start Android central");
    this->delegate = delegate;

    android_adapter = new AndroidAdapter();
}

void Central::startScan() {

}

void Central::stopScan() {

}

CentralState Central::getState() {
    return CentralState::NotAvailable;
}