#ifndef PROJECT_WORKER_H
#define PROJECT_WORKER_H

#include <string>
#include "Person.h"

class Worker : public Person{
private:


public:
    /** Inicializa um funcionário (que é uma pessoa)
     *
     * @param name nome do funcionário
     * @param age  idade do funcionário
     * @param sex  sexo do funcionário ('M', 'F' ou 'U')
     */
    Worker(std::string name, int age, char sex) : Person(name, age, sex) {};
};


#endif