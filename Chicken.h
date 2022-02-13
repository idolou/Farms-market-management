//
// Created by ise on 1/4/22.
//

#ifndef FARMERSMARKET_CHICKEN_H
#define FARMERSMARKET_CHICKEN_H
#include "Animal.h"
#include "Farm.h"

class Chicken : public Animal {
public:
    ///default constructor
    Chicken():Animal(3,3){};
    ///destructure
    ~Chicken() override= default;
};

#endif //FARMERSMARKET_CHICKEN_H
