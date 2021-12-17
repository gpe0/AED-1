#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "Date.h"
#include "Duration.h"
#include "Flight.h"
#include "Passenger.h"
#include "Person.h"
#include "Plane.h"
#include "Service.h"
#include "ConstTimeGen.h"
#include "Worker.h"
#include "Carriage.h"
#include "Car.h"

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

    //Tests <<

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

    //Testing <<

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
    Duration d1(10, 12, 14);
    // TODO
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

TEST(test1, Plane) {

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

TEST(test2, Carriage) {
    Carriage carriage(3, 4);
    Luggage l1(3.2, 1.6, 8);
    Luggage l2(4.4, 3.3, 10);

    EXPECT_TRUE(carriage.getLuggages().empty());
    EXPECT_EQ(l1.getID(), 1);
    EXPECT_EQ(l2.getID(), 2);

    carriage.addLuggage(&l1);
    carriage.addLuggage(&l2);

    EXPECT_EQ(carriage.getLuggages().size(), 1);
    EXPECT_EQ(carriage.getLuggages().top().size(), 2);
    EXPECT_EQ(*carriage.getLuggages().top().top(), l2);

    EXPECT_FALSE(carriage.addLuggage(&l1));

    carriage.removeNextLuggage();

    EXPECT_TRUE(carriage.addLuggage(&l2));

}

TEST(test2, Car) {
    Car car(3, 3, 4);

    Luggage l1(3.2, 1.6, 8);
    Luggage l2(4.4, 3.3, 10);

    EXPECT_TRUE(car.getCarriages().size() == 3);

    car.addLuggage(&l1);

    EXPECT_EQ(car.getCarriages().front().getLuggages().size(), 1);

}