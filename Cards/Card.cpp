//
// Created by Arielle on 5/19/2022.
//

#include "Card.h"

Card::Card(const std::string &name) : m_name(name) {

}

void Card::printInfo(std::ostream& os) const{
    printCardDetails(os, this->m_name);
    printEndOfCardDetails(os);
}

std::ostream& operator<<(std::ostream& os, const Card& card){
    card.printInfo(os);
    return os;
}