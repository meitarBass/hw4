#include "Mtmchkin.h"
#include <algorithm>

Mtmchkin::Mtmchkin(const std::string &fileName) {
    //Try opening the file by given file name.
    createDeck(fileName);
    checkDeckSize(m_deck.size());

    printStartGameMessage();
    int teamSize = getTeamSize(); // TODO: check if needed: when input is string etc, print invalidSize or invalidInput?
    Mtmchkin::getPlayers(teamSize);
}

void Mtmchkin::playRound() {
    printRoundStartMessage(++m_roundNumber);
    for (int i = 0; i < m_playerQueue.size(); i++) {
        withdrawCard();
    }
    if (isGameOver()) {
        printGameEndMessage();
    }
}

int Mtmchkin::getTeamSize() {
    printEnterTeamSizeMessage();

    int teamSize;
    std::cin >> teamSize;

    while (!isGroupSizeValid(teamSize)) {
        printInvalidTeamSize();
        clearBuffer();
        std::cin >> teamSize;
    }
    return teamSize;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int i = 1;
    for (const std::shared_ptr<Player> &player: m_leaderboard) {
        printPlayerLeaderBoard(i++, *player);
    }
}

bool Mtmchkin::isGameOver() const {
    return m_number_of_losers + m_number_of_winners == m_leaderboard.size();
}

void Mtmchkin::createDeck(const std::string &fileName) {
    std::ifstream cardFile;
    cardFile.open(fileName);
    if (cardFile.fail()) {
        throw DeckFileNotFound();
    }

    //Get Card deck from file
    std::string tempCard;
    int line_number = 1;
    std::getline(cardFile, tempCard);
    while (!cardFile.eof() || !tempCard.empty()) {
        if (tempCard == "Fairy") {
            m_deck.push_back(std::unique_ptr<Card>(new Fairy()));
        } else if (tempCard == "Goblin") {
            m_deck.push_back(std::unique_ptr<Card>(new Goblin()));
        } else if (tempCard == "Vampire") {
            m_deck.push_back(std::unique_ptr<Card>(new Vampire()));
        } else if (tempCard == "Barfight") {
            m_deck.push_back(std::unique_ptr<Card>(new Barfight()));
        } else if (tempCard == "Dragon") {
            m_deck.push_back(std::unique_ptr<Card>(new Dragon()));
        } else if (tempCard == "Treasure") {
            m_deck.push_back(std::unique_ptr<Card>(new Treasure()));
        } else if (tempCard == "Merchant") {
            m_deck.push_back(std::unique_ptr<Card>(new Merchant()));
        } else if (tempCard == "Pitfall") {
            m_deck.push_back(std::unique_ptr<Card>(new Pitfall()));
        } else {
            throw DeckFileFormatError(line_number);
        }
        line_number++;
        tempCard = "";
        std::getline(cardFile, tempCard);
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundNumber;
}

void Mtmchkin::getPlayers(int number_of_players) {
    std::string name, job;
    for (int i = 0; i < number_of_players; i++) {
        printInsertPlayerMessage();
        do {
            std::cin >> name;
            if (!isNameValid(name)) {
                printInvalidName();
                continue;
            }
            std::cin >> job;
            if (job == "Rogue") {
                pushData(new Rogue(name));
                break;
            } else if (job == "Wizard") {
                pushData(new Wizard(name));
                break;
            } else if (job == "Fighter") {
                pushData(new Fighter(name));
                break;
            } else {
                printInvalidClass();
            }
        } while (true);
    }
}

void Mtmchkin::pushData(Player *player) {
    std::shared_ptr<Player> player_ptr{player};
    m_playerQueue.push_back(player_ptr);
    m_leaderboard.push_back(player_ptr);
}

void Mtmchkin::checkDeckSize(int size) {
    if (size < 5) {
        throw DeckFileInvalidSize();
    }
}

bool Mtmchkin::isGroupSizeValid(int size) {
    return size >= 2 && size <= 6;
}

bool Mtmchkin::isNameValid(const std::string &player_name) {
    return (player_name.length() <= 15 && !std::any_of(player_name.begin(), player_name.end(), ::isdigit));
}

bool Mtmchkin::isClassValid(const std::string &player_class) {
    return (player_class == "Fighter" || player_class == "Wizard" || player_class == "Rogue");
}

void Mtmchkin::clearBuffer() {
    std::cin.clear();
    std::cin.ignore(256, '\n');
}

void Mtmchkin::withdrawCard() {
    std::shared_ptr<Player> current_player = std::move(m_playerQueue.front());

    m_playerQueue.pop_front();
    if (current_player->isStillPlaying()) {
        printTurnStartMessage(current_player->getName());
        std::unique_ptr<Card> card_to_withdraw = std::move(m_deck.front());
        m_deck.pop_front();
        card_to_withdraw->applyEncounter(*current_player);

        if (current_player->getLevel() == 10) {
            m_leaderboard.erase(std::find(m_leaderboard.begin(), m_leaderboard.end(), current_player));
            m_leaderboard.insert(m_leaderboard.begin() + m_number_of_winners, current_player);
            m_number_of_winners++;
        } else if (current_player->isKnockedOut()) {
            m_leaderboard.erase(std::find(m_leaderboard.begin(), m_leaderboard.end(), current_player));
            m_leaderboard.insert(m_leaderboard.end() - m_number_of_losers, current_player);
            m_number_of_losers++;
        }

        m_deck.push_back(std::move(card_to_withdraw));
    }
    m_playerQueue.push_back(std::move(current_player));
}

