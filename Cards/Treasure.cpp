//
// Created by ariel on 6/12/2022.
//

#include "Treasure.h"

Treasure::Treasure() :Card("Treasure"){}

void Treasure::applyEncounter(Player& player) const{
    player.addCoins(this->coins);
    printTreasureMessage();
}
