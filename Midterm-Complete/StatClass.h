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


#endif /* StatClass_h */
