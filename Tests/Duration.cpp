#include "Duration.h"

using namespace std;

Duration::Duration(int hours, int min, int secs) : ConstTimeGen(hours, min, secs) {
    validTime = !(hours < 0 or min < 0 or secs < 0 or min > 60 or secs > 60);
}

int Duration::getHours() {
    if (!validTime)
        throw InvalidTime("Invalid Duration");
    return LEFT;
}

int Duration::getMin() {
    if (!validTime)
        throw InvalidTime("Invalid Duration");
    return MID;
}

int Duration::getSecs() {
    if (!validTime)
        throw InvalidTime("Invalid Duration");
    return RIGHT;
}

Duration Duration::operator+(Duration const &right) {
    if (!(validTime and right.validTime))
        throw InvalidTime("Invalid Duration");
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
