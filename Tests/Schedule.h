#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <utility>
#include <vector>
#include <string>
#include "Date.h"
#include "Duration.h"

class Schedule {
private:

    Date& date;
    std::vector< std::pair<Duration*, std::string> > entries;
public:
    Schedule(Date& date);
    void addEntry(Duration* time, std::string event);
    void removeEntry(Duration &timeBegin, Duration &timeEnd);
    void removeEntry(std::string event);
    std::vector<std::pair<Duration*, std::string>> getEntries(std::string event);
    std::vector<std::pair<Duration*, std::string>> getEntries(Duration &timeBegin, Duration& timeEnd);
    Date& getDate();
    std::vector< std::pair<Duration*, std::string> > getAllEntries();
};


#endif
