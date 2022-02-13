//
// Created by ise on 12/25/21.
//

#ifndef FARMERSMARKET_ANIMAL_H
#define FARMERSMARKET_ANIMAL_H

#include <iostream>
#include <string>
#include <list>
//#include "Farm.h"
using namespace std;

class Animal {
protected:
    int Age;
    int RetailPrice;
    int LivigTime;
public:
    ///getter functions
    const int &getAge() const { return this->Age; }

    const int &getPrice() const { return this->RetailPrice; }

    const int &getLivig() const { return this->LivigTime; }

    ///update age - return true if the animal still living after the update
    bool Grow(int years);

    ///default constructors

    Animal(int RetailPrice, int LivigTime);

    ///destructure
    virtual ~Animal();
};


#endif //FARMERSMARKET_ANIMAL_H
