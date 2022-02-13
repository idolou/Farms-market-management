//
// Created by ise on 12/25/21.
//

#include "Animal.h"
using namespace std;


//Animal::Animal() {RetailPrice = 0 , LivigTime = 0, Age = 0, farm = nullptr;}
//Animal::Animal(int price, int livigTime): RetailPrice(price), LivigTime(livigTime) {Age = 0, farm = nullptr;}
Animal::Animal(int price, int livigTime): RetailPrice(price), LivigTime(livigTime) {Age = 0;}

bool Animal::Grow(int years) {
    bool res = true;
    Age+=years;
    if(Age>=LivigTime)
        res = false;
    return res;
}


Animal::~Animal()= default;
