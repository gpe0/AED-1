#include "TimeGeneralization.h"
#include <chrono>
#include <iostream>

using namespace std;

TimeGeneralization::TimeGeneralization(int left, int mid, int right) : LEFT(left), MID(mid), RIGHT(right) {
    validObject = true;
}

std::ostream& operator<<(std::ostream& os, TimeGeneralization& object) {
    if (!object.validObject)
        throw (runtime_error("Invalid Object"));
    os << object.LEFT << "/" << object.MID << "/" << object.RIGHT;
    return os;
}

bool operator<(TimeGeneralization &left, TimeGeneralization &right) {
    return left.LEFT < right.LEFT or (left.LEFT==right.LEFT and left.MID < right.MID)
        or (left.LEFT==right.LEFT and left.MID==right.MID and left.RIGHT < right.RIGHT);
}
