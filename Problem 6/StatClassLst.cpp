//
//  StatClass.cpp
//  Problem3
//
//  Created by Juan on 10/31/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "StatClassLst.h"

using namespace std;

// initial mean and median with the values of zero
// default constructor for LnkdLst will be used for initialzization
StatClass::StatClass(LnkdLst<int> data): mean(0), median(0)
{
    this->data = data;
};
void StatClass::print() {
    if (mean==0) {
        cout << "No data was input" << endl;
    }
    else {
        cout << "Mean: " << mean << endl
             << "Median: " << median << endl
             << "Mode: ";
        if (mode.getSize()==0) {
            cout << " { 0 }" << endl;
        }
        else {
            cout << "{ ";
            for (int i = 0; i != mode.getSize(); ++i) {
                cout << mode.get(i) << " ";
            }
            cout << "}\n";
        }
    }
}