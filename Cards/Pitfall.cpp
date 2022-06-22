//
// Created by ariel on 6/12/2022.
//

#include "Pitfall.h"

Pitfall::Pitfall() : Card("Pitfall") {

}

void Pitfall::applyEncounter(Player& player) const{
    bool isRogue = player.getType() == this->ignore;
    if(!isRogue) {
        player.damage(this->damage);
    }
    printPitfallMessage(isRogue);
}