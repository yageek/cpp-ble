//
// Created by Yannick Heinrich on 18.08.17.
//

#include "AndroidAdapter.h"
#include "../jni/AndroidJNIHelper.h"

// See https://stackoverflow.com/questions/28991228/getting-android-bluetooth-adapter-name-from-jni-c

AndroidAdapter::AndroidAdapter() {
    env = AndroidJNIHelper::getJNIEnv();

    jclass classBta = env->FindClass("android/bluetooth/BluetoothAdapter");
    jmethodID methodIdGetAdapter = env->GetStaticMethodID(classBta, "getDefaultAdapter", "()Landroid/bluetooth/BluetoothAdapter;");

    adapter = (jobject)  env->CallStaticObjectMethod(classBta, methodIdGetAdapter);
    env->DeleteLocalRef(classBta);
}

AndroidAdapter::~AndroidAdapter() {
    env->DeleteLocalRef(adapter);
}