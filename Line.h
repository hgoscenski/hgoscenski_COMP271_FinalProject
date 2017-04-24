//
// Created by hgoscenski on 4/7/17.
//

#ifndef HGOSCENSKI_COMP271_FINALPROJECT_LINE_H
#define HGOSCENSKI_COMP271_FINALPROJECT_LINE_H


#include <string>
#include <vector>
#include <list>
#include "Station.h"

class Line {
public:
    std::string getLineName();
    void addLineStation(Station lineStation);
    std::string printLineStations();
    bool isEqual(Line otherLine);
    Line(std::string name);

private:
    std::string lineName;
    std::vector<Station> lineStations;
    std::list<Station> lineStationsOrdered;
};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_LINE_H
