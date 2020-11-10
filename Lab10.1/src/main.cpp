/**
 * @file main.cpp
 * @brief Lab 10.1 C++ review driver
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.1
 * @date 09/11/2020
 * @credits
 * 
 **/


#include <iostream>
#include <vector>

#include "util.h"

int main() 
{
    srand(time(NULL));
    std::vector<std::string> stringVector = {"red", "orange", "yellow", "green", "blue", "indigo", "violet"};
    std::vector<double> doubleVector = {1.3, 2.7, 5.9, 6.3, 8.4, 6.4, 3.7};
    std::string sentence = "A little bird with a yellow bill";

    // String vector work
    std::cout << "String Vector: ";
    for(auto iter : stringVector) 
    {
        std::cout << iter << " ";
    }
    std::cout << "\nRandom Element: " << randomElement(stringVector) << std::endl;

    // Double vector work
    std::cout << "Double Vector: ";
    for(auto iter : doubleVector)
    {
        std::cout << iter << " ";
    }
    std::cout << "\nsum: " << sum(doubleVector) << std::endl;
    std::cout << "avg: " << avg(doubleVector) << std::endl;
    std::cout << "lowest: " << lowest(doubleVector) << std::endl;

    // String work
    std::cout << "Pre camel case: " << sentence << std::endl;
    std::cout << "Post camel case: " << camelCase(sentence) << std::endl;



    return 0;
}