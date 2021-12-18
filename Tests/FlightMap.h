#ifndef FLIGHTMAP_H
#define FLIGHTMAP_H

#include "Airport.h"
#include "Location.h"

#include <iostream>
#include <fstream>
#include <string>

class Map {
private:
    std::string html;
public:
    void addMarker(Location& location, Airport& airport);
    void addRoute(Location& location1, Location& location2);
    void airportsurroundMap(Location& location, string name, string type);
    std::string getHTML();
};

/*
ifstream inFile("mapBase.html");
string line, html = "";
fstream myfile;
myfile.open("mapBase.html", ios::in);
if (!myfile)
cout << "file cannot open!";

while (getline(myfile, line))
{
html += line;
}

html = addingmarker(html, 4.0, 10.0, "Airport_test");
html = addingroute(html, 40.0, 27.0, 13.0, 8.0);
ofstream out("output_.html");
out << html;
myfile.close();
out.close();
*/
#endif
