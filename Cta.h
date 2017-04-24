//
// Created by hgoscenski on 4/7/17.
//

#ifndef HGOSCENSKI_COMP271_FINALPROJECT_CTA_H
#define HGOSCENSKI_COMP271_FINALPROJECT_CTA_H\

#include <array>
#include <vector>
#include "Station.h"
#include "Line.h"

class Cta {
public:
    std::vector<Station> static getTransferLines(Station transStation, std::vector<Station> transferStations);
    std::vector<Line> getLines();
    Cta();

private:
    void addLine(Line line);
    std::vector<Line> lines;
    std::vector<Station> transferLines;

};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_CTA_H
