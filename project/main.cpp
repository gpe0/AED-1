#include <iostream>
#include <list>
#include "Flight.h"
#include "Plane.h"
#include "Date.h"
#include "Person.h"
#include "Worker.h"


using namespace std;

int main() {

    Date d1(10, 11, 2021);
    Date d2(11, 11, 2021);
    Date d3;

    Flight f1(1, d1, 1.5, "Porto", "Madrid");
    Flight f2(2, d2, 2, "Lisboa", "Madrid");
    Flight f3(3, d3, 3.5, "Madrid", "Amesterdão");

    list<Flight> flights;

    flights.push_back(f1);
    flights.push_back(f2);
    flights.push_back(f3);

    Plane plane("A101", 300, flights);

    cout << plane.getLicensePlate() << endl;

    for (Flight x: plane.getFlights()) {
        cout << x.getOrigin() << endl;
    }

    cout << plane.getServices().empty() << endl;


    return 0;
}
