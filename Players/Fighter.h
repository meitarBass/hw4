//
// Created by Meitar Basson on 07/06/2022.
//

#ifndef HW4_FIGHTER_H
#define HW4_FIGHTER_H

#include "Player.h"


class Fighter: public Player {
public:
    /*
    * C'tor of Fighter class
    *
    */
    Fighter(const std::string &name);

    /*
    * D'tor of Fighter class
    *
    * @return
    *      Safely delete fighter object.
    */
    ~Fighter() = default;

    /*
    * Copy constructor of Fighter class
    *
    * @param Fighter - The fighter to copy
    *      A new copy of player.
    */
    Fighter(const Fighter&) = default;

    int getAttackStrength() const override;
    void print(std::ostream &os) const override;
};


#endif //HW4_FIGHTER_H
