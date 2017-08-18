//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_CENTRALPROXY_H
#define CONNECTED_MACHINES_CENTRALPROXY_H

#import "../../ble/CentralDelegate.h"
#import <CoreBluetooth/CoreBluetooth.h>

class Central;
class CentralDelegate;

@interface AppleCentralDelegate: NSObject <CBCentralManagerDelegate> {
    CentralDelegate *delegate;
    Central* central;
}
- (instancetype) initWithDelegate:(CentralDelegate*) delegateInstance forCentral:(Central *) central;
@end
#endif //CONNECTED_MACHINES_CENTRALPROXY_H
