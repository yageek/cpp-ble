//
//  ViewController.m
//  TestBLEMac
//
//  Created by Yannick Heinrich on 18.08.17.
//  Copyright © 2017 yageek. All rights reserved.
//

#import "ViewController.h"
#import "ble/Central.h"
#import "ble/CentralDelegate.h"

@implementation ViewController {
    Central *cppCentral;
    CentralDelegate *centralDelegate;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    centralDelegate = new CentralDelegate();
    cppCentral = new Central(centralDelegate);
    // Do any additional setup after loading the view.
}


- (void)setRepresentedObject:(id)representedObject {
    [super setRepresentedObject:representedObject];

    // Update the view, if already loaded.
}


@end
