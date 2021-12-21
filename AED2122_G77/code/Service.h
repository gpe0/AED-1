#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "Date.h"
#include "Worker.h"

class Service {
private:
    std::string type;
    Date* date;
    Worker worker;

public:
    /**Initializes a service with a type, a date and a worker
     *
     * @param type type - maintenance or cleanup
     * @param date date
     * @param worker worker
     */
    Service(std::string type, Date * date, Worker worker);

    /**Returns the service type
     *
     * @return type
     */
    std::string getType();

    /**Returns the service date (a copy)
     *
     * @return date
     */
    Date getDate();

    /**Returns the service worker
     *
     * @return worker
     */
    Worker getWorker();
};


#endif
