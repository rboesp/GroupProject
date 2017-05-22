/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the Tool class function implementation file. 
 *************************************************************************************/

#include "Tool.hpp"

#include <iostream>
using std::cout;
using std::endl;


//default constructor
Tool::Tool() : Tool(1) {}

//constructor
Tool::Tool(int str) {
    strength = str;
    type = ' ';
    favored = ' ';
}


/************************************************************
* Description: This is the the fight function. This function
* accepts a pointer to a Tool and returns an enum/int 
* representing the result of the rock, paper, scissors fight.
************************************************************/
Result Tool::fight(Tool* other) 
{
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


//setter
void Tool::setType(char t) {
    type = t;
}


//setter
void Tool::setFavored(char f) {
    favored = f;
}


//setter
void Tool::setStrength(int s) {
    strength = s;
}

//getter
char Tool::getType() {
    return type;
}

//getter
char Tool::getFavored() {
    return favored;
}


//getter
int Tool::getStrength() {
    return strength;
}

