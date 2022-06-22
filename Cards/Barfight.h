//
// Created by ariel on 6/12/2022.
//

#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {
public:
    /*
    * C'tor of Barfight class
    *
    */
    Barfight();

    /*
    * D'tor of Barfoght class
    *
    */
    ~Barfight() = default;

    void applyEncounter(Player& player) const override;
private:
    PLAYER_TYPE ignore = FIGHTER;
    int damage= 10;
};


#endif //HW4_BARFIGHT_H
