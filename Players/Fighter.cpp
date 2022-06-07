//
// Created by Meitar Basson on 07/06/2022.
//

#include "Fighter.h"

int Fighter::getAttackStrength() const {
    return this->force * 2 + this->level;
}


