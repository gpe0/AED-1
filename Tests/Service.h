#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include "Date.h"
#include "Worker.h"

class Service {
private:
    std::string type;
    Date date;
    Worker worker;

};


#endif
