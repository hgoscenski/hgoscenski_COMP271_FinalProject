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

//std::vector<Station> Cta::getTransferLines(Station transStation, std::vector<Station> transferStations) {
//    std::vector<Station> temp;
//    for(Station s : transferStations){
//        if(s.getStationName() == transStation.getStationName()){
//            temp.push_back(s);
//        }
//    }
//    return temp;
//}

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
//    int startStationIndex = 0;
//    int endStationIndex = 0;
//    int transStationIndexStart;
//    int transStationIndexEnd;
    std::string transStation;

    if(findLineStation(startStation) && findLineStation(endStation)){
        Line startLine = determineLine(startStation);
        Line endLine = determineLine(endStation);
        if(startLine.isEqual(endLine)){
            startLine.printLineStations(startStation, endStation);
        } else{
//            startStationIndex = startLine.findStationIndex(startStation);
//            endStationIndex = endLine.findStationIndex(endStation);
            transStation = this->findIntersection(startLine, endLine).getStationName(); // this will determine what transfer stations there are then we can crossreference transfer stations with the line we want to get to.
//            transStationIndexStart = startLine.findStationIndex(transStation);
//            transStationIndexEnd = endLine.findStationIndex(transStation);
//            std::cout << this->stationToStationPathFinding(startStation, transStation) << " | " << this->stationToStationPathFinding(transStation, endStation) << std::endl;
            std::cout << startLine.printLineStations(startStation, transStation) << " \\\\Transfer// \n" << endLine.printLineStations(transStation, endStation) << std::endl;
    }

    } else {
        std::cout << "Both stations are not legitimate stations on the CTA, please verify they are the correct stations and try again." << std::endl;
    }
    return 0;
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

Station Cta::findIntersection(Line startLine, Line endLine) {
    for(int i = 0; i < startLine.getTransferVector().size(); i ++){
        for(int j = 0; j < endLine.getTransferVector().size(); j++){
            if(startLine.getTransferVector()[i].getStationName() == endLine.getTransferVector()[j].getStationName() ){
                return startLine.getTransferVector()[i];
            }
        }
    }
    return Station("NULL", false, false);
}
