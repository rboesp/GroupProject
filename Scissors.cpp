/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the scissors class function implementation file. 
 *************************************************************************************/

#include "Scissors.hpp"

//default constructor
Scissors::Scissors() : Scissors(1) {}


//constructor
Scissors::Scissors(int str) : Tool(str) {
    setType('s');
    setFavored('p');
}

