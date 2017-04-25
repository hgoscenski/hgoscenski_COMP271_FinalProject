#include <iostream>
#include <fstream>
#include <set>
#include "Cta.h"

int main() {
    std::vector<std::string> lineFiles = {
            "blue",
            "brown",
            "green",
            "orange",
            "pink",
            "purple",
            "red",
            "yellow"
    };

    std::vector<Line> lines;
    std::set<std::string> allStations;
    std::ifstream infile;
    std::string line;

    for(std::string s:lineFiles){
//        std::cout<<s<<std::endl;
        Line tempLine(s);
        int terminalCounter = 0;

        std::string currFile = "../lines/" + s;
        infile.open(currFile);

        int numOfLinesInFile = 0;
        while (std::getline(infile, line)) {
            ++numOfLinesInFile;
        }
        infile.close();
        infile.open(currFile);


        while(getline(infile, line))
        {
            bool tempBool;
            std::string t = "(T)";
            if(line.find(t) != std::string::npos){
                line.erase(line.length()-3, t.length());
                tempBool = true;
            } else {
                tempBool = false;
            }
            Station tempStation = Station(line, tempBool,(terminalCounter==0 || terminalCounter== numOfLinesInFile-1));
            allStations.insert(line);
            tempLine.addLineStation(tempStation);
            terminalCounter++;
        }

        lines.push_back(tempLine);
        infile.close();
        infile.clear();
    }

    Cta cta = Cta(lines);
    cta.setAllStations(allStations);

//    cta.printLines();

    std::cout<<cta.findLineStation("nahhh") << " || " << cta.findLineStation("Loyola") <<std::endl;
//
//    for(std::string s:allStations){
//        std::cout<<s<<std::endl;
//    }

    return 0;
}
