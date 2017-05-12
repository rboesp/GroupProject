/*********************************************************************
 ** Author:  David Ackerman
 ** Date:    May 7, 2017
 ** Description:
 *********************************************************************/


#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "RPSGame.hpp"


int main() {
    RPSGame game;
    char strengths;
    cout << "Would you like to change default strengths (y, n)? ";
    cin >> strengths;
    if (strengths == 'y') {
        game.setStrengths();
    }
    bool play = true;
    while (play) {
        play = game.play();
    }
    return 0;
}

