#include "Mtmchkin.h"

static void readline_without_cr(std::ifstream& ifstream, std::string& out) {
    std::getline(ifstream, out);
    out.erase(std::remove(out.begin(), out.end(), '\r'), out.end());
}

Mtmchkin::Mtmchkin(const std::string &fileName) {
    //Try opening the file by given file name.
    printStartGameMessage();
    createDeck(fileName);
    checkDeckSize(m_deck.size());

    int teamSize = getTeamSize(); // TODO: check if needed: when input is string etc, print invalidSize or invalidInput?
    Mtmchkin::getPlayers(teamSize);
}

void Mtmchkin::playRound() {
    printRoundStartMessage(++m_roundNumber);
    for (unsigned int i = 0; i < m_playerQueue.size(); i++) {
        withdrawCard();
    }
    if (isGameOver()) {
        printGameEndMessage();
    }
}

int Mtmchkin::getTeamSize() {
    int teamSize;
    std::string input;

    do {
        printEnterTeamSizeMessage();
        try {
            std::getline(std::cin, input);
            teamSize = std::stoi(input);

            if(isGroupSizeValid(teamSize)) {
                return teamSize;
            }
        } catch(std::exception& e) {}
        printInvalidTeamSize();
    }while(true);
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int i = 1;
    for (const std::shared_ptr<Player> &player: m_leaderboard) {
        printPlayerLeaderBoard(i++, *player);
    }
}

bool Mtmchkin::isGameOver() const {
    return m_number_of_losers + m_number_of_winners == int(m_leaderboard.size());
}

void Mtmchkin::createDeck(const std::string &fileName) {
    std::ifstream cardFile;
    cardFile.open(fileName);
    if (cardFile.fail()) {
        throw DeckFileNotFound();
    }

    //Get Card deck from file
    std::string tempCard;
    readline_without_cr(cardFile, tempCard);
    int line_number = 1;

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
        readline_without_cr(cardFile, tempCard);
    }
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundNumber;
}

std::vector<std::string> split(const std::string& i_str, const std::string& i_delim)
{
    std::vector<std::string> result;

    size_t found = i_str.find(i_delim);
    size_t startIndex = 0;

    while(found != std::string::npos)
    {
        result.push_back(std::string(i_str.begin()+startIndex, i_str.begin()+found));
        startIndex = found + i_delim.size();
        found = i_str.find(i_delim, startIndex);
    }
    if(startIndex != i_str.size())
        result.push_back(std::string(i_str.begin()+startIndex, i_str.end()));
    return result;
}

void Mtmchkin::getPlayers(int number_of_players) {
    std::string name, job, vector;
    for (int i = 0; i < number_of_players; i++) {

        printInsertPlayerMessage();
        do {
            std::getline(std::cin, vector);
            name = split(vector, " ")[0];
            job = split(vector, " ")[1];
            if (!isNameValid(name)) {
                printInvalidName();
                continue;
            }

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

bool isNotAlpha(const char c) {
    return !std::isalpha(c);
}

bool Mtmchkin::isNameValid(const std::string &player_name) {
    return (player_name.length() <= 15 && !std::any_of(player_name.begin(), player_name.end(), isNotAlpha));
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

