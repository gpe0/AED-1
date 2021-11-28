#ifndef PROJECT_PASSENGER_H
#define PROJECT_PASSENGER_H

#include "Person.h"
#include "Flight.h"

class Passenger : public Person {
    /** Inicializa um passageiro (que é uma pessoa)
     *
     * @param name nome do passageiro
     * @param age  idade do passageiro
     * @param sex  sexo do passageiro ('M', 'F' ou 'U')
     */
    Passenger(std::string name, int age, char sex) : Person(name, age, sex) {};

    /** Tenta adquirir um bilhete para um determinado voo para o passageiro, caso ainda haja lugares disponíveis
     *
     * @param flight voo que o passageiro quer embarcar
     * @param hasLuggage inclusão de bagagem (ou não)
     * @return true - caso adquira o bilhete ; false - caso não adquira o bilhete
     */
    bool acquireTicket(Flight flight, bool hasLuggage);
};


#endif
