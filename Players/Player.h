//
// Created by Meitar Basson on 16/05/2022.
//

#ifndef HW2_PLAYER_H
#define HW2_PLAYER_H

#include <iostream>

/*
 * All existing types of players.
 */
typedef enum {WIZARD, FIGHTER, ROGUE} PLAYER_TYPE;

class Player {

protected:
    int level, coins, force, hp, max_hp;
    std::string name;
    PLAYER_TYPE type;

    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    virtual void print(std::ostream& os) const = 0;

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
    explicit Player(std::string name);

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
    virtual void heal(int amount);

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
    virtual void addCoins(int amount);

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
    virtual int getAttackStrength() const;

    /*
     * Get a player's type.
     *
     * @return
     *          Player's type.
     */
    virtual PLAYER_TYPE getType() const;

    /*
    * Get a player's name.
    *
    * @return
    *          Player's name.
    */
    std::string getName() const;

    /*
     * Lower Player's level by one (1);
     */
    void levelDown();

    /*
    * Get a player's health points.
    *
    * @return
    *          Player's hp.
    */
    const int getHP() const;

    /*
    * Get a player's number of coins.
    *
    * @return
    *          Player's coins.
    */
    const int getCoins() const;
};


#endif //HW2_PLAYER_H
