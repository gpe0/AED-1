#ifndef PROJECT_FLIGHT_H
#define PROJECT_FLIGHT_H

#include <string>
#include "Date.h"

class Flight {
private:
    int num;
    int availableSeats;
    Date date;
    float duration;
    std::string origin;
    std::string destination;

public:
    /** Inicializa um voo (O número de lugares começará igual a '-1' e será alterado para o número
     * da capacidade do avião do qual faz parte (quando for atribuído a um))
     * @param num número de voo
     * @param date data do voo
     * @param duration duração do voo (em horas)
     * @param origin origem do voo
     * @param destination destino do voo
     */
    Flight(int num, Date date, float duration, std::string origin, std::string destination);

    /** Devolve o número do voo
     *
     * @return número do voo
     */
    int getNum();

    /** Devolve o número de lugares disponíveis
     *
     * @return lugares disponíveis
     */
    int getAvailableSeats();

    /** Devolve a data do voo
     *
     * @return data do voo
     */
    Date getDate();

    /** Devolve a duração do voo (em horas)
     *
     * @return duração do voo (em horas)
     */
    float getDuration();

    /** Devolve a origem do voo
     *
     * @return origem do voo
     */
    std::string getOrigin();

    /** Devolve o destino do voo
     *
     * @return destino do voo
     */
    std::string getDestination();

    /** Atribui um número ao voo
     *
     * @param num número do voo
     */
    void setNum(int num);

    /** Atribui um número de lugares disponíveis ao voo
     *
     * @param avaibleSeat número de lugares disponíveis
     */
    void setAvailableSeats(int availableSeats);

    /** Atribui uma data ao voo
     *
     * @param date data do voo
     */
    void setDate(Date date);

    /** Atribui uma duração ao voo (em horas)
     *
     * @param duration duração do voo (em horas)
     */
    void setDuration(float duration);

    /** Atribui uma origem ao voo
     *
     * @param origin origem do voo
     */
    void setOrigin(std::string origin);

    /** Atribui um destino ao voo
     *
     * @param destination destino do voo
     */
    void setDestination(std::string destination);
};


#endif
