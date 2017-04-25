//
// Created by hgoscenski on 4/7/17.
//

#include <iostream>
#include <set>
#include "Cta.h"

std::vector<Line> Cta::getLines() {
    return lines;
}

std::vector<Station> Cta::getTransferLines(Station transStation, std::vector<Station> transferStations) {
    std::vector<Station> temp;
    for(Station s : transferStations){
        if(s.getStationName() == transStation.getStationName()){
            temp.push_back(s);
        }
        return temp;
    }
    return temp;
}

bool Cta::findLineStation(std::string searchingStationName){
    return allStationsSet.find(searchingStationName) != allStationsSet.end();
}

void Cta::setAllStations(std::set<std::string> stationSet){
    for(std::set<std::string>::iterator it = stationSet.begin(); it != stationSet.end(); ++it) {
        allStationsSet.insert(*it);
    }
}

Cta::Cta(std::vector<Line> lineVector){
    for(std::vector<Line>::iterator it = lineVector.begin(); it != lineVector.end(); ++it) {
        this->addLine(*it);
    }
}

void Cta::addLine(Line line) {
    lines.push_back(line);
}

std::string Cta::printLines(){
    for(std::vector<Line>::iterator it = lines.begin(); it != lines.end(); ++it) {
        std::cout<< it->getLineName()<<"\n"<< it->printLineStations()<< std::endl;
    }
}

Cta::Cta(){
    // DO NOTHING!
}