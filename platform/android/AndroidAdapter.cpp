//
// Created by Yannick Heinrich on 18.08.17.
//

#include <jni/jni.hpp>
#include "AndroidAdapter.h"
#include "AndroidJNIHelper.h"

// See https://stackoverflow.com/questions/28991228/getting-android-bluetooth-adapter-name-from-jni-c

AndroidAdapter::~AndroidAdapter() { }

AndroidAdapter::AndroidAdapter(CentralDelegate *delegateInstance): delegate(delegateInstance) {


}

void AndroidAdapter::startScan() {
    jni::JNIEnv &env = *AndroidJNIHelper::getJNIEnv();
    static jni::jclass* systemClass = jni::NewGlobalRef(env, &jni::FindClass(env, "java/lang/System")).release();

}

void AndroidAdapter::stopScan(){

}