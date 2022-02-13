//
// Created by ise on 1/4/22.
//

#ifndef FARMERSMARKET_SHEEPFARM_H
#define FARMERSMARKET_SHEEPFARM_H

#include "Farm.h"

class SheepFarm : public Farm {

public:
    ///default constructor
    SheepFarm();

    ///destructure
    ~SheepFarm() override;

    ///virtual polymorphism functions
    void HandleCow(Farm *f) override { f->AddSheepFarm(this); };

    void HandleChicken(Farm *f) override {};

    void HandleSheep(Farm *f) override {};

    void AddSheepFarm(Farm *f) override {};

    void AddChickenFarm(Farm *f) override {
        Observers.push_back(f);
        cout << "Sheep farm(" << this->ID << ") " <<
             "Added Chicken farm(" << f->getID() << ") to his client list" << endl;
    };

    void AddCowFarm(Farm *f) override {};

    ///virtual functions
    void BuyProducts(Farm *farmToBuyfrom) override;

    void printFarm() override;

    void productivity() override;

    void BuyAnimals() override;

};

#endif //FARMERSMARKET_SHEEPFARM_H
