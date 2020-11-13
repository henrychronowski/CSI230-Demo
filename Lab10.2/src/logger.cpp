/**
 * @file logger.cpp
 * @brief handles function definitions for logger.cpp
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.2
 * @date 12/11/2020
 * @credits Lecture 10.2
 * 
 **/
#include "logger.h"

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    std::string strTime;

    // Get time and remove newline
    time_t logTime = time(0);
    strTime = ctime(&logTime);
    int timeSize = strTime.size();
    if(timeSize)
    {
        strTime[timeSize-1] = ' ';
    }

    // get pid
    pid_t pid = getpid();
    //get hostname
    char *temp = new char[512];
    gethostname(temp, 512);
    std::string strHostName = temp;

    if(logFile)
    {
        //write log
        logFile << strTime << strHostName << " " << programName << "[" << pid << "]: " << msg << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    

}