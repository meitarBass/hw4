#ifndef HW4_MONSTER_H
#define HW4_MONSTER_H
#include "Card.h"
#include "../Players/Player.h"


class Monster : public Card{
public:
    /*
    * Default C'tor of Monster class
    *
    */
    Monster() = default;

    /*
    * Default D'tor of Monster class
    *
    */
    ~Monster() = default;

    void applyEncounter(Player& player) const override;
    void printInfo(ostream& os) const override;

protected:
    int m_force = 0;
    int m_damageUponLoss = 0;
    int m_coins = 0;
};


#endif //HW4_MONSTER_H
