//
// Created by hgoscenski on 4/7/17.
//

#ifndef HGOSCENSKI_COMP271_FINALPROJECT_STATION_H
#define HGOSCENSKI_COMP271_FINALPROJECT_STATION_H


#include <string>

class Station {
public:
    bool isTransferStation();
    bool isTerminalStation();
    std::string getStationName();
    Station(std::string name, bool isTransfer, bool isTerminal);
    Station();

private:
    std::string stationName;
    bool isTransfer;
    bool isTerminal;
};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_STATION_H
