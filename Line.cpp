//
// Created by hgoscenski on 4/7/17.
//

#include "Line.h"
#include <Station.h>

bool Line::isEqual(Line otherLine) {
    return lineName == otherLine.getLineName();
}

void Line::addLineStation(Station stationName) {
    Line currLine = *this;
    lineStations.push_back(stationName);
    stationName.setLine(currLine);
}

Line::Line(std::string lineName){
    lineName = lineName;
}

std::string Line::getLineName() {
    return lineName;
}