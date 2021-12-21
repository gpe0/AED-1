#include "Schedule.h"
using namespace std;

Schedule::Schedule(Date &date) : date(date){}

void Schedule::addEntry(Duration *time, std::string event) {

   auto it = entries.begin();
    for(it; it != entries.end(); it++) {
        if (*time < (*(*it).duration)) break;
    }
    Entry entry{time, event};

    if (entries.empty()) entries.insert(it, entry);
    else entries.insert(--it, entry);

}

bool Schedule::removeEntry(Duration &timeBegin, Duration &timeEnd) {
    bool removed = false;
    for (auto it = entries.begin(); it != entries.end(); it++){
        if (!((*(*it).duration) < timeBegin) && (*(*it).duration) < timeEnd) {
            it = entries.erase(it);
            it--;
            removed = true;
        }
    }
    return removed;
}

bool Schedule::removeEntry(std::string event) {
    bool removed = false;
    for (auto it = entries.begin(); it != entries.end(); it++) {
        if ((*it).event == event) {
            entries.erase(it);
            it--;
            removed = true;
        }
    }
    return removed;
}

std::vector<Schedule::Entry> Schedule::getEntries(std::string event) {
    vector<Entry> result;
    for (auto it = entries.begin(); it != entries.end(); it++) {
        if ((*it).event == event) {
            result.push_back(*it);
        }
    }
    return result;
}

std::vector<Schedule::Entry> Schedule::getEntries(Duration &timeBegin, Duration &timeEnd) {
    vector<Entry> result;
    for (auto it = entries.begin(); it != entries.end(); it++){
        if (!((*(*it).duration) < timeBegin) && (*(*it).duration) < timeEnd) {
            result.push_back(*it);
        }
    }
    return result;
}

std::vector<Schedule::Entry> Schedule::getAllEntries() {
    return entries;
}

Date &Schedule::getDate() {
    return date;
}

