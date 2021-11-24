#include "Person.h"

Person::Person() {
    name = "undefined";
    age = 0;
    sex = 'U';
}

Person::Person(std::string name, int age, char sex) {
    this->name = name;
    this->age = age;
    this->sex = sex;
}

std::string Person::getName() const{
    return name;
}

int Person::getAge() const{
    return age;
}

char Person::getSex() const{
    return sex;
}

void Person::setName(std::string name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

void Person::setSex(char sex) {
    this->sex = sex;
}
