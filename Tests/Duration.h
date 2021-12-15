#ifndef DURATION_H
#define DURATION_H


#include "ConstTimeGen.h"

class Duration : public ConstTimeGen {
public:
    Duration(int hours, int min, int secs);
    int getHours();
    int getMin();
    int getSecs();
    Duration operator+(Duration const &right) const;
};


#endif
