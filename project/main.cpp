#include <iostream>
#include "Flight.h"
#include "Plane.h"
#include "Date.h"
#include "Person.h"
#include "Worker.h"

using namespace std;

int main() {

    Worker w("Rei", 20, 'M');
    cout << w.getName() << endl;

    return 0;
}
