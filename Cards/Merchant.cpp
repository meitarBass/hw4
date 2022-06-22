//
// Created by ariel on 6/12/2022.
//

#include "Merchant.h"
#include <ostream>

Merchant::Merchant() : Card("Merchant") {

}

void Merchant::applyEncounter(Player& player) const{
    this->applyEncounter(player, std::cout, std::cin);
}

int getMerchantInput(Player& player, std::ostream& os, std::istream& is, int playerCoins) {
    printMerchantInitialMessageForInteractiveEncounter(os, player.getName(), playerCoins);

    std::string input;
    int inputInt = 0;

    do {
        try {
            std::getline(std::cin, input);
            inputInt = std::stoi(input);

            if(inputInt >= 0 && inputInt <= 2) {
                return inputInt;
            }
        } catch(std::exception& e) {}
        printInvalidInput();
    }while(true);
}

void Merchant::applyEncounter(Player& player, std::ostream& os, std::istream& is) const{
    const int buyNothing = 0;
    const int buyHP = 1;
    const int buyForce = 2;
    int playerCoins = player.getCoins();
    int cost = 0;

    int inputInt = getMerchantInput(player, os, is, playerCoins);

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
                player.pay(cost);
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