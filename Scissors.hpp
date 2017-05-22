/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the Scissors class header file. 
 *************************************************************************************/

#ifndef SCISSORS_HPP
#define SCISSORS_HPP

#include "Tool.hpp"

/************************************************************
* Description: This is the Scissors class. This is a derived
* class from the base class Tool. This class represents the 
* 'scissors' tool in the rock, paper, scissors game.
************************************************************/
class Scissors : public Tool { 
public:
    Scissors();
    Scissors(int str);
};


#endif /* SCISSORS_HPP */

