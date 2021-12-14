#ifndef WORKER_H
#define WORKER_H

#include <string>
#include "Person.h"

class Worker : public Person{
private:


public:
    /** Initializes a worker (who is a person)
     * (validation and testing not implemented yet)
     *
     * @param name worker name
     * @param age  worker age
     * @param sex  worker sex
     */
    Worker(std::string name, int age, char sex) : Person(name, age, sex) {};
};


#endif