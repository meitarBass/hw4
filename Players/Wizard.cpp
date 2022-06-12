//
// Created by Meitar Basson on 07/06/2022.
//

#include "Wizard.h"

void Wizard::heal(int amount) {
    Player::heal(amount * 2);
}

void Wizard::print(std::ostream &os) const {
    os << this->name << " " << this->level << " " << this->force << " " << this->hp << " " << this->coins << " " << "Fighter";
}