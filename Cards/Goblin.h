#ifndef HW4_GOBLIN_H
#define HW4_GOBLIN_H

#include <ostream>
#include "Monster.h"

class Goblin : public Monster{
public:
    /*
    * C'tor of Goblin class
    *
    */
    Goblin();

    /*
    * D'tor of Goblin class
    *
    */
    ~Goblin();

private:
    const int m_force = 6;
    const int m_damageUponLoss = 10;
    const int m_coins = 2;
};


#endif //HW4_GOBLIN_H
