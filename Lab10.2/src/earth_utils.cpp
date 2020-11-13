/**
 * @file earth_utils.cpp
 * @brief handles function definitions for earth_utils.h
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.2
 * @date 12/11/2020
 * @credits Lecture 10.2
 * 
 **/

#include "earth_utils.h"
#include <sstream>

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount = 0;

    if(inFile)
    {
        // open output file and write header
        std::ofstream kmlOut;
        kmlOut.open(kmlFileName);
        kmlOut << KML_HEADER;

        getline(inFile, strLine);  //Skip first line
        while(getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            getline(s_stream, strCountry, ',');
            getline(s_stream, strCapital, ',');
            getline(s_stream, strLat, ',');
            getline(s_stream, strLong, ',');

            // Write placemark to kml file
            writePlacemark(kmlOut, strCapital + ", " + strCountry, strLong + "," + strLat);
            recordCount++;
        }

        // Write footer to kml file and close file
        kmlOut << KML_FOOTER;
        kmlOut.close();
    }
    else
    {
        return recordCount;
    }
    
    // return the record count
    return recordCount;
}

void writePlacemark(std::ofstream&kmlFile, std::string name, std::string coord)
{
    kmlFile << PLACEMARK_HEAD << name << PLACEMARK_MID << coord << PLACEMARK_FOOT;
}