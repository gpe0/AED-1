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

    /**Initializes a Schedule with a date
     *
     * @param date date
     */
    Schedule(Date& date);

    /**Adds an entry to the schedule
     *
     * @param time duration of the entry
     * @param event event name of the entry
     */
    void addEntry(Duration* time, std::string event);

    /**Removes every entry beetween the two times
     *
     * @param timeBegin time begin
     * @param timeEnd time end
     */
    void removeEntry(Duration &timeBegin, Duration &timeEnd);

    /**Removes every entry with a given event name
     *
     * @param event event name
     */
    void removeEntry(std::string event);

    /**Returns every entry with the given event name
     *
     * @param event event name
     * @return entries
     */
    std::vector<std::pair<Duration*, std::string>> getEntries(std::string event);

    /**Returns every entry beetween the two given times
     *
     * @param timeBegin time begin
     * @param timeEnd time end
     * @return entries
     */
    std::vector<std::pair<Duration*, std::string>> getEntries(Duration &timeBegin, Duration& timeEnd);

    /**Returns schedule's date
     *
     * @return date
     */
    Date& getDate();

    /**Returns every entry
     *
     * @return entries
     */
    std::vector< std::pair<Duration*, std::string> > getAllEntries();
};


#endif
