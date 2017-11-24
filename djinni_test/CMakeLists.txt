cmake_minimum_required(VERSION 3.4.1)
project(cpp-ble VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
if(APPLE)
    add_compile_options(-x objective-c++)
endif()

# Common elements
file(GLOB CPP_GEN_SRC "generated-src/cpp/*.hpp" "generated-src/cpp/*.cpp")
file(GLOB CPP_HAND_SRC "handwritten-src/cpp/*.hpp" "handwritten-src/cpp/*.cpp")


# Apple 
if(APPLE)
    message("[iOS Build]: ${CPP_GEN_SRC}")
    file(GLOB CPP_OBJC_GEN_SRC "generated-src/objc/*.mm" "generated-src/objc/*.h")
    include_directories("generated-src/objc" "generated-src/cpp" "handwritten-src/objc" "handwritten-src/cpp")
    add_library(cpp-ble ${CPP_HAND_SRC} ${CPP_GEN_SRC} ${CPP_OBJC_GEN_SRC})
endif()
