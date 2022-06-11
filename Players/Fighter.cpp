//
// Created by Meitar Basson on 07/06/2022.
//

#include "Fighter.h"

int Fighter::getAttackStrength() const {
    return this->force * 2 + this->level;
}

void Fighter::print(ostream &os) const {
    os << this->name << " " << this->level << " " << this->force << " " << this->hp << " " << this->coins << " " << "Fighter";
}





