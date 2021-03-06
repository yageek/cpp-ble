//
// Created by Yannick Heinrich on 16.08.17.
//

#include "AppleCentralDelegate.h"

@implementation AppleCentralDelegate

- (instancetype) initWithDelegate:(CentralDelegate*) delegateInstance forCentral:(Central *) centralInstance {

    if (self = [super init]) {
        self->delegate = delegateInstance;
        self->central = centralInstance;
    }
    return self;
}

- (void) centralManagerDidUpdateState:(CBCentralManager *)centralInstance {
    if(!self->delegate) {
        return;
    }

    self->delegate->central_updated_state(self->central);
}

- (void) centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary<NSString *,id> *)advertisementData RSSI:(NSNumber *)RSSI {
    if(!self->delegate) {
        return;
    }
    std::string cppName([peripheral.name UTF8String], [peripheral.name lengthOfBytesUsingEncoding:NSUTF8StringEncoding]);
    self->delegate->device_discovered(cppName, RSSI.doubleValue);
}

@end
