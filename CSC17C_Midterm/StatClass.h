//
//  StatClass.h
//  Problem3
//
//  Created by Juan on 10/31/15.
//
//  StatClass is a class to hold the mean media and mode
//  as calculated as part of Problem 3 for the CSC-17C midterm

#ifndef StatClass_h
#define StatClass_h

#include "SimpleVector.h"

class StatClass{
public:
    StatClass();
    
    void setMean(float mean) {this->mean = mean;}
    void setMedian(float median) {this->median = median;}
    void setMode(SimpleVector<int> mode) {this->mode = mode;}
    void print() const;
private:
    float mean;
    float median;
    SimpleVector<int> mode;
};

// initial mean and median with the values of zero
// default constructor for SimpleVector will be used for initialzization
StatClass::StatClass(): mean(0), median(0) {};
void StatClass::print() const {
    if (mean==0) {
        cout << "No data was input" << endl;
    }
    else {
        cout << "Mean: " << mean << endl
        << "Median: " << median << endl
        << "Mode: ";
        if (mode.empty()) {
            cout << " { 0 }" << endl;
        }
        else {
            cout << "{ ";
            for (SimpleVector<int>::const_iterator it= mode.begin();
                 it != mode.end(); ++it) {
                cout << *it << " ";
            }
            cout << "}\n";
        }
    }
}

#endif /* StatClass_h */
