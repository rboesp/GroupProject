/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the RPSGame class header file. 
 *************************************************************************************/

#ifndef RPSGAME_HPP
#define RPSGAME_HPP

#include "InputValidator.hpp"
#include "Tool.hpp"
#include "Rock.hpp"
#include "Paper.hpp"
#include "Scissors.hpp"

/***************************************************************
* Description: This is the RPSGame class. This class represents
* an controls the rock, paper, scissors simulation/game. 
***************************************************************/
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

