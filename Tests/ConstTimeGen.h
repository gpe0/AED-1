#ifndef CONSTTIMEGEN_H
#define CONSTTIMEGEN_H


#include <iostream>
#include <vector>

class ConstTimeGen {
protected:
    const int LEFT;
    const int MID;
    const int RIGHT;
    bool validTime;

public:
    /** Initializes a generic time measurement (LEFT:MID:RIGHT)
     *
     * @param LEFT leftmost camp of the time indication (LEFT:M:R)
     * @param MID middle camp of the time indication (L:MID:R)
     * @param RIGHT rightmost camp of the time indication (L:M:RIGHT)
     */
    ConstTimeGen(int left, int mid, int right);

    bool setInvalid();

    friend std::ostream& operator<<(std::ostream& os, ConstTimeGen& object);

    friend bool operator<(ConstTimeGen& left, ConstTimeGen& right);

    class InvalidTime {
    private:
        std::string msg;
    public:
        InvalidTime(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };
};


#endif
