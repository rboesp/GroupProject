/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tool.hpp
 * Author: david
 *
 * Created on May 7, 2017, 11:14 AM
 */

#ifndef TOOL_HPP
#define TOOL_HPP

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
    //pure Virtual function?
};

#endif /* TOOL_HPP */

