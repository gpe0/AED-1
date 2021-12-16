//
// Created by guilh on 12/16/2021.
//

#ifndef AED_1_TRANSITSTOP_H
#define AED_1_TRANSITSTOP_H
#include "Location.h"
#include "Schedule.h"
#include "Date.h"

#include <utility>
#include <vector>
#include <string>

class TransitStop {
private:
    Location& location;
    std::vector<Schedule&> schedules;
    std::string transportType;
    std::string name;
public:
    TransitStop(std::string name, std::string transportType, Location &location);

    std::pair<Date*, Date*> getRangeScheduled();

    void resetSchedule();
    void addSchedule(Schedule& schedule);
    void appendSchedule(Schedule& schedule);

    class InvalidTransitStop {
    private:
        std::string msg;
    public:
        InvalidTransitStop(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };

};


#endif //AED_1_TRANSITSTOP_H
