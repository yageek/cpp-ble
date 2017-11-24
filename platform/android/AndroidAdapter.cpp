//
// Created by Yannick Heinrich on 18.08.17.
//

#include <jni/jni.hpp>
#include "AndroidAdapter.h"
#include "AndroidJNIHelper.h"
#include <android/log.h>
// See https://stackoverflow.com/questions/28991228/getting-android-bluetooth-adapter-name-from-jni-c

AndroidAdapter::~AndroidAdapter() { }

AndroidAdapter::AndroidAdapter(CentralDelegate *delegateInstance): delegate(delegateInstance) {
    jni::JNIEnv &env = *AndroidJNIHelper::getJNIEnv();
    jazz = jni::NewGlobalRef(env, &jni::FindClass(env, "net/yageek/cppble/ScanningHelper"));

    jni::jmethodID &method = jni::GetMethodID(env, *jazz.get(), "getScanningHelper", "()Lnet/yageek/cppble/ScanningHelper;");
    object = jni::CallStaticMethod<jni::jobject*>(env, *jazz.get(), method);
}

void AndroidAdapter::startScan() {

    jni::JNIEnv &env = *AndroidJNIHelper::getJNIEnv();
    jni::jmethodID &method = jni::GetMethodID(env, *jazz.get(), "scanForBLE", "()Z");
    jni::CallMethod<jni::jboolean>(env, object, method);
}

void AndroidAdapter::stopScan(){

}
// MAIN CODE for the library to test
extern "C"
JNIEXPORT void JNICALL
Java_net_yageek_cppble_CentralCallbackLegacy_onScanResultProxy(JNIEnv *env, jobject instance, jstring name) {

    const char *nativeString = env->GetStringUTFChars(name, nullptr);
    __android_log_print(ANDROID_LOG_DEBUG, "CppBLE", "Name from NDK: %s", nativeString);
}
