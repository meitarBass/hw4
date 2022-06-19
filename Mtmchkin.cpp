#include "Mtmchkin.h"

Mtmchkin::Mtmchkin(const std::string fileName) {
    std::ifstream cardFile;
    cardFile.open(fileName);

    //TODO: Create Deck - from file

    //TODO: Create Player queue - from user

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


