//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_ANDROIDJNIHELPER_H
#define CONNECTED_MACHINES_ANDROIDJNIHELPER_H

#include <jni.h>
#include <string>

namespace AndroidJNIHelper {
    JavaVM *getJVM();
    JNIEnv *getJNIEnv();
};

#endif //CONNECTED_MACHINES_ANDROIDJNIHELPER_H
