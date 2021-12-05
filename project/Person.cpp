#include <stdexcept>
#include "Person.h"

using namespace std;

Person::Person() : name("undefined"), sex('U'){
    age = 0;
    validPerson = false;
}

Person::Person(string name, int age, char sex) : name(name), sex(sex){
    validPerson = true;
    this->age = age;
    if (age <= 0 || age > 120 || sex != 'M' || sex != 'F' || sex != 'U') {
        validPerson == false;
    }
}

bool Person::isValid() {
    return validPerson;
}

string Person::getName() const{
    if (not validPerson)
        throw (runtime_error("Invalid Person"));
    return name;
}

int Person::getAge() const{
    if (not validPerson)
        throw (runtime_error("Invalid Person"));
    return age;
}

char Person::getSex() const{
    if (not validPerson)
        throw (runtime_error("Invalid Person"));
    return sex;
}

void Person::setName(string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setSex(char sex) {
    this->sex = sex;
}

