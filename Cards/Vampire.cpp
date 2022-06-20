//
// Created by ariel on 6/11/2022.
//

#include "Vampire.h"

Vampire::Vampire() : Monster("Vampire", 10, 10, 2) {

}

void Vampire::applyEncounter(Player& player) const{
    if(player.getAttackStrength() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_name);
    }
    else{
        player.damage(this->m_damageUponLoss);
        player.forceDown();
        printLossBattle(player.getName(), this->m_name);
    }
}