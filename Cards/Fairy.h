//
// Created by ariel on 6/12/2022.
//

#ifndef HW4_FAIRY_H
#define HW4_FAIRY_H

#include "Card.h"

class Fairy : public Card{
public:
    /*
    * C'tor of Fairy class
    *
    */
    Fairy();

    /*
    * D'tor of Fairy class
    *
    */
    ~Fairy() = default;

    void applyEncounter(Player& player) const override;
private:
    PLAYER_TYPE addTo = WIZARD;
    int healingPoints = 10;
};


#endif //HW4_FAIRY_H
