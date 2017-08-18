//
// Created by Yannick Heinrich on 18.08.17.
//

#include "AndroidAdapter.h"
#include "../jni/AndroidJNIHelper.h"

// See https://stackoverflow.com/questions/28991228/getting-android-bluetooth-adapter-name-from-jni-c

AndroidAdapter::AndroidAdapter(CentralDelegate *delegateInstance): delegate(delegateInstance) {
    env = AndroidJNIHelper::getJNIEnv();

    clazz = env->FindClass("android/bluetooth/BluetoothAdapter");
    jmethodID methodIdGetAdapter = env->GetStaticMethodID(clazz, "getDefaultAdapter", "()Landroid/bluetooth/BluetoothAdapter;");

    adapter = env->CallStaticObjectMethod(clazz, methodIdGetAdapter);

}

AndroidAdapter::~AndroidAdapter() {
    env->DeleteLocalRef(adapter);
    env->DeleteLocalRef(clazz);
}

void AndroidAdapter::startScan() {

    jmethodID methodScan = env->GetMethodID(clazz, "startLeScan", "([Ljava/util/UUID;Landroid/bluetooth/BluetoothAdapter/BluetoothAdapter$LeScanCallback;)Z");
    jboolean result = env->CallBooleanMethod(adapter, methodScan);
}

void AndroidAdapter::stopScan(){
    jmethodID methodStop = env->GetMethodID(clazz, "stopLeScan", "([Landroid/bluetooth/BluetoothAdapter/BluetoothAdapter$LeScanCallback;)V");
    env->CallVoidMethod(adapter, methodStop);
}