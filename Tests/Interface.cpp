#include <fstream>
#include <list>
#include <iostream>
#include "Interface.h"
#include "Flight.h"
#include "Plane.h"
#include "Date.h"
#include "Person.h"
#include "Worker.h"
#include "Passenger.h"
#include "Duration.h"
#include "Interface.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

using namespace std;

void Interface::readFlights(string file, list<Flight> &flights) {

    file = "../files/input/" + file;
    ifstream f(file);
    string line, w;

    getline(f, line);
    if (f.is_open()) {
        while (getline(f, line)) {
            stringstream s(line);
            stringstream aux;

            getline(s, w, ';'); //flight num

            aux.clear();
            aux.str(w);

            int fNum;

            aux >> fNum;

            getline(s, w, ';'); //date

            aux.clear();
            aux.str(w);

            int day, month, year;
            char bar;

            aux >> day >> bar >> month >> bar >> year;

            Date* date = new Date(day, month, year);

            getline(s, w, ';'); //duration

            aux.clear();
            aux.str(w);

            double durationD;

            aux >> durationD;

            int secs = durationD * 3600; //warning
            int min = secs / 60;
            secs = secs % 60;
            int hour = min / 60;
            min = min % 60;

            Duration *duration = new Duration(hour, min, secs);

            getline(s, w, ';'); //origin

            string origin = w;

            getline(s, w, ';'); //destination

            string destination = w;

            flights.push_back(Flight(fNum, date, duration, origin, destination));
        }
    }

}

void Interface::displayMenu() {

    cout << "Airline Information Management" << endl;
    cout << "------------------------------------" << endl << endl;
    cout << "1 - Create a Plane" << endl;
    cout << "2 - Run Tests" << endl;
    cout << "3 - Debug" << endl;
    cout << "4 - Exit" << endl;
    cout << "------------------------------------" << endl;
    cout << "Option: " << flush;
}

void Interface::readPlanes(string file, list<Plane>& planes, string flights) {

    file = "../files/input/" + file;

    ifstream f(file);
    string line, w;

    getline(f, line);
    if (f.is_open()) {
        while (getline(f, line)) {
            stringstream s(line);
            stringstream aux;

            getline(s, w, ';'); //license Plate

            string licensePlate = w;

            getline(s, w, ';'); //type

            string type = w;

            getline(s, w, ';'); //capacity

            aux.clear();
            aux.str(w);

            int capacity;

            aux >> capacity;


            list<Flight> flightsL;

            readFlights(flights, flightsL);

            planes.push_back(Plane(licensePlate, type, capacity, flightsL));

        }
    }
}

int Interface::menu(int argc, char* argv[]) {
    int option = 0;
    string input;
    stringstream s;

    while (option != 4) {
        displayMenu();

        cin >> input;

        s.clear();
        s.str(input);

        s >> option;

        while (option < 1 || option > 4) {

            cout << "Wrong Input, try again: " << flush;

            cin >> input;

            s.clear();
            s.str(input);

            s >> option;
        }

        if (option == 1) {
            //
        } else if (option == 2) {
            testing::InitGoogleTest(&argc, argv);
            return RUN_ALL_TESTS();
        } else if (option == 3) {

            list<Plane> planes;

            Interface::readPlanes("planes.csv", planes, "flights.csv");

            for (const auto & ele : planes) {
                cout << ele.getLicensePlate() << endl;
                cout << ele.getType() << endl;
            }
        }
    }
    return 0;
}