#include "Schedule.h"
using namespace std;

Schedule::Schedule(Date &date) : date(date){}

void Schedule::addEntry(Duration *time, std::string event) {

   auto it = entries.begin();
    for(it; it != entries.end(); it++) {
        if ((*(*it).first) < *time) continue;
        else break;
    }
    pair<Duration*, string> entry(time, event);

    entries.insert(--it, entry);

}

void Schedule::removeEntry(Duration &timeBegin, Duration &timeEnd) {
    for (auto it = entries.begin(); it != entries.end(); it++){
        if (!((*(*it).first) < timeBegin) && (*(*it).first) < timeEnd) {
            it = entries.erase(it);
            it--;
        }
    }
}

void Schedule::removeEntry(std::string event) {
    for (auto it = entries.begin(); it != entries.end(); it++) {
        if ((*it).second == event) {
            entries.erase(it);
            it--;
        }
    }
}

std::vector<std::pair<Duration *, std::string>> Schedule::getEntries(std::string event) {
    vector<pair<Duration *, string>> result;
    for (auto it = entries.begin(); it != entries.end(); it++) {
        if ((*it).second == event) {
            result.push_back(*it);
        }
    }
    return result;
}

std::vector<std::pair<Duration *, std::string>> Schedule::getEntries(Duration &timeBegin, Duration &timeEnd) {
    vector<pair<Duration *, string>> result;
    for (auto it = entries.begin(); it != entries.end(); it++){
        if (!((*(*it).first) < timeBegin) && (*(*it).first) < timeEnd) {
            result.push_back(*it);
        }
    }
    return result;
}

std::vector<std::pair<Duration *, std::string> > Schedule::getAllEntries() {
    return entries;
}

Date &Schedule::getDate() {
    return date;
}

