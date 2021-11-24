#ifndef PROJECT_WORKER_H
#define PROJECT_WORKER_H

#include <string>
#include "Person.h"

class Worker : public Person{
private:


public:
    Worker(std::string name, int age, char sex) : Person(name, age, sex) {};
};


#endif