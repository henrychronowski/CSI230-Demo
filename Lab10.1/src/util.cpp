/**
 * @file util.cpp
 * @brief Contains function definitions for util.h
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.1
 * @date 09/11/2020
 * @credits
 * 
 **/

#include "util.h"

std::string randomElement(std::vector<std::string>& rVector)
{
    return rVector.at(rand() % rVector.size());
}

double sum(std::vector<double>& lhs)
{
    double result = 0.0;
    for(auto iter : lhs)
    {
        result += iter;
    }
    return result;
}

double avg(std::vector<double>& lhs)
{
    double result = 0.0;
    int it = 0;

    for(auto iter:lhs) 
    {
        result += iter;
        it++;
    }

    return result / static_cast<double>(it);
}

double lowest(std::vector<double>& lhs)
{
    double result = __DBL_MAX__;

    for(auto iter:lhs)
    {
        if(iter < result)
            result = iter;
    }

    return result;
}

std::string camelCase(std::string&s)
{
    int endIndex = 0;
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            s[i+1] = toupper(s[i+1]);
            continue;
        }
        else
        {
            s[endIndex++] = s[i];
        }
    }
    s[0] = tolower(s[0]);

    return s.substr(0, endIndex);
}