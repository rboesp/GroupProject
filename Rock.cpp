/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the Rock class function implementation file. 
 *************************************************************************************/

#include "Rock.hpp"


//default constructor
Rock::Rock() : Rock(1) {}


//constructor
Rock::Rock(int str) : Tool(str) {
    setType('r');
    setFavored('s');
}