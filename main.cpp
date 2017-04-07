#include <iostream>
#include <fstream>

// Each node can have 1 or more connections, each must have at least one out connection-- i.e. terminating stops have at least one upstream from them.

int main() {
//    std::ifstream infile("/Users/hgoscenski/ClionProjects/hgoscenski-COMP271-FinalProject/lines/blue");
    std::ifstream lineInput;
    std::string line;

    lineInput.open("../lines/blue");
    while(getline(lineInput, line))
    {
        std::cout<<line<<"-->";
    }
    lineInput.close();
    lineInput.clear();

    std::cout<< std::endl;

    lineInput.open("../lines/brown");
    while(getline(lineInput, line))
    {
        std::cout<<line<<"-->";
    }
    std::cout<<"\n";
    lineInput.close();
    lineInput.clear();

    return 0;
}
