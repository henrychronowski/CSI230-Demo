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

#include <boost/lambda/lambda.hpp>
#include <iterator>
#include <iostream>
#include <algorithm>

int main()
{
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " ");


    return EXIT_SUCCESS;
}