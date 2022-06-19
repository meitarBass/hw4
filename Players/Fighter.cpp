#include "Fighter.h"

int Fighter::getAttackStrength() const {
    return this->force * 2 + this->level;
}

void Fighter::print(std::ostream &os) const {
    os << this->name << " " << this->level << " " << this->force << " " << this->hp << " " << this->coins << " " << "Fighter";
}



