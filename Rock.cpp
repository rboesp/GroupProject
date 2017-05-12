/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Rock.cpp
 * Author: david
 * 
 * Created on May 7, 2017, 11:20 AM
 */

#include "Rock.hpp"

Rock::Rock() : Rock(1) {}

Rock::Rock(int str) : Tool(str) {
    setType('r');
    setFavored('s');
}