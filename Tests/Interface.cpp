#include <fstream>
#include <sstream>
#include "Interface.h"

using namespace std;

void Interface::readFlights(string file, list<Flight> &flights) {
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

            int secs = durationD * 3600;
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