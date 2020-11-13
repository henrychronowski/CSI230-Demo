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
#include <iostream>
int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    std::string strCountry, strCapital, strLat, strLong;
    std::string strLine;
    int recordCount = 0;
    //set records written to 0
    // if infile doesn't exist return records written
    // if it does exist
    // create the kml file
    // write the header out
    // read each line in the inFile, skipping first one
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
            //std::cout << strCountry << "~" << strCapital << "~" << strLat << "~" << strLong << std::endl;
            // Write placemark to kml file
            kmlOut << PLACEMARK_HEAD << strCapital << ", " << strCountry << PLACEMARK_MID << strLat << "," << strLong << PLACEMARK_FOOT;
            recordCount++;
        }
        //std::cout << strLine << std::endl;
        // Write footer to kml file and close file
        kmlOut << KML_FOOTER;
        kmlOut.close();
    }
    else
    {
        return recordCount;
    }
    
    // call the writeplacemark function to create a record
    // increment the count of records
    // write any footer out
    // return the record count
    return recordCount;
}

void writePlacemark(std::ofstream&kmlFile, std::string name, std::string latitude, std::string longitude)
{

}