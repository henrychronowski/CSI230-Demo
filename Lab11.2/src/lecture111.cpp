/**
 * @file lecture111.cpp
 * @brief Code demonstrating the program_options library and the chrono library
 * 
 * @author Henry Chronowski
 * @assignment Lab 11.2
 * @date 19/11/2020
 * @credits Lecture 11.2
 * https://www.boost.org/doc/libs/1_71_0/doc/html/chrono.html
 * https://www.boost.org/doc/libs/1_71_0/doc/html/program_options.html
 * 
 **/

#include <boost/program_options.hpp>
#include <boost/chrono/include.hpp>
#include <iostream>
#include <iomanip>
#include <chrono>

using namespace boost::program_options;

const double NUMBER = 289.7773;
const double TO_SECONDS = 0.00000001;

int main(int argc, const char *argv[])
{
  try
  {
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("it", value<long>()->default_value(100), "Iterations");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("it"))
    {
      long i;

      // Run a for loop and time it with the stl timer
      auto startTime = std::chrono::high_resolution_clock::now();
      for( i = 0; i < vm["it"].as<long>(); i++)
      {
        std::sqrt(NUMBER);
      }
      auto secondsPassed = std::chrono::high_resolution_clock::now() - startTime;

      // Run a for loop and time it with the chrono timer
      boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
      for( i = 0; i < vm["it"].as<long>(); i++)
      {
        std::sqrt(NUMBER);
      }
      boost::chrono::duration<double> dt = boost::chrono::system_clock::now() - start;

      // Output results
      std::cout << "Iterations: " << vm["it"].as<long>() << '\n';
      std::cout << "Boost timer: " << dt << std::endl;
      std::cout << "STL timer: " << std::fixed << std::setprecision(5) << secondsPassed.count() * TO_SECONDS << " seconds\n";
    }
      
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}