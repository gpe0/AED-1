#include "FunLuggageProblem.h"

FunLuggageProblem::FunLuggageProblem(vector<Luggage*> luggageList, vector<Carriage> carriageList, int maxCarriageNumber) {
    this->maxCarriageNumber= maxCarriageNumber;
    this->carriageList = carriageList;
    this->luggageList = insertionSort(luggageList);
}

vector<Luggage*> FunLuggageProblem::insertionSort(vector<Luggage*> luggageList) {
    for(size_t i = 1; i < luggageList.size(); i++){
        Luggage* anchor = luggageList[i];
        size_t t;
        for(t = i; t > 0 and anchor->getWeight() > (*luggageList[t-1]).getWeight(); t--){
            luggageList[t] = luggageList[t-1];
        }
        luggageList[t] = anchor;
    }
    return luggageList;
}

Car FunLuggageProblem::run() {
    Car car(maxCarriageNumber);

    while (!luggageList.empty()) {
        double bestEfficiency = 0;
        Carriage bCarriage(0, 0, 0);
        for (int i = 0; i < luggageList.size(); i++) {
            for (auto carriage: carriageList) {
                auto begin = luggageList.begin() + i;
                auto end = luggageList.end();
                vector<Luggage *> auxLuggage(begin, end);
                for (auto l: auxLuggage) {
                    carriage.addLuggage(l);
                }
                if (carriage.getEfficiency() > bestEfficiency) {
                    bestEfficiency = carriage.getEfficiency();
                    bCarriage = carriage;
                }
            }
        }

        if (bestEfficiency == 0) return Car(0);
        car.addCarriage(bCarriage);
        for (auto it = carriageList.begin(); it != carriageList.end(); it++) {
            if ((*it) == bCarriage){
                carriageList.erase(it);
                break;
            }
        }

        for (auto it = luggageList.begin(); it != luggageList.end(); it++) {
            bool found = false;
            for (auto row : bCarriage.getLuggage()) {
                vector<Luggage> aux;
                while (!row.empty()){
                    aux.push_back(*row.top());
                    row.pop();
                }
                for (auto & l : aux){
                    if (l == *(*it)) {
                        it = luggageList.erase(it);
                        it--;
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
        }

    }

    return car;

}



