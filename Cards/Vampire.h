//
// Created by ariel on 6/11/2022.
//

#ifndef HW4_VAMPIRE_H
#define HW4_VAMPIRE_H
#include "Monster.h"

class Vampire : public Monster{
public:
    /*
    * C'tor of Vampire class
    *
    */
    Vampire() = default;

    /*
    * D'tor of Vampire class
    *
    */
    ~Vampire() = default;

    void applyEncounter(Player& player) const override;
private:
    const int m_force = 10;
    const int m_damageUponLoss = 10;
    const int m_coins = 2;
};


#endif //HW4_VAMPIRE_H
