//
// Created by hgoscenski on 4/7/17.
//

#include "Station.h"
#include "Cta.h"

Station::Station(std::string name, Line line, bool transfer, bool terminal) {
    stationName = name;
    lineMember = line;
    isTerminal = terminal;
    isTransfer = transfer;
}

void Station::addNextStation(Station next, Line lineName){
    nextStation = next;
}

void Station::addPreviousStation(Station prior, Line lineName) {
    previousStation = prior;
}

Station Station::getNextStation() {
    return nextStation;
}

Station Station::getNextStation(Line lineName) {
    if(lineMember.isEqual(lineName)){
        return nextStation;
    } else {
        Station currentStation = *this;
        std::vector transferStations = Cta::getTransferLines(currentStation);
        int length = transferStations.size();
            for (Station s : transferStations) {
                if(s.getLine().isEqual(lineName)){
                    return s;
                }
            }
    }
    return nullptr;

}

Station Station::getPreviousStation() {
    return previousStation;
}

Station Station::getPreviousStation(Line lineName) {
    if(lineMember.isEqual(lineName)){
        return previousStation;
    } else {
        Station currentStation = *this;
        std::vector transferStations = Cta::getTransferLines(currentStation);
        int length = transferStations.size();
        for (Station s : transferStations) {
            if(s.getLine().isEqual(lineName)){
                return s;
            }
        }
    }
    return nullptr;
}

Line Station::getLine() {
    return lineMember;
}

bool Station::isTerminalStation() {
    return isTerminal;
}

bool Station::isTransferStation(){
    return isTransfer;
}

