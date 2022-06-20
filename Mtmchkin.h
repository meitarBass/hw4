#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Goblin.h"
#include "Cards/Merchant.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Vampire.h"
#include "Players/Fighter.h"
#include "Players/Wizard.h"
#include "Players/Rogue.h"
#include "Exception.h"

#include <deque>
#include <fstream>
#include <memory>
#include <vector>

class Mtmchkin {

private:
    std::deque<std::unique_ptr<Card>> m_deck;
    std::deque<std::shared_ptr<Player>> m_playerQueue;
    std::vector<std::shared_ptr<Player>> m_leaderboard;

    int m_roundNumber = 0;
    int m_number_of_winners = 0;
    int m_number_of_losers = 0;

    void createDeck(const std::string &fileName);
    void pushData(Player *player);

    int getTeamSize();
    void getPlayers(int number_of_players);

    static void checkDeckSize(int size);
    static bool isGroupSizeValid(int size);
    static bool isNameValid(const std::string &player_name); // Check if required
    static bool isClassValid(const std::string &player_class);
    static void clearBuffer();

    void withdrawCard();

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    /*
     * Manually removing copy C'tor and assignment operator,
     *      so no other versions of a specific game are created;
     */
    Mtmchkin(const Mtmchkin& mtmchkin) = delete;
    Mtmchkin& operator=(Mtmchkin& mtmchkin) = delete;
};



#endif /* MTMCHKIN_H_ */
