//
//  ViewController.m
//  TestBLE
//
//  Created by Yannick Heinrich on 16.08.17.
//  Copyright © 2017 yageek. All rights reserved.
//

#import "ViewController.h"
#import "ble/Central.h"
#include "CustomCentralDelegate.hpp"

@interface ViewController () {
    Central *cppCentral;
    CustomCentralDelegate *centralDelegate;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    centralDelegate = new CustomCentralDelegate();
    cppCentral = new Central(centralDelegate);

    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(5 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        cppCentral->stopScan();
    });
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
