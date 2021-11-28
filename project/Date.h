#ifndef PROJECT_DATE_H
#define PROJECT_DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:

    /** Inicializa a data do dia atual
     *
     */
    Date();

    /** Inicializa uma data
     *
     * @param day dia
     * @param month mês
     * @param year ano
     */
    Date(int day, int month, int year);

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};


#endif
