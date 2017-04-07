//
// Created by hgoscenski on 4/7/17.
//

#ifndef HGOSCENSKI_COMP271_FINALPROJECT_STATION_H
#define HGOSCENSKI_COMP271_FINALPROJECT_STATION_H


#include <string>
#include "Line.h"

class Station {
public:
    void addNextStation(Station next, Line lineName);
    bool isTransferStation();
    bool isTerminalStation();
    std::string getStationName();
    void addPreviousStation(Station prior, Line lineName);
    Station getNextStation();
    Station getNextStation(Line lineName);
    Station getPreviousStation();
    Station getPreviousStation(Line lineName);
private:
    Station nextStation;
    Station previousStation;
    std::string stationName;
    bool isTransfer;
    bool isTerminal;
};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_STATION_H
