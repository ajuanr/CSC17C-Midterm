//
//  main.cpp
//  Problem7
//
//  Created by Juan on 10/31/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include <iostream>

#include "SelfOrganizingList.h"

using namespace std;

void fill(LnkdLst<int>&, int, int = 9);
void printLst(LnkdLst<int>&, int=100);

int main(int argc, const char * argv[]) {
    LnkdLst<int> *ll = new SelfOrganizingList<int>();
    
    fill(*ll, 10, 9);
    printLst(*ll);
    cout << ll->inList(9) << endl;
    printLst(*ll);
    
    return 0;
}

void fill(LnkdLst<int>& ll, int size, int mod) {
    // use current time as seed for random number generator
    //srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i != size; ++i) {
        ll.append(rand() % mod + 1);
    }
}

void printLst(LnkdLst<int>& ll, int p) {
    for (int i = 0; i != ll.getSize(); ++i) {
        cout << ll.get(i) << " ";
        if (i % p == p-1)
            cout << endl;
    }
    cout << endl;
}