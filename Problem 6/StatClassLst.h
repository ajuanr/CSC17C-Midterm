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

class StatClass{
public:
    StatClass(LnkdLst<int>);
    
    void setMean(float mean) {this->mean = mean;}
    void setMedian(float median) {this->median = median;}
    void setMode(LnkdLst<int> mode) {this->mode = mode;}
    void print();
private:
    float mean;
    float median;
    LnkdLst<int> mode;
    LnkdLst<int> data;
};


#endif /* StatClass_h */
