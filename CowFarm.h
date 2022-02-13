//
// Created by ise on 1/4/22.
//

#ifndef FARMERSMARKET_COWFARM_H
#define FARMERSMARKET_COWFARM_H

#include "Farm.h"

class CowFarm : public Farm {
public:
    CowFarm();

    ~CowFarm() override;

    void HandleCow(Farm *f) override {};

    void HandleChicken(Farm *f) override { f->AddCowFarm(this); };

    void HandleSheep(Farm *f) override {};

    void AddSheepFarm(Farm *f) override {
        Observers.push_back(f);
        cout << "Cow farm(" << this->getID() << ") " << "Added Sheep farm(" << f->getID() << ") to his client list"
             << endl;
    };

    void AddChickenFarm(Farm *f) override {};

    void AddCowFarm(Farm *f) override {};


    ///virtual functionality
    void productivity() override;

    void BuyAnimals() override;

    void BuyProducts(Farm *farmToBuyfrom) override;


//    friend ostream& operator<<(ostream& out, const Farm &e);
    void printFarm() override;
};


#endif //FARMERSMARKET_COWFARM_H
