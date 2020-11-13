#include <iostream>
#include <pwd.h>
#include <unistd.h>
#include <libgen.h>


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
            optErr = false;
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
    std::cout << "KML flag is:" << kmlFlag << " Log flag is: " << logFlag << std::endl;
    std::cout << "Count: " << kmlValue << " Log: " << logValue << std::endl;
    std::cout << "optErr:" << optErr << std::endl;

    return EXIT_SUCCESS;
}