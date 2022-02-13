//
// Created by ise on 12/28/21.
//

#ifndef FARMERSMARKET_MARKET_H
#define FARMERSMARKET_MARKET_H

#include "Farm.h"
#include "Exception.h"
#include "ChickenFarm.h"
#include "CowFarm.h"
#include "SheepFarm.h"
#include "Chicken.h"
#include "Sheep.h"
#include "Cow.h"
#include <vector>


class Market {
    int static years;
protected:
    vector<Farm *> farms;
public:
    ///default constructor
    Market();

    ///destructure
    ~Market();

    ///print all farms in market
    void printMarketFarms();

    ///get current year
    static int getYear() { return years; }

    ///go to next year
    void nextYear();

    ///go to next years
    void fastForwardYears();

    ///farms products - yield the products of each farm
    void FarmsProducts();

    ///function for the trading day - trade between farms & buy animals
    void TradingDay();

    ///function for the observer pattern to add potential clients
    void addClients(Farm *f);

    ///help functions - add new farms to market
    void newFarms();
};


#endif //FARMERSMARKET_MARKET_H
