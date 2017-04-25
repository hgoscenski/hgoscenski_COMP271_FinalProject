//
// Created by hgoscenski on 4/7/17.
//

#include <iostream>
#include <sstream>
#include "Line.h"

Line::Line(std::string name) {
//    std::vector<Station> lineStations;
    lineName = name;
}



bool Line::isEqual(Line otherLine) {
    return lineName == otherLine.getLineName();
}

void Line::addLineStation(Station stationName) {
    lineStations.push_back(stationName);
}



std::string Line::getLineName() {
    return lineName;
}

std::string Line::printLineStations() {
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
    return "--------------------------------------------------";
}

Line::Line(){
//    do nothing
}