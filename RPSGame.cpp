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

#include <string>
using std::to_string;
using std::string;

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
    int strengthLeft = MAX_STRENGTHS;
    string tools[] = {"rock", "paper", "scissors"};
    cout << "You have " << MAX_STRENGTHS << " points to allocate amongst your tools" << endl;
    for (int i = 0; i < 2; i++) {
        playerStrengths[i] = getValidInt("How many points for " + tools[i] + "? ",
                "Error. Must be between 0 and " + to_string(strengthLeft), 0, strengthLeft);
        strengthLeft -= playerStrengths[i];
        cout << "You have " << strengthLeft << " points left." << endl;
    }
    cout << "Scissors gets " << strengthLeft << " points." << endl;
    playerStrengths[2] = strengthLeft;
    
    
    //set computer strengths
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
    char options[] = {'r', 'p', 's', 'e'};
    char choice = getValidChar("Choose your tool (r-rock, p-paper, s-scissors, e-exit): ",
            "Invalid choice.", options, 4);
    if (choice != 'e') {
        setPlayerTool(choice);
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