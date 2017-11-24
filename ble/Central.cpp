//
// Created by Yannick Heinrich on 16.08.17.
//

#include "Central.h"
#include "CentralDelegate.h"

Central(std::weak_ptr<CentralDelegate> delegate) delegate(delegate.lock()){
}

Central::~Central() {
}
