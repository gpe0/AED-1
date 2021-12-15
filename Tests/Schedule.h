//
// Created by guilh on 12/15/2021.
//

#ifndef AED_1_SCHEDULE_H
#define AED_1_SCHEDULE_H

#include "Date.h"
#include "Duration.h"
#include <utility>
#include <vector>
#include <string>

class Schedule {
private:
    Date& date;
    std::vector<std::pair<Duration&, std::string>> entries;
public:
    Schedule(Date& date);
    void addEntry(Duration& time, std::string event);
    void removeEntry(Duration& timeBegin, Duration& timeEnd);
    void removeEntry(std::string event);
};


#endif //AED_1_SCHEDULE_H
