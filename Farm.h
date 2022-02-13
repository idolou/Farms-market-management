//
// Created by ise on 12/25/21.
//

#ifndef FARMERSMARKET_FARM_H
#define FARMERSMARKET_FARM_H
#include "Animal.h"
#include "Cow.h"
#include "Sheep.h"
#include "Chicken.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <array>
#include <map>

using namespace std;

class Farm {

protected:
    int ID;
    int Money;
    map<string, int> products;       // each farm can have 3 type of products(Actually 2)
    vector<Animal *> Animals;       // the size will be the number of animals
    vector<Farm*> Observers;       //Client list, the farm will sell products to those farms
    static int FarmsNum;           //will count the farms number and will give unique ID
public:
    ///default constructor
    Farm();
    ///destructor
    virtual ~Farm();

    ///getter functions
    static int getNumOfFarms(){return FarmsNum;}
    const int & getID()const{return this->ID;}
    const int & getMoney()const{return this->Money;}
    const vector<Farm*> & getClient()const{return this->Observers;}
    const map<string, int> & getProducts()const{ return this->products;}
    const vector<Animal*> & getAnimals()const {return this->Animals;}

    ///update functions
    //update the right product and money after selling products
    void UpdateProducts(int quantity, const string& prod, int price);
    //Add 10$ to the farm money
    void AddMoney(){Money+=10;}
    //Growing all animals by x years
    void GrowAnimals(int years);

    ///help functions
    //add clients to my client list
    void addObserver(Farm* farm);
    //help function to print all products
    string PrintProducts();

    ///virtual functions
    virtual void productivity() = 0;
    virtual void BuyProducts(Farm* farmToBuyfrom) = 0;
    virtual void BuyAnimals() = 0;
    virtual void printFarm() = 0;


    ///polymorphism functions
    //with those functions we would add each other farm to the right client list
    virtual void HandleCow(Farm* f) = 0;
    virtual void HandleChicken(Farm* f) = 0;
    virtual void HandleSheep(Farm* f) = 0;
    virtual void AddCowFarm(Farm* f) = 0;
    virtual void AddChickenFarm(Farm* f) = 0;
    virtual void AddSheepFarm(Farm* f) = 0;
};


#endif //FARMERSMARKET_FARM_H
