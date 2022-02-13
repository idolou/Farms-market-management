//
// Created by ise on 1/4/22.
//

#ifndef FARMERSMARKET_SHEEP_H
#define FARMERSMARKET_SHEEP_H
#include "Animal.h"
#include "Farm.h"

class Sheep : public  Animal{
public:
    ///default constructor
    Sheep():Animal(5 ,5){};
    ///destructure
    ~Sheep() override= default;
};


#endif //FARMERSMARKET_SHEEP_H
