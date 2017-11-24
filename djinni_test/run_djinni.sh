# !/bin/sh

temp_out="generated-src"
java -jar djinni.jar --java-out "$temp_out/java" \
    --java-package "net.yageek.cppble" \
    --java-class-access-modifier "package" \
    --java-nullable-annotation "javax.annotation.CheckForNull" \
    --java-nonnull-annotation "javax.annotation.Nonnull" \
    --ident-java-field mFooBar \
    \
    --cpp-out "$temp_out/cpp" \
    --cpp-namespace cppble \
    --ident-cpp-enum-type foo_bar \
    \
    --jni-out "$temp_out/jni" \
    --ident-jni-class NativeFooBar \
    --ident-jni-file NativeFooBar \
    \
    --objc-out "$temp_out/objc" \
    --objcpp-out "$temp_out/objc" \
    --objc-type-prefix YG \
    --objc-swift-bridging-header "CppBle-Bridging-Header" \
    \
    --idl "idls/core.idl" 