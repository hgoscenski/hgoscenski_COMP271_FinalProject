//
// Created by hgoscenski on 4/7/17.
//

#include <iostream>
#include <set>
#include "Cta.h"

// constructor that that takes a vector of lines and then generates the lines of the cta
Cta::Cta(std::vector<Line> lineVector){
    for(std::vector<Line>::iterator it = lineVector.begin(); it != lineVector.end(); ++it) {
        this->addLine(*it);
    }
}

// This determines the line of a station by taking the station name as a string
// this then loops through the cta's vector of lines and then uses the line
// method of stationOnLine to determine if it is present
Line Cta::determineLine(std::string searchingStationName){
    for(std::vector<Line>::iterator it = lines.begin(); it != lines.end(); ++it) {
        if(it->stationOnLine(searchingStationName)){
            return *it;
        }
    }
//     there should never actually be one of these, since all requests to this function should pass through findLineStation
    return Line("fakeline");
}

/*
 *
 */
int Cta::stationToStationPathFinding(std::string startStation, std::string endStation){
    std::string transStation;

    if(findLineStation(startStation) && findLineStation(endStation)){
        Line startLine = determineLine(startStation);
        Line endLine = determineLine(endStation);
        if(startLine.isEqual(endLine)){
            startLine.printLineStations(startStation, endStation);
        } else{
            transStation = this->findIntersection(startLine, endLine).getStationName(); // this will determine what transfer stations there are then we can crossreference transfer stations with the line we want to get to.
            std::cout << startLine.printLineStations(startStation, transStation) << " \\\\Transfer// \n" << endLine.printLineStations(transStation, endStation) << std::endl;
    }

    } else {
        std::cout << "Both stations are not legitimate stations on the CTA, please verify they are the correct stations and try again." << std::endl;
    }
    return 0;
}

// This checks if a station is a station at all
// searches the set of stations
bool Cta::findLineStation(std::string searchingStationName){
    return allStationsSet.find(searchingStationName) != allStationsSet.end();
}

// This creates a set of all unique stations
// This is used for a quick check if a station exists at all
void Cta::setAllStations(std::set<std::string> stationSet){
    for(std::set<std::string>::iterator it = stationSet.begin(); it != stationSet.end(); ++it) {
        allStationsSet.insert(*it);
    }
}

// adds a line to the lines vector
void Cta::addLine(Line line) {
    lines.push_back(line);
}

// this prints all of the stations and all of the lines
std::string Cta::printLines(){
    for(std::vector<Line>::iterator it = lines.begin(); it != lines.end(); ++it) {
        std::cout<< it->getLineName()<<"\n"<< it->printLineStations()<< std::endl;
    }
    return "";
}

// default constructor
Cta::Cta(){
    // DO NOTHING!
}

// This function finds the intersection between two lines using the transfer vectors of the respective lines
Station Cta::findIntersection(Line startLine, Line endLine) {
    for(int i = 0; i < startLine.getTransferVector().size(); i ++){
        for(int j = 0; j < endLine.getTransferVector().size(); j++){
            if(startLine.getTransferVector()[i].getStationName() == endLine.getTransferVector()[j].getStationName() ){
                return startLine.getTransferVector()[i];
            }
        }
    }
//    this only accurs if something went terribly wrong
    return Station("NULL", false, false);
}
