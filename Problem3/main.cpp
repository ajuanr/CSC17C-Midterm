//
//  main.cpp
//  Problem3
//
//  Created by Juan Ruiz on 10/30/15.
//  Copyright © 2015 Juan Ruiz. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <map>
#include <numeric>

#include "SimpleVector.h"


//void fill(SimpleVector<int>&, int=10);
//void print(SimpleVector<int>&);

void fill(SimpleVector<int>&, int, int = 9);
void printVec(SimpleVector<int>&, int=100);
float median(const SimpleVector<int>&);
void mode(const SimpleVector<int>&);
int max(const map<int, int>&);


int main(int argc, const char * argv[]) {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    SimpleVector<int> v;
    // number for random number generator
    cout << "What is the largest value to use: ";
    int mod;
    cin >> mod;
    
    // numbers to print per line
    cout << "How many numbers to print per line: ";
    int perLine;
    cin >> perLine;
    
    fill(v, size, mod);
    
    printVec(v, perLine);
    
    if (!v.empty()) {
        cout<<"Mean: "<<accumulate(v.begin(), v.end(), 0.0) / v.size()
        << endl;
        cout << "Median: " << median(v) << endl;
        mode(v);
    }
    else
        cout << "No data was input\n";

    return 0;
}

void fill(SimpleVector<int>& a, int size, int mod) {
    // use current time as seed for random number generator
    srand(static_cast<unsigned int>(time(0)));
    for (int i = 0; i != size; ++i) {
        a.push_back(rand() % mod + 1);
    }
}

void printVec(SimpleVector<int>& a, int p) {
    for (int i = 0; i != a.size(); ++i) {
        cout << a[i] << " ";
        if (i % p == p-1)
            cout << endl;
    }
    cout << endl;
}

float median(const SimpleVector<int>& in) {
    SimpleVector<int> v = in;
    sort(v.begin(),v.end());
    int mid = v.size()/2;
    if (v.size() %2 == 0){
        return (v[mid] + v[mid-1])/2.0;
    }
    else
        return v[mid];
}

void mode(const SimpleVector<int>& v) {
    map<int, int> modes;
    for(SimpleVector<int>::const_iterator it= v.begin();
        it != v.end(); ++it) {
        modes[*it]++;
    }

    // prints out key with its frequency
//    for (map<int,int>::const_iterator it = modes.begin(); it!=modes.end(); ++it)
//        cout << it->first << " " << it->second << endl;
    
    int maxVal = max(modes);
    
    // if max is 1, then no number is repeated
    if (maxVal==1) {
        cout << "Mode: {0}";
    }
    
    else {
        cout << "Mode: { ";
        for (map<int, int>::iterator it = modes.begin();
             it != modes.end(); ++it) {
            if (it->second == maxVal) {
                cout << it->first << " ";
            }
        }
        cout << "}\n";
    }
    cout << endl;
}

int max(const map<int,int>& m) {
    int max = m.begin()->second;
    for (map<int, int>::const_iterator it= m.begin(); it!= m.end(); ++it) {
        if (it->second > max) {
            max = it->second;
        }
    }
    return max;
}