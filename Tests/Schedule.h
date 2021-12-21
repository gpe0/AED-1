#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <vector>
#include <string>
#include "Date.h"
#include "Duration.h"

class Schedule {
public:
    struct Entry {
        Duration * duration;
        std::string event;
    };
private:

    Date& date;
    std::vector<Entry> entries;
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
     * @return true - remove success ; false - failed to remove (at least one)
     */
    bool removeEntry(Duration &timeBegin, Duration &timeEnd);

    /**Removes every entry with a given event name
     *
     * @param event event name
     * @return true - remove success ; false - failed to remove (at least one)
     */
    bool removeEntry(std::string event);

    /**Returns every entry with the given event name
     *
     * @param event event name
     * @return entries
     */
    std::vector<Entry> getEntries(std::string event);

    /**Returns every entry beetween the two given times
     *
     * @param timeBegin time begin
     * @param timeEnd time end
     * @return entries
     */
    std::vector<Entry> getEntries(Duration &timeBegin, Duration& timeEnd);

    /**Returns schedule's date
     *
     * @return date
     */
    Date& getDate();

    /**Returns every entry
     *
     * @return entries
     */
    std::vector<Entry> getAllEntries();
};


#endif
