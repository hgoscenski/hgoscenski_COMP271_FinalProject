#include <iostream>
#include <fstream>
#include <set>
#include "Cta.h"

//int stationLineInfo(Cta cta, std::string searchStation){
//    if(cta.findLineStation(searchStation)){
//        std::cout << searchStation << " is a valid station and is on the " << cta.determineLine(searchStation).getLineName() << " line." << std::endl;
//    } else {
//        std::cout << "Error: " << searchStation << " is not a station at all!" << std::endl;
//    }
//    return 0;
//}

void printOptions(){
    std::cout << "Please Enter one of the following options:"<<std::endl;
    std::cout << "1. See if Station is in the CTA \n2. See what Line a Station is Part of \n3. Print all stations \n4. Find a path between 2 stations \n5. Quit \n" << std::endl;
}


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
                line.erase(line.length()-4, std::string::npos);
                tempBool = true;
            } else {
                tempBool = false;
            }
            Station tempStation = Station(line, tempBool,(terminalCounter==0 || terminalCounter== numOfLinesInFile-1));
            allStations.insert(line);
            tempLine.addLineStation(tempStation);
            terminalCounter++;
        }
        tempLine.createTransferVector();

        lines.push_back(tempLine);
        infile.close();
        infile.clear();
    }

    Cta cta = Cta(lines);
    cta.setAllStations(allStations);
//
//    std::cout << cta.findLineStation("Howard") << std::endl;
//
//    cta.stationToStationPathFinding("Loyola", "Howard");
//
//    cta.stationToStationPathFinding("Howard", "Dempster-Skokie");
//
//    std::cout << cta.findIntersection(lines[6], lines[7]).getStationName() << std::endl;
//
//    cta.stationToStationPathFinding("Loyola", "95th/Dan Ryan");

//    std::cout << "Loyola Station is on the " << cta.determineLine("Loyola").getLineName() << " Line" << std::endl;
//    std::cout << "O'Hare Station is on the " <<  cta.determineLine("O'Hare").getLineName() << " Line" << std::endl;

//    cta.printLines();
//    lines[0].printLineStations();

//    User input loop

    bool stop = false;
    std::cout << "Welcome to the CTA line finder" << std::endl;
    while(!stop){
        std::string option;
        printOptions();
        std::getline(std::cin, option);
        if(option == "1"){
            std::cout<<"Please enter a station name" << std::endl;
            std::getline(std::cin, option);
            if(cta.findLineStation(option)){
                std::cout<< option << " is a CTA station" << std::endl;
            }
        }
        if(option == "2"){
            std::cout<<"Please enter a station name" << std::endl;
            std::getline(std::cin, option);
            if(cta.findLineStation(option)){
                std::cout<<option << " is part of "<< cta.determineLine(option).getLineName() << " line"  << std::endl;
            }
        }
        if(option == "3"){
            cta.printLines();
        }
        if(option == "5"){
            stop = true;
        }
        if(option == "4"){
            std::string startStation;
            std::string endStation;
            std::cout << "Enter the starting station's name" << std::endl;
            std::getline(std::cin, option);
            startStation = option;
            std::cout << "Enter the ending station's name" << std::endl;
            std::getline(std::cin, option);
            endStation = option;
            cta.stationToStationPathFinding(startStation, endStation);
        }

    }

    return 0;
}
