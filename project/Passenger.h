#ifndef PROJECT_PASSENGER_H
#define PROJECT_PASSENGER_H

#include "Person.h"
#include "Flight.h"
#include "Plane.h"

class Passenger : public Person {

public:
    /** Inicializa um passageiro (que é uma pessoa)
     *
     * @param name nome do passageiro
     * @param age  idade do passageiro
     * @param sex  sexo do passageiro ('M', 'F' ou 'U')
     */
    Passenger(std::string name, int age, char sex) : Person(name, age, sex) {};

    /** Tenta adquirir um bilhete para um determinado voo para o passageiro, caso ainda haja lugares disponíveis
     *
     * @param flightNum número do voo que o passageiro quer embarcar
     * @param plane avião no qual será feita a busca do voo«
     * @param hasLuggage inclusão de bagagem (ou não)
     * @param tickets número de bilhetes a comprar (por defeito, é 1)
     * @return true - caso tenha conseguido adquirir o bilhete ; false - caso não tenho conseguido adquirir o bilhete
     */
    bool acquireTicket(int flightNum, Plane& plane, bool hasLuggage, int tickets = 1);
};


#endif
