#include "TransitStop.h"

using namespace std;

TransitStop::TransitStop(std::string name, std::string transportType, Location* location)
: location(location) {
    this->name = name;
    this->transportType = transportType;
}

void TransitStop::resetSchedule() {
    schedules.clear();
}

void TransitStop::appendSchedule(Schedule &schedule) {
   if((*schedules[schedules.size()-1]).getDate() < schedule.getDate()){
        throw InvalidTransitStop("the schedule can't be appended without jeopardizing sorting");
    }
    schedules.push_back(&schedule);
}

std::pair<Date *, Date *> TransitStop::getRangeScheduled() {
    pair<Date*, Date*> result;
    result.first = &((*schedules[0]).getDate());
    result.second = &((*schedules[schedules.size()-1]).getDate());
    return std::pair<Date *, Date *>();
}

void TransitStop::addSchedule(Schedule &schedule) {
    auto it = schedules.begin();
    for(it; it != schedules.end(); it++) {
        if (((*(*it)).getDate()) < schedule.getDate()) continue;
        else break;
    }
    schedules.insert(--it,&schedule);
}

std::string TransitStop::getTransportType() {
    return transportType;
}

void TransitStop::setAirport(TransitStop *airport) {
   this->airport = airport;
}

TransitStop::TransitStop() {
    location = new Location(0, 0);
    name = "";
    transportType = "";
}

bool TransitStop::operator<(const TransitStop &right) const {
    return location->getDistanceToLoc(*(airport->location)) < right.location->getDistanceToLoc(*(airport->location));
}

std::string TransitStop::getName() {
    return name;
}

Location* TransitStop::getLocation() {
    return location;
}
