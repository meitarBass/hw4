//
// Created by ariel on 6/12/2022.
//

#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H

#include "Card.h"

class Merchant : public Card{
public:
    /*
    * C'tor of Merchant class
    *
    */
    Merchant() = default;

    /*
    * D'tor of Merchant class
    *
    */
    ~Merchant() = default;

    void applyEncounter(Player& player) const override;
    void printInfo(ostream& os) const override = 0;

private:
    int healingPotion = 1;
    int forceBoost = 1;

    int healCost = 5;
    int forceCost = 10;
};


#endif //HW4_MERCHANT_H
