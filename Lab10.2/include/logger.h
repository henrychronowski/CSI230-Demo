/**
 * @file logger.h
 * @brief handles the declaration of all logging functionality
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.2
 * @date 12/11/2020
 * @credits Lecture 10.2
 * 
 **/

#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>


// Creates a syslog message based on input
bool log(std::string msg, std::string programName, std::ofstream& logFile);

#endif