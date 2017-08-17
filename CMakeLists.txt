cmake_minimum_required(VERSION 3.4.1)
project(cpp-ble VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
if(APPLE)
    add_compile_options(-x objective-c++)
endif()

set(HEADER_FILES ble/Central.h uuid/UUID.h ble/Central_p.h)
set(SOURCE_FILES ble/Central.cpp uuid/UUID.cpp ble/Central_p.cpp)

if(ANDROID)
find_library(log-lib log)

    LIST(APPEND SOURCE_FILES platform/jni/AndroidJNIHelper.h platform/jni/AndroidJNIHelper.cpp)
    LIST(APPEND HEADER_FILES platform/jni/AndroidJNIHelper.h)
    add_library(cpp-ble SHARED ${SOURCE_FILES} ${HEADER_FILES})
    target_link_libraries(cpp-ble ${log-lib})
endif()

if(APPLE)
    LIST(APPEND SOURCE_FILES ble/Central_p_apple.mm platform/apple/CentralProxy.mm platform/apple/CentralProxy.h)
    LIST(APPEND HEADER_FILES platform/apple/CentralProxy.h)
    add_library(cpp-ble ${SOURCE_FILES} ${HEADER_FILES})
endif()

