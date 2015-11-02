//
//  main.cpp
//  Problem 6
//
//  Created by Juan on 10/31/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <numeric>

//#include "LnkdLst.hpp"
#include "StatClassLst.h"
#include "StatClass.h"

using namespace std;

//functios for problem1
SimpleVector<int>* top(SimpleVector<int>, int);

// functions for problem 3
void fill(SimpleVector<int>&, int, int = 9);
void printVec(SimpleVector<int>&, int=100);
float median(const SimpleVector<int>&);
SimpleVector<int> mode(const SimpleVector<int>&);
int max(const map<int, int>&);
StatClass *stat(SimpleVector<int>);

// functions for problem 6
void fill(LnkdLst<int>&, int, int = 9);
void printLst(LnkdLst<int>&, int=100);
float mean(LnkdLst<int>&);
float median(LnkdLst<int>&);
int maxLst(const map<int, int>&);
void mode(LnkdLst<int>&, LnkdLst<int>&);
StatClassL *stat(LnkdLst<int>);

// functions for problem 8
float rTan(float);

// functions for problem 9
float h(float);
float g(float);


// for menu
void Menu();
int getN();
void def(int);
void problem1(); // 15 points
void problem3(); // 25 points
void problem6(); // 25 points
void problem8(); // 15 points
void problem9(); // 25 points
         //  total: 105 points


int main(int argc, const char * argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();cout << endl;break;
            case 2:    problem3();cout << endl;break;
            case 3:    problem6();cout << endl;break;
            case 4:    problem8();cout << endl;break;
            case 5:    problem9();cout << endl;break;
            default:   def(inN);
        }
        
    } while(inN<6);
    return 0;
}

void Menu()
{
    cout<<"Type 1 for problem 1"<< "  -15 points" <<endl;
    cout<<"Type 2 for problem 3"<< "  -25 points" <<endl;
    cout<<"Type 3 for problem 6"<< "  -25 points" <<endl;
    cout<<"Type 4 for problem 8"<< "  -15 points" <<endl;
    cout<<"Type 5 for problem 9"<< "  -25 points" <<endl;
    cout<<"Type 6 to exit \n"<<endl;
    cout << "Total: 105 points\n";
}
int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN)
{
    cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void problem1() {
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
    
    cout << "Enter number of top elements to retrieve: ";
    int p;
    cin >> p;
    SimpleVector<int> t = *top(v, p);
    printVec(t);
}

void problem3() {
    cout << "Uses a SimpleVector to implement get mean, median and mode\n";
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
}

void problem6(){
    cout << "Uses a linked list to implement get mean, median and mode\n";
    cout << "Enter the size of the list: ";
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
    
    StatClassL *sc = stat(ll);
    sc->print();
}


void problem8() {
    cout << "Enter an angle: ";
    float angle;
    cin >> angle;
    cout << "angle is: " << angle << endl;
    cout <<  "rTan(x) =       " << rTan(angle) << endl;
    cout <<  "System tan(x) = " << tan(angle) << endl;
}

void problem9() {
    cout << "Enter an x value: ";
    float angle;
    cin >> angle;
    cout << "value is: " << angle << endl;
    
    cout << "h(x) = " << h(angle) << endl;
    cout << "g(x) = " << g(angle) << endl;
}

void fill(LnkdLst<int>& ll, int size, int mod) {
    // use current time as seed for random number generator
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

int maxLst(const map<int,int>& m) {
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
    
    int maxVal = maxLst(modes);
    
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

StatClassL *stat(LnkdLst<int> x) {
    StatClassL *sc = new StatClassL();
    LnkdLst<int> l;
    if (!x.empty()) {
        sc->setMean(mean(x));
        sc->setMedian(median(x));
        mode(x,l);
        sc->setMode(l);
    }
    else
        cout << "No data was input\n";
    
    return sc;
}
//////////
void fill(SimpleVector<int>& a, int size, int mod) {
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
    StatClass *sc = new StatClass();
    if (!x.empty()) {
        sc->setMean(accumulate(x.begin(), x.end(), 0.0) / x.size());
        sc->setMedian(median(x));
        sc->setMode(mode(x));
    }
    else
        cout << "No data was input\n";
    
    return sc;
}

float rTan(float angle) {
    float tol = 1e-2;
    if (angle>-tol && angle<tol)
        return angle + angle*angle*angle/3;
    return (2*rTan(angle/2))/(1-(rTan(angle/2)*rTan(angle/2)));
}


float h(float x) {
    float tol = 1e-2;
    if (x>-tol && x<tol)
        return x+x*x*x/6;
    return 2*h(x/2)*g(x/2);
}

float g(float x) {
    float tol = 1e-6;
    if (x>-tol && x<tol) {
        return 1 + x*x/2;
    }
    return 1+2*h(x/2)*h(x/2);
}

SimpleVector<int>* top(SimpleVector<int> in, int p) {
        SimpleVector<int> *out = new SimpleVector<int>;
    if (p>in.size()) {
        cout << "Not enough elements to return";
        return out;
    }
    sort(in.begin(), in.end());
    //in.print();
    for(int i = 0; i != p; ++i) {
        out->push_back(in[in.size()-1-i]);
    }
    
    return out;
}