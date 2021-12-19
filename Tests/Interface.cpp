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
#include "Airport.h"
#include "Car.h"
#include "Carriage.h"
#include "TransitStop.h"
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

            getline(s, w, ','); //flight num

            aux.clear();
            aux.str(w);

            int fNum;

            aux >> fNum;

            getline(s, w, ','); //date

            aux.clear();
            aux.str(w);

            int day, month, year;
            char bar;

            aux >> day >> bar >> month >> bar >> year;

            Date* date = new Date(day, month, year);

            getline(s, w, ','); //duration

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

            getline(s, w, ','); //origin

            string origin = w;

            getline(s, w, ','); //destination

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

            getline(s, w, ','); //license Plate

            string licensePlate = w;

            getline(s, w, ','); //type

            string type = w;

            getline(s, w, ','); //capacity

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

void Interface::exportCsv(std::string fileName, std::list<Plane> &planes, std::list<Passenger> &passengers, Airport aO, Airport aD) {

    string fileNamePlanes = "../files/output/" + fileName + "_planes.csv";

    string fileNameFlights = "../files/output/" + fileName + "_flights.csv";

    string fileNameServices = "../files/output/" + fileName + "_services.csv";

    string fileNamePassengers = "../files/output/" + fileName + "_passengers.csv";

    string fileNameLuggage = "../files/output/" + fileName + "_luggage.csv";

    string fileNameAirports = "../files/output/" + fileName + "_airports.csv";

    string fileNameTransitStops = "../files/output/" + fileName + "_transitstops.csv";

    ofstream f(fileNamePlanes);
    if (f.is_open()) {
        f << "License Plate, Type, Capacity" << endl;
        for (auto plane : planes) {
            f << plane.getLicensePlate() << ", " << plane.getType() << ", " << plane.getCapacity() << endl;
        }
    }
    f.close();
    f.open(fileNameFlights);
    if (f.is_open()) {
        f << "Corresponding Plane (License Plate), Flight Number, Date, Duration, Origin, Destination, Available Seats" << endl;
        for (auto plane : planes) {
            for (auto flight : plane.getFlights()) {

                stringstream date;
                stringstream duration;

                date << flight.getDate().getDay() << "/" << flight.getDate().getMonth() << "/" << flight.getDate().getYear();
                duration << flight.getDuration().getHours() << ":" << flight.getDuration().getMin() << ":" << flight.getDuration().getSecs();

                f << plane.getLicensePlate() << ", " << flight.getNum() << ", " << date.str() << ", " << duration.str() << ", " << flight.getOrigin() << ", " << flight.getDestination() << ", " << flight.getAvailableSeats() << endl;
            }
        }
    }
    f.close();

    f.open(fileNameServices);
    if (f.is_open()) {
        f << "Type, Date, Worker's Name" << endl;
        for (auto plane : planes) {
            while (!plane.getServices().empty()) {
                Service service = plane.getServices().front();
                stringstream date;
                date << service.getDate().getDay() << "/" << service.getDate().getMonth() << "/" << service.getDate().getYear();

                f << service.getType() << ", " << date.str() << ", " << service.getWorker().getName();
                plane.finishNextService();
            }
        }
    }
    f.close();

    f.open(fileNamePassengers);
    if (f.is_open()) {
        f << "Name, Age, Sex" << endl;
        for (auto passenger : passengers) {
            f << passenger.getName() << ", " << passenger.getAge() << ", " << passenger.getSex() << endl;
        }
    }
    f.close();

    f.open(fileNameLuggage);
    if (f.is_open()) {
        f << "Luggage Passenger's Name, Luggage ID, Width, Height, Weight" << endl;
        for (auto passenger : passengers) {
            for (auto luggage: passenger.getLuggage())
            f << passenger.getName() << ", " << luggage->getID() << ", " << luggage->getWidth() << ", " << luggage->getHeight() << ", " << luggage->getWeight() << endl;
        }
    }
    f.close();

    f.open(fileNameAirports);
    if (f.is_open()){
        f << "Airport name, Latitude, Longitude" << endl;
        f << aO.getName() << ", " << aO.getLocation()->getLatitude() << ", " << aO.getLocation()->getLongitude() << endl;
        f << aD.getName() << ", " << aD.getLocation()->getLatitude() << ", " << aD.getLocation()->getLongitude() << endl;
    }
    f.close();

    f.open(fileNameTransitStops);
    if (f.is_open()) {
        f << "Corresponding Airport's Name,Transit Stop Name, Transport Type, Latitude, Longitude" << endl;
        vector<TransitStop> v;
        aO.getAllTransitStops(v);
        for (auto tStop : v) {
            f << aO.getName() << ", " << tStop.getName() << ", " << tStop.getTransportType() << ", " << tStop.getLocation()->getLatitude() << ", " << tStop.getLocation()->getLongitude() << endl;
        }
        v.clear();
        aD.getAllTransitStops(v);
        for (auto tStop : v) {
            f << aD.getName() << ", " << tStop.getName() << ", " << tStop.getTransportType() << ", " << tStop.getLocation()->getLatitude() << ", " << tStop.getLocation()->getLongitude() << endl;
        }
    }
    f.close();
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
            bool hasPlanes = false, hasFlights = false, hasPassengers = false, hasLuggage = false;

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
                cout << "Luggage to be assigned to the passager named " << (*it).getName() <<": " << flush;

                cin >> n;

                for (int i = 1; i <= n; i++) {

                    hasLuggage = true;

                    double width, height, weight;

                    cout << "Luggage's width: " << flush;

                    cin >> width;

                    cout << "Luggage's height: " << flush;

                    cin >> height;

                    cout << "Luggage's weight: " << flush;

                    cin >> weight;

                    Luggage* l = new Luggage(width, height, weight);

                    (*it).addLuggage(l);

                    cout << "Luggage added!" << endl << endl;
                }
            }
            char opt;
            cout << "Automatic Check-In? [Y/N]: " << flush;
            cin >> opt;

            if (opt == 'y' || opt == 'Y') {
                bool added = true;
                int carriages, stackNumber, stackSize;
                cout << "Number of carriages (car): " << flush;
                cin >> carriages;
                cout << "Number of stacks (carriage): " << flush;
                cin >> stackNumber;
                cout << "Stack size (carriage): " << flush;
                cin >> stackSize;
                Car car(carriages, stackNumber, stackSize);
                for (auto passenger : passengers)
                    for (auto lug : passenger.getLuggage())
                        if (!car.addLuggage(lug)) {
                            added = false;
                            break;
                        }
                if (!added)
                    cout << "Couldn't Process every luggage, you have to check in manually." << endl;
                else
                    cout << "You are now checked in!" << endl;
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
                                if (passengers.front().acquireTicket(num, plane, hasLuggage, passengers.size())) {
                                    cout << "\n---------------------\nTickets successfully bought!" << endl;
                                    cout << "Plane: " << lp << endl;
                                    cout << "Flight nmr: " << num << endl;
                                    cout << "Tickets bought: " << passengers.size() << endl;

                                    string origin, destination;
                                    for (auto newFlight : plane.getFlights()) {
                                        if (newFlight.getNum() == num){
                                            cout << "Current available seats: " << newFlight.getAvailableSeats() << endl;
                                            origin = newFlight.getOrigin();
                                            destination = newFlight.getDestination();
                                        }

                                    }
                                    cout << "---------------------" << endl;

                                    string airportOName, airportDName;
                                    double latO, latD, lonO, lonD;

                                    cout << origin <<"'s airport name: " << flush;
                                    cin >> airportOName;

                                    cout << origin <<"'s airport latitude: " << flush;
                                    cin >> latO;

                                    cout << origin <<"'s airport longitude: " << flush;
                                    cin >> lonO;

                                    Location * locO = new Location(latO, lonO);

                                    Airport aO(airportOName, locO);

                                    cout << "Number of transit stops to add to " << airportOName << " airport: " << flush;

                                    cin >> n;

                                    for (int i = 1; i <= n; i++) {
                                        cout << "Transit Stop " << i << endl;

                                        string name, type;
                                        cout << "Transit stop's name: " << flush;

                                        cin >> name;

                                        cout << "Transit stop's transport type: " << flush;

                                        cin >> type;
                                        double lat, lon;

                                        cout << "Transit stop's airport latitude: " << flush;
                                        cin >> lat;

                                        cout << "Transit stop's airport longitude: " << flush;
                                        cin >> lon;

                                        Location* location = new Location(lat, lon);
                                        aO.addTransitStop(TransitStop(name, type, location));

                                        cout << "Transit stop added!" << endl << endl;
                                    }

                                    cout << destination <<"'s airport name: " << flush;
                                    cin >> airportDName;

                                    cout << destination <<"'s airport latitude: " << flush;
                                    cin >> latD;

                                    cout << destination <<"'s airport longitude: " << flush;
                                    cin >> lonD;

                                    Location * locD = new Location(latD, lonD);

                                    Airport aD(airportDName, locD);

                                    cout << "Number of transit stops to add to " << airportDName << " airport: " << flush;

                                    cin >> n;

                                    for (int i = 1; i <= n; i++) {
                                        cout << "Transit Stop " << i << endl;

                                        string name, type;
                                        cout << "Transit stop's name: " << flush;

                                        cin >> name;

                                        cout << "Transit stop's transport type: " << flush;

                                        cin >> type;
                                        double lat, lon;

                                        cout << "Transit stop's airport latitude: " << flush;
                                        cin >> lat;

                                        cout << "Transit stop's airport longitude: " << flush;
                                        cin >> lon;

                                        Location* location = new Location(lat, lon);
                                        aD.addTransitStop(TransitStop(name, type, location));

                                        cout << "Transit stop added!" << endl << endl;
                                    }

                                    char op;
                                    cout << "Export data? [Y/N]: " << flush;
                                    cin >> op;
                                    if (op == 'y' || op == 'Y') {
                                        string fileName;
                                        cout << "File Name (without .csv): " << flush;
                                        cin >> fileName;
                                        exportCsv(fileName, planes, passengers, aO, aD);
                                    }
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



        }
    }
    return 0;
}