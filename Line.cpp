//
// Created by hgoscenski on 4/7/17.
//

#include <iostream>
#include <sstream>
#include "Line.h"

Line::Line(std::string name) {
    lineName = name;
}

bool Line::stationOnLine(std::string searchingStation){
    for(std::vector<Station>::iterator it = lineStations.begin(); it != lineStations.end(); it++){
        if(it->getStationName() == searchingStation){
            return true;
        }
    }
    return false;
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

std::string Line::printLineStations() {
    std::cout << lineName << std::endl;
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

Line::Line(){
//    do nothing
//    Default constructor
}

void Line::createTransferVector() {
    for(int i = 0; i < lineStations.size(); i++){
        if(lineStations[i].isTransferStation()){
            transferStations.push_back(lineStations[i]);
        }
    }
}

std::vector<Station> Line::getTransferVector() {
    return transferStations;
}
