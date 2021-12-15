//
// Created by guilh on 12/15/2021.
//

#include "Schedule.h"
using namespace std;
Schedule::Schedule(Date &date) : date(date){}


void Schedule::addEntry(Duration &time, std::string event) {
    int i = 0;

    for(i = 0; i<entries.size(); i++){
        if (entries.at(i).first < time)
            continue;
    }
    pair<Duration&, string> entry(time, event);
    //entries.insert(entries.begin() + i, entry);

}

void Schedule::removeEntry(Duration &timeBegin, Duration &timeEnd) {
    for(int i = 0; i<entries.size(); i++){
        if (!(entries.at(i).first < timeBegin) and entries.at(i).first < timeEnd){
            entries.erase(entries.begin() + i);
            i--;
        }
    }
}

void Schedule::removeEntry(std::string event) {
    for(int i = 0; i<entries.size(); i++){
        if (entries.at(i).second == event){
            entries.erase(entries.begin() + i);
            i--;
        }
    }
}
