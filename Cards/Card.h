#ifndef EX2_Card_H
#define EX2_Card_H

#include <ostream>
#include <string>
#include <ostream>
#include "../Players/Player.h"
#include "../utilities.h"

class Card {
public:
    /*
     * C'tor of Card class
     *
     * @return
     *      A new instance of Card.
    */
    Card(const std::string &name);

    /*
     * Handling the player's applyEncounter with the card:
     *
     * @param player - The player.
     * @return
     *      void
    */
    virtual void applyEncounter(Player& player) const = 0;


    /*
     * Prints the card info:
     *
     * @return
     *      void
    */
    virtual void printInfo(std::ostream& os) const;


    /*
     * Here we are explicitly telling the compiler to use the default methods
    */
    Card(const Card&) = default;
    virtual ~Card() = default;
    Card& operator=(const Card& other) = default;
    friend std::ostream& operator<<(std::ostream& os, const Card& card);

protected:
    std::string m_name;
};

#endif //EX2_Card_H
