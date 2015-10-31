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
#include "StatClass.h"

using namespace std;

void fill(SimpleVector<int>&, int, int = 9);
void printVec(SimpleVector<int>&, int=100);
float median(const SimpleVector<int>&);
SimpleVector<int> mode(const SimpleVector<int>&);
int max(const map<int, int>&);
StatClass *stat(SimpleVector<int>);

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
    
    StatClass *sc = stat(v);
    sc->print();
    
    // causes problems
//    delete sc;

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

SimpleVector<int> mode(const SimpleVector<int>& v) {
    SimpleVector<int> out;
    map<int, int> modes;
    for(SimpleVector<int>::const_iterator it= v.begin();
        it != v.end(); ++it) {
        modes[*it]++;
    }

    // prints out key with its frequency
//    for (map<int,int>::const_iterator it = modes.begin(); it!=modes.end(); ++it)
//        cout << it->first << " " << it->second << endl;
    
    int maxVal = max(modes);

    if (maxVal > 1){
        for (map<int, int>::iterator it = modes.begin();
             it != modes.end(); ++it) {
            if (it->second == maxVal) {
                out.push_back(it->first);
            }
        }
    }
    return out;
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

StatClass *stat(SimpleVector<int> x) {
    StatClass *sc = new StatClass;
    if (!x.empty()) {
        sc->setMean(accumulate(x.begin(), x.end(), 0.0) / x.size());
        sc->setMedian(median(x));
        sc->setMode(mode(x));
    }
    else
        cout << "No data was input\n";
    
    return sc;
}