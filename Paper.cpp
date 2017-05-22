/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the Paper class function implementation file. 
 *************************************************************************************/

#include "Paper.hpp"


//default constructor 
Paper::Paper() : Paper(1) {}


//constructor
Paper::Paper(int str) : Tool(str) {
    setType('p');
    setFavored('r');
}
