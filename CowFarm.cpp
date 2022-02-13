//
// Created by ise on 1/4/22.
//

#include <sstream>
#include "CowFarm.h"

CowFarm::CowFarm() : Farm() {
    for (int i = 0; i < 3; i++) {
        Cow *new_cow = new Cow;
        Animals.push_back(new_cow);
    }
}

void CowFarm::productivity() {
    int res = 0;
    for (Animal *cow: Animals)
        res += cow->getAge();
    products["Milk"] += res;
}

void CowFarm::BuyProducts(Farm *farmToBuyfrom) {
    string prod = "Eggs";
    int quantity_to_buy, total, quantity, prod_price;
    prod_price = 1;  ///cow buy eggs: price 1$
    total = this->getMoney();
    map<string, int> FarmB_prod = farmToBuyfrom->getProducts();
    quantity = FarmB_prod[prod];  ///how many eggs can chicken farm sell
    quantity_to_buy = total / prod_price;  ///how many eggs my farm can buy
    if (quantity == 0 || quantity_to_buy == 0)
        return;

    if (quantity_to_buy <= quantity) {
        this->products[prod] += quantity_to_buy;  ///add the number of products
        this->Money -= quantity_to_buy * prod_price; ///pay for the products
        farmToBuyfrom->UpdateProducts(quantity_to_buy, prod, prod_price); ///handle prod and price for seller

        cout << "Cow farm(" << this->getID() << ") " << "bought "
             << quantity_to_buy << " eggs for " << prod_price * quantity_to_buy << " dollars from Chicken farm("
             << farmToBuyfrom->getID()
             << ")" << endl;
    }
        ///we can buy all products and still have money
    else if (quantity > 0 && quantity_to_buy > 0) {
        this->products[prod] += quantity;
        this->Money -= quantity * prod_price;
        farmToBuyfrom->UpdateProducts(quantity, prod, prod_price);

        cout << "Cow farm(" << this->getID() << ") " << "bought "
             << quantity << " eggs for " << prod_price * quantity << " dollars from Chicken farm("
             << farmToBuyfrom->getID()
             << ")" << endl;
    }
}

void CowFarm::BuyAnimals() {
    int amount = this->getMoney() / 10;
    if (amount > 0) {
        for (int i = 0; i < amount; i++)
            this->Animals.push_back(new Cow);
        this->Money -= amount * 10;
        cout << "Cow farm(" << this->getID() << ") bought " << amount << " cows for " << amount * 10 << " dollars"
             << endl;
    }
}

void CowFarm::printFarm() {
    string s = PrintProducts();
    cout << "Farm Id: " << this->getID() << ", type: Cow farm, Money: " << this->getMoney() <<
         ", Animals: " << this->getAnimals().size() << " cows, Products: " << s << endl;

}

CowFarm::~CowFarm() {
    for (auto &animal: Animals)
        delete animal;
}






