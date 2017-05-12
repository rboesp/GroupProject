/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tool.cpp
 * Author: david
 * 
 * Created on May 7, 2017, 11:14 AM
 */

#include "Tool.hpp"

#include <iostream>
using std::cout;
using std::endl;

Tool::Tool() : Tool(1) {}

Tool::Tool(int str) {
    strength = str;
    type = ' ';
    favored = ' ';
}

Result Tool::fight(Tool* other) {
    double multiplier = 1;
    if (other->getType() == favored) {
        multiplier = 2.0;
    } else if (this->getType() == other->favored) {
        multiplier = 0.5;
    }
    cout << "Player: " << multiplier * strength << endl;
    cout << "Computer: " << other->getStrength() << endl;
    if (multiplier * strength > other->getStrength()) {
        return WIN;
    } else if (multiplier * strength < other->getStrength()) {
        return LOSE;
    } else {
        return DRAW;
    }
}

void Tool::setType(char t) {
    type = t;
}

void Tool::setFavored(char f) {
    favored = f;
}

void Tool::setStrength(int s) {
    strength = s;
}

char Tool::getType() {
    return type;
}

char Tool::getFavored() {
    return favored;
}

int Tool::getStrength() {
    return strength;
}

