//
// Created by ise on 1/4/22.
//

#ifndef FARMERSMARKET_CHICKENFARM_H
#define FARMERSMARKET_CHICKENFARM_H

#include "Farm.h"

class ChickenFarm : public Farm {
public:
    ///default constructor
    ChickenFarm();

    ///destructure
    ~ChickenFarm() override;

    ///virtual polymorphism functions
    void HandleCow(Farm *f) override {};

    void HandleChicken(Farm *f) override {};

    void HandleSheep(Farm *f) override { f->AddChickenFarm(this); };

    void AddSheepFarm(Farm *f) override {};

    void AddChickenFarm(Farm *f) override {};

    void AddCowFarm(Farm *f) override {
        Observers.push_back(f);
        cout << "Chicken farm(" << this->getID() << ") " << "Added Cow farm(" << f->getID() << ") to his client list"
             << endl;
    };

    ///virtual functions
    void printFarm() override;

    void BuyProducts(Farm *farmToBuyfrom) override;

    void productivity() override;

    void BuyAnimals() override;
};

#endif //FARMERSMARKET_CHICKENFARM_H
