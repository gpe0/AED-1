#include <iostream>
#include <list>
#include "Flight.h"
#include "Plane.h"
#include "Date.h"
#include "Person.h"
#include "Worker.h"
#include "Passenger.h"
#include "Duration.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;

int main(int argc, char* argv[]) {

    testing::InitGoogleTest(&argc, argv);
    std::cout << "AED 2021/2022 - Projeto 1" << std::endl;
    return RUN_ALL_TESTS();

/*
    Duration du1(1, 30, 0);
    Duration du2(0, 30, 0);

    Duration du3 = du1 + du2;

    cout << du3.getHours() << endl;
    cout << du3.getMin() << endl;
    cout << du3.getSecs() << endl;

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
  */

    return 0;
}
