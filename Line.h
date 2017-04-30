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
    bool stationOnLine(std::string searchingStation);
    std::string printLineStations(std::string startStation, std::string endStation);
    void createTransferVector();
    std::string printLineStations();
    std::vector<Station> getTransferVector();
    bool isEqual(Line otherLine);
    Line(std::string name);
    Line();

private:
    std::string lineName;
    std::vector<Station> lineStations;
    std::vector<Station> transferStations;
};

#endif //HGOSCENSKI_COMP271_FINALPROJECT_LINE_H
