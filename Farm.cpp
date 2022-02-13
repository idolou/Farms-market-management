//
// Created by ise on 12/25/21.
//

#include "Farm.h"

int Farm::FarmsNum=0;
using namespace std;

Farm::Farm(){
    FarmsNum++;
    ID = FarmsNum;
    Money = 10;
    products["Milk"] = 0;
    products["Wool"] = 0;
    products["Eggs"] = 0;
}

void Farm::UpdateProducts(int quantity, const string& prod, int price) {
    this->products[prod] -= quantity;
    this->Money += quantity*price;
}

void Farm::addObserver(Farm *farm) {
    HandleChicken(farm);
    HandleCow(farm);
    HandleSheep(farm);
}

//void Farm::GrowAnimals(int years) {
//    int i = 0;
//    for(auto &Animal : Animals){
//        if(!Animal->Grow(years)){
//            delete Animals[i];
//            Animals.erase(Animals.begin()+i);
//            continue;
//        }
//        i++;
//    }
//}


void Farm::GrowAnimals(int years) {
    for(int i = 0; i< Animals.size(); i++){
        if(!Animals[i]->Grow(years)){
            delete Animals[i];
            Animals.erase(Animals.begin()+i);
            i--;
        }
    }
}

string Farm::PrintProducts() {
    string s;
    s += ("Milk[" + to_string(products["Milk"]) + "], ");
    s += ("Wool[" + to_string(products["Wool"]) + "], ");
    s += ("Eggs[" + to_string(products["Eggs"]) + "]");
    return s;
}

Farm::~Farm() = default;
