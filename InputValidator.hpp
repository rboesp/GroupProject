/*******************************************************************************
** Project: 
** Author:  David Ackerman
** Date:    April 7th, 2017
** File:    InputValidator.hpp
** Description: This file is the header file for the InputValidator class.
 * 
 * The InputValidator currently has three methods for getting input from the user.
 * Each method is responsible for prompting and reprompting the user until
 * a valid input is received. For example:
 * 
 * getValidInt takes a prompt, and error, and two integers as parameters. The 
 * first integer is the lower bound and the second integer is the upper bound.
 * It will prompt first and get input from the user through std::cin. If the input
 * is less than lower or greater than upper it will reprompt or is not a valid
 * integer it will print the error message and reprompt.
*******************************************************************************/

#ifndef INPUTVALIDATOR_HPP
#define INPUTVALIDATOR_HPP

#include <string>
#include <iostream>

int getValidInt(std::string prompt, std::string error, int lower, int upper);
int getAnyInt(std::string prompt, std::string error);
double getValidDouble(std::string prompt, std::string error, double lower, double upper);
char getValidChar(std::string prompt, std::string error, char chars[], int n);
char getYorN(std::string prompt, std::string error);

#endif /* INPUTVALIDATOR_HPP */
