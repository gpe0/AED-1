//
// Created by guilh on 12/5/2021.
//

#include "Duration.h"

using namespace std;

Duration::Duration(int hours, int min, int secs) : TimeGeneralization(hours, min, secs) {
    validObject = !(hours < 0 or min < 0 or secs < 0 or min > 60 or secs > 60);
}

int Duration::getHours() {
    if (!validObject)
        throw (runtime_error("Invalid Object"));
    return LEFT;
}

int Duration::getMin() {
    if (!validObject)
        throw (runtime_error("Invalid Object"));
    return MID;
}

int Duration::getSecs() {
    if (!validObject)
        throw (runtime_error("Invalid Object"));
    return RIGHT;
}

Duration Duration::operator+(Duration const &right) {
    if (!(validObject and right.validObject))
        throw (runtime_error("Invalid Object"));
    int seconds, minutes=0, hours=0;
    seconds = RIGHT + right.RIGHT;
    while (seconds >= 60){
        seconds -= 60;
        minutes++;
    }
    minutes += MID + right.MID;
    while (minutes >= 60){
        minutes -= 60;
        hours++;
    }
    hours += LEFT + right.LEFT;

    Duration duration(hours, minutes, seconds);
    return duration;
}
