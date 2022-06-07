//
// Created by Meitar Basson on 16/05/2022.
//

#include "Player.h"

static bool CheckParamValidity(int param, int minimum) {
    return param >= minimum;
}

Player::Player(string name, int hp, int force) {
    this->name = name;

    if(!CheckParamValidity(hp, 1)) {
        hp = 100;
    }
    if(!CheckParamValidity(force, 1)) {
        force = 5;
    }
    this->hp = hp;
    this->max_hp = hp;
    this->force = force;
}

Player::~Player() = default;

Player::Player(const Player& player):
        force(player.force),
        hp(player.max_hp),
        max_hp(player.max_hp),
        name(player.name) {}


void Player::printInfo() {
    cout << "Player Details:" << endl <<
         "Name: "<< this->name << endl <<
         "Level: " << this->level << endl <<
         "Force: " << this->force << endl <<
         "HP: " << this->hp << endl <<
         "Coins: " << this->coins << endl <<
         "------------------------"<< endl;
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
