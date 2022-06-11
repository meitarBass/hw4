#include "Monster.h"

void Monster::applyEncounter(Player& player) const{
    if(player.getLevel() >= this->m_force){
        player.levelUp();
        player.addCoins(this->m_coins);
        printWinBattle(player.getName(), this->m_name);
    }
    else{
        player.damage(this->m_damageUponLoss);
        printLossBattle(player.getName(), this->m_name);
    }
}

void Monster::printInfo(std::ostream& os) const{
    printCardDetails(os, this->m_name);
    printMonsterDetails(os, this->m_force, this->m_damageUponLoss, this->m_coins, false);
    printEndOfCardDetails(os);
}