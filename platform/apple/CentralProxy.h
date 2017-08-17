//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_CENTRALPROXY_H
#define CONNECTED_MACHINES_CENTRALPROXY_H

#import <CoreBluetooth/CoreBluetooth.h>

class CentralCallbackSet;
class CentralProxy {

};

@interface AppleCentralDelegate: NSObject <CBCentralManagerDelegate> {
    CentralCallbackSet *callbacks;
}
- (instancetype) initWithSet:(CentralCallbackSet*) set;
@end
#endif //CONNECTED_MACHINES_CENTRALPROXY_H
