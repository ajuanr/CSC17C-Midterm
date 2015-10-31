//
//  StatClass.cpp
//  Problem3
//
//  Created by Juan on 10/31/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "StatClass.h"

using namespace std;

// initial mean and median with the values of zero
// default constructor for SimpleVector will be used for initialzization
StatClass::StatClass(): mean(0), median(0) {};
void StatClass::print() const {
    if (mean==0) {
        cout << "No data was input" << endl;
    }
    else {
        cout << "Mean: " << mean << endl
             << "Median: " << median << endl
             << "Mode: ";
        if (mode.empty()) {
            cout << " { 0 }" << endl;
        }
        else {
            cout << "{ ";
            for (SimpleVector<int>::const_iterator it= mode.begin();
                it != mode.end(); ++it) {
                cout << *it << " ";
            }
            cout << "}\n";
        }
    }
}