//
// Created by ariel on 6/12/2022.
//

#ifndef HW4_PITFALL_H
#define HW4_PITFALL_H

#include "Card.h"

class Pitfall : public Card{
public:
    /*
    * C'tor of Pitfall class
    *
    */
    Pitfall();

    /*
    * D'tor of Pitfall class
    *
    */
    ~Pitfall() = default;

    void applyEncounter(Player& player) const override;
private:
    PLAYER_TYPE ignore = ROGUE;
    int damage = 10;
};


#endif //HW4_PITFALL_H
