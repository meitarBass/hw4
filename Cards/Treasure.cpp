//
// Created by ariel on 6/12/2022.
//

#include "Treasure.h"
void Treasure::applyEncounter(Player& player) const{
    player.addCoins(this->coins);
    printTreasureMessage();
}
