#ifndef FUNLUGGAGEPROBLEM_H
#define FUNLUGGAGEPROBLEM_H

#include <vector>
#include <unordered_map>
#include "Luggage.h"
#include "Carriage.h"
#include "Car.h"

class FunLuggageProblem {
private:
    std::vector<Luggage*> luggageList;
    std::vector<Carriage> carriageList;
    int maxCarriageNumber;

public:
    /**Initializes the problem solver with a luggage list, carriage list and the max numbers of carriages
     *
     * @param luggageList luggage list
     * @param carriageList carriage list
     * @param maxCarriageNumber car's max number of carriages
     */
    FunLuggageProblem(vector<Luggage*> luggageList, std::vector<Carriage> carriageList, int maxCarriageNumber);

    /**Run the algorithm to find the best organized and the most efficient car
     *
     * @return car
     */
    Car run();
    static std::vector<Luggage*> insertionSort(vector<Luggage*> luggageList);
};


#endif
