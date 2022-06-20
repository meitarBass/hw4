#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName) {
    //Try opening the file by given file name.
    std::ifstream cardFile;
    try{
        cardFile.open(fileName);
    }
    catch(...){
        throw DeckFileNotFound();
    }

    //Get Card deck from file
    std::string tempCard;
    int line_number = 0;
    std::getline(cardFile, tempCard);
    while(!tempCard.empty()){
        if(tempCard == "Fairy"){
            m_deck.push_back(std::unique_ptr<Card>(new Fairy()));
        }
        else if(tempCard == "Goblin"){
            m_deck.push_back(std::unique_ptr<Card>(new Goblin()));
        }
        else if(tempCard == "Vampire"){
            m_deck.push_back(std::unique_ptr<Card>(new Vampire()));
        }
        else if(tempCard == "Barfight"){
            m_deck.push_back(std::unique_ptr<Card>(new Barfight()));
        }
        else if(tempCard == "Dragon"){
            m_deck.push_back(std::unique_ptr<Card>(new Dragon()));
        }
        else if(tempCard == "Treasure"){
            m_deck.push_back(std::unique_ptr<Card>(new Treasure()));
        }
        else if(tempCard == "Merchant"){
            m_deck.push_back(std::unique_ptr<Card>(new Merchant()));
        }
        else if(tempCard == "Pitfall"){
            m_deck.push_back(std::unique_ptr<Card>(new Pitfall()));
        }
        else{
            throw DeckFileFormatError(line_number);
        }
        line_number++;
        std::getline(cardFile, tempCard);
    }

    if(m_deck.size() < 5){
        throw DeckFileInvalidSize();
    }

    //TODO: Create Player queue - from user
    printStartGameMessage();
    printEnterTeamSizeMessage();
    int teamSize;
    std::cin >> teamSize;
    while(teamSize < 2 || teamSize > 6){
        printInvalidTeamSize();
        std::cin >> teamSize;
    } // TODO: check if needed: when input is string etc, print invalidSize or invalidInput?

    printInsertPlayerMessage();
    std::string name, job;
    std::cin >> name >> job;
    //TODO: continue this part, check input validity etc.
}

void Mtmchkin::playRound() {
    m_roundNumber++;

    //TODO: Iterate over player_queue
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
}

bool Mtmchkin::isGameOver() const {
    bool is_game_done = false;

    return is_game_done;
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundNumber;
}

