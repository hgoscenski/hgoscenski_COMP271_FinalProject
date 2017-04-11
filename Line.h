//
// Created by hgoscenski on 4/7/17.
//

#ifndef HGOSCENSKI_COMP271_FINALPROJECT_LINE_H
#define HGOSCENSKI_COMP271_FINALPROJECT_LINE_H


#include <string>
#include <vector>
#include "Station.h"

class Line {
public:
    std::string getLineName();
    void addLineStation(Station lineStation);
    bool isEqual(Line otherLine);
    Line(std::string lineName);

private:
    std::string lineName;
    std::vector<Station> lineStations;
};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_LINE_H
