/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Paper.cpp
 * Author: david
 * 
 * Created on May 7, 2017, 12:24 PM
 */

#include "Paper.hpp"

Paper::Paper() : Paper(1) {}

Paper::Paper(int str) : Tool(str) {
    setType('p');
    setFavored('r');
}
