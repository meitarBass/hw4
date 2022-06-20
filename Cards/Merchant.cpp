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
    do {
        try {
            std::cin >> inputInt;
            break;
        } catch(std::invalid_argument& e) {
            printInvalidInput();
            std::cin.clear();
            std::cin.ignore(256,'\n');
        }
    } while (true);
//
//    while(inputInt <= buyNothing || inputInt >= buyForce){
//        printInvalidInput();
//        getline(is, input);
//        inputInt = stoi(input);
//    };

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