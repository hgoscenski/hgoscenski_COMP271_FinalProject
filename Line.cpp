//
// Created by hgoscenski on 4/7/17.
//

#include <iostream>
#include <sstream>
#include "Line.h"

// Constructor that is used most
// Takes the name of the line and sets it
Line::Line(std::string name) {
    lineName = name;
}

// checks to see if a station is present on the current Line object
bool Line::stationOnLine(std::string searchingStation){
    for(std::vector<Station>::iterator it = lineStations.begin(); it != lineStations.end(); it++){
        if(it->getStationName() == searchingStation){
            return true;
        }
    }
    return false;
}

//Checks for line equivalency
bool Line::isEqual(Line otherLine) {
    return lineName == otherLine.getLineName();
}

//Adds a station to the vector<Station> that holds all the stations
void Line::addLineStation(Station stationName) {
    lineStations.push_back(stationName);
}

//Returns the name of the Line
std::string Line::getLineName() {
    return lineName;
}

/*
 * So this is where things start to get interesting
 * This iterates through the vector of stations and then determines the index of the the respective stations
 * The it takes those indexes and compares them for size
 * Then it iterates in the proper direction from start to end
 *
 * This is used for the path finding
 * This is an overloaded function
 */
std::string Line::printLineStations(std::string startStation, std::string endStation) {
    std::string stationsString = "test";

    int startStationIndex =0;
    int endStationIndex = 0;
    for(int i = 0; i < lineStations.size(); i++){
        if(lineStations[i].getStationName() == startStation){
            startStationIndex = i;
        }
        if(lineStations[i].getStationName() == endStation){
            endStationIndex = i;
        }
    }
    if(endStationIndex < startStationIndex) {
        for (int k = startStationIndex; k >= endStationIndex; k--) {
            std::cout << lineStations[k].getStationName() << std::endl;
        }
    } else {
        for (int l = startStationIndex;l <= endStationIndex; l++){
            std::cout << lineStations[l].getStationName() << std::endl;
        }
    }
    return "";
}

// This is the corresponding function to the above and it used to simply print all of the stations
// This uses an iterator to accomplish it
std::string Line::printLineStations() {
//    std::cout << lineName << std::endl;
    int counter = 0;
    if(this->lineStations.empty()){
        return "????????????????????????????????????????";
    }
    for(std::vector<Station>::iterator it = lineStations.begin(); it != lineStations.end(); ++it) {
        Station tempStation = *it;
        std::string stringThing = tempStation.getStationName();
        std::cout<< stringThing << " is a terminal station: "<< tempStation.isTerminalStation() << " is a transfer station: "<< tempStation.isTransferStation() <<std::endl;
        counter++;
    }
    std::cout<< "--------------------------------------------------" << std::endl;
    return "";
}

//Default constructor
Line::Line(){
//    do nothing
//    Default constructor
}

//This is used to generated the vector of objects that are used for the comparision of the lines across transfers
void Line::createTransferVector() {
    for(int i = 0; i < lineStations.size(); i++){
        if(lineStations[i].isTransferStation()){
            transferStations.push_back(lineStations[i]);
        }
    }
}

//returns the above created vector
std::vector<Station> Line::getTransferVector() {
    return transferStations;
}
