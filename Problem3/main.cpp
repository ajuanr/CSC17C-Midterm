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


//void fill(SimpleVector<int>&, int=10);
//void print(SimpleVector<int>&);

void fill(SimpleVector<int>&, int, int = 9);
void printVec(SimpleVector<int>&, int=100);

int main(int argc, const char * argv[]) {
    SimpleVector<int> simple;
    
    cout << "Enter size of the vector: ";
    int size=10;
    cin >> size;
    fill(simple, size);
    printVec(simple);

    return 0;
}

//void fill(SimpleVector<int>& s, int size) {
//    for (int i=0; i != size; ++i) {
//        s.push_back(rand()%10+1);
//    }
//}
//
//void print(SimpleVector<int>& s) {
//    for (int i = 0; i != s.size(); ++i) {
//        cout << s[i] << " ";
//    }
//    cout << endl;
//}

void fill(SimpleVector<int>& a, int size, int mod) {
    // use current time as seed for random number generator
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i != size; ++i) {
        a.push_back(rand() % mod + 1);
    }
}

void printVec(SimpleVector<int>& a, int p) {
    cout << a.size()<< endl;
    for (int i = 0; i != a.size(); ++i) {
        cout << a[i] << " ";
        if (i % p == p-1)
            cout << endl;
    }
    cout << endl;
}