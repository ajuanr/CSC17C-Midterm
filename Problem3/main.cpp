//
//  main.cpp
//  Problem3
//
//  Created by Juan on 10/30/15.
//  Copyright © 2015 Juan. All rights reserved.
//
//  CSC-17C Midterm, problem 3
//

#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <numeric>

// user libraries
#include "SimpleVector.h"

void fill(SimpleVector<int>&, int, int = 9);
void print(SimpleVector<int>&, int=100);
float median(const SimpleVector<int>&);
void mode(const SimpleVector<int>&);
int max(const map<int,int>);

int main(int argc, const char * argv[]) {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;
    SimpleVector<int> v;
    cout << v.empty() << endl;
    // number for random number generator
    cout << "What is the largest value to use: ";
    int mod;
    cin >> mod;
    
    // numbers to print per line
    cout << "How many numbers to print per line: ";
    int perLine;
    cin >> perLine;
    
    fill(v, size, mod);
    cout << v.size() << " " << v.empty() << endl;
    v.print();
//    cout << v.getElementAt(0) << endl;
  //  print(v, perLine);

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

//void fill(SimpleVector<int>& s) {
//    for (int i = 0; i != 10; ++i) {
//        s.push(rand() %10+1);
//    }
//}

//void print(SimpleVector<int> &s) {
//    for(SimpleVector<int>::const_iterator iter=s.begin();
//        iter != s.end(); ++iter) {
//        cout << *iter << " ";
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

void print(SimpleVector<int>& a, int p) {
    for (int i = 0; i != a.size()-1; ++i) {
        cout << i << endl;
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
    set<int> s(v.begin(), v.end());
    
    map<int, int> m;
    
    // add the keys to the map
    for(set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        m[*it];//.insert({*it, 0});
    }
    
    // add the values to the keys
    for (SimpleVector<int>::const_iterator it=v.begin(); it != v.end(); ++it) {
        ++m[*it];
    }
    
    int maxVal = max(m);
    
    // if max is 1, then no number is repeated
    if (maxVal==1) {
        cout << "Mode: {0}";
    }
    
    else {
        cout << "Mode: { ";
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            if (it->second == maxVal) {
                cout << it->first << " ";
            }
        }
        cout << "}\n";
    }
    cout << endl;
}
int max(const map<int,int> m) {
    int max = m.begin()->second;
    for (map<int, int>::const_iterator it= m.begin(); it!= m.end(); ++it) {
        if (it->second > max) {
            max = it->second;
        }
    }
    return max;
}