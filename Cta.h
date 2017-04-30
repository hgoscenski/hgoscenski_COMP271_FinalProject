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
    void setAllStations(std::set<std::string> stationSet);
    std::string printLines();
    Line determineLine(std::string searchingStationName);
    int stationToStationPathFinding(std::string startStation, std::string endStation);
    Cta();
    bool findLineStation(std::string searchingStationName);
    Station findIntersection(Line startLine, Line endLine);

private:
    void addLine(Line line);
    std::vector<Line> lines;
    std::set<std::string> allStationsSet;
};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_CTA_H
