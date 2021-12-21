#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Date.h"
#include "Duration.h"
#include "Flight.h"
#include "Passenger.h"
#include "Person.h"
#include "Plane.h"
#include "Service.h"
#include "ConstTimeGen.h"
#include "Worker.h"
#include "Schedule.h"
#include "Carriage.h"
#include "Car.h"
#include "Location.h"
#include "TransitStop.h"
#include "Airport.h"
#include "FunLuggageProblem.h"

using testing::Eq;
using namespace std;

//Time related tests

TEST(test1, ConstTimeGen){
    //Tests class when object is valid
    ConstTimeGen t1(0,0,0);
    ConstTimeGen t2(1,0,0);
    ConstTimeGen t3(0,1,0);
    ConstTimeGen t4(0,0,1);
    ConstTimeGen t5(1,0,1);
    ASSERT_EQ(true, t1 < t2);
    ASSERT_EQ(true, t1 < t3);
    ASSERT_EQ(true, t1 < t4);
    ASSERT_EQ(false, t2 < t1);
    ASSERT_EQ(false, t3 < t1);
    ASSERT_EQ(false, t4 < t1);  //Tests each parameter comparison
    ASSERT_EQ(false, t5 < t3);
    ASSERT_EQ(true, t2 < t5);   //Tests normal, mixed cases
    ASSERT_EQ(false, t1 < t1);  //Tests a possible exception

    stringstream testStream;
    testStream << t1;
    string solution = "0/0/0";
    ASSERT_EQ(testStream.str(), solution);

    t1.setInvalid(); //Makes validTime false

    //Testing < operator
    try {
        bool filler = t1 < t2;
        FAIL() << "Valid Time";
    }
    catch(ConstTimeGen::InvalidTime const & err) {
        EXPECT_EQ(err.what(), "Invalid Time");
    }
    catch(...) {
        FAIL() << "Invalid Time";
    }
    try {
        bool filler = t2 < t1;
        FAIL() << "Valid Time";
    }
    catch(ConstTimeGen::InvalidTime const & err) {
        EXPECT_EQ(err.what(), "Invalid Time");
    }
    catch(...) {
        FAIL() << "Invalid Time";
    }
    try {
        bool filler = t1 < t1;
        FAIL() << "Valid Time";
    }
    catch(ConstTimeGen::InvalidTime const & err) {
        EXPECT_EQ(err.what(), "Invalid Time");
    }
    catch(...) {
        FAIL() << "Invalid Time";
    }

    try {
        testStream << t1;
    }
    catch(ConstTimeGen::InvalidTime const & err) {
        EXPECT_EQ(err.what(), "Invalid Time");
    }
    catch(...) {
        FAIL() << "Invalid Time";
    }

}
TEST(test1, Date){
    Date p1(4, 10, 1990);
    Date p2(32, 12, 1990);
    Date p3(28, -1, 1990);
    Date p4(26, 12, -3);
    ASSERT_EQ(4, p1.getDay());
    // Tests if the day is correct
    ASSERT_EQ(10, p1.getMonth());
    // Tests if the month is correct
    ASSERT_EQ(1990, p1.getYear());
    // Tests if the year is correct
    ASSERT_EQ(true, p1.isValid());
    ASSERT_EQ(false, p2.isValid());
    ASSERT_EQ(false, p3.isValid());
    ASSERT_EQ(true, p4.isValid());
    // Tests if function isValid is working properly
    ASSERT_EQ(true, Date::isLeapYear(2020));
    ASSERT_EQ(false, Date::isLeapYear(2019));
    // Tests if function isLeapYear is working properly
}



TEST(test1, Duration){
    Duration d1(4, 10, 19);
    Duration d2(32, 12, -19);
    Duration d3(28, -1, 1900);
    Duration d4(26, 12, 3);
    ASSERT_EQ(4, d1.getHours());
    // Tests if the day is correct
    ASSERT_EQ(10, d1.getMin());
    // Tests if the month is correct
    ASSERT_EQ(19, d1.getSecs());
    // Tests if the year is correct
    ASSERT_EQ(true, d1.isValid());
    ASSERT_EQ(false, d2.isValid());
    ASSERT_EQ(false, d3.isValid());
    ASSERT_EQ(true, d4.isValid());
    // Tests if function isValid is working properly
}

TEST(test1, Flight){
    Date p1(4, 10, 1990);
    Duration d1(0, 45, 0);
    Flight f1(2, &p1, &d1, "Oporto", "Lisbon");


    int day = f1.getDate().getDay();
    int month = f1.getDate().getMonth();
    int year = f1.getDate().getYear();

    ASSERT_EQ(4, day);
    ASSERT_EQ(10, month);
    ASSERT_EQ(1990, year);
    // Tests if functions getDate is working properly
    ASSERT_EQ(2, f1.getNum());
    f1.setNum(3);
    ASSERT_EQ(3, f1.getNum());
    // Tests if functions getNum and setNum are working properly
    ASSERT_EQ(45, f1.getDuration().getMin());
    ASSERT_EQ(0, f1.getDuration().getHours());
    // Tests if functions setDuration and getDuration are working properly
    ASSERT_EQ("Oporto", f1.getOrigin());
    f1.setOrigin("Madrid");
    ASSERT_EQ("Madrid", f1.getOrigin());
    // Tests if functions setOrigin and getOrigin are working properly
    ASSERT_EQ("Lisbon", f1.getDestination());
    f1.setDestination("London");
    ASSERT_EQ("London", f1.getDestination());
    // Tests if functions setDestination and getDestination are working properly
    ASSERT_EQ(-1, f1.getAvailableSeats());
    f1.setAvailableSeats(2);
    ASSERT_EQ(2, f1.getAvailableSeats());
    // Tests if functions getAvailableSeats and setAvailableSeats are working properly
}

TEST(test1, Person) {
    Person p1("Pedro", 19, 'M');
    ASSERT_EQ("Pedro", p1.getName());
    p1.setName("Gonçalo");
    ASSERT_EQ("Gonçalo", p1.getName());
    // Tests if functions getName and setName are working properly
    ASSERT_EQ(19, p1.getAge());
    p1.setAge(17);
    ASSERT_EQ(17, p1.getAge());
    // Tests if functions getAge and setAge are working properly
    ASSERT_EQ('M', p1.getSex());
    p1.setSex('F');
    ASSERT_EQ('F', p1.getSex());
    // Tests if functions getSex and setSex are working properly

    // Testing exceptions
    ASSERT_EQ(true, p1.isValid());
    p1.setAge(-1);
    ASSERT_EQ(false, p1.isValid());
    p1.setAge(120);
    ASSERT_EQ(true, p1.isValid());
    p1.setAge(19);
    // Testing age limits

    ASSERT_EQ(true, p1.isValid());
    p1.setSex('V');
    ASSERT_EQ(false, p1.isValid());
    p1.setSex('M');
    // Testing sex limits

    // Testing throws
    p1.setAge(-1); // making validPerson = false

    //Testing getName()
    try {
        p1.getName();
        FAIL() << "Valid Person";
    }
    catch(Person::InvalidPerson const & err) {
        EXPECT_EQ(err.what(), "Invalid Person");

    }
    catch(...) {
        FAIL() << "Invalid Person";
    }

    //Testing getAge()
    try {
        p1.getAge();
        FAIL() << "Valid Person";
    }
    catch(Person::InvalidPerson const & err) {
        EXPECT_EQ(err.what(), "Invalid Person");

    }
    catch(...) {
        FAIL() << "Invalid Person";

    }

    //Testing getSex()
    try {
        p1.getSex();
        FAIL() << "Valid Person";
    }
    catch(Person::InvalidPerson const & err) {
        EXPECT_EQ(err.what(), "Invalid Person");

    }
    catch(...) {
        FAIL() << "Invalid Person";

    }

}

TEST(test1, Passenger) {
    Passenger passenger("Rui", 25, 'M');
    Luggage * l1 = new Luggage(1.5, 5.5, 5);
    Luggage * l2 = new Luggage(2.5, 6.2, 12);
    Luggage * l3 = new Luggage(1.6, 1.1, 3);
    Luggage * l4 = new Luggage(3.1, 23.8, 25);

    passenger.addLuggage(l1);
    passenger.addLuggage(l2);
    passenger.addLuggage(l3);
    passenger.addLuggage(l4);

    EXPECT_EQ(passenger.findLuggageWithId(l3->getID())->getHeight(), l3->getHeight());
    EXPECT_NEAR(passenger.findLuggageWithId(80)->getHeight(), -1, 0.01);
}

TEST(test1, Worker) {
    Worker w("Maria", 30, 'F');
    EXPECT_EQ(w.getName(), "Maria");
    EXPECT_EQ(w.getSex(), 'F');
    EXPECT_EQ(w.getAge(), 30);
    EXPECT_TRUE(w.isValid());
}

TEST(test1, TransitStop){
    TransitStop t1;
    EXPECT_EQ(t1.getName(), "");
    EXPECT_EQ(t1.getTransportType(), "");
    Location l2(0,0);
    TransitStop t2("name", "type", &l2);
    Location l3(0,0);
    TransitStop t3("name", "type", &l3);

}

TEST(test1, Airport){
    Location l1(0,0);
    Airport a1("Sá Carneiro", &l1);
    EXPECT_EQ(a1.getName(), "Sá Carneiro");
    EXPECT_EQ(a1.getTransportType(), "Airport");

}

TEST(test2, Schedule) {
    Date d(19, 12, 2021);
    Schedule schedule(d);

    Duration * du = new Duration(1, 45, 10);

    schedule.addEntry(du, "worker1Schedule");

    EXPECT_EQ(schedule.getAllEntries()[0].event, "worker1Schedule");

    Duration begin(1, 0, 0);
    Duration end1(1, 10, 0);
    Duration end2(1, 50, 0);
    EXPECT_TRUE(schedule.getEntries(begin, end1).empty());
    EXPECT_FALSE(schedule.getEntries(begin, end2).empty());

    EXPECT_TRUE(schedule.removeEntry("worker1Schedule"));
    EXPECT_TRUE(schedule.getAllEntries().empty());
}

TEST(test2, Carriage) {
    Carriage carriage(3, 4, 20);
    Luggage l1(3.2, 1.6, 8);
    Luggage l2(4.4, 3.3, 10);

    EXPECT_TRUE(carriage.getLuggage().empty());
    EXPECT_EQ(l1.getID(), 6);
    EXPECT_EQ(l2.getID(), 7);

    carriage.addLuggage(&l1);
    carriage.addLuggage(&l2);

    EXPECT_EQ(carriage.getLuggage().size(), 1);
    EXPECT_EQ(carriage.getLuggage().back().size(), 2);
    EXPECT_EQ(*carriage.getLuggage().back().top(), l2);

    EXPECT_FALSE(carriage.addLuggage(&l1));

    carriage.removeNextLuggage();

    EXPECT_TRUE(carriage.addLuggage(&l2));

}

TEST(test2, Car) {
    Car car(3);

    Luggage l1(3.2, 1.6, 8);

    EXPECT_TRUE(car.getCarriages().size() == 0);

    EXPECT_FALSE(car.addLuggage(&l1));

    car.addCarriage(Carriage(2, 2, 10));
    EXPECT_TRUE(car.addLuggage(&l1));
    EXPECT_FALSE(car.addLuggage(&l1));

}

TEST(test3, Airport) {
    Location* l1 = new Location(0, 0);
    Location* l2 = new Location(20, 20);
    Location* l3 = new Location(30, 30);
    Location* l4 = new Location(40, 40);
    vector<TransitStop> v1;
    Airport a("Porto", l1);

    a.getAllTransitStops(v1);

    EXPECT_TRUE(v1.size() == 0);

    a.addTransitStop(TransitStop("S Joao", "Autocarro", l4));
    a.addTransitStop(TransitStop("S Maria", "Comboio", l2));
    a.addTransitStop(TransitStop("Combatentes", "Metro", l3));

    a.getAllTransitStops(v1);

    EXPECT_TRUE(v1.size() == 3);
    EXPECT_TRUE(v1.front().getName() == "S Maria");


    vector<TransitStop> v2;
    a.getAllTransitStopsInRange(4700, v2);

    EXPECT_TRUE(v2.size() == 2);
    EXPECT_TRUE(v2.back().getName() == "Combatentes");
}

TEST(test3, Plane) {

    Duration *du1 = new Duration(1, 30, 0);
    Duration *du2 = new Duration(0, 30, 0);
    Duration *du3 = new Duration(3, 15, 0);

    Date *d1 = new Date(10, 11, 2021);
    Date *d2 = new Date(11, 11, 2021);
    Date *d3 = new Date;

    Flight f1(1, d1, du1, "Porto", "Madrid");
    Flight f2(2, d2, du2, "Lisboa", "Madrid");
    Flight f3(3, d3, du3, "Madrid", "Amesterdão");

    Passenger p1("Pedro", 19, 'M');

    list<Flight> flights;

    flights.push_back(f1);
    flights.push_back(f2);
    flights.push_back(f3);

    Plane plane("AA-990", "A101", 300, flights);

    EXPECT_TRUE(p1.acquireTicket(1, plane, false));

    EXPECT_EQ(plane.getFlights().front().getAvailableSeats(), 299);

    Worker w("Maria", 30, 'F');
    Service service("maintenance", d2, w);

    plane.addService(service);

    EXPECT_EQ(plane.getServices().front().getWorker().getName(), "Maria");
    EXPECT_EQ(plane.getServices().front().getDate().getYear(), 2021);

}

TEST(test4, FunLuggageProblem) {
    Luggage * l1 = new Luggage(1, 2, 4);
    Luggage * l2 = new Luggage(2, 1, 5);
    Luggage * l3 = new Luggage(1, 1, 2);
    Luggage * l4 = new Luggage(4, 3, 10);

    vector<Luggage*> vL;
    vL.push_back(l1);
    vL.push_back(l2);
    vL.push_back(l3);
    vL.push_back(l4);
    vector<Carriage> vC;
    vC.push_back(Carriage(2, 3, 20));

    FunLuggageProblem f(vL, vC, 3);
    Car c = f.run();

    EXPECT_TRUE(c.getCarriages().size() == 0);

}