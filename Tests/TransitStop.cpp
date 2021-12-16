#include "TransitStop.h"
using namespace std;
TransitStop::TransitStop(std::string name, std::string transportType, Location &location)
: location(location) {
    this->name = name;
    this->transportType = transportType;
}

void TransitStop::resetSchedule() {
    schedules.clear();
}

void TransitStop::appendSchedule(Schedule &schedule) {
    if(schedules[-1].getDate() < schedule.getDate()){
        throw InvalidTransitStop("the schedule can't be appended without jeopardizing sorting");
    }
    schedules.push_back(schedule);
}

std::pair<Date *, Date *> TransitStop::getRangeScheduled() {
    pair<Date*, Date*> result;
    result.first = &(schedules[0].getDate());
    result.second = &(schedules[-1].getDate());
    return std::pair<Date *, Date *>();
}

void TransitStop::addSchedule(Schedule &schedule) {
    auto it = schedules.begin();
    for(it; it != schedules.end(); it++) {
        if (((*it).getDate()) < schedule.getDate()) continue;
        else break;
    }
    schedules.insert(--it,schedule);
}
