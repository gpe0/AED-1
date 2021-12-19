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
    int maxStackSize;

    Carriage recursiveSolution(Carriage carriage, int maxIndex);
public:
    FunLuggageProblem(vector<Luggage*> &luggageList, std::vector<Carriage> carriageList, int maxStackSize);
    Car& run();
    static std::vector<Luggage*> insertionSort(vector<Luggage*> luggageList);
};


#endif
