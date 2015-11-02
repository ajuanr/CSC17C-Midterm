//
//  SelfOrganizingList.h
//  Problem7
//
//  Created by Juan on 10/31/15.
//  Copyright © 2015 Juan. All rights reserved.
//

#ifndef SelfOrganizingList_h
#define SelfOrganizingList_h

#include "LnkdLst.hpp"

template<class T>
class SelfOrganizingList: public LnkdLst<T> {
public:
    SelfOrganizingList():LnkdLst<T>(){}
    bool inList(T val);
private:
};

template<class T>
bool SelfOrganizingList<T>::inList(T val) {
    for (int i = 0; i != LnkdLst<T>::getSize(); ++i) {
        // if found at first element, leave it there
        if (LnkdLst<T>::get(i) == val && i != 0) {
            // delete
            LnkdLst<T>::extract(i+1);
            LnkdLst<T>::prepend(val);
            return true;
        }
    }
    return false;
}


#endif /* SelfOrganizingList_h */
