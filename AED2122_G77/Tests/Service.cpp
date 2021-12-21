#include "Service.h"

Service::Service(std::string type, Date *date, Worker worker) : date(date), worker(worker) {
    this->type = type;
}

std::string Service::getType() {
    return type;
}

Date Service::getDate() {
    return *date;
}

Worker Service::getWorker() {
    return worker;
}
