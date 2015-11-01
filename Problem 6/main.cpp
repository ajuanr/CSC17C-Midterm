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
#include <map>

#include "LnkdLst.hpp"

using namespace std;

void fill(LnkdLst<int>&, int, int = 9);
void printLst(LnkdLst<int>&, int=100);
float mean(LnkdLst<int>&);
float median(LnkdLst<int>&);
int max(const map<int, int>&);
void mode(LnkdLst<int>&, LnkdLst<int>&);

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
    printLst(ll, perLine);
    cout << "Median: " << median(ll) << endl;
    cout << "Mean: " << mean(ll) << endl;
    
    LnkdLst<int> modes;
    mode(ll, modes);
    printLst(modes);
    
    //mode(ll);
    return 0;
}

void fill(LnkdLst<int>& ll, int size, int mod) {
    // use current time as seed for random number generator
    srand(static_cast<unsigned int>(time(0)));
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

float median(LnkdLst<int>& in) {
    LnkdLst<int> v = in;
    v.sort();
    int mid = v.getSize()/2;
    if (v.getSize() %2 == 0){
        return (v.get(mid) + v.get(mid-1))/2.0;
    }
    else
        return v.get(mid);
}

float mean(LnkdLst<int>& ll) {
    float sum = 0.0;
    for (int i = 0; i != ll.getSize(); ++i) {
        sum += ll.get(i);
    }
    return sum/ll.getSize();
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

void mode(LnkdLst<int>& v, LnkdLst<int>& out) {
//    LnkdLst<int> out;
    map<int, int> modes;
    for(int i = 0; i != v.getSize(); ++i){
        modes[v.get(i)]++;
    }
    
    // prints out key with its frequency
//  for (map<int,int>::const_iterator it = modes.begin(); it!=modes.end(); ++it)
//      cout << it->first << " " << it->second << endl;
    
    int maxVal = max(modes);
    
    if (maxVal > 1){
        for (map<int, int>::iterator it = modes.begin();
             it != modes.end(); ++it) {
            if (it->second == maxVal) {
                out.append(it->first);
            }
        }
    }
    //return out;
}