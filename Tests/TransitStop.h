#ifndef TRANSITSTOP_H
#define TRANSITSTOP_H
#include "Location.h"
#include "Schedule.h"
#include "Date.h"

#include <utility>
#include <vector>
#include <string>

class TransitStop {
protected:
    Location* location;
    std::vector<Schedule*> schedules;
    std::string transportType;
    std::string name;
public:
    TransitStop();
    TransitStop(std::string name, std::string transportType, Location* location);

    std::pair<Date*, Date*> getRangeScheduled();
    std::string getTransportType();

    void resetSchedule();
    void addSchedule(Schedule& schedule);
    void appendSchedule(Schedule& schedule);

    bool operator<(const TransitStop& right) const;

    class InvalidTransitStop {
    private:
        std::string msg;
    public:
        InvalidTransitStop(std::string msg) {this->msg = msg;};
        std::string what() const {return msg;};
    };

};


#endif
