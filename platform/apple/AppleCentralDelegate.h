//
// Created by Yannick Heinrich on 16.08.17.
//

#ifndef CONNECTED_MACHINES_CENTRALPROXY_H
#define CONNECTED_MACHINES_CENTRALPROXY_H

#import <CoreBluetooth/CoreBluetooth.h>
class Central_p;
class CentralDelegate;

@interface AppleCentralDelegate: NSObject <CBCentralManagerDelegate> {
    CentralDelegate *delegate;
    Central_p* central;
}
- (instancetype) initWithDelegate:(CentralDelegate*) delegateInstance forCentral:(Central_p *) central;
@end
#endif //CONNECTED_MACHINES_CENTRALPROXY_H
