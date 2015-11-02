//
//  StatClass.h
//  Problem3
//
//  Created by Juan on 10/31/15.
//
//  StatClass is a class to hold the mean media and mode
//  as calculated as part of Problem 3 for the CSC-17C midterm

#ifndef StatClassLst_h
#define StatClassLst_h

#include "LnkdLst.hpp"

class StatClassL{
public:
    StatClassL();
    
    void setMean(float mean) {this->mean = mean;}
    void setMedian(float median) {this->median = median;}
    void setMode(LnkdLst<int> mode) {this->mode = mode;}
    void print();
private:
    float mean;
    float median;
    LnkdLst<int> mode;
};

// initial mean and median with the values of zero
// default constructor for LnkdLst will be used for initialzization
StatClassL::StatClassL(): mean(0), median(0){}

void StatClassL::print() {
    if (mean==0) {
        cout << "No data was input" << endl;
    }
    else {
        cout << "Mean: " << mean << endl
        << "Median: " << median << endl
        << "Mode: ";
        if (mode.getSize()==0) {
            cout << " { 0 }" << endl;
        }
        else {
            cout << "{ ";
            for (int i = 0; i != mode.getSize(); ++i) {
                cout << mode.get(i) << " ";
            }
            cout << "}\n";
        }
    }
}

#endif /* StatClass_h */
