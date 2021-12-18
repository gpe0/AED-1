#ifndef TRANSITSTOP_H
#define TRANSITSTOP_H
#include "Location.h"
#include "Schedule.h"
#include "Date.h"

#include <utility>
#include <vector>
#include <string>

class TransitStop {
private:
    TransitStop* airport;
protected:
    Location* location;
    std::vector<Schedule*> schedules;
    std::string transportType;
    std::string name;
public:
    /**Initializes a transit stop with no name, no type and a empty location
     *
     */
    TransitStop();

    /**Initializes a transit stop with a name, a transport type and a location
     *
     * @param name name
     * @param transportType type
     * @param location location
     */
    TransitStop(std::string name, std::string transportType, Location* location);

    /**Returns a pair of dates (the first is the oldest, and the second is the newest)
     *
     * @return pair of dates
     */
    std::pair<Date*, Date*> getRangeScheduled();

    /**Returns the transit stop's type
     *
     * @return type
     */
    std::string getTransportType();

    /**Returns the transit stop's name
     *
     * @return name
     */
    std::string getName();

    /**Returns the transit stop's location
     *
     * @return location
     */
    Location* getLocation();

    /**Resets the schedule
     *
     */
    void resetSchedule();

    /**Adds a schedule to the schedules (in the right position)
     *
     * @param schedule schedule
     */
    void addSchedule(Schedule& schedule);

    /**Adds a schedule to the end of schedules
     *
     * @param schedule schedule
     */
    void appendSchedule(Schedule& schedule);

    /**Sets an airport pointer (to be used in comparisons)
     *
     * @param airport airport
     */
    void setAirport(TransitStop* airport);

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
