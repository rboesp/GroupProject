/*************************************************************************************
 ** Program Name: Rock, Paper, Scissors
 **	Author:  	  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
 ** Date:         May 7, 2017
 ** Description:  This is the Tool class header file. 
 *************************************************************************************/

#ifndef TOOL_HPP
#define TOOL_HPP

/************************************************************
* Description: This is the Tool class. This class holds the  
characteristics that all the  tool in the rock, paper, scissors 
simulation have in common. 
************************************************************/
enum Result{WIN, LOSE, DRAW};

class Tool {
private:
    char type;
    char favored;
    int strength;
public:
    Tool();
    Tool(int str);
    void setType(char);
    void setFavored(char);
    void setStrength(int);
    char getType();
    char getFavored();
    int getStrength();
    Result fight(Tool*);
 
};

#endif /* TOOL_HPP */

