#include <iostream>
#include <fstream>
#include <set>
#include "Cta.h"


/*
 * Harrison Goscenski 4-30-17
 *
 * So this is a lot of code in main, I agree.
 * However in order to load the files into the cta class it seemed to be the most effective method
 * Thusly there are a few more lines of code in main than I would prefer
 * I figured out how to make the path findinding work
 *  -I use a vector of transfer stations on a line
 *  -and then compare that to the vector of transfer stations on the line we want to end up on
 * This looks like this
 *  Start at Loyola station
 *      Determine that it is part of the redline
 *  Look at EndStation of O'Hare
 *      Determine that it is part of the Blueline
 *
 *  Compare blue and red transferStation vectors
 *  Determine the crossover is at Jackson
 *  Go red line down to Jackson and then from Jackson Up the blueline to O'Hare.
 *  There we are!
 *  We did it!
 *  Yay CTA and yay for vectors
 */

// This is used to output the options for the user input loop
void printOptions(){
    std::cout << "Please Enter one of the following options:"<<std::endl;
    std::cout << "1. See if Station is in the CTA \n2. See what Line a Station is Part of \n3. Print all stations \n4. Find a path between 2 stations \n5. Quit \n" << std::endl;
}


int main() {

//    stores a list of line/file names for loading the cta
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

//    initializing the main objects needed for loading the main cta/line/station objects
    std::vector<Line> lines;
    std::set<std::string> allStations;
    std::ifstream infile;
    std::string line;

//    Makes a loop to go through all the files in the lines folder at the root of the program.
//    These files are then read through to create the lines of stations
    for(std::string s:lineFiles){
        Line tempLine(s);
        int terminalCounter = 0;

        std::string currFile = "../lines/" + s;
        infile.open(currFile);

//        Gets the number of stations in the file
        int numOfLinesInFile = 0;
        while (std::getline(infile, line)) {
            ++numOfLinesInFile;
        }

//        Closes the file that was read through
        infile.close();

//        Reopened file to actually iterate through
        infile.open(currFile);

//        Loops through all of the lines in the current lineFile and thusly creates the vector<Station> in the line object
        while(getline(infile, line))
        {
//            This logic here determines whether or not a station is a transfer station or not
            bool tempBool;
            std::string t = "(T)";
            if(line.find(t) != std::string::npos){
                line.erase(line.length()-4, std::string::npos);
                tempBool = true;
            } else {
                tempBool = false;
            }
//            Creates the station object with the name, whether it is a transfer station, and whether it is a first or last station
            Station tempStation = Station(line, tempBool,(terminalCounter==0 || terminalCounter== numOfLinesInFile-1));
            allStations.insert(line);
            tempLine.addLineStation(tempStation);
            terminalCounter++;
        }
//        for the current line it creates the vector which holds the transfer station available
        tempLine.createTransferVector();

//        Adds the current line with all of its properties/objects to the array of lines
        lines.push_back(tempLine);

//        Closes the file being used and clears the io buffer
        infile.close();
        infile.clear();
    }

//    creates the cta object from the vector<Line>
    Cta cta = Cta(lines);
    cta.setAllStations(allStations);

//    User input loop

    bool stop = false;
    std::cout << "Welcome to the CTA line finder" << std::endl;
    while(!stop){
        std::string option;
        printOptions();
        std::getline(std::cin, option);
//        option 1
        if(option == "1"){
            std::cout<<"Please enter a station name" << std::endl;
            std::getline(std::cin, option);
            if(cta.findLineStation(option)){
                std::cout<< option << " is a CTA station" << std::endl;
            }
        }
//        option 2
        if(option == "2"){
            std::cout<<"Please enter a station name" << std::endl;
            std::getline(std::cin, option);
            if(cta.findLineStation(option)){
                std::cout<<option << " is part of "<< cta.determineLine(option).getLineName() << " line"  << std::endl;
            }
        }
//        option 3
        if(option == "3"){
            cta.printLines();
        }
//        option 5
        if(option == "5"){
            stop = true;
        }
//        option 4
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
