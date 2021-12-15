#include "ConstTimeGen.h"
#include <chrono>
#include <iostream>

using namespace std;

ConstTimeGen::ConstTimeGen(int left, int mid, int right) : LEFT(left), MID(mid), RIGHT(right) {
    validTime = true;
}

std::ostream& operator<<(std::ostream& os, ConstTimeGen& object) {
    if (!object.validTime)
        throw (ConstTimeGen::InvalidTime("Invalid Time"));
    os << object.LEFT << "/" << object.MID << "/" << object.RIGHT;
    return os;
}

bool operator<(ConstTimeGen &left, ConstTimeGen &right) {
    if (!left.validTime or !right.validTime)
        throw (ConstTimeGen::InvalidTime("Invalid Time"));
    return left.LEFT < right.LEFT or (left.LEFT==right.LEFT and left.MID < right.MID)
        or (left.LEFT==right.LEFT and left.MID==right.MID and left.RIGHT < right.RIGHT);
}

void ConstTimeGen::setInvalid() {
    validTime = false;
}
