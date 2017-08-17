//
// Created by Yannick Heinrich on 16.08.17.
//

#include "CentralProxy.h"
#include "../../ble/Central_p.h"

@implementation AppleCentralDelegate

- (instancetype) initWithSet:(CentralCallbackSet*) set {

    if (self = [super init]) {
        self->callbacks = set;
    }
    return self;
}

- (void) centralManagerDidUpdateState:(CBCentralManager *)central {

}

- (void) centralManager:(CBCentralManager *)central didDiscoverPeripheral:(CBPeripheral *)peripheral advertisementData:(NSDictionary<NSString *,id> *)advertisementData RSSI:(NSNumber *)RSSI {
    self->callbacks->device_discovered(0);
}

@end
