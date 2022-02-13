//
// Created by ise on 1/2/22.
//

#ifndef FARMERSMARKET_COW_H
#define FARMERSMARKET_COW_H
#include "Animal.h"
#include "Farm.h"

class Cow : public Animal{
public:
    ///default constructor
    Cow():Animal(10 ,10){};
    ///destructure
    ~Cow() override= default;
};


#endif //FARMERSMARKET_COW_H
