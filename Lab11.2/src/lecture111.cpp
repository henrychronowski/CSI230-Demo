/**
 * @file 102.cpp
 * @brief Driver code for lab 10.2
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.2
 * @date 12/11/2020
 * @credits Lecture 11.2
 * https://www.boost.org/doc/libs/1_71_0/doc/html/chrono.html
 * https://www.boost.org/doc/libs/1_71_0/doc/html/program_options.html
 * 
 **/

#include <boost/program_options.hpp>
#include <boost/chrono/include.hpp>
#include <iostream>

using namespace boost::program_options;

void on_age(int age)
{
  std::cout << "On age: " << age << '\n';
}

int main(int argc, const char *argv[])
{
  try
  {
      boost::chrono::system_clock::time_point start = boost::chrono::system_clock::now();
    options_description desc{"Options"};
    desc.add_options()
      ("help,h", "Help screen")
      ("pi", value<float>()->default_value(3.14f), "Pi")
      ("age", value<int>()->notifier(on_age), "Age");

    variables_map vm;
    store(parse_command_line(argc, argv, desc), vm);
    notify(vm);

    if (vm.count("help"))
      std::cout << desc << '\n';
    else if (vm.count("age"))
      std::cout << "Age: " << vm["age"].as<int>() << '\n';
    else if (vm.count("pi"))
      std::cout << "Pi: " << vm["pi"].as<float>() << '\n';

    boost::chrono::duration<double> sec = boost::chrono::system_clock::now() - start;
    std::cout << sec << std::endl;
  }
  catch (const error &ex)
  {
    std::cerr << ex.what() << '\n';
  }
}