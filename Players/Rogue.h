//
// Created by Meitar Basson on 07/06/2022.
//

#ifndef HW4_ROGUE_H
#define HW4_ROGUE_H

#include "Player.h"

class Rogue: public Player {
    /*
    * C'tor of Rogue class
    *
    */
    using Player::Player;

    /*
    * D'tor of Rogue class
    *
    * @return
    *      Safely delete Rogue object.
    */
    ~Rogue() = default;

    /*
    * Copy constructor of Rogue class
    *
    * @param Rogue - The rogue to copy
    *      A new copy of rogue.
    */
    Rogue(const Rogue&) = default;

    void addCoins(int amount) override;
};


#endif //HW4_ROGUE_H
