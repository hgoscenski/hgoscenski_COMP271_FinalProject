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
//    pointer = &lineStations;
//    std::cout<<pointer<<std::endl;
//    Station tempBack = lineStations.back();
//    std::cout<<tempBack.getStationName()<<std::endl;
//    Station tempStation = stationName;
//    std::cout<<tempStation.getStationName()<<"////"<<std::endl;
}

std::string Line::getLineName() {
    return lineName;
}

std::string Line::printLineStations() {
    int counter = 0;
//    std::cout<<this->getLineName()<<std::endl;
//    std::cout<<this->lineStations.back().getStationName()<<std::endl;
//    std::cout<<lineStations.empty()<<std::endl;
//    std::cout<<this->lineStations.empty()<<std::endl;
    for(std::vector<Station>::iterator it = lineStations.begin(); it != lineStations.end(); ++it) {

        std::cout<<counter<<std::endl;
        Station tempStation = *it;
        std::string stringThing = tempStation.getStationName();
        std::cout<< stringThing <<std::endl;
        counter++;

    }
    return "WHY?!";
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