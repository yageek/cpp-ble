// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from core.idl

#import "YGCentralInterface+Private.h"
#import "YGCentralInterface.h"
#import "Basic-objc.hpp"
#import "DJIMarshal+Private.h"
#import "DJIObjcWrapperCache+Private.h"
#include <stdexcept>

static_assert(__has_feature(objc_arc), "Djinni requires ARC to be enabled for this file");

namespace djinni_generated {

class CentralInterface::ObjcProxy final
: public ::cppble::CentralInterface
, private ::djinni::ObjcProxyBase<ObjcType>
{
    friend class ::djinni_generated::CentralInterface;
public:
    using ObjcProxyBase::ObjcProxyBase;
    void start_scan(const std::vector<cppble::UUID> & c_uuids) override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() startScan:(::djinni::List<::djinni::Color>::fromCpp(c_uuids))];
        }
    }
    void stop_scan() override
    {
        @autoreleasepool {
            [djinni_private_get_proxied_objc_object() stopScan];
        }
    }
};

}  // namespace djinni_generated

namespace djinni_generated {

auto CentralInterface::toCpp(ObjcType objc) -> CppType
{
    if (!objc) {
        return nullptr;
    }
    return ::djinni::get_objc_proxy<ObjcProxy>(objc);
}

auto CentralInterface::fromCppOpt(const CppOptType& cpp) -> ObjcType
{
    if (!cpp) {
        return nil;
    }
    return dynamic_cast<ObjcProxy&>(*cpp).djinni_private_get_proxied_objc_object();
}

}  // namespace djinni_generated
