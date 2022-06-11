//
// Created by ariel on 6/11/2022.
//

#include "Vampire.h"

void Vampire::applyEncounter(Player& player) const{
    if(player.getLevel() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_name);
    }
    else{
        player.damage(this->m_damageUponLoss);
        player.levelDown();
        printLossBattle(player.getName(), this->m_name);
    }
}