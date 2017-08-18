//
// Created by Yannick Heinrich on 16.08.17.
//

#include "AndroidJNIHelper.h"
#include <android/log.h>

static JavaVM *m_android_vm = nullptr;

JavaVM *AndroidJNIHelper::getJVM() {
    return m_android_vm;
}

JNIEnv *AndroidJNIHelper::getJNIEnv() {
    JavaVM *vm = AndroidJNIHelper::getJVM();
    JNIEnv *jniEnv(nullptr);

    const jint ret = vm->GetEnv((void **) &jniEnv, JNI_VERSION_1_6);
    if (ret == JNI_OK) // Already attached
        return jniEnv;
    if (ret == JNI_EDETACHED) { // We need to (re-)attach
        JavaVMAttachArgs args = {JNI_VERSION_1_6, "CPP-BLEThread", nullptr};
        if (vm->AttachCurrentThread(&jniEnv, &args) != JNI_OK)
            return jniEnv;
    }
    return jniEnv;
}

extern "C"
jint JNICALL JNI_OnLoad(JavaVM *vm, void *) {
    __android_log_print(ANDROID_LOG_DEBUG, "CppBLE", "JNI Init");
    static bool initialised = false;

    if (initialised) {
        return initialised;
    }
    initialised = true;
    m_android_vm = nullptr;

    typedef union {
        JNIEnv *nativeEnvironment;
        void *venv;
    } UnionJNIEnvToVoid;
    
    UnionJNIEnvToVoid venv;
    JNIEnv *nativeEnvironment = nullptr;

    if (vm->GetEnv(&venv.venv, JNI_VERSION_1_4) != JNI_OK) {
        __android_log_print(ANDROID_LOG_FATAL, "CppBLE", "GetEnv failed");
        return -1;
    }
    return JNI_VERSION_1_6;
}
