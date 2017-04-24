//
// Created by hgoscenski on 4/7/17.
//

#include "Station.h"
#include "Cta.h"

Station::Station(std::string name, bool transfer, bool terminal) {
    stationName = name;
    isTerminal = terminal;
    isTransfer = transfer;
}

std::string Station::getStationName(){
    return stationName;
}

bool Station::isTerminalStation(){
    return isTerminal;
}

bool Station::isTransferStation() {
    return isTransfer;
}

