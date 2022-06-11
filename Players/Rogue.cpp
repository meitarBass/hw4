//
// Created by Meitar Basson on 07/06/2022.
//

#include "Rogue.h"

void Rogue::addCoins(int amount) {
    Player::addCoins(amount * 2);
}

void Rogue::print(ostream &os) const {
    os << this->name << " " << this->level << " " << this->force << " " << this->hp << " " << this->coins << " " << "Fighter";
}