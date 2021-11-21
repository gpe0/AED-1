#ifndef PROJECT_PLANE_H
#define PROJECT_PLANE_H

#include <string>
#include <list>
#include "Flight.h"

class Plane {

private:
    std::string const licensePlate;
    int const capacity;
    std::list<Flight> flights;

public:
    /** Inicializa um avião, com uma matrícula e capacidades constantes e uma lista de voos
     *
     * @param licensePlate Matrícula do avião (constante)
     * @param capacity Capacidade do avião (constante)
     * @param flights Voos do avião
     */
    Plane(std::string licensePlate, int capacity, std::list<Flight> flights);

    /** Devolve a matrícula do avião
     *
     * @return matrícula
     */
    std::string getLicensePlate();

    /** Devolve a capacidade do avião
     *
     * @return capacidade
     */
    int getCapacity();

    /** Devolve a lista de voos do avião
     *
     * @return lista de voos
     */
    std::list<Flight> getFlights();

    /** Associa a lista de voos ao avião
     *
     * @param flights lista de voos
     */
    void setFlights(std::list<Flight> flights);
};

#endif