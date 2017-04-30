//
// Created by hgoscenski on 4/7/17.
//

#include <iostream>
#include <set>
#include "Cta.h"


Cta::Cta(std::vector<Line> lineVector){
    for(std::vector<Line>::iterator it = lineVector.begin(); it != lineVector.end(); ++it) {
        this->addLine(*it);
    }
}

std::vector<Line> Cta::getLines() {
    return lines;
}

std::vector<Station> Cta::getTransferLines(Station transStation, std::vector<Station> transferStations) {
    std::vector<Station> temp;
    for(Station s : transferStations){
        if(s.getStationName() == transStation.getStationName()){
            temp.push_back(s);
        }
    }
    return temp;
}

Line Cta::determineLine(std::string searchingStationName){
    for(std::vector<Line>::iterator it = lines.begin(); it != lines.end(); ++it) {
        if(it->stationOnLine(searchingStationName)){
            return *it;
        }
    }
//     there should never actually be one of these, since all requests to this function should pass through findLineStation
    return Line("fakeline");
}

int Cta::stationToStationPathFinding(std::string startStation, std::string endStation){
    if(findLineStation(startStation) && findLineStation(endStation)){
        Line startLine = determineLine(startStation);
        Line endLine = determineLine(endStation);
        if(startLine.isEqual(endLine)){
            startLine.printLineStations(startStation, endStation);
        }
    } else {
        std::cout << "Both stations are not legitimate stations on the CTA, please verify they are the correct stations and try again." << std::endl;
    }
}

bool Cta::findLineStation(std::string searchingStationName){
    return allStationsSet.find(searchingStationName) != allStationsSet.end();
}

void Cta::setAllStations(std::set<std::string> stationSet){
    for(std::set<std::string>::iterator it = stationSet.begin(); it != stationSet.end(); ++it) {
        allStationsSet.insert(*it);
    }
}

void Cta::addLine(Line line) {
    lines.push_back(line);
}

std::string Cta::printLines(){
    for(std::vector<Line>::iterator it = lines.begin(); it != lines.end(); ++it) {
        std::cout<< it->getLineName()<<"\n"<< it->printLineStations()<< std::endl;
    }
    return "";
}

Cta::Cta(){
    // DO NOTHING!
}
