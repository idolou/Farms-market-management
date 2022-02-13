//
// Created by ise on 1/4/22.
//

#include "SheepFarm.h"

SheepFarm::SheepFarm():Farm(){
    for(int i =0; i < 3; i++){
        Animal* new_Sheep = new Sheep;
        Animals.push_back(new_Sheep);
    }
}

void SheepFarm::productivity() {
    int res = 0;
    for(Animal* sheep : Animals)
        res += sheep->getAge();
    products["Wool"] += res;
}

void SheepFarm::BuyAnimals() {
    int amount = this->Money/5;
    if (amount > 0) {
        for (int i = 0; i < amount ; i++)
            this->Animals.push_back(new Sheep);
        this->Money -= amount * 5;
        cout<<"Sheep farm(" << this->getID() << ") bought " << amount << " sheeps for " << amount*5 << " dollars"<<endl;
    }
}

void SheepFarm::printFarm() {
    string s = PrintProducts();
    cout<<"Farm Id: " << this->getID() << ", type: Sheep farm, Money: " << this->getMoney()<<
    ", Animals: " << this->getAnimals().size()<< " sheep, Products: "<< s << endl;
}

void SheepFarm::BuyProducts(Farm *farmToBuyfrom) {
    string prod = "Milk";
    int quantity_to_buy, total, quantity, prod_price;
    prod_price = 3; ///sheep farm buy Milk: price 3$
    total = this->getMoney();
    map<string, int> FarmB_prod = farmToBuyfrom->getProducts();
    quantity = FarmB_prod[prod];  ///how many milk can cow farm sell
    quantity_to_buy = total/prod_price;   ///how many milk my farm can buy
    if(quantity == 0 || quantity_to_buy == 0)
        return;
    if(quantity_to_buy <= quantity ){
        this->products[prod] += quantity_to_buy;
        this->Money-= quantity_to_buy*prod_price;
        farmToBuyfrom->UpdateProducts(quantity_to_buy, prod, prod_price);

        cout<< "Sheep farm(" << this->getID() << ") " << "bought "
            << quantity_to_buy << " milk for "<< prod_price*quantity_to_buy<<" dollars from Cow farm(" << farmToBuyfrom->getID()
            <<")" <<endl;

    }
        ///we can buy all products and still have money
    else if(quantity > 0){
        this->products[prod] += quantity;
        this->Money -= quantity*prod_price;
        farmToBuyfrom->UpdateProducts(quantity, prod, prod_price);

        cout<< "Sheep farm(" << this->getID() << ") " << "bought "
            << quantity << " milk for "<< prod_price*quantity<<" dollars from Cow farm(" << farmToBuyfrom->getID()
            <<")" <<endl;
    }
}

SheepFarm::~SheepFarm() {
    for (auto &animal: Animals)
        delete animal;
}




