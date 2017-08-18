#include <jni.h>
#include <string>
#include "ble/Central.h"
#include "ble/CentralDelegate.h"

extern "C"
JNIEXPORT jstring JNICALL
Java_net_yageek_testapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    CentralDelegate *delegate = new CentralDelegate();
    Central *central = new Central(delegate);
    central->startScan();

    return env->NewStringUTF("dedwedwd");
}
