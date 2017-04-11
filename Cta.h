//
// Created by hgoscenski on 4/7/17.
//

#ifndef HGOSCENSKI_COMP271_FINALPROJECT_CTA_H
#define HGOSCENSKI_COMP271_FINALPROJECT_CTA_H\

#include <array>
#include <vector>
#include "Station.h"

class Cta {
public:
    std::vector static getTransferLines(Station transStation, std::vector transferStations);
    std::vector getLines();
    Cta();

private:
    std::vector lines;
    std::vector transferLines;

};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_CTA_H
