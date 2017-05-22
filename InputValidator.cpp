/*******************************************************************************
** Project: Rock, Paper, Scissors
** Author:  David Ackerman, Kirsten Wollam, Trevor Bergstrom, Robert Boespflug
** Date:    April 7th, 2017
** File:    InputValidator.cpp
** Description: This file is the implementation for the InputValidator class.
*******************************************************************************/

#include "InputValidator.hpp"
using std::string;
using std::cout;
using std::endl;
using std::cin;

using std::stoi;
using std::stod;
using std::to_string;
using std::getline;

#include <stdexcept>
using std::invalid_argument;

#include <limits>


/************************************************************************************
 * This is the getValidInt() function. This function accepts two string arguments 
 * and two integer arguments and returns an integer. This function prompts the user 
 * for an integer between lower and upper inclusive  from std::cin. If the input 
 * does not meet the requirements then the error message is printed, the prompt is 
 * reprinted and the program asks again.
 *
 * @param prompt - the message to be displayed asking for the input
 * @param error - the error message to be displayed on invalid input
 * @param lower - the lower bound of allowed input (inclusive)
 * @param upper - the upper bound of allowed input (inclusive)
 * 
 * @return an integer n, such that lower <= n <= upper.
 ***********************************************************************************/
int getValidInt(string prompt, string error, int lower, int upper) {
	
    int res;
    string line;
    cout << prompt;
	
	//get input from user
    getline(cin, line);
	
	//check if integer
    try {
        res = stoi(line);    
    } 
	
	//not a valid integer
	catch (const invalid_argument& ia) {
        cout << error << endl;
        return getValidInt(prompt, error, lower, upper);
    }
	
	//not a valid integer
    if (res < lower || res > upper
            || to_string(res) != line) {
        cout << error << endl;
        return getValidInt(prompt, error, lower, upper);
    } 
	
	//else a valid integer
	else {
        return res;
    }
}


/*******************************************************************************
 * This is the getAnyInt() function. This function accepts two string arguments
 * and returns any integer, using the <limits> header file.
 * 
 * @param prompt, message to prompt
 * @param error, error message to print
 
 * @return any integer.
 ******************************************************************************/
int getAnyInt(string prompt, string error) {
	
	//call getValidInt() with upper and lower arguments
    return getValidInt(prompt, error,
            std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
			
}


/***********************************************************************************
 * This is the getValidDouble() function. The function accepts two string arguments
 * and two double arguments and returns a double. This function prompts the user for 
 * a double between lower and upper inclusive from std::cin. If the input does not 
 * meet the requirements then the error message is printed, the prompt is reprinted 
 * and the program asks again.
 * 
 * @param prompt - the message to be displayed asking for the input
 * @param error - the error message to be displayed on invalid input
 * @param lower - the lower bound of allowed input (inclusive)
 * @param upper - the upper bound of allowed input (inclusive)
 * 
 * @return a double n, such that lower <= n <= upper.
 ******************************************************************************/
double getValidDouble(std::string prompt, string error, double lower, double upper) {
	
    double res;
    string line;
    cout << prompt;
	
	//get input from user
    getline(cin, line);
	
	//check if user input is a valid double
    try {
        res = stod(line);    
    } 
	
	//if not valid double
	catch (const invalid_argument& ia) {
        cout << error << endl;
        return getValidDouble(prompt, error, lower, upper);
    }
	
	//if not a valid double
    if (res < lower || res > upper) {
        cout << error << endl;
        return getValidDouble(prompt, error, lower, upper);
    } 
	
	//else a valid double
	else {
        return res;
    }
}


/**************************************************************************************
 * This is the getValidChar() function. This function prompts the user for a character 
 * from the supplied array of characters. The function checks for the input to be one 
 * of the characters and if the character does not match it reprompts. This function
 * accepts two string arguments, one character argument, and one integer argument. The
 * function returns a character that represents the valid user choice.
 *
 * @param prompt - the message to be displayed asking for the input
 * @param error - the error message to be displayed on invalid input
 * @param chars - the array of valid characters
 * @param n - the size of the array
 * 
 * @return a char that is in the array chars
 ************************************************************************************/
char getValidChar(std::string prompt, string error, char chars[], int n) {
	
    string res;
    cout << prompt;
	
	//get input from user
    getline(cin, res);
	
	//check if valid char
    if (res.length() != 1) {
        cout << error << endl;
        return getValidChar(prompt, error, chars, n);
    } else {
        bool inArray = false;
		
		//if valid
        for (int i = 0; i < n; i++) {
            if (res[0] == chars[i]) {
                inArray = true;
            }
        }
		
		//if not a valid char
        if(!inArray) {
            cout << error << endl;
            return getValidChar(prompt, error, chars, n);
        } else {
            return res[0];
        }
    }
}


/************************************************************
* Description: This is the getYorN function. This function 
* accepts two string arguments and returns a character 
* representing the user choice.
************************************************************/
char getYorN(std::string prompt, string error) {
    char chars[] = {'y', 'n'};
    return getValidChar(prompt, error, chars, 2);
}