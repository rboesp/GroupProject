/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the Paper class function header file.
 *************************************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

#include "Tool.hpp"


/************************************************
* Description: This is the Paper class. This is 
* a derived class from the base class Tool. This 
* class represents the 'paper' tool in the rock,
* paper, scissors simulation. 
************************************************/
class Paper : public Tool { 
public:
    Paper();
    Paper(int str);
};


#endif /* PAPER_HPP */

