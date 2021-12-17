#ifndef DATE_H
#define DATE_H

#include "ConstTimeGen.h"
#include <iostream>
#include <vector>

class Date : public ConstTimeGen {
public:

    /** Initializes the current date (testing not implemented yet)
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
     * @return validation
     */
    bool isValid() const;

    /**Returns date's day
     *
     * @return day
     */
    int getDay() const;

    /**Returns date's month
     *
     * @return month
     */
    int getMonth() const;

    /**Returns date's year
     *
     * @return year
     */
    int getYear() const;

    friend std::ostream& operator<<(std::ostream& os, Date& date);

    /**Returns the current date
     *
     * @return vector with day, month and year
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
