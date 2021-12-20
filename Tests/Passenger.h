#ifndef PASSENGER_H
#define PASSENGER_H

#include <vector>
#include "Person.h"
#include "Flight.h"
#include "Plane.h"
#include "Luggage.h"

class Passenger : public Person {
private:
    std::vector<Luggage*> luggage;


public:
    /** Initializes a passenger (who is a person)
     * (validation and testing not implemented yet)
     *
     * @param name passenger name
     * @param age  passenger age
     * @param sex  passenger sex ('M', 'F' or 'U')
     */
    Passenger(std::string name, int age, char sex) : Person(name, age, sex) {};

    /** Tries to aquire a ticket to a certain flight
     *
     * @param flightNum flight number
     * @param plane plane with the certain flight
     * @param tickets number of tickets to be bought (default is one)
     * @return true - if it succeed ; false - if it don't
     */
     bool acquireTicket(int flightNum, Plane& plane, bool hasLuggage, int tickets = 1);

     /**Returns the passenger's luggage
      *
      * @return luggage
      */
     std::vector<Luggage*> getLuggage();

     /**Adds a luggage to the list of luggages of the passenger
      *
      * @param l luggage
      */
     void addLuggage(Luggage* l);

     /**Tries to remove a specific luggage from the passenger's luggages list
      *
      * @param l luggage
      * @return true - if it removed ; false - if it didn't remove
      */
     bool removeLuggage(Luggage* l);

     /**Tries to find the luggage with the given ID
      *
      * @param id ID
      * @return luggage found (if not found, is created an invalid luggage (negatives values))
      */
     Luggage * findLuggageWithId(int id);

     /**Frees the memory allocated to the passenger's luggage
      *
      */
    ~Passenger();

};


#endif
