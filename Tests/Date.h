#ifndef DATE_H
#define DATE_H

#include "ConstTimeGen.h"
#include <iostream>
#include <vector>

class Date : public ConstTimeGen {
public:

    /** Initializes the current date
     *
     */
    Date();

    /** Initializes a specified date (validation and testing not implemented yet)
     * There is a possibility of building another construction with strings for months for convenience
     *
     * @param day specified day (must be 1 or higher and 31/30/29/28 or lower, depending on month and year)
     * @param month specified month (between 1 and 12)
     * @param year specified year (no restrictions applied)
     */
    Date(int day, int month, int year);

    /**Returns if date is valid or not
     *
     * @return validTime
     */
    bool isValid() const;

    /**Returns date's day
     *
     * @return LEFT
     */
    int getDay() const;

    /**Returns date's month
     *
     * @return MID
     */
    int getMonth() const;

    /**Returns date's year
     *
     * @return RIGHT
     */
    int getYear() const;

    friend std::ostream& operator<<(std::ostream& os, Date& date);

    /**Returns the current date
     *
     * @return vector with LEFT, MID and RIGHT
     */
    static std::vector<int> getCurrentDate();

    /**Checks if a given year is a leap year
     *
     * @param year year
     * @return true - it is leap year ; false - it isn't leap year
     */
    static bool isLeapYear(int year);


};


#endif
