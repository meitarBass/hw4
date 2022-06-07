//
// Created by Meitar Basson on 16/05/2022.
//

#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H

#include <iostream>
#include "../../HW2/utilities.h"
using namespace std;

class Player {
    int level = 1, coins = 0, force, hp, max_hp;
    string name;

public:
    /*
    * C'tor of Player class
    *
    * @param name - The player's name.
    * @param hp - The player's hp.
    * @param force - The player's hp.
    * @return
    *      A new instance of player.
    */
    explicit Player(string name, int hp = 100, int force = 5);

    /*
    * D'tor of Player class
    *
    * @return
    *      Safely delete player object.
    */
    ~Player();

    /*
    * Copy constructor of Player class
    *
    * @param Player - The player to copy
    *      A new copy of player.
    */
    Player(const Player&);


    /*
    *  printing player info
    *
    *  @return
    *          void
    */
    void printInfo();

    /*
    *  Leveling up player (<10)
    *
    *  @return
    *          void
    */
    void levelUp();

    /*
    *  Getting player level
    *
    *  @return
    *          int - player\s level
    */
    int getLevel() const;

    /*
    *  Using a buff
    *
    * @param amount - buff amount
    *
    *  @return
    *          void
    */
    void buff(int amount);

    /*
    *  Using heal
    *
    * @param amount - heal points amount
    *
    *  @return
    *          void
    */
    void heal(int amount);

    /*
    *  Player being damaged
    *
    * @param amount - damage amount
    *
    *  @return
    *          void
    */
    void damage(int amount);

    /*
    *  Checking if player is knocked out.
    *
    *  @return
    *          true if player hp is 0
     *          false else.
    */
    bool isKnockedOut() const;

    /*
    *  Adding coins after win a buff
    *
    * @param amount - coins amount
    *
    *  @return
    *          void
    */
    void addCoins(int amount);

    /*
    *  Paying for extra.
    *
    * @param amount - item price.
    *
    *  @return
    *          true if player can purchase.
     *          false else.
    */
    bool pay(int amount);

    /*
    *  Get player's strength
    *
    *  @return
    *          Player's attack strength.
    */
    int getAttackStrength() const;
};


#endif //HW2_PLAYER_H
