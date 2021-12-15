#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
#include "Date.h"
#include "Duration.h"

class Flight {
private:
    int num;
    int availableSeats;
    Date *date;
    Duration *duration;
    std::string origin;
    std::string destination;

public:
    /** Initializes a flight (the number of seats will start at '-1' and then be altered to
     * the capacity of the plane the flight is attributed to)
     * @param num flight number
     * @param date flight date
     * @param duration flight duration in hours
     * @param origin flight origin
     * @param destination flight destination
     */
    Flight(int num, Date date, Duration duration, std::string origin, std::string destination);

    /** Returns the flight number
     *
     * @return flight number
     */
    int getNum() const;

    /** Returns the number os still available seats
     *
     * @return available seats
     */
    int getAvailableSeats() const;

    /** Returns the flight date
     *
     * @return flight date
     */
    Date getDate() const;

    /** Returns the flight duration (using Duration Class)
     *
     * @return flight duration
     */
    Duration getDuration() const;

    /** Returns the flight origin
     *
     * @return flight origin
     */
    std::string getOrigin() const;

    /** Returns the flight destination
     *
     * @return flight destination
     */
    std::string getDestination() const;

    /** Sets a flight number
     *
     * @param num flight number
     */
    void setNum(int num);

    /** Sets the number of available seats
     * Possibility of implementing num++
     *
     * @param avaibleSeat number of available seats
     */
    void setAvailableSeats(int availableSeats);

    /** Sets a flight date
     *
     * @param date flight date
     */
    void setDate(Date date);

    /** Sets a flight duration
     *
     * @param duration flight duration
     */
    void setDuration(Duration duration);

    /** Sets a flight origin
    *
    * @param origin flight origin
    */
    void setOrigin(std::string origin);

    /** Sets a flight destination
     *
     * @param destination flight destination
     */
    void setDestination(std::string destination);
};


#endif
