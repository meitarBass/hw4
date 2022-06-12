//
// Created by ariel on 6/12/2022.
//

#include "Merchant.h"
#include <ostream>
void Merchant::applyEncounter(Player& player) const{
    this->applyEncounter(player, std::cout, std::cin);
}
void Merchant::printInfo(std::ostream& os) const{
}

void Merchant::applyEncounter(Player& player, std::ostream& os, std::istream& is) const{
    const int buyNothing = 0;
    const int buyHP = 1;
    const int buyForce = 2;
    std::string input;
    int inputInt = -1;
    int playerCoins = player.getCoins();
    int cost = 0;
    printMerchantInitialMessageForInteractiveEncounter(os, player.getName(), playerCoins);
    getline(is, input);
    inputInt = stoi(input);
    while(inputInt <= buyNothing || inputInt >= buyForce){
        printInvalidInput();
        getline(is, input);
        inputInt = stoi(input);
    };

    switch (inputInt) {
        case buyHP:
            if(playerCoins >= healCost){
                player.heal(healingPotion);
                player.pay(healCost);
                cost = healCost;
            }
            else {
                printMerchantInsufficientCoins(os);
            }
            break;
        case buyForce:
            if(playerCoins >= forceCost){
                player.buff(forceBoost);
                cost = forceCost;
            }
            else {
                printMerchantInsufficientCoins(os);
            }
            break;
        case buyNothing:
            break;
    }

    printMerchantSummary(os, player.getName(), inputInt, cost);
}