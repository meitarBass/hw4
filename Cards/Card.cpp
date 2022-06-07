//
// Created by Arielle on 5/19/2022.
//

#include "Card.h"

static void executeBattle(Player& player, int force, int hpLoss, int loot);
static void executeBuff(Player& player, int cost, int buff);
static void executeHeal(Player& player, int cost, int heal);
static void executeTreasure(Player& player, int loot);

Card::Card(CardType type, const CardStats& stats){
    m_stats = CardStats(stats.force, stats.hpLossOnDefeat, stats.cost, stats.heal, stats.buff, stats.loot);
    m_effect = type;
}


void Card::applyEncounter(Player& player) const{
    int force = this->m_stats.force, hp_loss = this->m_stats.hpLossOnDefeat,
            loot = this->m_stats.loot, cost = this->m_stats.cost,
            buff = this->m_stats.buff, heal = this->m_stats.heal;
    switch(this->m_effect){
        case CardType::Battle:
            executeBattle(player, force, hp_loss, loot);
            break;
        case CardType::Buff:
            executeBuff(player, cost, buff);
            break;
        case CardType::Heal:
            executeHeal(player, cost, heal);
            break;
        case CardType::Treasure:
            executeTreasure(player, loot);
            break;
    }
}

void Card::printInfo() const{
    switch(this->m_effect){
        case CardType::Battle:
            printBattleCardInfo(this->m_stats);
            break;
        case CardType::Buff:
            printBuffCardInfo(this->m_stats);
            break;
        case CardType::Heal:
            printHealCardInfo(this->m_stats);
            break;
        case CardType::Treasure:
            printTreasureCardInfo(this->m_stats);
            break;
    }
}


static void executeBattle(Player& player, int force, int hpLoss, int loot){
    bool win = player.getAttackStrength() >= force;
    if(win){
        player.levelUp();
        player.addCoins(loot);
    }
    else{
        player.damage(hpLoss);
    }
    printBattleResult(win);
}
static void executeBuff(Player& player, int cost, int buff){
    if(player.pay(cost)) {
        player.buff(buff);
    }
}
static void executeHeal(Player& player, int cost, int heal){
    if(player.pay(cost)){
        player.heal(heal);
    }
}
static void executeTreasure(Player& player, int loot){
    player.addCoins(loot);
}