#ifndef DURATION_H
#define DURATION_H


#include "TimeGeneralization.h"

class Duration : public TimeGeneralization {
public:
    Duration(int hours, int min, int secs);
    int getHours();
    int getMin();
    int getSecs();
    Duration operator+(Duration const &right);

    class InvalidDuration {
    private:
        std::string msg;
    public:
        InvalidDuration(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};


#endif
