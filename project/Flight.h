#ifndef PROJECT_FLIGHT_H
#define PROJECT_FLIGHT_H

#include <string>
#include "Date.h"

class Flight {
private:
    int num;
    Date date;
    float duration;
    std::string origin;
    std::string destination;

public:
    /** Inicializa um voo
     *
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
