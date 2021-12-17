#ifndef DURATION_H
#define DURATION_H


#include "ConstTimeGen.h"

class Duration : public ConstTimeGen {
public:

    /**Initializes a duration with given hours, minutes and seconds
     *
     * @param hours hours
     * @param min minutes
     * @param secs seconds
     */
    Duration(int hours, int min, int secs);

    /**Returns duration's hours
     *
     * @return hours
     */
    int getHours();

    /**Returns duration's minutes
     *
     * @return minutes
     */
    int getMin();

    /**Returns duration's seconds
     *
     * @return seconds
     */
    int getSecs();

    Duration operator+(Duration const &right) const;
};


#endif
