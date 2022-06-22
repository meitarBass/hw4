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
    Vampire();

    /*
    * D'tor of Vampire class
    *
    */
    ~Vampire() = default;

    void applyEncounter(Player& player) const override;
};


#endif //HW4_VAMPIRE_H
