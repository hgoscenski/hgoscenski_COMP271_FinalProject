#include <iostream>
#include <fstream>
#include "Cta.h"

// Each node can have 1 or more connections, each must have at least one out connection-- i.e. terminating stops have at least one upstream from them.

int main() {
    std::vector<std::string> lineFiles = {"blue", "brown","green","orange","pink","purple","red","yellow"};

    Line blueLine = Line("blue");
    Line brownLine = Line("brown");
    Line greenLine = Line("green");
    Line orangeLine = Line("orange");
    Line pinkLine = Line("pink");
    Line purpleLine = Line("purple");
    Line redLine = Line("red");
    Line yellowLine = Line("yellow");

    std::vector<Line> lines = {blueLine,brownLine,greenLine,orangeLine,pinkLine,purpleLine,redLine,yellowLine};
//    std::cout << lines.at(0).getLineName()<<std::endl;


    std::ifstream infile;
    std::string line;

    int lineCounter = 0;
    for(std::string s:lineFiles){

        int terminalCounter = 0;
        std::string currFile = "../lines/" + s;
//        std::cout<<currFile<<std::endl;
        infile.open(currFile);

//        long line_count = std::count(
//                std::istream_iterator<char>(infile),
//                std::istream_iterator<char>(),
//                '\n');
//        lines[lineCounter].addLineStation(Station("Howard", true, true));

        while(getline(infile, line))
        {
//            std::cout<<line<<std::endl;
//            long line_count = 10;
//            std::cout << line << std::endl;
//            blueLine.addLineStation(Station(line, line.find("(T)") != std::string::npos,
//                                                      (terminalCounter == line_count || terminalCounter == 0)));
//            std::cout<<lines[lineCounter].getLineName()<<std::endl;
            Station tempStation = Station(line,false,false);
            lines[lineCounter].addLineStation(tempStation);

        }
        lineCounter+=1;
        infile.close();
        infile.clear();
    }

    blueLine.printLineStations();

//    std::cout<<blueLine.printLineStations()<<std::endl;

//    std::cout<<blueLine.printLineStations()<<std::endl;
//    std::ifstream infile("/Users/hgoscenski/ClionProjects/hgoscenski-COMP271-FinalProject/lines/blue");
//    std::ifstream lineInput;
//    std::string line;
//
//    lineInput.open("../lines/blue");
//    while(getline(lineInput, line))
//    {
//        std::cout<<line<<"-->";
//    }
//    lineInput.close();
//    lineInput.clear();
//
//    std::cout<< std::endl;
//
//    lineInput.open("../lines/brown");
//    while(getline(lineInput, line))
//    {
//        std::cout<<line<<"-->";
//    }
//    std::cout<<"\n";
//    lineInput.close();
//    lineInput.clear();

    Cta cta = Cta();

    return 0;
}
