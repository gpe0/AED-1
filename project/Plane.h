#ifndef PROJECT_PLANE_H
#define PROJECT_PLANE_H

#include <string>
#include <list>
#include <queue>
#include "Flight.h"
#include "Service.h"

class Plane {

private:
    std::string const licensePlate;
    int const capacity;
    std::list<Flight> flights;
    std::queue<Service> services;
    std::queue<Service> finishedServices;

public:
    /** Inicializa um avião (a fila dos serviços já realizados começa vazia), e associa o número de lugares disponíveis aos voos
     *
     * @param licensePlate Matrícula do avião (constante)
     * @param capacity Capacidade do avião (constante)
     * @param flights Voos do avião
     * @param services Serviços a realizar no avião (poderá não ser indicada, sendo o seu valor default uma fila vazia)
     */
    Plane(std::string licensePlate, int capacity, std::list<Flight> flights, std::queue<Service> services = std::queue<Service>());

    /** Devolve a matrícula do avião
     *
     * @return matrícula
     */
    std::string getLicensePlate() const;

    /** Devolve a capacidade do avião
     *
     * @return capacidade
     */
    int getCapacity() const;

    /** Devolve a lista de voos do avião
     *
     * @return lista de voos
     */
    std::list<Flight> getFlights() const;

    /**Devolve a fila de serviços por realizar
     *
     * @return fila de serviços a realizar
     */
    std::queue<Service> getServices() const;

    /**Devolve a fila de serviços já realizados
     *
     * @return fila de serviços já realizados
     */
    std::queue<Service> getFinishedServices() const;
    /** Atribui uma lista de voos ao avião
     *
     * @param flights lista de voos
     */
    void setFlights(std::list<Flight> flights);

    /**Adiciona a fila de serviços (por realizar) um novo serviço
     *
     * @param service serviço
     */
    void addService(Service service);


};

#endif