//
// Created by hgoscenski on 4/7/17.
//

#include "Line.h"

bool Line::isEqual(Line otherLine) {
    return lineName == otherLine.getLineName();
}

void Line::addLineStation(Station stationName) {
    Line currLine = *this;
    lineStations.push_back(stationName);
    stationName.setLine(currLine);
}

std::string Line::getLineName() {
    return lineName;
}