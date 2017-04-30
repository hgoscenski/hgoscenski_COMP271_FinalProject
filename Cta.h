//
// Created by hgoscenski on 4/7/17.
//

#ifndef HGOSCENSKI_COMP271_FINALPROJECT_CTA_H
#define HGOSCENSKI_COMP271_FINALPROJECT_CTA_H\

#include <array>
#include <vector>
#include <set>
#include "Station.h"
#include "Line.h"

class Cta {
public:
    Cta(std::vector<Line, std::allocator<Line>> lineVector);
    std::vector<Station> static getTransferLines(Station transStation, std::vector<Station> transferStations);
    void setAllStations(std::set<std::string> stationSet);
    std::vector<Line> getLines();
    std::string printLines();
    Line determineLine(std::string searchingStationName);
    int stationToStationPathFinding(std::string startStation, std::string endStation);
    Cta();
    bool findLineStation(std::string searchingStationName);

private:
    void addLine(Line line);
    std::vector<Line> lines;
    std::vector<Station> transferLines;
    std::set<std::string> allStationsSet;
};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_CTA_H
