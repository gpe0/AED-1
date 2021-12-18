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
    cout << "1 - Simulate" << endl;
    cout << "2 - Run Tests" << endl;
    cout << "3 - Demo" << endl;
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
            bool hasPlanes = false, hasFlights = false, hasPassengers = false, hasLuggages = false;

            int n;
            list<Plane> planes;

            cout << "Planes to be created: " << flush;

            cin >> n;

            for (int i = 1; i <= n; i++) {
                hasPlanes = true;
                string licenseP, type;
                int capacity;
                cout << "Plane " << i << endl;
                cout << "License Plate: " << flush;

                cin >> licenseP;

                cout << "Type: " << flush;

                cin >> type;

                cout << "capacity: " << flush;

                cin >> capacity;

                planes.push_back(Plane(licenseP, type, capacity));

                cout << "Plane added!" << endl << endl;
            }

            for (auto it = planes.begin(); it != planes.end(); it++) {
                cout << "Flights to be assigned to the plane (" << (*it).getLicensePlate() << "): " << flush;

                cin >> n;

                for (int i = 1; i <= n; i++) {
                    hasFlights = true;
                    cout << "Flight " << i << endl;

                    int num;

                    cout << "Flight number: " << flush;

                    cin >> num;

                    int day, month, year;
                    char op;
                    cout << "Date (DD/MM/YYYY): " << flush;

                    cin >> day >> op >> month >> op >> year;

                    Date* da = new Date(day, month, year);

                    int hours, mins, secs;
                    cout << "Duration (HH:MM:SS): " << flush;

                    cin >> hours >> op >> mins >> op >> secs;

                    Duration* du = new Duration(hours, mins, secs);

                    string origin, destination;
                    cout << "Origin: " << flush;

                    cin >> origin;

                    cout << "Destination: " << flush;

                    cin >> destination;
                    Flight f(num, da, du, origin, destination);
                    (*it).addFlight(f, (*it).getCapacity());

                    cout << "Flight added!" << endl << endl;
                }

                cout << "Services to be assigned to the plane (" << (*it).getLicensePlate() << "): " << flush;

                cin >> n;

                for (int i = 1; i <= n; i++) {

                    cout << "Service " << i << endl;

                    string type;

                    cout << "Type: " << flush;

                    cin >> type;

                    int day, month, year;
                    char op;
                    cout << "Date (DD/MM/YYYY): " << flush;

                    cin >> day >> op >> month >> op >> year;

                    Date* da = new Date(day, month, year);

                    string name;
                    char sex;
                    int age;

                    cout << "Worker's name: " << flush;

                    cin >> name;

                    cout << "Worker's age: " << flush;

                    cin >> age;

                    cout << "Worker's sex: " << flush;

                    cin >> sex;

                    Worker w(name, age, sex);

                    (*it).addService(Service(type, da, w));

                    cout << "Service added!" << endl << endl;
                }

            }

            list<Passenger> passengers;

            cout << "Number of tickets to be bought: " << flush;

            cin >> n;

            for (int i = 1; i <= n; i++) {
                hasPassengers = true;
                cout << "Passenger " << i << endl;

                string name;
                char sex;
                int age;

                cout << "Passenger's name: " << flush;

                cin >> name;

                cout << "Passenger's age: " << flush;

                cin >> age;

                cout << "Passenger's sex: " << flush;

                cin >> sex;

                passengers.push_back(Passenger(name, age, sex));

                cout << "Passenger added!" << endl << endl;
            }

            for (auto it = passengers.begin(); it != passengers.end(); it++) {
                cout << "Luggages to be assigned to the passager named " << (*it).getName() <<": " << flush;

                cin >> n;

                for (int i = 1; i <= n; i++) {

                    hasLuggages = true;

                    double width, height, weight;

                    cout << "Luggage's width: " << flush;

                    cin >> width;

                    cout << "Luggage's height: " << flush;

                    cin >> height;

                    cout << "Luggage's weight: " << flush;

                    cin >> weight;

                    Luggage* l = new Luggage(width, height, weight);

                    (*it).addLuggage(l);
                }
            }

            if (hasPassengers && hasFlights && hasPlanes) {
                cout << "Flight Number the group will get aboard\nAvailable" << endl;
                for (auto plane : planes) {
                    for (auto flight : plane.getFlights()) {
                        cout << flight.getNum() << " (" << flight.getOrigin() << " - " << flight.getDestination() << ")" << endl;
                    }
                }
                int num;
                cout << "Option: " << flush;
                cin >> num;
                int count = 0;

                for (auto plane : planes) {
                    for (auto flight : plane.getFlights()) {
                        if (flight.getNum() == num) {
                            count++;
                            break;
                        }

                    }
                }

                if (count == 0) {
                    cout << "Invalid Flight Number. Ending simulation" << endl;
                    break;
                }

                cout << "Plane's license plate that has the given flight\nAvailable" << endl;

                for (auto plane : planes) {
                    for (auto flight : plane.getFlights()) {
                        if (flight.getNum() == num) {
                            cout << "Plane (" << plane.getLicensePlate() << ")" << endl;
                            break;
                        }

                    }
                }
                cout << "Option: " << flush;
                string lp;
                cin >> lp;

                Plane* planeF;

                bool found = false;

                for (auto& plane : planes) {
                    if (plane.getLicensePlate() == lp) {
                        for (auto& flight : plane.getFlights()) {
                            if (flight.getNum() == num) {
                                found = true;
                                if (passengers.front().acquireTicket(num, plane, hasLuggages, passengers.size())) {
                                    cout << "Tickets successfully bought!" << endl;
                                    cout << "Plane: " << lp << endl;
                                    cout << "Flight nmr: " << num << endl;
                                    cout << "Tickets bought: " << passengers.size() << endl;

                                    for (auto newFlight : plane.getFlights()) {
                                        if (newFlight.getNum() == num)
                                            cout << "Current available seats: " << newFlight.getAvailableSeats() << endl;
                                    }



                                    //TO DO
                                }
                                break;
                            }

                        }
                    }

                }

                if (!found) {
                    cout << "Invalid plane for the given flight. Ending simulation" << endl;
                    break;
                }



            }







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