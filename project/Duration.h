//
// Created by guilh on 12/5/2021.
//

#ifndef PROJECT_DURATION_H
#define PROJECT_DURATION_H


#include "TimeGeneralization.h"

class Duration : public TimeGeneralization {
public:
    Duration(int hours, int min, int secs);
    int getHours();
    int getMin();
    int getSecs();
    friend Duration& operator+(const Duration &right);
};


#endif //PROJECT_DURATION_H
