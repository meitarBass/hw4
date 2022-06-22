//
// Created by ariel on 6/11/2022.
//

#include "Dragon.h"
Dragon::Dragon() : Monster("Dragon", 25, -1, 1000) {

}
void Dragon::applyEncounter(Player& player) const{
    if(player.getAttackStrength() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_name);
    }
    else{
        player.damage(player.getHP());
        printLossBattle(player.getName(), this->m_name);
    }
}

void Dragon::printInfo(std::ostream& os) const{
    printCardDetails(os, this->m_name);
    printMonsterDetails(os, this->m_force, this->m_damageUponLoss, this->m_coins, true);
    printEndOfCardDetails(os);
}