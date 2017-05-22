/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the RPSGame class function implentation file.
 *************************************************************************************/

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


//constructor
RPSGame::RPSGame() {
	
	//initialize ptr's to null
    player = NULL;
    computer = NULL;
	
	//seed random element
    srand(time(0));
	
	//initialize RPSGame attributes
    for (int i = 0; i < 3; i++) {
        playerStrengths[i] = 1;
        computerStrengths[i] = 1;
    }
    playerWins = 0;
    computerWins = 0;
    ties = 0;
	bestMove = 'r';
}


//destructor 
RPSGame::~RPSGame() {
	
	//de-allocates memory
    delete player;
    delete computer;
}



/******************************************************************
* Description: This is the setStrengths() setter function. This 
* void function accepts no arguments and sets the strengths of 
* the rock, paper, and scissor tools if the user decides to change
* the default strengths of the tools. 
******************************************************************/
void RPSGame::setStrengths() {
	
	//variable holds points left to allocate 
	//amongst remaining tools
    int strengthLeft = MAX_STRENGTHS;
	
	//initialize tools array
    string tools[] = {"rock", "paper", "scissors"};
	
	//print user prompt
    cout << "You have " << MAX_STRENGTHS << " points to allocate amongst your tools" << endl;
	
	//set tool strengths to user input, starting with first index of tools array
    for (int i = 0; i < 2; i++) {
        playerStrengths[i] = getValidInt("How many points for " + tools[i] + "? ",
                "Error. Must be between 0 and " + to_string(strengthLeft), 0, strengthLeft);
        strengthLeft -= playerStrengths[i];
        cout << "You have " << strengthLeft << " points left." << endl;
    }
	
	//last tools array element gets points left
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



/************************************************************
* Description: This is the setPlayerTool() setter function. 
* This void function accepts a character argument and sets
* the player tool to the user input.
************************************************************/
void RPSGame::setPlayerTool(char type) {
	
    delete player;
	
	//if user picks to play with rock
    if (type == 'r') {    
        player = new Rock(playerStrengths[0]);
		
	//else if user picks to play with paper
    } else if (type == 'p') {
        player = new Paper(playerStrengths[1]);
		
	//else user picks to play with scissors
    } else {
        player = new Scissors(playerStrengths[2]);
    }
}



/**********************************************************
 * This is the setComputerTool() setter function. This void 
 * function accepts no arguments and picks a weighted 
 * random tool for the computer. 50% chance to pick the 
 * "best move" which is whatever the computer was favored 
 * against in the previous round. 25% chance to select
 * either of the other tool options. 
 *********************************************************/
void RPSGame::setComputerTool() {
	
   delete computer;
   
   //have computer get random int between 1 and 3
   int tool = rand() % 4;
   
   cout << "rand: " << tool;
   
   //if computer picks scissors
   if (tool == 3){
        if (bestMove == 'r'){
            tool = 0;
        } else if (bestMove == 'p'){
			tool = 1;
        }
    }
	
    cout << "tool" << tool << endl;
	
	//if computer picks rock
    if (tool == 0) {
        computer = new Rock(computerStrengths[0]);
		bestMove = 's';
	
	//else if computer picks paper
    } else if (tool == 1) {
        computer = new Paper(computerStrengths[1]);
		bestMove = 'r';
    } else {
        computer = new Scissors(computerStrengths[2]);
		bestMove = 'p';
    }
}



//getter function prompts round results
void RPSGame::getStats() {
    cout << "Player wins: " << playerWins << endl;
    cout << "Computer wins: " << computerWins << endl;
    cout << "Ties: " << ties << endl << endl;
}



/******************************************************************
* Description: This is the play function. This function accepts
* no arguments and returns a bool variable. This function controls
* a round of the rock, paper, scissors game against the comuter. 
* The function outputs the winner and stats the the screen, unless
* the user has picked to exit.
******************************************************************/
bool RPSGame::play() {
	
	//print user menu
    char options[] = {'r', 'p', 's', 'e'};
	
	//validate user input
    char choice = getValidChar("Choose your tool (r-rock, p-paper, s-scissors, e-exit): ",
            "Invalid choice.", options, 4);
			
	//if user does not pick to exit
    if (choice != 'e') {
		
		//set user choice
        setPlayerTool(choice);
		
		//set random computer choice
        setComputerTool();
		
		//play rock, paper, scissors against
		//computer, declare res, and assign
		//result of round to res
        Result res = player->fight(computer);
		
		//print computer choice
        cout << "Computer chose " << computer->getType() << endl;
		
		
        //if player wins
        if (res == WIN) {
            cout << "Player wins!" << endl;
            playerWins++;
		
		//else if computer wins
        } else if (res == LOSE) {
            cout << "Computer wins!" << endl;
            computerWins++;
			
		//else tie
        } else {
            cout << "Tie!" << endl;
            ties++;
        }
		
		//print the stats
        getStats();
		
        return true;
    }
	
	//else user picks to exit
    return false;
}