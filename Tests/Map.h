#ifndef AED_1_MAP_H
#define AED_1_MAP_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Map {
private:
public:
    string addingmarker(string html, double latitude, double longitude, string name);
    string addingroute(string html, double latitude, double longitude, double latitude2, double longitude2);
};
#endif //AED_1_MAP_H

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