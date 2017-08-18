cmake_minimum_required(VERSION 3.4.1)
project(cpp-ble VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
if(APPLE)
    add_compile_options(-x objective-c++)
endif()

set(HEADER_FILES ble/Central.h uuid/UUID.h ble/CentralDelegate.h)
set(SOURCE_FILES uuid/UUID.cpp)

if(ANDROID)
find_library(log-lib log)

    LIST(APPEND SOURCE_FILES platform/jni/AndroidJNIHelper.cpp platform/android/AndroidAdapter.cpp ble/Central_android.cpp)
    LIST(APPEND HEADER_FILES platform/jni/AndroidJNIHelper.h platform/android/AndroidAdapter.h)
    add_library(cpp-ble SHARED ${SOURCE_FILES} ${HEADER_FILES})
    target_link_libraries(cpp-ble ${log-lib})
endif()

if(APPLE)
    LIST(APPEND SOURCE_FILES ble/Central_ios.mm platform/apple/AppleCentralDelegate.mm)
    LIST(APPEND HEADER_FILES platform/apple/AppleCentralDelegate.h)
    add_library(cpp-ble ${SOURCE_FILES} ${HEADER_FILES})
endif()

