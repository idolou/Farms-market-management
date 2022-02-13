//
// Created by ise on 1/4/22.
//

#include "ChickenFarm.h"

ChickenFarm::ChickenFarm() : Farm() {
    for (int i = 0; i < 3; i++) {
        auto *new_chicken = new Chicken;
        Animals.push_back(new_chicken);
    }
}


void ChickenFarm::productivity() {
    int res = 0;
    for (Animal *Chicken: Animals)
        res += Chicken->getAge();
    products["Eggs"] += res;
}

void ChickenFarm::BuyAnimals() {
    int amount = this->Money / 3;
    if (amount > 0) {
        for (int i = 0; i < amount; i++)
            this->Animals.push_back(new Chicken);
        this->Money -= amount * 3;
        cout << "Chicken farm(" << this->getID() << ") bought " << amount << " chickens for " << amount * 3
             << " dollars" << endl;
    }
}

void ChickenFarm::printFarm() {
    string s = PrintProducts();
    cout << "Farm Id: " << this->getID() << ", type: Chicken Farm, Money: " << this->getMoney() <<
         ", Animals: " << this->getAnimals().size() << " chickens, Products: " << s << endl;

}

void ChickenFarm::BuyProducts(Farm *farmToBuyfrom) {
    string prod = "Wool";
    int quantity_to_buy, total, quantity, prod_price;
    prod_price = 2;  ///chickenFarm buy wool: price 2$
    total = this->getMoney();
    map<string, int> FarmB_prod = farmToBuyfrom->getProducts();
    quantity = FarmB_prod[prod];   ///how many wool can the farm sell
    quantity_to_buy = total / prod_price;  ///how many wool my farm can buy
    if (quantity == 0 || quantity_to_buy == 0)
        return;
    if (quantity_to_buy <= quantity) {
        this->products[prod] += quantity_to_buy;
        this->Money -= quantity_to_buy * prod_price;
        farmToBuyfrom->UpdateProducts(quantity_to_buy, prod, prod_price);
        cout << "Chicken farm(" << this->getID() << ") " << "bought "
             << quantity_to_buy << " wool for " << prod_price * quantity_to_buy
             << " dollars from Sheep farm(" << farmToBuyfrom->getID() << ")" << endl;
    }
        ///we can buy all products and still have money
    else if (quantity > 0 && quantity_to_buy > 0) {
        this->products[prod] += quantity;
        this->Money -= quantity * prod_price;
        farmToBuyfrom->UpdateProducts(quantity, prod, prod_price);

        cout << "Chicken farm(" << this->getID() << ") " << "bought "
             << quantity << " wool for " << prod_price * quantity << " dollars from Sheep farm("
             << farmToBuyfrom->getID() << ")" << endl;
    }
}

ChickenFarm::~ChickenFarm() {
    for (auto &animal: Animals)
        delete animal;
}


