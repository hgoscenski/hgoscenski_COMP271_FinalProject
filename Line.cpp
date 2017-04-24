//
// Created by hgoscenski on 4/7/17.
//

#include <iostream>
#include <sstream>
#include "Line.h"

bool Line::isEqual(Line otherLine) {
    return lineName == otherLine.getLineName();
}

void Line::addLineStation(Station stationName) {
    lineStations.push_back(stationName);
//    Station tempBack = lineStations.back();
//    std::cout<<tempBack.getStationName()<<std::endl;
//    Station tempStation = stationName;
//    std::cout<<tempStation.getStationName()<<"////"<<std::endl;
}

Line::Line(std::string name) {
    lineName = name;
}

std::string Line::getLineName() {
    return lineName;
}

std::string Line::printLineStations() {
    for(std::vector<Station>::iterator it = lineStations.begin(); it != lineStations.end(); ++it) {
        Station tempStation = *it;
        std::cout<< tempStation.getStationName() <<std::endl;
    }
//    std::string temp = "";
//    for(Station s:lineStations){
//
//        std::cout<<s.isTerminalStation()<<std::endl;
//
//        temp+= s.getStationName()+ "-->";
//    }
//    std::cout<<temp<<std::endl;
//    return "\n";


//    std::ostringstream tempString;
//    std::string temp;
//    for(Station s : lineStations) {
//        std::cout<<"1"<<std::endl;
//        tempString << (s.getStationName()) << "-->";
//        temp = tempString.str();
//        std::cout << temp << std::endl;
//    }
//    return temp;
}