/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the Rock class header file.
 *************************************************************************************/

#ifndef ROCK_HPP
#define ROCK_HPP

#include "Tool.hpp"


/************************************************
* Description: This is the Rock class. This is 
* a derived class from the base class Tool. This 
* class represents the 'Rock' tool in the rock,
* paper, scissors simulation. 
************************************************/
class Rock : public Tool { 
public:
    Rock();
    Rock(int str);
};

#endif /* ROCK_HPP */

