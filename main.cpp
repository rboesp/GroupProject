/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is a rock, paper, scissors simulation. There is one
 **				  user who plays against the computer. 
 *************************************************************************************/


#include <iostream>
using std::cout;
using std::endl;

#include "RPSGame.hpp"
#include "InputValidator.hpp"

//main function
int main() {
	
	//create a rock, paper, scissors game object
    RPSGame game;
	
	
	//prompt user to change default tool strengths
    char strengths = getYorN("Would you like to change default strengths (y, n)? ",
            "Invalid choice.");
			
    if (strengths == 'y') {
        game.setStrengths();
    }
	
	//while user has not hit exit, play the game
    bool play = true;
    while (play) {
        play = game.play();
    }
	
    return 0;
}

