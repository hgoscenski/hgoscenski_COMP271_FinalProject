//
// Created by hgoscenski on 4/7/17.
//

#include "Cta.h"

std::vector<Line> Cta::getLines() {
    return lines;
}

std::vector<Station> static Cta::getTransferLines(Station transStation, std::vector transferStations) {
    std::vector<Station> temp;
    for(Station s : transferStations){
        if(s.getStationName() == transStation.getStationName()){
            temp.push_back(s);
        }
        return temp;
    }
}

void Cta::addLine(Line line) {
    lines.push_back(line);
}
