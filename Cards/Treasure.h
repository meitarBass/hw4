//
// Created by ariel on 6/12/2022.
//

#ifndef HW4_TREASURE_H
#define HW4_TREASURE_H

#include "Card.h"

class Treasure : public Card{
public:
    /*
    * C'tor of Treasure class
    *
    */
    Treasure() = default;

    /*
    * D'tor of Treasure class
    *
    */
    ~Treasure() = default;

    void applyEncounter(Player& player) const override;
private:
    int coins = 10;
};


#endif //HW4_TREASURE_H
