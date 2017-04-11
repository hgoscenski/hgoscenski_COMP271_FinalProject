//
// Created by hgoscenski on 4/7/17.
//

#include "Cta.h"

std::vector Cta::getLines() {
    return lines;
}

std::vector static Cta::getTransferLines(Station transStation, std::vector transferStations) {
    std::vector temp;
    for(Station s : transferStations){
        if(s.getStationName() == transStation.getStationName()){
            temp.push_back(s);
        }
        return temp;
    }
}