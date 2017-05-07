/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RPSGame.cpp
 * Author: david
 * 
 * Created on May 7, 2017, 11:33 AM
 */

#include "RPSGame.hpp"

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <cstdlib>
using std::rand;
using std::srand;

#include <time.h>

RPSGame::RPSGame() {
    player = NULL;
    computer = NULL;
    srand(time(0));
    for (int i = 0; i < 3; i++) {
        playerStrengths[i] = 1;
        computerStrengths[i] = 1;
    }
    playerWins = 0;
    computerWins = 0;
    ties = 0;
}

RPSGame::~RPSGame() {
    delete player;
    delete computer;
}

void RPSGame::setStrengths() {
    cout << "You have " << MAX_STRENGTHS << " points to allocate amongst your tools" << endl;
    cout << "How many points for rock? " << endl;
    cin >> playerStrengths[0];
    cout << "How many points for paper? " << endl;
    cin >> playerStrengths[1];
    cout << "How many points for scissors? " << endl;
    cin >> playerStrengths[2];
    //TODO add input validation
    
    //Set computer strengths
    int totalStrengths = MAX_STRENGTHS;
    int startIdx = rand() % 3;
    for (int i = 0; i < 2; i++) {
        int current = (i + startIdx) % 3;
        computerStrengths[current] = rand() % (totalStrengths + 1);
        totalStrengths -= computerStrengths[current];
    }
    computerStrengths[(startIdx + 2) % 3] = totalStrengths;
}

void RPSGame::setPlayerTool(char type) {
    delete player;
    if (type == 'r') {    
        player = new Rock(playerStrengths[0]);
    } else if (type == 'p') {
        player = new Paper(playerStrengths[1]);
    } else {
        player = new Scissors(playerStrengths[2]);
    }
}

/**
 * Picks a random tool for the computer.
 * 
 * TODO smart game theory AI (EXTRA)
 */
void RPSGame::setComputerTool() {
    delete computer;
    int tool = rand() % 3;
    if (tool == 0) {
        computer = new Rock(computerStrengths[0]);
    } else if (tool == 1) {
        computer = new Paper(computerStrengths[1]);
    } else {
        computer = new Scissors(computerStrengths[2]);
    }
}

void RPSGame::getStats() {
    cout << "Player wins: " << playerWins << endl;
    cout << "Computer wins: " << computerWins << endl;
    cout << "Ties: " << ties << endl << endl;
}

bool RPSGame::play() {
    char option;
    cout << "Choose your tool (r-rock, p-paper, s-scissors, e-exit): ";
    cin >> option;
    //TODO input validation
    if (option != 'e') {
        setPlayerTool(option);
        setComputerTool();
        Result res = player->fight(computer);
        cout << "Computer chose " << computer->getType() << endl;
        //TODO display string
        if (res == WIN) {
            cout << "Player wins!" << endl;
            playerWins++;
        } else if (res == LOSE) {
            cout << "Computer wins!" << endl;
            computerWins++;
        } else {
            cout << "Tie!" << endl;
            ties++;
        }
        getStats();
        return true;
    }
    return false;
}