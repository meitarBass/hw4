//
// Created by ariel on 6/12/2022.
//

#include "Barfight.h"

void Barfight::applyEncounter(Player& player) const{
    bool isFighter = player.getType() == this->ignore;
    if(!isFighter) {
        player.damage(this->damage);
    }
    printBarfightMessage(isFighter);
}