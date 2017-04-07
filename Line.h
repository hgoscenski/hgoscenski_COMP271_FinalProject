//
// Created by hgoscenski on 4/7/17.
//

#ifndef HGOSCENSKI_COMP271_FINALPROJECT_LINE_H
#define HGOSCENSKI_COMP271_FINALPROJECT_LINE_H


#include <string>
#include "Station.h"

class Line {
public:
    std::string getLineName();
    std::vector addLineStation(Station lineStation);
};


#endif //HGOSCENSKI_COMP271_FINALPROJECT_LINE_H
