#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string &fileName) {
    //Try opening the file by given file name.
    createDeck(fileName);
    checkDeckSize(m_deck.size());

    printStartGameMessage();
    int teamSize = getTeamSize(); // TODO: check if needed: when input is string etc, print invalidSize or invalidInput?
    Mtmchkin::getPlayers(teamSize);
}

void Mtmchkin::playRound() {
    m_roundNumber++;

    //TODO: Iterate over player_queue
}

int Mtmchkin::getTeamSize() {
    printEnterTeamSizeMessage();

    int teamSize;
    std::cin >> teamSize;

    while(!isGroupSizeValid(teamSize)) {
        printInvalidTeamSize();
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> teamSize;
    }
    return teamSize;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
}

bool Mtmchkin::isGameOver() const {
    bool is_game_done = false;
    return is_game_done;
}

void Mtmchkin::createDeck(const std::string &fileName) {
    std::ifstream cardFile;
    try{
        cardFile.open(fileName);
    }
    catch(...){
        throw DeckFileNotFound();
    }

    //Get Card deck from file
    std::string tempCard;
    int line_number = 1;
    std::getline(cardFile, tempCard);
    while(!cardFile.eof()){
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
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundNumber;
}

void Mtmchkin::getPlayers(int number_of_players) {
    std::string name, job;
    for(int i = 0 ; i < number_of_players ; i++) {
        printInsertPlayerMessage();

        std::cin >> name;
        while(!isNameValid(name)) {
            printInvalidName();
            std::cin >> name;
        }

        std::cin >> job;
        while(!isClassValid(job)) {
            printInvalidClass();
            std::cin >> job;

            if(job == "Rogue") {
                m_playerQueue.push_back(std::unique_ptr<Player>(new Rogue(name)));
            } else if( job == "Wizard") {
                m_playerQueue.push_back(std::unique_ptr<Player>(new Wizard(name)));
            } else {
                m_playerQueue.push_back(std::unique_ptr<Player>(new Fighter(name)));
            }

        }
    }
}

void Mtmchkin::checkDeckSize(int size) {
    if(size < 5) {
        throw DeckFileInvalidSize();
    }
}

bool Mtmchkin::isGroupSizeValid(int size) {
    return size >= 2 && size <= 6;
}

bool Mtmchkin::isNameValid(const std::string &player_name) {
    return(player_name.length() <= 15 && !std::any_of(player_name.begin(), player_name.end(), ::isdigit));
}

bool Mtmchkin::isClassValid(const std::string &player_class) {
    return(player_class == "Fighter" || player_class == "Wizard" || player_class == "Rogue");
}

