/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RPSGame.hpp
 * Author: david
 *
 * Created on May 7, 2017, 11:33 AM
 */

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "Tool.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"

class RPSGame {
private:
    const static int MAX_STRENGTHS = 10;
    Tool* player;
    Tool* computer;
    int playerStrengths[3];
    int computerStrengths[3];
    int playerWins;
    int computerWins;
    int ties;
	char bestMove;
public:
    RPSGame();
    virtual ~RPSGame();
    void setPlayerTool(char);
    void setComputerTool();
    void setStrengths();
    bool play();
    void getStats();
};

#endif /* RPSGAME_HPP */

