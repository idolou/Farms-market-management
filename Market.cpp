//
// Created by ise on 12/28/21.
//

#include "Market.h"
#include <algorithm>
#include <vector>
#include <iostream>
#include "Exception.h"

using namespace std;
int Market::years;

Market::Market() {
    years = 0;
}

void Market::nextYear() {
    years += 1;
    ///adding new farms
    newFarms();
    ///farm productivity
    FarmsProducts();
    ////starting tradingDay
    TradingDay();
    ///grow all animals by 1;
    for (auto &farm: farms)
        farm->GrowAnimals(1);
    ///add 10$ for each farm
    for (auto &farm: farms)
        farm->AddMoney();
}

void Market::fastForwardYears() {
    int Years;
    cout << "How many years to fast forward?" << endl;
    cin >> Years;
    for (int i = 0; i < Years; i++) {
        years++;
        ///farm productivity
        FarmsProducts();
        ////starting tradingDay
        TradingDay();
        ///grow all animals by 1;
        for (auto &farm: farms)
            farm->GrowAnimals(1);
        ///add 10$ for each farm
        for (auto &farm: farms)
            farm->AddMoney();
    }
}

void Market::printMarketFarms() {
    cout << "----Market Farms----" << endl;
    for (auto &farm: farms)
        farm->printFarm();
}

void Market::addClients(Farm *f) {
    for (auto &farm: farms) {
        f->addObserver(farm);
        farm->addObserver(f);
    }
}

void Market::FarmsProducts() {
    for (auto &farm: farms) {
        farm->productivity();
    }
}

void Market::TradingDay() {
    cout << "----Begin Market----" << endl;
    for (auto &farm_seller: farms) {
        for (auto &farm_client: farm_seller->getClient())
            farm_client->BuyProducts(farm_seller);
    }

    cout << "----Buy Animals----" << endl;
    for (auto &farm: farms)
        if (farm->getMoney() > 0)
            farm->BuyAnimals();
}

//void Market::newFarms() {
//    Farm *new_farm;
//    int numOfCow, numOfSheep, numOfChicken;
//    cout << "----Creating new farms----" << endl;
//    bool done = false;  ///if done is true all values are valid (greater then zero)
//    while (!done) {
//        cout << "How many new cow farms will be added this year?" << endl;
//        try {
//            cin >> numOfCow;
//            if (numOfCow < 0) {
//                done = false;
//                throw CowException();
//            }
//            done = true;
//            cout << "How many new sheep farms will be added this year?" << endl;
//            cin >> numOfSheep;
//            if (numOfSheep < 0) {
//                done = false;
//                throw SheepException();
//            }
//            done = true;
//            cout << "How many new chicken farms will be added this year?" << endl;
//            cin >> numOfChicken;
//            if (numOfChicken < 0) {
//                done = false;
//                throw ChickenException();
//            }
//            done = true;
//        }
//        catch (CowException &ce) {
//            cout << ce.what() << endl;
//            continue;
//        }
//        catch (SheepException &ce) {
//            cout << ce.what() << endl;
//            continue;
//        }
//        catch (ChickenException &ce) {
//            cout << ce.what() << endl;
//            continue;
//        }
//    }
//
//    cout << "----Adding new farms to market----" << endl;
//    for (int i = 0; i < numOfCow; i++) {
//        new_farm = new CowFarm;
//        addClients(new_farm);
//        this->farms.push_back(new_farm);
//    }
//    for (int i = 0; i < numOfSheep; i++) {
//        new_farm = new SheepFarm;
//        addClients(new_farm);
//        this->farms.push_back(new_farm);
//    }
//    for (int i = 0; i < numOfChicken; i++) {
//        new_farm = new ChickenFarm;
//        addClients(new_farm);
//        this->farms.push_back(new_farm);
//    }
//}
//



void Market::newFarms() {
    Farm *new_farm;
    int numOfCow, numOfSheep, numOfChicken;
    cout << "----Creating new farms----" << endl;
    bool done = false;  ///if done is true all values are valid (greater then zero)
    while (!done) {
        cout << "How many new cow farms will be added this year?" << endl;
        try {
            cin >> numOfCow;
            if (numOfCow < 0) {
                done = false;
                throw CowException();
            }
            done = true;
            cout << "How many new sheep farms will be added this year?" << endl;
            cin >> numOfSheep;
            if (numOfSheep < 0) {
                done = false;
                throw SheepException();
            }
            done = true;
            cout << "How many new chicken farms will be added this year?" << endl;
            cin >> numOfChicken;
            if (numOfChicken < 0) {
                done = false;
                throw ChickenException();
            }
            done = true;
        }
        catch (myException &e) {
            cout << e.what() << endl;
            continue;
        }
    }

    cout << "----Adding new farms to market----" << endl;
    for (int i = 0; i < numOfCow; i++) {
        new_farm = new CowFarm;
        addClients(new_farm);
        this->farms.push_back(new_farm);
    }
    for (int i = 0; i < numOfSheep; i++) {
        new_farm = new SheepFarm;
        addClients(new_farm);
        this->farms.push_back(new_farm);
    }
    for (int i = 0; i < numOfChicken; i++) {
        new_farm = new ChickenFarm;
        addClients(new_farm);
        this->farms.push_back(new_farm);
    }
}


Market::~Market() {
    for (auto &farm: farms)
        delete farm;
}