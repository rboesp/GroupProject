/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scissors.cpp
 * Author: david
 * 
 * Created on May 7, 2017, 12:24 PM
 */

#include "Scissors.hpp"

Scissors::Scissors() : Scissors(1) {}

Scissors::Scissors(int str) : Tool(str) {
    setType('s');
    setFavored('p');
}

