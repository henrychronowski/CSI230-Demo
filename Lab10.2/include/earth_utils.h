/**
 * @file earth_utils.h
 * @brief handles parsing a lat/long csv file and converting it into a kml format
 * 
 * @author Henry Chronowski
 * @assignment Lab 10.2
 * @date 12/11/2020
 * @credits Lecture 10.2
 **/

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include<string>
#include<fstream>

const std::string KML_HEADER = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<kml xmlns=\"http://www.opengis.net/kml/2.2\">\n<Document>";
const std::string KML_FOOTER = "</Document>\n</kml>\n";

const std::string PLACEMARK_HEAD = "<Placemark>\n<name>";
const std::string PLACEMARK_MID = "</name>\n<Point><coordinates>";
const std::string PLACEMARK_FOOT = "</coordinates></Point>\n";

// Takes in a csv file and outputs the contents to a kml formatted file
int processCSV(std::ifstream& inFile, std::string kmlFileName);

// Writes a placemark record into an already existing kml file
void writePlacemark(std::ofstream&kmlFile, std::string name, std::string latitude, std::string longitude);

#endif