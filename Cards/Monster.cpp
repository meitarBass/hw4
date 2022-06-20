#include "Monster.h"
Monster::Monster(const std::string& name, const int force, const int damage_upon_loss, const int coins):
    Card(name),
    m_force(force),
    m_damageUponLoss(damage_upon_loss),
    m_coins(coins)

    {}

void Monster::applyEncounter(Player& player) const{
    if(player.getAttackStrength() >= this->m_force){
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