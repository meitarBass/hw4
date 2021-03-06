//
// Created by Meitar Basson on 16/05/2022.
//

#include "Player.h"
#include "../utilities.h"

static bool CheckParamValidity(int param, int minimum) {
    return param >= minimum;
}

Player::Player(std::string name, PLAYER_TYPE type) : type(type) {
    this->name = name;
    this->hp = 100;
    this->max_hp = 100;
    this->force = 5;
    this->coins = 10;
    this->level = 1;
}

Player::~Player() = default;

Player::Player(const Player& player):
        force(player.force),
        hp(player.max_hp),
        max_hp(player.max_hp),
        name(player.name) {}


void Player::printInfo() {
    std::cout << "Player Details:" << std::endl <<
         "Name: "<< this->name << std::endl <<
         "Level: " << this->level << std::endl <<
         "Force: " << this->force << std::endl <<
         "HP: " << this->hp << std::endl <<
         "Coins: " << this->coins << std::endl <<
         "------------------------"<< std::endl;
}

void Player::levelUp() {
    if(this->level < 10) {
        this->level += 1;
    }
}

int Player::getLevel() const {
    return this->level;
}

void Player::buff(int amount) {
    if(CheckParamValidity(amount, 1)) {
        this->force += amount;
    }
}

void Player::heal(int amount) {
    if(CheckParamValidity(amount, 1)) {
        if (this->hp + amount < this->max_hp) {
            this->hp += amount;
        } else {
            this->hp = this->max_hp;
        }
    }
}

void Player::damage(int amount) {
    if(CheckParamValidity(amount, 1)){
        if(this->hp - amount > 0) {
            this->hp -= amount;
        } else {
            this->hp = 0;
        }
    }
}

bool Player::isKnockedOut() const {
    return this->hp == 0;
}

void Player::addCoins(int amount) {
    if(CheckParamValidity(amount, 1)) {
        this->coins += amount;
    }
}

bool Player::pay(int amount) {
    if(this->coins >= amount) {
        if (amount > 0) {
            this->coins -= amount;
        }
        return true;
    }
    return false;
}

int Player::getAttackStrength() const {
    return this->force + this->level;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    std::string job;
    switch (player.getType()){
        case FIGHTER:
            job = "Fighter";
            break;
        case WIZARD:
            job = "Wizard";
            break;
        case ROGUE:
            job = "Rogue";
            break;
    }
    printPlayerDetails(os, player.getName(), job, player.getLevel(), player.force, player.getHP(), player.getCoins());
    return os;
}

PLAYER_TYPE Player::getType() const{
    return this->type;
}

std::string Player::getName() const{
    return this->name;
}

void Player::forceDown() {
    if(this->force > 0) {
        this->force -= 1;
    }

}

const int Player::getHP() const{
    return this->hp;
}

const int Player::getCoins() const{
    return this->coins;
}

bool Player::isStillPlaying() const {
    return !(isKnockedOut() || getLevel() == 10);
}