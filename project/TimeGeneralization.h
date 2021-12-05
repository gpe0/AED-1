#ifndef PROJECT_TIMEGENERALIZATION_H
#define PROJECT_TIMEGENERALIZATION_H


#include <iostream>
#include <vector>

class TimeGeneralization {
protected:
    const int LEFT;
    const int MID;
    const int RIGHT;
    bool validObject;

public:
    /** Initializes a generic time measurement (LEFT:MID:RIGHT)
     *
     * @param LEFT leftmost camp of the time indication (LEFT:M:R)
     * @param MID middle camp of the time indication (L:MID:R)
     * @param RIGHT rightmost camp of the time indication (L:M:RIGHT)
     */
    TimeGeneralization(int left, int mid, int right);

    friend std::ostream& operator<<(std::ostream& os, TimeGeneralization& object);

    friend bool operator<(TimeGeneralization& left, TimeGeneralization& right);
};


#endif //PROJECT_TIMEGENERALIZATION_H
