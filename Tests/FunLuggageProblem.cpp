#include "FunLuggageProblem.h"

FunLuggageProblem::FunLuggageProblem(vector<Luggage*> &luggageList, std::vector<Carriage> carriageList, int maxStackSize)
: luggageList(insertionSort(luggageList)) {
    this->maxStackSize= maxStackSize;
    this->carriageList = carriageList;
}

vector<Luggage*> FunLuggageProblem::insertionSort(vector<Luggage*> luggageList) {
    for(size_t i = 1; i < luggageList.size(); i++){
        Luggage anchor = *luggageList[i];
        size_t t;
        for(t = i; t > 0 and anchor.getWeight() < (*luggageList[t-1]).getWeight(); t--){
            luggageList[t] = luggageList[t-1];
        }
        luggageList[t] = &anchor;
    }
    return luggageList;
}

Car& FunLuggageProblem::run(){
    Car car(maxStackSize);
    Carriage bestPossibleCarriage(0,0,0);
    while (luggageList.size() != 0){
        for (size_t i = 0; i < carriageList.size(); i++){
            Carriage possibleCarriage(0,0,0);
            possibleCarriage = recursiveSolution(possibleCarriage, luggageList.size());
            if(possibleCarriage.getAvailableCapacity() > bestPossibleCarriage.getAvailableCapacity()){
                bestPossibleCarriage = possibleCarriage;
            }
        }
        list<stack<Luggage*>> lugaggesFilled = bestPossibleCarriage.getLuggages();
        list<stack<Luggage*>>::iterator it = lugaggesFilled.begin();
        for (size_t i = 0; i < lugaggesFilled.size(); i++) {
            while(!((*it).empty())){
                for (size_t t = 0; t < luggageList.size(); t++){
                    if(((*it).top()->getID() == luggageList[i]->getID())) {
                        luggageList.erase(luggageList.begin() + t);
                        break;
                    }
                    }
            }
            for (size_t t = 0; t < luggageList.size(); t++){
                luggageList.erase(luggageList.begin() + t);
                break;
            }
            it++;
        }
        car.addCarriage(bestPossibleCarriage);
    }
    return car;
}


Carriage FunLuggageProblem::recursiveSolution(Carriage carriage, int maxIndex) {
    Carriage currentBestCarriage = carriage;
    for(int i = maxIndex; i>= 0; i--){
        if(luggageList[i]->getWeight() > carriage.getCapacity())
            maxIndex--;
        else if(luggageList[i]->getWidth() < carriage.getWidth() and luggageList[i]->getHeight() < carriage.getHeigth()){
            Carriage tempCarriage = carriage;
            tempCarriage.addNewStack(luggageList[i]);
            tempCarriage = recursiveSolution(tempCarriage, maxIndex);
            if (tempCarriage.getEfficiency() > currentBestCarriage.getEfficiency()){
                currentBestCarriage = tempCarriage;
            }
        }
    }
    if (maxIndex == 0){
        return carriage;
    }

    for(int i = 0; i < carriage.getStackLength(); i++) {//Stack in carriage
        Luggage* topElement = carriage.getStackNum(i).top();//stack.top()-> unordenered_map
        for (size_t i = 0; i < luggageList.size() and i < maxIndex; i++){
            Carriage tempCarriage = carriage;
            tempCarriage.addLugToStackNum(i,luggageList[i]);
            tempCarriage = recursiveSolution(tempCarriage, maxIndex);
            if (tempCarriage.getEfficiency() > currentBestCarriage.getEfficiency()){
                currentBestCarriage = tempCarriage;
            }
        }
    }
}
