#include <iostream>
#include <fstream>
#include "Cta.h"
#include <vector>

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

    std::ifstream infile;
    std::string line;
    int counter = 0;
    for(std::string s:lineFiles){
        int terminalCounter;
        infile.open("../lines/"+s);
        long line_count = std::count(
                std::istream_iterator<char>(infile),
                std::istream_iterator<char>(),
                '\n');
        while(getline(infile, line)){
            if(s.find("(T)") != std::string::npos){
            Station(s,lines.at(counter),true,(terminalCounter==line_count || terminalCounter ==0));
            }
            else{
                Station(s,lines.at(counter),false,(terminalCounter==line_count || terminalCounter ==0));
            }
        }
    }
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
