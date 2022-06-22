//
// Created by ariel on 6/11/2022.
//

#ifndef HW4_DRAGON_H
#define HW4_DRAGON_H

#include "Monster.h"

class Dragon : public Monster{
public:
    /*
    * C'tor of Dragon class
    *
    */
    Dragon();

    /*
    * D'tor of Dragon class
    *
    */
    ~Dragon() = default;

    void applyEncounter(Player& player) const override;
    void printInfo(std::ostream& os) const override;
};


#endif //HW4_DRAGON_H
