//
//  main.cpp
//  Problem 6
//
//  Created by Juan on 10/31/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "LnkdLst.hpp"

void fill(LnkdLst<int>&, int, int = 9);
void printVec(LnkdLst<int>&, int=100);

int main(int argc, const char * argv[]) {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    LnkdLst<int> ll;
    // number for random number generator
    cout << "What is the largest value to use: ";
    int mod;
    cin >> mod;
    
    // numbers to print per line
    cout << "How many numbers to print per line: ";
    int perLine;
    cin >> perLine;
    
    fill(ll, size, mod);
    printVec(ll, perLine);
    ll.sort();
    ll.print();
    
    return 0;
}

void fill(LnkdLst<int>& ll, int size, int mod) {
    // use current time as seed for random number generator
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i != size; ++i) {
    ll.append(rand() % mod + 1);
    }
}

void printVec(LnkdLst<int>& ll, int p) {
    for (int i = 0; i != ll.getSize(); ++i) {
        cout << ll.get(i) << " ";
        if (i % p == p-1)
            cout << endl;
    }
    cout << endl;
}