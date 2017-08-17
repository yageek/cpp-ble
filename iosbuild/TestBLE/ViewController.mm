//
//  ViewController.m
//  TestBLE
//
//  Created by Yannick Heinrich on 16.08.17.
//  Copyright © 2017 yageek. All rights reserved.
//

#import "ViewController.h"
#import <ble/Central.h>

@interface ViewController () {
    Central *centeal;
}

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    Central *p = new Central();
    p->startScan(nullptr);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
