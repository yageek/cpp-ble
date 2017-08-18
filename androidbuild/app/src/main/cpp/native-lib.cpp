#include <jni.h>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_net_yageek_testapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {

    return env->NewStringUTF("dedwedwd");
}
