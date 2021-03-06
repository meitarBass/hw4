//
// Created by ariel on 6/12/2022.
//

#include "Fairy.h"

Fairy::Fairy() : Card("Fairy"){
}

void Fairy::applyEncounter(Player& player) const{
    bool isWizard = player.getType() == this->addTo;
    if(isWizard){
        player.heal(this->healingPoints);
    }
    printFairyMessage(isWizard);
}