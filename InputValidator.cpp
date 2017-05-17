/*******************************************************************************
** Project: 
** Author:  David Ackerman
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

/**
 * getValidInt()
 * 
 * This prompts the user for an integer between lower and upper inclusive from
 * std::cin. If the input does not meet the requirements then the error message
 * is printed, the prompt is reprinted and the program asks again.
 * 
 * @param prompt - the message to be displayed asking for the input
 * @param error - the error message to be displayed on invalid input
 * @param lower - the lower bound of allowed input (inclusive)
 * @param upper - the upper bound of allowed input (inclusive)
 * 
 * @return an integer n, such that lower <= n <= upper.
 */
int getValidInt(string prompt, string error, int lower, int upper) {
    int res;
    string line;
    cout << prompt;
    getline(cin, line);
    try {
        res = stoi(line);    
    } catch (const invalid_argument& ia) {
        cout << error << endl;
        return getValidInt(prompt, error, lower, upper);
    }
    if (res < lower || res > upper
            || to_string(res) != line) {
        cout << error << endl;
        return getValidInt(prompt, error, lower, upper);
    } else {
        return res;
    }
}

/**
 * getAnyInt()
 * 
 * Returns any integer.
 * 
 * @param prompt, message to prompt
 * @param error, error message to print
 * @return any integer.
 */
int getAnyInt(string prompt, string error) {
    return getValidInt(prompt, error,
            std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

/**
 * getValidDouble()
 * 
 * This prompts the user for a double between lower and upper inclusive from
 * std::cin. If the input does not meet the requirements then the error message
 * is printed, the prompt is reprinted and the program asks again.
 * 
 * @param prompt - the message to be displayed asking for the input
 * @param error - the error message to be displayed on invalid input
 * @param lower - the lower bound of allowed input (inclusive)
 * @param upper - the upper bound of allowed input (inclusive)
 * 
 * @return a double n, such that lower <= n <= upper.
 */
double getValidDouble(std::string prompt, string error, double lower, double upper) {
    double res;
    string line;
    cout << prompt;
    getline(cin, line);
    try {
        res = stod(line);    
    } catch (const invalid_argument& ia) {
        cout << error << endl;
        return getValidDouble(prompt, error, lower, upper);
    }
    if (res < lower || res > upper) {
        cout << error << endl;
        return getValidDouble(prompt, error, lower, upper);
    } else {
        return res;
    }
}

/**
 * getValidChar()
 * 
 * This prompts the user for a character from the supplied array of characters.
 * It checks for the input to be one of the characters and if the character
 * does not match it reprompts.
 * 
 * @param prompt - the message to be displayed asking for the input
 * @param error - the error message to be displayed on invalid input
 * @param chars - the array of valid characters
 * @param n - the size of the array
 * 
 * @return a char that is in the array chars
 */
char getValidChar(std::string prompt, string error, char chars[], int n) {
    string res;
    cout << prompt;
    getline(cin, res);
    if (res.length() != 1) {
        cout << error << endl;
        return getValidChar(prompt, error, chars, n);
    } else {
        bool inArray = false;
        for (int i = 0; i < n; i++) {
            if (res[0] == chars[i]) {
                inArray = true;
            }
        }
        if(!inArray) {
            cout << error << endl;
            return getValidChar(prompt, error, chars, n);
        } else {
            return res[0];
        }
    }
}

//getYorN gets a 'y' or 'n' answer.
char getYorN(std::string prompt, string error) {
    char chars[] = {'y', 'n'};
    return getValidChar(prompt, error, chars, 2);
}