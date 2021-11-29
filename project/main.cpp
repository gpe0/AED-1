#include <iostream>
#include <list>
#include "Flight.h"
#include "Plane.h"
#include "Date.h"
#include "Person.h"
#include "Worker.h"
#include "Passenger.h"


using namespace std;

int main() {

    Date d1(10, 11, 2021);
    Date d2(11, 11, 2021);
    Date d3;

    Flight f1(1, d1, 1.5, "Porto", "Madrid");
    Flight f2(2, d2, 2, "Lisboa", "Madrid");
    Flight f3(3, d3, 3.5, "Madrid", "Amesterdão");

    Passenger p1("Goncalo", 19, 'M');

    list<Flight> flights;

    flights.push_back(f1);
    flights.push_back(f2);
    flights.push_back(f3);


    Plane plane("A101", 300, flights);


    cout << p1.acquireTicket(1, plane, false) << endl;

    cout << plane.getLicensePlate() << endl << endl;



    for (Flight x: plane.getFlights()) {
        cout << x.getAvailableSeats() << endl;
    }


    return 0;
}
