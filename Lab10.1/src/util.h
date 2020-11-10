#ifndef UTIL_H
#define UTIL_H

/**
 * @file util.h
 * @brief Contains constants and forward declarations
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.1
 * @date 09/11/2020
 * @credits
 * 
 **/

#include<vector>
#include<string>

// Returns a random element of a given string vector
std::string randomElement(std::vector<std::string>&);

// Returns sum of doubles in the given vector
double sum(std::vector<double>&);

// Returns the average of doubles in the given vector
double avg(std::vector<double>&);

// Returns the lowest double in the given vector
double lowest(std::vector<double>&);

// Returns the given string converted to camelCase
std::string camelCase(std::string&);

#endif