/**
 * @file 102.cpp
 * @brief Driver code for lab 10.2
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.2
 * @date 12/11/2020
 * @credits Lecture 10.2
 * 
 **/

#include <iostream>
#include <pwd.h>
#include <libgen.h>
#include "logger.h"


int main(int argc, char* argv[]) 
{
    int opt{};
    bool kmlFlag{false};
    bool logFlag{false};
    std::string kmlValue;
    std::string logValue;
    bool optErr = true;

    while((opt = getopt(argc, argv, "k:l:")) != EOF)
    {
        switch (opt)
        {
        case 'k':
            kmlFlag = true;
            kmlValue = optarg;
            break;
        case 'l':
            logFlag = true;
            logValue = optarg;
            break;
        default:
        optErr = true;
            break;
        }
    }

    if(kmlFlag && logFlag) 
    {
        std::cout << "flags set!\n";
        if(logValue.empty() || kmlValue.empty())
        {
            optErr = true;
            std::cout << "option arguments are not set\n";
        }
        else
        {
            std::ofstream flog;
            flog.open(logValue, std::ios_base::app);
            if(flog)
            {
                std::string programName = basename(argv[0]);
                std::string msg = "kmlfile: " + kmlValue + " Log: " + logValue;
                log(msg, programName, flog);
                optErr = false;
                flog.close();
            }
            else
            {
                std::cout << "couldn't open " << logValue << std::endl;
                optErr = true;
            }
        }
        
    }
    else
    {
        std::cout << "error - flags are not set!\n";
        optErr = true;
    }

    if(optErr)
    {
        return EXIT_FAILURE;
    }

    

    std::cout << "kml flag is:" << kmlFlag << " Log flag is: " << logFlag << std::endl;
    std::cout << "kmlfile: " << kmlValue << " Log: " << logValue << std::endl;
    std::cout << "optErr:" << optErr << std::endl;

    return EXIT_SUCCESS;
}