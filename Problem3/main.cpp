//
//  main.cpp
//  Problem3
//
//  Created by Juan Ruiz on 10/30/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <cstdlib>

#include "SimpleVector.h"


void fill(SimpleVector<int>&, int=10);
void print(SimpleVector<int>&);

int main(int argc, const char * argv[]) {
    SimpleVector<int> simple;
    
    fill(simple);
    print(simple);
    
    return 0;
}

void fill(SimpleVector<int>& s, int size) {
    for (int i=0; i != size; ++i) {
        s.push_back(rand()%10);
    }
}

void print(SimpleVector<int>& s) {
    for (int i = 0; i != s.size(); ++i) {
        cout << s[i] << " ";
    }
    cout << endl;
}
